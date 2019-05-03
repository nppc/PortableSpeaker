; PWM on OC1A pin (PB1)
; 250 Khz
init_PWM:
	cbi PORTB, PIN_PWM		; after reset it will be LOW,( but still, let's force it to LOW.
	sbi DDRB, PIN_PWM		; output
	out TCNT1, z0
	out OCR1A, z0			; no PWM
	cbr Charge_flags, 1<<Charge_flag_regulatePWM
	ldi tmp, (0<<CS13) | (0<<CS12) | (0<<CS11) | (1<<CS10) | (1<<PWM1A) | (1<<COM1A1) | (0<<COM1A0)	; prescaller 1; fast PWM on OC1A
	out TCCR1, tmp	
	; Enable 64mhz
	ldi tmp, (1<<PLLE)
	out PLLCSR, tmp
	; wait until clock stabilize (about 100us)
waitPLL:
	in tmp, PLLCSR
	sbrs tmp, PLOCK
	rjmp waitPLL
	ldi tmp, (1<<PCKE) | (1<<PLLE)
	out PLLCSR, tmp
	ret

; Reduce PWM immediately. this way we will protect our batteries
reduce_PWM:
	in tmp, OCR1A	; read current PWM
	cpi tmp, 0
	breq reduce_PWM_exit
	dec tmp
	out OCR1A, tmp
reduce_PWM_exit:
	ret

	; The routine checks measured voltage and compare it to the desired voltage (setVolt_tmp)
increase_PWM:
	; check flag PWM_flag_regulatePWM
	sbrs Charge_flags, Charge_flag_regulatePWM
	rjmp increase_PWM_exit
	cbr Charge_flags, (1<<Charge_flag_regulatePWM)	; clear flag
	in tmp1, OCR1A	; read current PWM
	; we increase PWM by 1.
	cpi tmp1, 255
	breq increase_PWM_exit
	inc tmp1
	out OCR1A, tmp1
increase_PWM_exit:
	ret
