; LiIon Charger firmware
; based on UDCBuckHW.asm
;
; Author : Pavel
;

#define DEBUG

;#define	MOVINGAVERAGE ; comment it if not needed
.EQU	MOVINGAVERAGE_N = 5 ; can be 3, 5 or 7.


.include "tn85def.inc"

; Pins assignment
.EQU	PIN_LED		= PB0	; WS2812B pin
.EQU	PIN_PWM		= PB1	; PWM to Buck mosfet driver
;.EQU	PIN_SCL		= PB2	; I2C_SCL
.EQU	PIN_Isense	= PB3	; Current measurement (analog signal)
.EQU	PIN_Vsense	= PB4	; Voltage measurement (analog signal)


; variables assignment
.def	z0			=	r0
.def	z1			=	r1
.def	r_sreg		=	r2	; Store SREG register in interrupts
.def	tmp			=	r16
.def	tmp1		=	r17
.def	tmp2		=	r3
.def	tmp3		=	r4
.def	tmp4		=	r5
.def	itmp		=	r18	; variables to use in interrupts
.def	itmp1		=	r19	; variables to use in interrupts
.def	itmp2		=	r6	; variables to use in interrupts
.def	itmp3		=	r7	; variables to use in interrupts
.def	tmpL1		=	r8	; temp register for 16 bit calculations
.def	tmpH1		=	r9	; temp register for 16 bit calculations
.def	tmpL2		=	r10	; temp register for 16 bit calculations
.def	tmpH2		=	r11	; temp register for 16 bit calculations
.def	ADC_counter	=	r20	; Flags for ADC. Refer to ADC.inc for details
.def	setVolt_tmp	=	r12	; For smooth change of preset voltage
.def	V_chg_const	=	r13	; Converted value for timer0 from Voltage_Change SRAM
.def	Voltage_Set	=	r21	; Voltage for Buck output (V*10)
.def	SchedulerCnt=	r14	; Counter for scheduler
.def	PWM_flags	=	r22	; Flags for generating PWM 
; YH:YL 
; ZH:ZL for general use in main loop
.DSEG
.ORG SRAM_START
;USI_dataBuffer:				.BYTE USI_DATALEN	; USI bytes buffer
;USI_buffer_updateStatus:	.BYTE 1	; 1 - Buffer updated with new data, 0 - data is read by main loop
; Variables (R/W)
Voltage_Change:				.BYTE 1 ; (V*10). Before using this variable, we need to convert it for timer0 counter
Voltage_Min:				.BYTE 1 ; (V*10)
Voltage_Max:				.BYTE 1 ; (V*10)
; Variables (R)
Voltage_Measured:			.BYTE 2 ; (V*100)
Current_Measured:			.BYTE 1 ; (C*10)
ADC_Current_zero_RAW:		.BYTE 2	; ADC value when no load (0.0A)
#ifdef MOVINGAVERAGE
M_AVERAGE_voltage_COUNTER:	.BYTE 1	 ; Counter in the table
M_AVERAGE_voltage_TABLE:	.BYTE MOVINGAVERAGE_N * 2 ; Table for running moving average algorithm (max 14 bytes).
M_AVERAGE_current_COUNTER:	.BYTE 1	 ; Counter in the table
M_AVERAGE_current_TABLE:	.BYTE MOVINGAVERAGE_N * 2 ; Table for running moving average algorithm (max 14 bytes).
#endif
; RGB bytes
byteR:						.BYTE 1
byteG:						.BYTE 1
byteB:						.BYTE 1

.CSEG
.ORG 0

	; Interrupt vectors
	rjmp RESET ; Reset Handler
	reti	;rjmp EXT_INT0 ; IRQ0 Handler
	reti	;PCINT0 External Interrupt Request 1
	reti	;TIMER1 COMPA Timer/Counter1 Compare Match A
	reti	;TIMER1 OVF Timer/Counter1 Overflow
	reti	;TIMER0 OVF Timer/Counter0 Overflow
	reti	;EE_RDY EEPROM Ready
	reti	;ANA_COMP Analog Comparator
	reti	;ADC_INT ;ADC Conversion Complete
	reti	;TIMER1 COMPB Timer/Counter1 Compare Match B
	rjmp TMR0_COMPA ; Timer/Counter0 Compare Match A
	reti	;TIMER0 COMPB Timer/Counter0 Compare Match B
	reti	;WDT
	reti	;rjmp USI_start	; USI start
	reti	;rjmp USI_ovf	; USI Overflow

	
.include "PWM.inc"
.include "ADC.inc"
.include "MovAverage.inc"
.include "math.inc"
.include "scheduler.inc"
.include "ws2812b.inc"
;.include "EEPROM.inc"
.include "main.inc"

RESET:
	cli


	;initialize constants
	clr z0
	clr z1
	inc z1

	rcall ws2812_init
	
	clr Voltage_Set	; At the beginning it is always 0.
	
	ldi tmp, 1<<CLKPCE	
	out CLKPR, tmp		; enable clock change
	out CLKPR, z0		; prescaler 1

	ldi tmp, high(RAMEND) 
	out SPH,tmp				; Set Stack Pointer to top of RAM
	ldi tmp, low(RAMEND)
	out SPL,tmp				; Set Stack Pointer to top of RAM

	;rcall EEPROM_restoreSettings

	rcall init_PWM	; Initialize FET controlling with PWM
	#ifdef MOVINGAVERAGE
		rcall init_Moving_Average
	#endif
	rcall init_ADC			; Initialize V and I measuring
	rcall init_Scheduler	; Initialize scheduler for smooth change to desired voltage


	; this call should be the last before enabling interrupts and entering main loop
	rcall Scheduler_start	

	sbi ADCSRA, ADSC
	
	sei
	
	#ifdef DEBUG
		;rcall sendColor
		;rcall debug_off
		;rcall debug_yellow
	#endif
	; set LED color to GREEN
	
loop:
	rcall sendColor
	
	ldi tmp, 255
loop1:
	dec tmp
	brne loop1
	
	rjmp loop
	; wait for ADC complete
	sbic ADCSRA, ADSC
	rjmp loop
	rcall ADC_Read

	rcall Regulate_PWM
	
	rjmp loop
