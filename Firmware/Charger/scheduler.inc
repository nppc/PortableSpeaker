; For scheduler we will use Timer0, that overflows every 1ms.
; At 8Mhz divider is 1/64 and overflow value is 125 (OCR0A).
init_Scheduler:
	; Halt the timer
	ldi tmp, (1<<TSM) | (1<<PSR0)
	out GTCCR, tmp		; we don't care about timer1 as GTCCR is not used there
	; Configure timer in CTC mode and prescaller
	ldi tmp, (1<<WGM01) | (0<<WGM00)
	out TCCR0A, tmp
	ldi tmp, (0<<WGM02) | (0<<CS02) | (1<<CS01) | (1<<CS00)
	out TCCR0B, tmp
	out TCNT0, z0
	; Set top value to match 1ms.
	ldi tmp, 125
	out OCR0A, tmp
	; Enable interrupt 
	ldi tmp, (1<<OCIE0A)
	out TIMSK, tmp		; we don't care about timer1 interrupts as we don't use them. 
	ret
	
	
Scheduler_start:
	; start timer when everything else configured and ready
	ldi tmp, (0<<TSM)
	out GTCCR, tmp		; we don't care about timer1 as GTCCR is not used there
	ret
	
; interrupt for timer0 counting (every 1ms)
TMR0_COMPA:
	in r_sreg, SREG
	sbr Charge_flags, (1<<Charge_flag_regulatePWM)	; We adjust PWM every 1ms.
	out SREG, r_sreg
	reti
