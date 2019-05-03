; Flag PWM_flags
; bit 7 - Regulate PWM - bit sets every 1ms indicating that we can compare voltages and adjust PWM.
.EQU	PWM_flag_regulatePWM = 7

; Convert ADC RAW voltage to real voltage
; Remember, that raw ADC is multiplied by 2!
Convert_VoltageADC_to_Volt:
	#ifdef MOVINGAVERAGE
		ldi ZL, LOW(M_AVERAGE_voltage_COUNTER)
		ldi ZH, HIGH(M_AVERAGE_voltage_COUNTER)
		rcall moving_average
	#endif
	; Value is ready for converting to Volts (actually mV*10 eg 1200 = 12.00V)
	; The formula is: ADC * 64 / 2 / VOLT_DIV_CONST
	ldi tmp, 5
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
; Remember, that raw ADC is multiplied by 2!
Convert_CurrentADC_to_Current:
	#ifdef MOVINGAVERAGE
		ldi ZL, LOW(M_AVERAGE_current_COUNTER)
		ldi ZH, HIGH(M_AVERAGE_current_COUNTER)
		rcall moving_average
	#endif
	; Value is ready for converting to Current (actually mA*10 eg 550 = 5.5A)
	; ADC_Current_zero_RAW - reference for 0.0A
	; The formula is: (ADC-ADC_Current_zero_RAW)*(4/2)*32/CURRENT_DIV_CONST
	lds tmpL1, ADC_Current_zero_RAW
	lds tmpH1, ADC_Current_zero_RAW+1
	sub tmp2, tmpL1
	sbc tmp3, tmpH1
	brcc convert_C_notminus
	clr tmp2	; if minus, then 0
	clr tmp3	; if minus, then 0
convert_C_notminus:
	; Result should be lower than 1024, otherwise it will overflow
	ldi tmp, high(1024)
	cp tmp2, z0
	cpc tmp3, tmp
	brlo convert_C_nooverflow
	ldi tmp, low(1023)
	mov tmp2, tmp
	ldi tmp, high(1023)
	mov tmp3, tmp
convert_C_nooverflow:
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
	rcall div16u	; result in tmpH1:tmpL1
	sts Current_Measured, tmpL1
	sts Current_Measured+1, tmpH1
convert_C_exit:
	ret

; ***** TODO *****
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