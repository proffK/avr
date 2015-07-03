;##############################################################################
;                                      by ProffK                              #
;##############################################################################

.include "m48def.inc"                    ; array

;=============================================================================+
; Definition section
    
    .def temp = R16
    .def counter = R17
    .def stop_digit = R18
    .def time_over_flag = R19
    .equ digit_port = PORTD
    .equ digit_ddr = DDRD
    .equ clk_port = PORTC
    .equ clk_ddr = DDRC
    .equ digit_num = 6
    
    
;=============================================================================-
; RAM
.DSEG
digit: .byte digit_num

; FLASH
.CSEG

;=============================================================================+
; Interrupt table
; For Mega48
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
    rjmp TIMER1_COMPA
    ;reti

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
    rjmp TIMER0_OVF
    ;reti

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

;End interrupt table
;==============================================================================
;Interrupts
        
TIMER0_OVF:
        
        ldi temp, 0
        out digit_port, temp
        sbis clk_port, digit_num - 1
        rjmp LAST_DIGIT
        lsl counter
        com counter
        out clk_port, counter
        com counter
CONTINUE:
        ld temp, -X
        rcall digit_convert
        out digit_port, temp
        reti

LAST_DIGIT:

        ldi counter, 0b00000001           ;if cur digit is last, then 
        com counter
        out clk_port, counter             ;input first digit
        com counter
        ldi XL, low(digit + digit_num)
        ldi XH, high(digit + digit_num)
        rjmp CONTINUE

TIMER1_COMPA:
        push XH
        push XL

        ldi XH, high(digit + digit_num)
        ldi XL, low(digit + digit_num)
        ldi stop_digit, 9
        rcall inc_time
        cpi time_over_flag, 0
        breq timer1_end
        ldi stop_digit, 5
        rcall inc_time
        cpi time_over_flag, 0
        breq timer1_end
        ldi stop_digit, 9
        rcall inc_time
        cpi time_over_flag, 0
        breq timer1_end
        ldi stop_digit, 5
        rcall inc_time
        cpi time_over_flag, 0
        breq timer1_end
        ldi stop_digit, 3
        rcall inc_time
        cpi time_over_flag, 0
        breq timer1_end
        ldi stop_digit, 2
        rcall inc_time
timer1_end:
        clr temp
        sts TCNT1H, temp
        sts TCNT1L, temp
        clr time_over_flag

        pop XL
        pop XH

        reti

;End Interrupts
;==============================================================================

RESET:
        ldi temp, low(RAMEND)          ; Stack init
        out SPL, temp
        ldi temp, high(RAMEND)
        out SPH, temp           

RAM_FLUSH:
        ldi ZL, low(IOEND)
        ldi ZH, high(IOEND)
        clr temp
FLUSH:
        st  Z+, temp
        cpi ZH, high(RAMEND + 1)
        brne FLUSH
        cpi ZL, low(RAMEND + 1)
        brne FLUSH
        
        ldi	ZL, 30			
        clr	ZH		
        dec	ZL		
        st	Z, ZH		
        brne PC-2
INIT:
        ldi temp, 0
        sts digit, temp
        ldi temp, 0
        sts digit + 1, temp

        ser temp
        out clk_ddr, temp
        out digit_ddr, temp
        
        ldi counter, (1 << (digit_num - 1))
        com counter
        out clk_port, counter
        com counter

        ;ldi XH, high(digit)
        ;ldi XL, low(digit)

        ;ld temp, X
        ;rcall digit_convert
        ;out digit_port, temp

        ldi temp, (1 << TOIE0)             ;Timer clk init
        sts TIMSK0, temp
        ldi temp, (1 << CS01|1 << CS00)
        out TCCR0B, temp

        ldi temp, (1 << OCIE1A)
        sts TIMSK1, temp
        ldi temp, (1 << CS12)
        sts TCCR1B, temp
        ldi temp, high(31125)
        sts OCR1AH, temp
        ldi temp, low(31125)
        sts OCR1AL, temp
        sei

        
MAIN:
        rjmp main


;==============================================================================
;Subroutines

inc_time:
        
        ld temp, -X
        cp temp, stop_digit
        brne time_not_end
        ldi temp, 0
        ldi time_over_flag, 1
        st X, temp
        ret
time_not_end:
        inc temp
        st X, temp
        ldi time_over_flag, 0
        ret
        

digit_convert:
        
        push ZH
        push ZL
        push r0
        ldi ZH, high(digit_array*2)
        ldi ZL, low(digit_array*2)
        add ZL, temp
        clr temp
        adc ZH, temp
        lpm
        mov temp, r0
        pop r0
        pop ZL
        pop ZH
        ret

digit_array:
        
        .db 0b00111111,\
            0b00000110,\
            0b01011011,\
            0b01001111,\
            0b01100110,\
            0b01101101,\
            0b01111101,\
            0b00000111,\
            0b01111111,\
            0b01101111
;End Subroutines
;==============================================================================
        


