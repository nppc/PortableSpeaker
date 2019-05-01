; Flag PWM_flags
; bit 7 - Regulate PWM - bit sets every 1ms indicating that we can compare voltages and adjust PWM.
.EQU	PWM_flag_regulatePWM = 7

; Convert ADC RAW voltage to real voltage
Convert_VoltageADC_to_Volt:
	#ifdef MOVINGAVERAGE
		ldi ZL, LOW(M_AVERAGE_voltage_COUNTER)
		ldi ZH, HIGH(M_AVERAGE_voltage_COUNTER)
		rcall moving_average
	#endif
	; Value is ready for converting to Volts (actually V*100 eg 1200 = 12.00V)
	; The formula is: ADC * 64 / VOLT_DIV_CONST
	ldi tmp, 6
mult32:
	lsl tmp2
	rol tmp3
	dec tmp
	brne mult32
	; divide it by a constant
	mov tmpL1, tmp2
	mov tmpH1, tmp3
	ldi tmp, VOLT_DIV_CONST
	mov tmpL2, tmp
	clr tmpH2
	rcall div16u	; result in tmpH1:tmpL1 (actually only low byte)
	sts Voltage_Measured, tmpL1
	sts Voltage_Measured+1, tmpH1
convert_V_exit:
	ret

; Convert ADC RAW current to real current
Convert_CurrentADC_to_Current:
	#ifdef MOVINGAVERAGE
		ldi ZL, LOW(M_AVERAGE_current_COUNTER)
		ldi ZH, HIGH(M_AVERAGE_current_COUNTER)
		rcall moving_average
	#endif
	; Value is ready for converting to Current (actually C*10 eg 55 = 5.5A)
	; ADC_Current_zero_RAW - reference for 0.0A
	; The formula is: (ADC-ADC_Current_zero_RAW)*64/CURRENT_DIV_CONST
	lds tmpL1, ADC_Current_zero_RAW
	lds tmpH1, ADC_Current_zero_RAW+1
	sub tmp2, tmpL1
	sbc tmp3, tmpH1
	brcc convert_C_notminus
	mov tmp2, tmpL1	; if minus, then 0
	mov tmp3, tmpH1	; if minus, then 0
convert_C_notminus:
	ldi tmp, 6
mult64:
	lsl tmp2
	rol tmp3
	dec tmp
	brne mult64
	; divide it by a constant
	mov tmpL1, tmp2
	mov tmpH1, tmp3
	ldi tmp, CURRENT_DIV_CONST
	mov tmpL2, tmp
	clr tmpH2
	rcall div16u	; result in tmpH1:tmpL1 (actually only low byte)
	sts Current_Measured, tmpL1
convert_C_exit:
	ret
	
; The routine checks measured voltage and compare it to the desired voltage (setVolt_tmp)
; Need to see, how it is better to check voltage, by filtered RAW value or calculated V*10?
Regulate_PWM:
	; check flag PWM_flag_regulatePWM
	sbrs PWM_flags, PWM_flag_regulatePWM
	rjmp Regulate_PWM_exit
	cbr PWM_flags, (1<<PWM_flag_regulatePWM)	; clear flag
	in tmp1, OCR1A	; read current PWM
	; compare voltages
	; TODO votage now is 2 byte value
	lds tmp, Voltage_Measured	
	cp tmp, setVolt_tmp
	breq Regulate_PWM_exit	; No need to change
	brsh Regulate_PWM_minus ; need to decrease PWM
	; need to increase PWM
	; check that we not at max already
	cpi tmp1, 255
	breq Regulate_PWM_exit
	inc tmp1
Regulate_PWM_update:
	out OCR1A, tmp1
Regulate_PWM_exit:
	ret
Regulate_PWM_minus:
	; check that we not at min already
	cpi tmp1, 0
	breq Regulate_PWM_exit
	dec tmp1
	rjmp Regulate_PWM_update