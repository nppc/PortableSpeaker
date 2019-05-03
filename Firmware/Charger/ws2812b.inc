.MACRO SEND1COLOR_V2
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

.MACRO SEND1COLOR
	lsl tmp
	out PINB, tmp1		;0.125us - toggle HIGH
	brcc nop8			;0.125us
	nop					;0.125us
	nop					;0.125us
	nop					;0.125us
nop8:
	out PINB, tmp1	
	brcs wsend8
	nop
	nop
	nop
wsend8:
	lsl tmp
	out PINB, tmp1		;0.125us - toggle HIGH
	brcc nop7			;0.125us
	nop					;0.125us
	nop					;0.125us
	nop					;0.125us
nop7:
	out PINB, tmp1	
	brcs wsend7
	nop
	nop
	nop
wsend7:
	lsl tmp
	out PINB, tmp1		;0.125us - toggle HIGH
	brcc nop6			;0.125us
	nop					;0.125us
	nop					;0.125us
	nop					;0.125us
nop6:
	out PINB, tmp1	
	brcs wsend6
	nop
	nop
	nop
wsend6:	
	lsl tmp
	out PINB, tmp1		;0.125us - toggle HIGH
	brcc nop5			;0.125us
	nop					;0.125us
	nop					;0.125us
	nop					;0.125us
nop5:
	out PINB, tmp1	
	brcs wsend5
	nop
	nop
	nop
wsend5:
	lsl tmp
	out PINB, tmp1		;0.125us - toggle HIGH
	brcc nop4			;0.125us
	nop					;0.125us
	nop					;0.125us
	nop					;0.125us
nop4:
	out PINB, tmp1	
	brcs wsend4
	nop
	nop
	nop
wsend4:
	lsl tmp
	out PINB, tmp1		;0.125us - toggle HIGH
	brcc nop3			;0.125us
	nop					;0.125us
	nop					;0.125us
	nop					;0.125us
nop3:
	out PINB, tmp1	
	brcs wsend3
	nop
	nop
	nop
wsend3:
	lsl tmp
	out PINB, tmp1		;0.125us - toggle HIGH
	brcc nop2			;0.125us
	nop					;0.125us
	nop					;0.125us
	nop					;0.125us
nop2:
	out PINB, tmp1	
	brcs wsend2
	nop
	nop
	nop
wsend2:
	lsl tmp
	out PINB, tmp1		;0.125us - toggle HIGH
	brcc nop1			;0.125us
	nop					;0.125us
	nop					;0.125us
	nop					;0.125us
nop1:
	out PINB, tmp1	
	brcs wsend1
	nop
	nop
	nop
wsend1:
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
	;cbi PORTB, PIN_LED ; make sure it LOW
	ldi tmp1, 1<<PIN_LED
	;ldi tmp, 8			; bits per byte
	;mov tmp2,tmp		; counter for G
	;mov tmp3,tmp		; counter for R
	;mov tmp4,tmp		; counter for B
	cli
	; send G color
	;lds tmp, byteG		;0.250us
	ldi tmp, 1
	SEND1COLOR_V2	; Green
	ldi tmp, 10
	SEND1COLOR_V2	; Red
	ldi tmp, 0
	SEND1COLOR_V2	; Blue
	clr z0		; restore z0 register as it will be corrupted
	sei
	ret
;loop_G:
;	lsl tmp				; shift bit to C flag
;	sbi PORTB, PIN_LED 	;0.250us - HIGH
;	brcc skpnopG		;0.125us
;	nop					;0.125us
;	nop					;0.125us
;skpnopG:
;	cbi PORTB, PIN_LED 	;0.250us - LOW
;	dec tmp2			;0.125us
;	brne loop_G			;0.125us
;
;	; send R color
;	;lds tmp, byteR		;0.250us
;	ldi tmp, 0
;loop_R:
;	lsl tmp				; shift bit to C flag
;	; clear or set bit according to flag C
;	out PINB, tmp1		;0.125us - toggle HIGH
;	;sbi PORTB, PIN_LED 	;0.250us - HIGH
;	brcc skpnopR		;0.125us
;	nop
;	nop
;	nop
;skpnopR:
;	out PINB, tmp1		;0.125us - toggle LOW
;	;cbi PORTB, PIN_LED 	;0.250us - LOW
;	dec tmp3			;0.125us
;	brne loop_R			;0.125us
;
;	; send B color
;	;lds tmp, byteB		;0.250us
;loop_B:
;;	lsl tmp				; shift bit to C flag
;;	; clear or set bit according to flag C
;;	sbi PORTB, PIN_LED 	;0.250us - HIGH
;;	brcc skpnopB		;0.125us
;;	nop					;0.125us
;;	nop					;0.125us
;;skpnopB:
;;	cbi PORTB, PIN_LED 	;0.250us - LOW
;;	dec tmp4			;0.125us
;;	brne loop_B			;0.125us
;;	sei
;	sbi PORTB, PIN_LED
;	nop
;	nop
;	nop
;	cbi PORTB, PIN_LED
;	nop
;	sbi PORTB, PIN_LED
;	nop
;	cbi PORTB, PIN_LED
;	nop
;	nop
;	nop
;	sbi PORTB, PIN_LED
;	nop
;	cbi PORTB, PIN_LED
;	nop
;	nop
;	nop
;	sbi PORTB, PIN_LED
;	nop
;	cbi PORTB, PIN_LED
;	nop
;	nop
;	nop
;	sbi PORTB, PIN_LED
;	nop
;	cbi PORTB, PIN_LED
;	nop
;	nop
;	nop
;	sbi PORTB, PIN_LED
;	nop
;	cbi PORTB, PIN_LED
;	nop
;	nop
;	nop
;	sbi PORTB, PIN_LED
;	nop
;	cbi PORTB, PIN_LED
;	nop
;	nop
;	nop
;	sbi PORTB, PIN_LED
;	nop
;	cbi PORTB, PIN_LED
;	nop
;	nop
;	nop
;	ret
	
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


