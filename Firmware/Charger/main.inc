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

; charging process
; first safety checks
; then try to increase pwm
DoCharge:
	; Are we charging?
	sbrc Charge_flags, Charge_flag_Charging
	rjmp Charging
	; should we start charge?
	lds tmpL1, Voltage_Measured
	lds tmpH1, Voltage_Measured+1
	ldi tmp, LOW(TRIGGER_CHARGE_VOLTAGE)
	ldi tmp1, HIGH(TRIGGER_CHARGE_VOLTAGE)
	cp tmpL1, tmp
	cpc tmpH1, tmp1
	brlo Charging	; start charging
	rjmp DoCharge_exit

Charging:
	sbr Charge_flags, 1<<Charge_flag_Charging ; start charging
	; check that voltage not higher than CELLS * 4.2V * 100
	lds tmpL1, Voltage_Measured
	lds tmpH1, Voltage_Measured+1
	ldi tmp, LOW(CELLS * 420 + 1)
	ldi tmp1, HIGH(CELLS * 420 + 1)
	cp tmpL1, tmp
	cpc tmpH1, tmp1
	brlo ChargeVoltageSafe
	; Maybe we need to finish charge?
	; Check cutoff Current
	lds tmpL1, Current_Measured
	lds tmpH1, Current_Measured+1
	ldi tmp, LOW(CHARGE_CUTOFF)
	ldi tmp1, HIGH(CHARGE_CUTOFF)
	cp tmpL1, tmp
	cpc tmpH1, tmp1
	brlo Charging_Competed
	; we need continue to charge, but reduce PWM
	rcall reduce_PWM	; reduce PWM
ChargeVoltageSafe:
	; Check Current
	lds tmpL1, Current_Measured
	lds tmpH1, Current_Measured+1
	ldi tmp, LOW(CHARGE_CURRENT)
	ldi tmp1, HIGH(CHARGE_CURRENT)
	cp tmpL1, tmp
	cpc tmpH1, tmp1
	brlo ChargeCurrentSafe
	rcall reduce_PWM	; reduce PWM
ChargeCurrentSafe:
	rcall increase_PWM	; 1 unit per 1ms
DoCharge_exit:
	ret

Charging_Competed:
	; need to clear flag Charge_flag_Charging  when fully charged
	cbr Charge_flags, 1<<Charge_flag_Charging
	out OCR1A, z0	; turn off PWM
	rjmp DoCharge_exit


; Indicate charging process
Charging_Status_LED:
	; if not charging, then show the battery status (green)
	sbrs Charge_flags, Charge_flag_Charging
	rjmp LED_status_Green
	; if charging - show charging state
	; CC (control Current) - RED
	; CV (control Voltage) - ORANGE
	; CHARGE_CUTOFF * 2 - BLINK GREEN

	ret
LED_status_Green:
	ldi tmp, 50
	sts byteR, tmp
	ldi tmp, 150
	sts byteG, tmp
	sts byteB, z0
	rjmp wsLED

LED_status_Orange:
	ldi tmp, 100
	sts byteR, tmp
	ldi tmp, 50
	sts byteG, tmp
	sts byteB, z0
	rjmp wsLED
