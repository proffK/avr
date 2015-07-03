;##############################################################################
;                                      by ProffK                              #
;##############################################################################

.include <template_mk.inc>                     ; Using template_mk

;=============================================================================+
; Definition section

    .def temp = R16                    
    .def out_ddr = 
    .def out_port = 
    .def in_ddr = 
    .def in_port = 
   `.def in_pin = 
    
;=============================================================================-
; RAM
.DSEG

; FLASH
.CSEG

;=============================================================================+
; Interrupt table
/* For Mega48
    .ORG 0x00                         
    rjmp RESET

    .ORG 0x01
    ;rjmp INT0                         
    reti

    .ORG 0x02
    ;rjmp INT1  
    reti

    .ORG 0x03
    ;rjmp PCINT0_OK
    reti

    .ORG 0x04
    ;rjmp PCINT1_OK
    reti

    .ORG 0x05
    ;rjmp PCINT2_OK
    reti

    .ORG 0x06
    ;rjmp WDT
    reti

    .ORG 0x07
    ;rjmp TIMER2_COMPA
    reti

    .ORG 0x08
    ;rjmp TIMER2_COMPB
    reti

    .ORG 0x09
    ;rjmp TIMER2_OVF
    reti

    .ORG 0x0A
    ;rjmp TIMER1_CAPT
    reti

    .ORG 0x0B
    ;rjmp TIMER1_COMPA
    reti

    .ORG 0x0C
    ;rjmp TIMER1_COMPB
    reti

    .ORG 0x0D
    ;rjmp TIMER1_OVF
    reti 
    
    .ORG 0x0E
    ;rjmp TIMER0_COMPA
    reti

    .ORG 0x0F
    ;rjmp TIMER0_COMPB
    reti

    .ORG 0x10
    ;rjmp TIMER0_OVF
    reti

    .ORG 0x11
    ;rjmp SPI
    reti

    .ORG 0x12
    ;rjmp USART_RX
    reti

    .ORG 0x13
    ;rjmp USART_UDRE
    reti

    .ORG 0x14
    ;rjmp USART_TX
    reti

    .ORG 0x15
    ;rjmp ADC
    reti

    .ORG 0x16
    ;rjmp EEE_READY
    reti

    .ORG 0x17
    ;rjmp ANAL_COMP
    reti

    .ORG 0x18
    ;rjmp TWI
    reti

    .ORG 0x19
    ;rjmp SPMRE
    reti
*/
;End interrupt table
;==============================================================================
;Interrupts


;End Interrupts
;==============================================================================

RESET:
        ldi temp, low(RAMEND)          ; Stack init
        out SPL, temp
        ldi temp, high(RAMEND)
        out SPH, temp           

RAM_FLUSH:
        ldi ZL, low(IO_END)
        ldi ZH, high(IO_END)
        clr temp
FLUSH:
        st  Z+, temp
        cpi ZH, high(RAMEND + 1)
        brne FLUSH
        cpi ZL, low(RAMEND + 1)
        brne FLUSH
        
        LDI	ZL, 30			
        CLR	ZH		
        DEC	ZL		
        ST	Z, ZH		
        BRNE PC-2
        
MAIN:
        rjmp main
        
;==============================================================================
;Subroutines

;End Subroutines
;==============================================================================
        


