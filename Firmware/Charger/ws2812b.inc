; send 3 bytes of data GRB (high first)
sendColor:
	cbi PORTB, PIN_LED ; make sure it LOW
	ldi tmp1, 1<<PIN_LED
	ldi tmp, 8			; bits per byte
	mov tmp2,tmp		; counter for G
	mov tmp3,tmp		; counter for R
	mov tmp4,tmp		; counter for B
	cli
	; send G color
	;lds tmp, byteG		;0.250us
	ldi tmp, 200
loop_G:
	lsl tmp				; shift bit to C flag
	; clear or set bit according to flag C
	sbi PORTB, PIN_LED 	;0.250us - HIGH
	brcc skpnopG		;0.125us
	nop					;0.125us
	nop					;0.125us
skpnopG:
	cbi PORTB, PIN_LED 	;0.250us - LOW
	dec tmp2			;0.125us
	brne loop_G			;0.125us

	; send R color
	;lds tmp, byteR		;0.250us
	ldi tmp, 0
loop_R:
	lsl tmp				; shift bit to C flag
	; clear or set bit according to flag C
	out PINB, tmp1		;0.125us - toggle HIGH
	;sbi PORTB, PIN_LED 	;0.250us - HIGH
	brcc skpnopR		;0.125us
	nop
	nop
	nop
skpnopR:
	out PINB, tmp1		;0.125us - toggle LOW
	;cbi PORTB, PIN_LED 	;0.250us - LOW
	dec tmp3			;0.125us
	brne loop_R			;0.125us

	; send B color
	;lds tmp, byteB		;0.250us
loop_B:
;	lsl tmp				; shift bit to C flag
;	; clear or set bit according to flag C
;	sbi PORTB, PIN_LED 	;0.250us - HIGH
;	brcc skpnopB		;0.125us
;	nop					;0.125us
;	nop					;0.125us
;skpnopB:
;	cbi PORTB, PIN_LED 	;0.250us - LOW
;	dec tmp4			;0.125us
;	brne loop_B			;0.125us
;	sei
	sbi PORTB, PIN_LED
	nop
	nop
	nop
	cbi PORTB, PIN_LED
	nop
	sbi PORTB, PIN_LED
	nop
	cbi PORTB, PIN_LED
	nop
	nop
	nop
	sbi PORTB, PIN_LED
	nop
	cbi PORTB, PIN_LED
	nop
	nop
	nop
	sbi PORTB, PIN_LED
	nop
	cbi PORTB, PIN_LED
	nop
	nop
	nop
	sbi PORTB, PIN_LED
	nop
	cbi PORTB, PIN_LED
	nop
	nop
	nop
	sbi PORTB, PIN_LED
	nop
	cbi PORTB, PIN_LED
	nop
	nop
	nop
	sbi PORTB, PIN_LED
	nop
	cbi PORTB, PIN_LED
	nop
	nop
	nop
	sbi PORTB, PIN_LED
	nop
	cbi PORTB, PIN_LED
	nop
	nop
	nop
	ret
	
; preset colors for debug
#ifdef DEBUG	
debug_off:
	sts byteR, z0
	sts byteG, z0
	sts byteB, z0
	rjmp sendColor

debug_red:
	ldi tmp, 255
	sts byteR, tmp
	sts byteG, z0
	sts byteB, z0
	rjmp sendColor

debug_green:
	ldi tmp, 1
	sts byteR, tmp
	sts byteG, tmp
	sts byteB, z0
	rjmp sendColor

debug_blue:
	ldi tmp, 255
	sts byteR, z0
	sts byteG, z0
	sts byteB, tmp
	rjmp sendColor

debug_white:
	ldi tmp, 255
	sts byteR, tmp
	sts byteG, tmp
	sts byteB, tmp
	rjmp sendColor

debug_violet:
	ldi tmp, 255
	sts byteR, tmp
	sts byteG, z0
	sts byteB, tmp
	rjmp sendColor

debug_yellow:
	ldi tmp, 100
	sts byteR, tmp
	sts byteG, tmp
	sts byteB, z0
	rjmp sendColor

debug_cyan:
	ldi tmp, 255
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


