;#########################################################
;			 			Обучение
;#########################################################
.include "m48def.inc"   ; Используем ATMega48
		
		.def temp = R16
		.def temp1 = R17
		.def temp2 = R18
		.def temp3 = R19
		.def LED = R20
		.def tempM = R24
		.def tempS = R23
	
		.equ ddrout = DDRD
		.equ portout = PORTD

;= Start macro.inc ========================================
 
; Тут будут наши макросы, потом.
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

;= End macro.inc  ========================================
 
 
; RAM =====================================================
		.DSEG			; Сегмент ОЗУ

 
; FLASH ===================================================
		.CSEG			; Кодовый сегмент
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
; Interrupts =====================================================


	PCINT1_OK:
	
	rcall INTERRUPT_DISABLE

	push temp

	rcall DELAY
	in temp, PINC
	sbrs temp, 3
	rjmp END

	sbrc LED, 0
	ror LED
	ror LED

	END:
	pop temp
	out portout, LED

	rcall INTERRUPT_ENABLE

	reti

;program body ============================================
					
	RESET:

	ldi temp, low(RAMEND)
	out SPL, temp
	
	ldi temp, high(RAMEND)
	out SPH, temp

	rcall INTERRUPT_ENABLE	

	MOVP ddrout, 0xFF
	MOVP DDRC, 0x00
	MOVP PORTC, 0x7F

	rcall INIT
			
	MAIN:	
	rjmp MAIN
	
; Область функций =========================================

	DELAY:
	push temp1
	push temp2
	push temp3
	ldi temp1, 20
wt1:
	dec temp1
	breq END_DELAY
	ldi temp2, 0xFF
wt2:
	dec temp2
	breq wt1
	ldi temp3, 0xFF
wt3:
	dec temp3
	brne wt3
	rjmp wt2
END_DELAY:
	pop temp3
	pop temp2
	pop temp1

	ret
;##########################################################
	INIT:
	
	rcall DELAY
	ldi LED, 0b00000001

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
	.ESEG			; Сегмент EEPROM
