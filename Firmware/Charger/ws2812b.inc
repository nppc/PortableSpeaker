; Vry good research of ws2812 timing was done here:
; https://cpldcpu.wordpress.com/2014/01/14/light_ws2812-library-v2-0-part-i-understanding-the-ws2812/
;

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


LED_off:
	sts byteR, z0
	sts byteG, z0
	sts byteB, z0
	rjmp wsLED


; about 30us per LED
wsLED:
	ldi tmp, 3 ; bytes to send
	ldi tmp1, 1<<PIN_LED
	mov tmp3, tmp1	; pin to trigger
	ldi tmp1, 7
	ldi ZL, LOW(byteG)
	ldi ZH, HIGH(byteG)
	ld tmp2, Z+
	cli
wsl01:
	nop
wsl02:
	cbi PORTB, PIN_LED
wsl03:
	lsl tmp2
	out PINB, tmp3
	brcs wsl04
	out PINB, tmp3
wsl04:
	dec tmp1
	brne wsl01
	lsl tmp2
	cbi PORTB, PIN_LED
	ldi tmp1, 7
	out PINB, tmp3
	brcc wsl05
	ld tmp2, Z+
	dec tmp
	brne wsl02
	rjmp wsl06
wsl05:	
	out PINB, tmp3
	ld 	tmp2, Z+
	dec tmp
	brne wsl03
wsl06:
	cbi PORTB, PIN_LED
	sei
	ret
	
	
; preset colors for debug
#ifdef DEBUG	
	.EQU	color_intense = 150

	debug_red:
		ldi tmp, color_intense
		sts byteR, tmp
		sts byteG, z0
		sts byteB, z0
		rjmp wsLED

	debug_green:
		ldi tmp, color_intense
		sts byteR, z0
		sts byteG, tmp
		sts byteB, z0
		rjmp wsLED

	debug_blue:
		ldi tmp, color_intense
		sts byteR, z0
		sts byteG, z0
		sts byteB, tmp
		rjmp wsLED

	debug_white:
		ldi tmp, color_intense
		sts byteR, tmp
		sts byteG, tmp
		sts byteB, tmp
		rjmp wsLED

	debug_violet:
		ldi tmp, color_intense
		sts byteR, tmp
		sts byteG, z0
		sts byteB, tmp
		rjmp wsLED

	debug_yellow:
		ldi tmp, color_intense
		sts byteR, tmp
		sts byteG, tmp
		sts byteB, z0
		rjmp wsLED

	debug_cyan:
		ldi tmp, color_intense
		sts byteR, z0
		sts byteG, tmp
		sts byteB, tmp
		rjmp wsLED
#endif
