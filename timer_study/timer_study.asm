;##############################################################################
;                                      by proffk                              #
;##############################################################################

.include "m48def.inc"                     ; using m48
;=============================================================================+
; definition section

    .def temp = r16      
    .def counter = r20
    .def flag = r21
    .def delay_time = r22
    .equ out_ddr = ddrd
    .equ out_port = portd
    .equ in_ddr = ddrc
    .equ in_port = portc
    .equ in_pin = pinc
    
;=============================================================================-
; ram
.dseg
; flash
.cseg

;=============================================================================+
; interrupt table
; for mega48
    .org 0x00                         
    rjmp reset

    .org 0x01
    ;rjmp int0                         
    reti

    .org 0x02
    ;rjmp int1  
    reti

    .org 0x03
    ;rjmp pcint0_ok
    reti

    .org 0x04
    rjmp pcint1_ok
    ;reti

    .org 0x05
    ;rjmp pcint2_ok
    reti

    .org 0x06
    ;rjmp wdt
    reti

    .org 0x07
    ;rjmp timer2_compa
    reti

    .org 0x08
    ;rjmp timer2_compb
    reti

    .org 0x09
    ;rjmp timer2_ovf
    reti

    .org 0x0a
    ;rjmp timer1_capt
    reti

    .org 0x0b
    rjmp timer1_compa
    ;reti

    .org 0x0c
    ;rjmp timer1_compb
    reti

    .org 0x0d
    ;rjmp timer1_ovf
    reti 
    
    .org 0x0e
    ;rjmp timer0_compa
    reti

    .org 0x0f
    ;rjmp timer0_compb
    reti

    .org 0x10
    rjmp timer0_ovf
    ;reti

    .org 0x11
    ;rjmp spi
    reti

    .org 0x12
    ;rjmp usart_rx
    reti

    .org 0x13
    ;rjmp usart_udre
    reti

    .org 0x14
    ;rjmp usart_tx
    reti

    .org 0x15
    ;rjmp adc
    reti

    .org 0x16
    ;rjmp eee_ready
    reti

    .org 0x17
    ;rjmp anal_comp
    reti

    .org 0x18
    ;rjmp twi
    reti

    .org 0x19
    ;rjmp spmre
    reti

;end interrupt table
;==============================================================================
;interrupts

pcint1_ok:
        clr temp                       ; disable interrupts
        sts pcicr, temp
        
        sbrs flag, 0
        rjmp push_pin
        cbr flag, 1

        lpm
        mov counter, r0                    ; action
        tst r0, r0
        brne pcint1_out
        ldi zh, high(mode_1*2)
        ldi zl, low(mode_1*2) 
        lpm 
        mov counter, r0

pcint1_out:
        clr temp
        inc zl
        adc zh, temp
        out out_port, counter

pcint_end:
        ldi delay_time, 50
        rjmp end_int
push_pin:
        sbr flag, 1
        ldi delay_time, 80
end_int:
        ldi temp, (1<<cs02)
        out tccr0b, temp
        reti


timer0_ovf:
        dec delay_time
        breq end_count
        reti
end_count:
        clr temp
        out tccr0b, temp
        sts pcifr, temp
        ldi temp, (1<<pcie1)
        sts pcicr, temp
        reti

timer1_compa:
 
        lpm
        mov counter, r0                    ; action
        tst r0, r0
        brne timer1_out
        ldi zh, high(mode_2*2)
        ldi zl, low(mode_2*2) 
        lpm 
        mov counter, r0

timer1_out:
        clr temp
        inc zl
        adc zh, temp
        out out_port, counter 
        sts tcnt1h, temp
        sts tcnt1l, temp
        reti


;end interrupts
;==============================================================================

reset:
        ldi temp, low(ramend)          ; stack init
        out spl, temp
        ldi temp, high(ramend)
        out sph, temp           

ram_flush:
        ldi zl, low(ioend)
        ldi zh, high(ioend)
        clr temp
flush:
        st  z+, temp
        cpi zh, high(ramend + 1)
        brne flush
        cpi zl, low(ramend + 1)
        brne flush
        
        ldi zl, 30			
        clr	zh		
        dec	zl		
        st 	z, zh		
        brne pc-2
        
        clr temp 
        out in_ddr, temp
        ldi temp, (1<<pinc3)
        out in_port, temp
        ser temp
        out out_ddr, temp 
        
        ldi temp, (1<<pcie1)
        sts pcicr, temp
        ldi temp, (1<<pcint11)
        sts pcmsk1, temp

        ldi temp, (1<<toie1)
        sts timsk0, temp
        ldi temp, (1<<ocie1a)
        sts timsk1, temp


        ldi temp, high(31125)
        sts ocr1ah, temp
        ldi temp, low(31125)
        sts ocr1al, temp

        ldi temp, (1<<cs12)
        sts tccr1b, temp
        
        ldi counter, 1
        out out_port, counter

        ldi zh, high(mode_2*2)
        ldi zl, low(mode_2*2) 
        sei
        nop
        nop
        nop
        nop
        nop     
main:
        rjmp main

mode_1:  .db   0b00000001,\
               0b00000010,\
               0b00000100,\
               0b00001000,\
               0b00010000,\
               0b00100000,\
               0b01000000,\
               0b10000000,\
               0,0
mode_2:  .db   0b10000001,\
               0b01000010,\
               0b00100100,\
               0b00011000,\
               0b00011000,\
               0b00100100,\
               0b01000010,\
               0b10000001,\
               0,0
mode_3:  .db   0b00000001, 0b00000010,\ 
               0b00000100, 0b00001000,\
               0b00010000, 0b00100000,\ 
               0b01000000, 0b10000000,\ 
               0b01000000, 0b00100000,\
               0b00010000, 0b00001000,\ 
               0b00000100, 0b00000010,\
               0  
;==============================================================================
;Subroutines

;End Subroutines
;==============================================================================
        


