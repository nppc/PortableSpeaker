; Vry good research of ws2812 timing was done here:
; https://cpldcpu.wordpress.com/2014/01/14/light_ws2812-library-v2-0-part-i-understanding-the-ws2812/
;

shortLED:
	ldi tmp1, 1<<PIN_LED
	mov tmp3, tmp1	; pin to trigger
	ldi tmp1, 7
	ldi ZL, LOW(byteR)
	ldi ZH, HIGH(byteR)
	ld tmp2, Z+
	cli
cont06:
	nop
cont07:
	;nop ; most probaby don't need as next cbi uses 2 cycles
	cbi PORTB, PIN_LED	; should work out PORTB, z0 ???????????
cont09:
	lsl tmp2
	out PINB, tmp3	; toggle to HIGH (out PORTB, z1)
	brcs skip03
	out PINB, tmp3	; toggle to LOW (out PORTB, z0)
skip03:
	dec tmp1
	brne cont06
	lsl tmp2
	;brcc Lx008
	; send last 1
	cbi PORTB, PIN_LED ; should work (out PORTB, z0) ; ??????????????
	ldi tmp1, 7
	out PINB, tmp3	; toggle to HIGH (out PORTB, z1)
	brcc Lx008
	ld tmp2, Z+
	dec tmp
	brne cont07
	rjmp brk18
	;send last 0
Lx008:	
	;cbi PORTB, PIN_LED ; should work (out PORTB, z0) ; ?????????????
	;ldi tmp1, 7
	;out PINB, tmp3	; toggle to HIGH (out PORTB, z1)
	;nop
	out PINB, tmp3	; toggle to LOW (out PORTB, z0)
	ld 	tmp2, Z+
	dec tmp
	brne cont09
brk18:
	cbi PORTB, PIN_LED ; just force ine down
	sei
	ret
	
;shortLED:
;	ldi tmp1, 1<<PIN_LED
;	mov tmp3, tmp1	; pin to trigger
;	ldi tmp1, 7
;	ldi ZL, LOW(byteR)
;	ldi ZH, HIGH(byteR)
;	ld tmp2, Z+
;	cli
;cont06:
;	nop
;cont07:
;	;nop ; most probaby don't need as next cbi uses 2 cycles
;	cbi PORTB, PIN_LED	; should work out PORTB, z0 ???????????
;cont09:
;	lsl tmp2
;	out PINB, tmp3	; toggle to HIGH (out PORTB, z1)
;	brcs skip03
;	out PINB, tmp3	; toggle to LOW (out PORTB, z0)
;skip03:
;	dec tmp1
;	brne cont06
;	lsl tmp2
;	brcc Lx008
;	; send last 1
;	cbi PORTB, PIN_LED ; should work (out PORTB, z0) ; ??????????????
;	ldi tmp1, 7
;	out PINB, tmp3	; toggle to HIGH (out PORTB, z1)
;	ld tmp2, Z+
;	dec tmp
;	brne cont07
;	rjmp brk18
;	;send last 0
;Lx008:	
;	cbi PORTB, PIN_LED ; should work (out PORTB, z0) ; ?????????????
;	ldi tmp1, 7
;	out PINB, tmp3	; toggle to HIGH (out PORTB, z1)
;	nop
;	out PINB, tmp3	; toggle to LOW (out PORTB, z0)
;	ld 	tmp2, Z+
;	dec tmp
;	brne cont09
;brk18:
;	cbi PORTB, PIN_LED ; just force ine down
;	sei
;	ret	

