;#########################################################
;						HEART
;#########################################################
.include "tn13def.inc"   ; ATMega48
		
		.def temp = R16
		.def temp1 = R17
		.def counterH = R18
		.def counterL = R19
		.def SPEED = R20
		.def tempM = R24
		.def tempS = R23
	
		.equ ddrout = DDRB
		.equ portout = PORTB
		.equ portin = PINB
;		 Start macro.inc ========================================

.MACRO MOVP
	
	ldi tempM, @1
	out @0, tempM

.ENDM 

.MACRO LDIL
	
	ldi tempM, @1
	mov @0, tempM

.ENDM

.MACRO PUSHK 

	ldi tempM, @0
	push tempM

.ENDM

.MACRO UOUT
	
	.IF		@0 < 0x40
	
	out @0, @1
	
	.ELSE
	
	sts @0, @1
	
	.ENDIF
.ENDM
	

;		End macro.inc  =====================================

; 		RAM ================================================ 

.DSEG


; 		FLASH ===================================================
		.CSEG			
						; Interrupt vectors
		.ORG $000		; RESET
		rjmp RESET	
		
		.ORG $001 		; INT0
		;rjmp INT0_OK
		reti
					
		.ORG $002		; PCINT0
		;rjmp PCINT0_OK
		reti
		
		.ORG $003		; OVF
		;rjmp TIM0_OVF
		reti
		
		.ORG $004		; EEREADY
		reti
		
		.ORG $005		; ANALOG COMP
		reti
		
		.ORG $006		; COMPA
		reti
		.ORG $007		; COMPB
		reti
		
		.ORG $008		; WDT
		reti
		
		.ORG $009		; ADC
		reti


;#######################################################################
		PCINT0_OK:
	
		rcall INTERRUPT_DISABLE
	
		push temp
	
		rcall DELAY
		in temp, PINB
		sbrs temp, 0
		rjmp END

		ldi temp, 0x01
		add SPEED, temp

		END:
	
		rcall INTERRUPT_ENABLE 
	
		pop temp
	
		reti
; 	Program ============================================================
		
	RESET:

	ldi temp, RAMEND
	out SPL, temp
	
	rcall MCU_INIT
	
	MOVP DDRB, 0b00011110
	MOVP PORTB, 0b00011111		
	ldi SPEED, 0x01
	
	clr temp1
	
	main:
	
	ldi temp, 0b00011110
	eor temp1, temp
	out portout, temp1
	
	rcall DELAY
	in temp, PINB
	sbrc temp, 0
	rjmp main
	rcall DELAY
	ldi temp, 0b00000001
	eor SPEED, temp
	rjmp main 
		
;	Functions ==========================================================

;##########################################################
	MCU_INIT:
	
	LDIL R0, 0
	LDIL R1, 0
	LDIL R2, 0
	LDIL R3, 0
	LDIL R4, 0
	LDIL R5, 0
	LDIL R6, 0
	LDIL R7, 0
	LDIL R8, 0
	LDIL R9, 0
	LDIL R10, 0
	LDIL R11, 0
	LDIL R12, 0
	LDIL R13, 0
	LDIL R14, 0
	LDIL R15, 0
	ldi R16, 0
	ldi R17, 0
	ldi R18, 0
	ldi R19, 0
	ldi R20, 0
	ldi R21, 0
	ldi R22, 0
	ldi R23, 0
	ldi R24, 0
	ldi R25, 0
	ldi R26, 0
	ldi R27, 0
	ldi R28, 0
	ldi R29, 0
	ldi r30, 0
	ldi R31, 0
	
	RAM_FLUSH:
	
	ldi ZL,Low(0x5f+1)
	ldi ZH,High(0x5f+1)
	clr R16
	
	FLUSH:

	st Z+, R16

	cpi ZH, High(RAMEND-1)
	brne FLUSH
	
	cpi ZL, Low(RAMEND-1)
	brne FLUSH 
	
	clr ZL
	clr ZH
	
	ret

;##########################################################


	INTERRUPT_DISABLE:
	
	cli
	push temp
	ldi temp, 0
	sts GIMSK, temp
	sts GIFR, temp
	sts PCMSK, temp
	pop temp

	ret

;#######################################################################

	TIMER_INIT:
	
	push temp
	
	ldi temp, (1<<TOIE0)
	sts TIMSK0, temp 
	
	clr temp
	out TCNT0, temp
	
	ldi temp, 0b00000001
	out TCCR0B, temp
	
	ldi counterL, 0x12
	mov counterH, SPEED
	
	pop temp
	
	ret
;###################################################################
	
	TIMER_STOP:
	
	push temp
	
	clr temp
	out TCNT0, temp
	
	ldi temp, 0b00000000
	out TCCR0B, temp
	
	pop temp
	
	ret

;#######################################################################

	INTERRUPT_ENABLE:
	
	push temp
	
	ldi temp, 0b00100000
	sts GIMSK, temp

	ldi temp, 0b00000001
	sts PCMSK, temp

	clr temp
	sts GIFR, temp
	pop temp
	
	sei
	
	ret

;#######################################################################
	DELAY:
	push temp1
	push counterH
	push counterL
	mov temp1, SPEED
	ldi counterH, 0xFF
	ldi counterL, 0xFF
	WAIT:
	subi counterL, 1
	sbci counterH, 0
	sbci temp1, 0
	brcc WAIT
	pop counterL
	pop counterH
	pop temp1
	clc

	ret

;##########################################################
; EEPROM ==================================================
	.ESEG			;  EEPROM
		

