;#########################################################
;						STUDY
;#########################################################
.include "m48def.inc"   ; ATMega48
		
		.def temp = R16
		.def temp1 = R17
		.def temp2 = R18
		.def temp3 = R19
		.def LED = R20
		.def tempM = R24
		.def tempS = R23
	
		.equ ddrout = DDRD
		.equ portout = PORTD

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
	

;		End macro.inc  ========================================
 
 
; 		RAM =====================================================
		.DSEG
 
; 		FLASH ===================================================
		.CSEG			
						; Interrupt vectors
		.ORG $000		; RESET
		rjmp RESET	
		
		.ORG $001 		; INT0
		;rjmp INT0_OK
		reti
					
		.ORG $002		; INT1
		;rjmp INT1_OK				
		reti
		.ORG $003		; PCINT0
		reti
		.ORG $004
		rjmp PCINT1_OK	; PCINT1
		;reti
		.ORG $005		; PCINT2
		reti
		
		.ORG $006		; WDT
		reti
						; TIMER2
		.ORG $007		; COMPA
		reti
		.ORG $008		; COMPB
		reti
		.ORG $009		; OVF
		reti
						; TIMER1
		.ORG $00A		; CAPT
		reti
		.ORG $00B		; COMPA
		reti
		.ORG $00C		; COMPB
		reti
		.ORG $00D		; OVF
		reti
						; TIMER0
		.ORG $00E		; COMPA
		reti
		.ORG $00F		; COMPB
		reti
		.ORG $010		; OVF
		reti
		.ORG $011		; SPI
		reti
						; USART
		.ORG $012		; RX
		reti
		.ORG $013		; UDRE
		reti
		.ORG $014		; TX
		reti
		
		.ORG $015		; ADC
		reti

		.ORG $016		; EEREADY
		reti

		.ORG $017		; ANALOG COMP
		reti
		
		.ORG $018		; TWI
		reti
		
		.ORG $019		; SPMRE
		reti
		
						; End interrupt table.
;   Interrupts =====================================================


	PCINT1_OK:
	
	rcall INTERRUPT_DISABLE

	push temp

	rcall DELAY
	in temp, PINC
	sbrs temp, 3
	rjmp END

	sbrc LED, 0 ; main action
	ror LED 
	ror LED

	END:
	
	out portout, LED ; end main action
	pop temp
	rcall INTERRUPT_ENABLE 

	reti

;   Program ============================================
					
	RESET:
	
	ldi temp, low(RAMEND)
	out SPL, temp
	
	ldi temp, high(RAMEND)
	out SPH, temp
	
	rcall MCU_INIT

	rcall INTERRUPT_ENABLE	

	MOVP ddrout, 0xFF
	MOVP DDRC, 0x00
	MOVP PORTC, 0x7F

	rcall INIT
			
	MAIN:	
	rjmp MAIN
	
;	Function =========================================

	DELAY:
	push temp1
	push temp2
	push temp3
	ldi temp1, 19
	ldi temp2, 0xFF
	ldi temp3, 0xFF
	WAIT:
	subi temp3, 1
	sbci temp2, 0
	sbci temp1, 0
	brcc WAIT
	pop temp3
	pop temp2
	pop temp1
	clc

	ret

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
	
	ldi ZL,Low(IOEND+1)
	ldi ZH,High(IOEND+1)
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
	INIT: 
	
	rcall DELAY
	ldi LED, 0b10000000
	out portout, LED

	ret
;##########################################################

	INTERRUPT_DISABLE:
	
	cli
	push temp
	ldi temp, 0
	sts PCICR, temp
	sts PCMSK1, temp
	pop temp

	ret

;##########################################################

	INTERRUPT_ENABLE:

	push temp

	ldi temp, 0b00000010
	sts PCICR, temp
	ldi temp, 0xFF
	sts PCMSK1, temp

	clr temp
	sts PCIFR, temp
	pop temp

	sei

	ret

; EEPROM ==================================================
	.ESEG			;  EEPROM