.MACRO SEND1COLOR
	out PINB, tmp1	;0.125us - toggle HIGH
	sbrc tmp,7
	LPM
	out PINB, tmp1	;0.125us - toggle LOW
	sbrs tmp,7
	LPM
	out PINB, tmp1	;0.125us - toggle HIGH
	sbrc tmp,6
	LPM
	out PINB, tmp1	;0.125us - toggle LOW
	sbrs tmp,6
	LPM
	out PINB, tmp1	;0.125us - toggle HIGH
	sbrc tmp,5
	LPM
	out PINB, tmp1	;0.125us - toggle LOW
	sbrs tmp,5
	LPM
	out PINB, tmp1	;0.125us - toggle HIGH
	sbrc tmp,4
	LPM
	out PINB, tmp1	;0.125us - toggle LOW
	sbrs tmp,4
	LPM
	out PINB, tmp1	;0.125us - toggle HIGH
	sbrc tmp,3
	LPM
	out PINB, tmp1	;0.125us - toggle LOW
	sbrs tmp,3
	LPM
	out PINB, tmp1	;0.125us - toggle HIGH
	sbrc tmp,2
	LPM
	out PINB, tmp1	;0.125us - toggle LOW
	sbrs tmp,2
	LPM
	out PINB, tmp1	;0.125us - toggle HIGH
	sbrc tmp,1
	LPM
	out PINB, tmp1	;0.125us - toggle LOW
	sbrs tmp,1
	LPM
	out PINB, tmp1	;0.125us - toggle HIGH
	sbrc tmp,0
	LPM
	out PINB, tmp1	;0.125us - toggle LOW
	sbrs tmp,0
	LPM
.ENDMACRO


ws2812_init:
	#ifdef DEBUG
		; enable output for power LED from I2c connector
		sbi DDRB, PB2
		sbi PORTB, PB2
	#endif
	; initialize pin
	sbi DDRB, PIN_LED
	cbi PORTB, PIN_LED
	; clear SRAM location
	ret

; send 3 bytes of data GRB (high first)
sendColor:
	ldi tmp1, 1<<PIN_LED
	cli
	ldi tmp, 1
	SEND1COLOR	; Green
	ldi tmp, 10
	SEND1COLOR	; Red
	ldi tmp, 0
	SEND1COLOR	; Blue
	clr z0		; restore z0 register as it will be corrupted
	sei
	ret

sendColor_new:
	ldi tmp, 1
	sts byteR, tmp
	ldi tmp, 10
	sts byteG, tmp
	ldi tmp, 0
	sts byteB, tmp
	ldi tmp, 3 ; bytes to send
	rcall shortLED
	ret

	
; preset colors for debug
#ifdef DEBUG	
	.EQU	color_intense = 200
	debug_off:
		sts byteR, z0
		sts byteG, z0
		sts byteB, z0
		rjmp sendColor

	debug_red:
		ldi tmp, color_intense
		sts byteR, tmp
		sts byteG, z0
		sts byteB, z0
		rjmp sendColor

	debug_green:
		ldi tmp, color_intense
		sts byteR, z0
		sts byteG, tmp
		sts byteB, z0
		rjmp sendColor

	debug_blue:
		ldi tmp, color_intense
		sts byteR, z0
		sts byteG, z0
		sts byteB, tmp
		rjmp sendColor

	debug_white:
		ldi tmp, color_intense
		sts byteR, tmp
		sts byteG, tmp
		sts byteB, tmp
		rjmp sendColor

	debug_violet:
		ldi tmp, color_intense
		sts byteR, tmp
		sts byteG, z0
		sts byteB, tmp
		rjmp sendColor

	debug_yellow:
		ldi tmp, color_intense
		sts byteR, tmp
		sts byteG, tmp
		sts byteB, z0
		rjmp sendColor

	debug_cyan:
		ldi tmp, color_intense
		sts byteR, z0
		sts byteG, tmp
		sts byteB, tmp
		rjmp sendColor
#endif


;setBit:
;	; 0.85us+0.4us
;	; we assume that state of the pin is LOW
;	sbi PINB, PIN_LED 	;0.250us - HIGH
;	nop					;0.125us
;	nop					;0.125us
;	nop					;0.125us
;	nop					;0.125us
;	sbi PINB, PIN_LED 	;0.250us - LOW
;	ret
;
;clearBit:
;	; 0.4us+0.85us
;	; we assume that state of the pin is LOW
;	sbi PINB, PIN_LED 	;0.250us - HIGH
;	nop					;0.125us
;	nop					;0.125us
;	sbi PINB, PIN_LED 	;0.250us - LOW
;	nop					;0.125us
;	nop					;0.125us
;	ret


