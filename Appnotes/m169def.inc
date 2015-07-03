;***************************************************************************
;* A P P L I C A T I O N   N O T E   F O R   T H E   A V R   F A M I L Y
;* 
;* Number           : AVR000
;* File Name        : "m169def.inc"
;* Title            : Register/Bit Definitions for the ATmega169
;* Date             : June 14th, 2001
;* Version          : 2.0
;* Support E-mail   : support@atmel.no
;* Target MCU       : ATmega169
;*
;* DESCRIPTION
;* When including this file in the assembly program file, all I/O register  
;* names and I/O register bit names appearing in the data book can be used.
;* In addition, the six registers forming the three data pointers X, Y and
;* Z have been assigned names XL - ZH. Highest RAM address for Internal 
;* SRAM is also defined 
;*
;* The Register names are represented by their hexadecimal address.
;* 
;* The Register Bit names are represented by their bit number (0-7).
;* 
;* Please observe the difference in using the bit names with instructions
;* such as "sbr"/"cbr" (set/clear bit in register) and "sbrs"/"sbrc" 
;* (skip if bit in register set/cleared). The following example illustrates
;* this:
;* 
;* in   r16,PORTB       ;read PORTB latch
;* sbr  r16,(1<<PB6)+(1<<PB5)   ;set PB6 and PB5 (use masks, not bit#)
;* out  PORTB,r16       ;output to PORTB
;*
;* in   r16,TIFR        ;read the Timer Interrupt Flag Register
;* sbrc r16,TOV0        ;test the overflow flag (use bit#)
;* rjmp TOV0_is_set     ;jump if set
;* ...              ;otherwise do something else
;***************************************************************************

;**** Specify Device ****
.device ATmega169

;*****************************************************************************
; I/O Register Definitions
;*****************************************************************************

;**** Memory Mapped I/O Register Definitions  (0xFF-0x60) ****
.equ  LCDDR18   = 0xFE
.equ  LCDDR17   = 0xFD 
.equ  LCDDR16   = 0xFC
.equ  LCDDR15   = 0xFB
.equ  LCDDR13   = 0xF9 
.equ  LCDDR12   = 0xF8
.equ  LCDDR11   = 0xF7
.equ  LCDDR10   = 0xF6 
.equ  LCDDR8    = 0xF4
.equ  LCDDR7    = 0xF3
.equ  LCDDR6    = 0xF2
.equ  LCDDR5    = 0xF1 
.equ  LCDDR3    = 0xEF
.equ  LCDDR2    = 0xEE
.equ  LCDDR1    = 0xED 
.equ  LCDDR0    = 0xEC
.equ  LCDCCR    = 0xE7
.equ  LCDFRR    = 0xE6
.equ  LCDCRB    = 0xE5
.equ  LCDCRA    = 0xE4
.equ  UDR       = 0xC6  
.equ  UBRRH     = 0xC5  
.equ  UBRRL     = 0xC4  
.equ  UCSRC     = 0xC2
.equ  UCSRB     = 0xC1
.equ  UCSRA     = 0xC0
.equ  USIDR     = 0xBA
.equ  USISR     = 0xB9
.equ  USICR     = 0xB8
.equ  ASSR      = 0xB6
.equ  OCR2A     = 0xB3  
.equ  TCNT2     = 0xB2  
.equ  TCCR2A    = 0xB0
.equ  OCR1BH    = 0x8B 
.equ  OCR1BL    = 0x8A 
.equ  OCR1AH    = 0x89 
.equ  OCR1AL    = 0x88 
.equ  ICR1H     = 0x87 
.equ  ICR1L     = 0x86 
.equ  TCNT1H    = 0x85 
.equ  TCNT1L    = 0x84 
.equ  TCCR1C    = 0x82 
.equ  TCCR1B    = 0x81
.equ  TCCR1A    = 0x80
.equ  DIDR1     = 0x7F
.equ  DIDR0     = 0x7E
.equ  ADMUX     = 0x7C 
.equ  ADCSRB    = 0x7B
.equ  ADCSRA    = 0x7A
.equ  ADCH      = 0x79 
.equ  ADCL      = 0x78
.equ  TIMSK2    = 0x70
.equ  TIMSK1    = 0x6F
.equ  TIMSK0    = 0x6E
.equ  PCMSK1    = 0x6C
.equ  PCMSK0    = 0x6B 
.equ  EICRA     = 0x69 
.equ  OSCCAL    = 0x66
.equ  PRR       = 0x64
.equ  CLKPR     = 0x61
.equ  WDTCR     = 0x60
.equ  WDTCSR    = WDTCR

;**** I/O Register Definitions (0x3F-0x00) ****
.equ  SREG      = 0x3F
.equ  SPH       = 0x3E
.equ  SPL       = 0x3D
.equ  SPMCSR    = 0x37
.equ  MCUCR     = 0x35
.equ  MCUSR     = 0x34
.equ  SMCR      = 0x33
.equ  OCDR      = 0x31
.equ  ACSR      = 0x30
.equ  SPDR      = 0x2E 
.equ  SPSR      = 0x2D
.equ  SPCR      = 0x2C
.equ  GPIOR2    = 0x2B 
.equ  GPIOR1    = 0x2A 
.equ  OCR0A     = 0x27
.equ  TCNT0     = 0x26 
.equ  TCCR0A    = 0x24
.equ  GTCCR     = 0x23
.equ  EEARH     = 0x22 
.equ  EEARL     = 0x21 
.equ  EEDR      = 0x20
.equ  EECR      = 0x1F
.equ  GPIOR0    = 0x1E 
.equ  EIMSK     = 0x1D
.equ  EIFR      = 0x1C
.equ  TIFR2     = 0x17
.equ  TIFR1     = 0x16
.equ  TIFR0     = 0x15
.equ  PORTG     = 0x14
.equ  DDRG      = 0x13
.equ  PING      = 0x12
.equ  PORTF     = 0x11
.equ  DDRF      = 0x10
.equ  PINF      = 0x0F
.equ  PORTE     = 0x0E
.equ  DDRE      = 0x0D
.equ  PINE      = 0x0C
.equ  PORTD     = 0x0B
.equ  DDRD      = 0x0A
.equ  PIND      = 0x09
.equ  PORTC     = 0x08
.equ  DDRC      = 0x07
.equ  PINC      = 0x06
.equ  PORTB     = 0x05
.equ  DDRB      = 0x04
.equ  PINB      = 0x03
.equ  PORTA     = 0x02
.equ  DDRA      = 0x01
.equ  PINA      = 0x00

;*****************************************************************************
; Bit Definitions
;*****************************************************************************

; *** LCDDR18 ***
.equ SEG324     = 0

; *** LCDDR17 ***
.equ SEG323     = 7
.equ SEG322     = 6
.equ SEG321     = 5
.equ SEG320     = 4
.equ SEG319     = 3
.equ SEG318     = 2
.equ SEG317     = 1
.equ SEG316     = 0

; *** LCDDR16 ***
.equ SEG315     = 7
.equ SEG314     = 6
.equ SEG313     = 5
.equ SEG312     = 4
.equ SEG311     = 3
.equ SEG310     = 2
.equ SEG309     = 1
.equ SEG308     = 0

; *** LCDDR15 ***
.equ SEG307     = 7
.equ SEG306     = 6
.equ SEG305     = 5
.equ SEG304     = 4
.equ SEG303     = 3
.equ SEG302     = 2
.equ SEG301     = 1
.equ SEG300     = 0

; *** LCDDR13 ***
.equ SEG224     = 0

; *** LCDDR12 ***
.equ SEG223     = 7
.equ SEG222     = 6
.equ SEG221     = 5
.equ SEG220     = 4
.equ SEG219     = 3
.equ SEG218     = 2
.equ SEG217     = 1
.equ SEG216     = 0

; *** LCDDR11 ***
.equ SEG215     = 7
.equ SEG214     = 6
.equ SEG213     = 5
.equ SEG212     = 4
.equ SEG211     = 3
.equ SEG210     = 2
.equ SEG209     = 1
.equ SEG208     = 0

; *** LCDDR10 ***
.equ SEG207     = 7
.equ SEG206     = 6
.equ SEG205     = 5
.equ SEG204     = 4
.equ SEG203     = 3
.equ SEG202     = 2
.equ SEG201     = 1
.equ SEG200     = 0

; *** LCDDR8 ***
.equ SEG124     = 0

; *** LCDDR7 ***
.equ SEG123     = 7
.equ SEG122     = 6
.equ SEG121     = 5
.equ SEG120     = 4
.equ SEG119     = 3
.equ SEG118     = 2
.equ SEG117     = 1
.equ SEG116     = 0

; *** LCDDR6 ***
.equ SEG115     = 7
.equ SEG114     = 6
.equ SEG113     = 5
.equ SEG112     = 4
.equ SEG111     = 3
.equ SEG110     = 2
.equ SEG109     = 1
.equ SEG108     = 0

; *** LCDDR5 ***
.equ SEG107     = 7
.equ SEG106     = 6
.equ SEG105     = 5
.equ SEG104     = 4
.equ SEG103     = 3
.equ SEG102     = 2
.equ SEG101     = 1
.equ SEG100     = 0

; *** LCDDR3 ***
.equ SEG024     = 0

; *** LCDDR2 ***
.equ SEG023     = 7
.equ SEG022     = 6
.equ SEG021     = 5
.equ SEG020     = 4
.equ SEG019     = 3
.equ SEG018     = 2
.equ SEG017     = 1
.equ SEG016     = 0

; *** LCDDR1 ***
.equ SEG015     = 7
.equ SEG014     = 6
.equ SEG013     = 5
.equ SEG012     = 4
.equ SEG011     = 3
.equ SEG010     = 2
.equ SEG009     = 1
.equ SEG008     = 0

; *** LCDDR0 ***
.equ SEG007     = 7
.equ SEG006     = 6
.equ SEG005     = 5
.equ SEG004     = 4
.equ SEG003     = 3
.equ SEG002     = 2
.equ SEG001     = 1
.equ SEG000     = 0

; *** LCDCCR ***
.equ LCDDC2     = 7
.equ LCDDC1     = 6
.equ LCDDC0     = 5
.equ LCDCC3     = 3 
.equ LCDCC2     = 2
.equ LCDCC1     = 1
.equ LCDCC0     = 0

; *** LCDFRR *** 
.equ LCDPS2     = 6 
.equ LCDPS1     = 5
.equ LCDPS0     = 4
.equ LCDCD2     = 2
.equ LCDCD1     = 1
.equ LCDCD0     = 0
                
; *** LCDCRB ***
.equ LCDCS      = 7 
.equ LCD2B      = 6
.equ LCDMUX1    = 5 
.equ LCDMUX0    = 4
.equ LCDPM2     = 2
.equ LCDPM1     = 1
.equ LCDPM0     = 0
        
; *** LCDCRA ***
.equ LCDEN      = 7 
.equ LCDAB      = 6     
.equ LCDIF      = 4
.equ LCDIE      = 3
.equ LCDBL      = 0

; *** UCSRC ***
.equ UMSEL      = 6
.equ UPM1       = 5
.equ UPM0       = 4
.equ USBS       = 3
.equ UCSZ1      = 2
.equ UCSZ0      = 1
.equ UCPOL      = 0

; *** UCSRB ***
.equ RXCIE      = 7
.equ TXCIE      = 6
.equ UDRIE      = 5
.equ RXEN       = 4
.equ TXEN       = 3
.equ UCSZ2      = 2
.equ RXB8       = 1
.equ TXB8       = 0

; *** UCSRA ***
.equ RXC        = 7
.equ TXC        = 6
.equ UDRE       = 5
.equ FE         = 4
.equ DOR        = 3
.equ UPE        = 2
.equ U2X        = 1
.equ MPCM       = 0

; *** USISR ***
.equ USISIF     = 7  
.equ USIOIF     = 6
.equ USIPF      = 5
.equ USIDC      = 4
.equ USICNT3    = 3
.equ USICNT2    = 2
.equ USICNT1    = 1
.equ USICNT0    = 0

; *** USICR ***
.equ USISIE     = 7  
.equ USIOIE     = 6
.equ USIWM1     = 5
.equ USIWM0     = 4
.equ USICS1     = 3
.equ USICS0     = 2
.equ USICLK     = 1
.equ USITC      = 0
    
; *** ASSR ***
.equ EXCLK      = 4
.equ AS2        = 3  
.equ TCN2UB     = 2
.equ OCR2UB     = 1
.equ TCR2UB     = 0

; *** TCCR2A ***
.equ FOC2       = 7  
.equ WGM20      = 6
.equ COM2A1     = 5
.equ COM2A0     = 4
.equ WGM21      = 3
.equ CS22       = 2
.equ CS21       = 1
.equ CS20       = 0

; *** TCCR1C ***
.equ FOC1A      = 7  
.equ FOC1B      = 6

; *** TCCR1B ***
.equ ICNC1      = 7  
.equ ICES1      = 6
.equ WGM13      = 4
.equ WGM12      = 3
.equ CS12       = 2
.equ CS11       = 1
.equ CS10       = 0

; *** TCCR1A ***
.equ COM1A1     = 7  
.equ COM1A0     = 6
.equ COM1B1     = 5
.equ COM1B0     = 4
.equ WGM11      = 1
.equ WGM10      = 0

; *** DIDR1 ***
.equ ADC7D      = 7  
.equ ADC6D      = 6
.equ ADC5D      = 5
.equ ADC4D      = 4
.equ ADC3D      = 3
.equ ADC2D      = 2
.equ ADC1D      = 1
.equ ADC0D      = 0

; *** DIDR0 ***
.equ AIN1D      = 1  
.equ AIN0D      = 0

; *** ADMUX ***
.equ REFS1      = 7  
.equ REFS0      = 6
.equ ADLAR      = 5
.equ MUX4       = 4
.equ MUX3       = 3
.equ MUX2       = 2
.equ MUX1       = 1
.equ MUX0       = 0

; *** ADCSRB ***
.equ ACME       = 6
.equ ADTS2      = 2
.equ ADTS1      = 1
.equ ADTS0      = 0

; *** ADCSRA ***
.equ ADEN       = 7  
.equ ADSC       = 6
.equ ADATE      = 5
.equ ADIF       = 4
.equ ADIE       = 3
.equ ADPS2      = 2
.equ ADPS1      = 1
.equ ADPS0      = 0

; *** TIMSK2 ***
.equ OCIE2A     = 1
.equ TOIE2      = 0

; *** TIMSK1 ***
.equ ICIE1      = 5  
.equ OCIE1B     = 2
.equ OCIE1A     = 1
.equ TOIE1      = 0

; *** TIMSK0 ***
.equ OCIE0A     = 1
.equ TOIE0      = 0

; *** PCMSK1 ***
.equ PCINT15    = 7  
.equ PCINT14    = 6
.equ PCINT13    = 5
.equ PCINT12    = 4
.equ PCINT11    = 3
.equ PCINT10    = 2
.equ PCINT9     = 1
.equ PCINT8     = 0

; *** PCMSK0 ***
.equ PCINT7     = 7  
.equ PCINT6     = 6
.equ PCINT5     = 5
.equ PCINT4     = 4
.equ PCINT3     = 3
.equ PCINT2     = 2
.equ PCINT1     = 1
.equ PCINT0     = 0

; *** EICRA ***
.equ ISC01      = 1
.equ ISC00      = 0

; *** PRR ***
.equ PRLCD      = 4
.equ PRTIM1     = 3
.equ PRSPI      = 2
.equ PRUSART0   = 1
.equ PRADC      = 0

; *** CLKPR ***
.equ CLKPCE     = 7  
.equ CLKPS3     = 3
.equ CLKPS2     = 2
.equ CLKPS1     = 1
.equ CLKPS0     = 0

; *** WDTCR ***
.equ WDCE       = 4  
.equ WDE        = 3
.equ WDP2       = 2
.equ WDP1       = 1
.equ WDP0       = 0

; *** SREG ***
.equ I          = 7  
.equ T          = 6
.equ H          = 5
.equ S          = 4
.equ V          = 3
.equ N          = 2
.equ Z          = 1
.equ C          = 0

; *** SPH ***
.equ SP15       = 7  
.equ SP14       = 6
.equ SP13       = 5
.equ SP12       = 4
.equ SP11       = 3
.equ SP10       = 2
.equ SP9        = 1
.equ SP8        = 0

; *** SPL ***
.equ SP7        = 7  
.equ SP6        = 6
.equ SP5        = 5
.equ SP4        = 4
.equ SP3        = 3
.equ SP2        = 2
.equ SP1        = 1
.equ SP0        = 0

; *** SPMCSR ***
.equ SPMIE      = 7  
.equ RWWSB      = 6
.equ RWWSRE     = 4
.equ BLBSET     = 3
.equ PGWRT      = 2
.equ PGERS      = 1
.equ SPMEN      = 0

; *** MCUCR ***
.equ JTD        = 7  
.equ PUD        = 4
.equ IVSEL      = 1
.equ IVCE       = 0

; *** MCUSR ***
.equ JTRF       = 4  
.equ WDRF       = 3
.equ BORF       = 2
.equ EXTRF      = 1
.equ PORF       = 0

; *** SMCR ***
.equ SM2        = 3  
.equ SM1        = 2
.equ SM0        = 1
.equ SE         = 0

; *** OCDR ***
.equ IDRD       = 7  
.equ OCD        = 7
.equ OCDR6      = 6
.equ OCDR5      = 5
.equ OCDR4      = 4
.equ OCDR3      = 3
.equ OCDR2      = 2
.equ OCDR1      = 1
.equ OCDR0      = 0

; *** ACSR ***
.equ ACD        = 7  
.equ ACBG       = 6
.equ ACO        = 5
.equ ACI        = 4
.equ ACIE       = 3
.equ ACIC       = 2
.equ ACIS1      = 1
.equ ACIS0      = 0

; *** SPSR ***
.equ SPIF       = 7  
.equ WCOL       = 6
.equ SPI2X      = 0

; *** SPCR ***
.equ SPIE       = 7 
.equ SPE        = 6
.equ DORD       = 5
.equ MSTR       = 4
.equ CPOL       = 3
.equ CPHA       = 2
.equ SPR1       = 1
.equ SPR0       = 0

; *** TCCR0A ***
.equ FOC0A      = 7 
.equ WGM00      = 6
.equ COM0A1     = 5
.equ COM0A0     = 4
.equ WGM01      = 3
.equ CS02       = 2
.equ CS01       = 1
.equ CS00       = 0

; *** GTCCR ***
.equ TSM        = 7  
.equ PSR2       = 1
.equ PSR10      = 0
                     
; *** EECR ***
.equ EERIE      = 3  
.equ EEMWE      = 2
.equ EEWE       = 1
.equ EERE       = 0

; *** EIMSK ***
.equ PCIE1      = 7
.equ PCIE0      = 6
.equ INT0       = 0

; *** EIFR ***
.equ PCIF1      = 7
.equ PCIF0      = 6
.equ INTF0      = 0

; *** TIFR2 ***
.equ OCF2A      = 1
.equ TOV2       = 0

; *** TIFR1 ***
.equ ICF1       = 5  
.equ OCF1B      = 2
.equ OCF1A      = 1
.equ TOV1       = 0

; *** TIFR0 ***
.equ OCF0A      = 1
.equ TOV0       = 0

; *** PORTG ***
.equ PORTG4     = 4
.equ PORTG3     = 3
.equ PORTG2     = 2
.equ PORTG1     = 1
.equ PORTG0     = 0
.equ PG4        = 4
.equ PG3        = 3
.equ PG2        = 2
.equ PG1        = 1
.equ PG0        = 0

; *** DDRG ***
.equ DDG4       = 4
.equ DDG3       = 3
.equ DDG2       = 2
.equ DDG1       = 1
.equ DDG0       = 0

; *** PING ***
.equ PING5      = 5
.equ PING4      = 4
.equ PING3      = 3
.equ PING2      = 2
.equ PING1      = 1
.equ PING0      = 0

; *** PORTF ***
.equ PORTF7     = 7  
.equ PORTF6     = 6
.equ PORTF5     = 5
.equ PORTF4     = 4
.equ PORTF3     = 3
.equ PORTF2     = 2
.equ PORTF1     = 1
.equ PORTF0     = 0
.equ PF7        = 7  
.equ PF6        = 6
.equ PF5        = 5
.equ PF4        = 4
.equ PF3        = 3
.equ PF2        = 2
.equ PF1        = 1
.equ PF0        = 0

; *** DDRF ***
.equ DDF7       = 7  
.equ DDF6       = 6
.equ DDF5       = 5
.equ DDF4       = 4
.equ DDF3       = 3
.equ DDF2       = 2
.equ DDF1       = 1
.equ DDF0       = 0

; *** PINF ***
.equ PINF7      = 7  
.equ PINF6      = 6
.equ PINF5      = 5
.equ PINF4      = 4
.equ PINF3      = 3
.equ PINF2      = 2
.equ PINF1      = 1
.equ PINF0      = 0

; *** PORTE ***
.equ PORTE7     = 7  
.equ PORTE6     = 6
.equ PORTE5     = 5
.equ PORTE4     = 4
.equ PORTE3     = 3
.equ PORTE2     = 2
.equ PORTE1     = 1
.equ PORTE0     = 0
.equ PE7        = 7  
.equ PE6        = 6
.equ PE5        = 5
.equ PE4        = 4
.equ PE3        = 3
.equ PE2        = 2
.equ PE1        = 1
.equ PE0        = 0

; *** DDRE ***
.equ DDE7       = 7  
.equ DDE6       = 6
.equ DDE5       = 5
.equ DDE4       = 4
.equ DDE3       = 3
.equ DDE2       = 2
.equ DDE1       = 1
.equ DDE0       = 0

; *** PINE ***
.equ PINE7      = 7  
.equ PINE6      = 6
.equ PINE5      = 5
.equ PINE4      = 4
.equ PINE3      = 3
.equ PINE2      = 2
.equ PINE1      = 1
.equ PINE0      = 0

; *** PORTD ***
.equ PORTD7     = 7  
.equ PORTD6     = 6
.equ PORTD5     = 5
.equ PORTD4     = 4
.equ PORTD3     = 3
.equ PORTD2     = 2
.equ PORTD1     = 1
.equ PORTD0     = 0
.equ PD7        = 7  
.equ PD6        = 6
.equ PD5        = 5
.equ PD4        = 4
.equ PD3        = 3
.equ PD2        = 2
.equ PD1        = 1
.equ PD0        = 0

; *** DDRD ***
.equ DDD7       = 7  
.equ DDD6       = 6
.equ DDD5       = 5
.equ DDD4       = 4
.equ DDD3       = 3
.equ DDD2       = 2
.equ DDD1       = 1
.equ DDD0       = 0

; *** PIND ***
.equ PIND7      = 7  
.equ PIND6      = 6
.equ PIND5      = 5
.equ PIND4      = 4
.equ PIND3      = 3
.equ PIND2      = 2
.equ PIND1      = 1
.equ PIND0      = 0

; *** PORTC ***
.equ PORTC7     = 7  
.equ PORTC6     = 6
.equ PORTC5     = 5
.equ PORTC4     = 4
.equ PORTC3     = 3
.equ PORTC2     = 2
.equ PORTC1     = 1
.equ PORTC0     = 0
.equ PC7        = 7  
.equ PC6        = 6
.equ PC5        = 5
.equ PC4        = 4
.equ PC3        = 3
.equ PC2        = 2
.equ PC1        = 1
.equ PC0        = 0

; *** DDRC ***
.equ DDC7       = 7  
.equ DDC6       = 6
.equ DDC5       = 5
.equ DDC4       = 4
.equ DDC3       = 3
.equ DDC2       = 2
.equ DDC1       = 1
.equ DDC0       = 0

; *** PINC ***
.equ PINC7      = 7  
.equ PINC6      = 6
.equ PINC5      = 5
.equ PINC4      = 4
.equ PINC3      = 3
.equ PINC2      = 2
.equ PINC1      = 1
.equ PINC0      = 0

; *** PORTB ***
.equ PORTB7     = 7  
.equ PORTB6     = 6
.equ PORTB5     = 5
.equ PORTB4     = 4
.equ PORTB3     = 3
.equ PORTB2     = 2
.equ PORTB1     = 1
.equ PORTB0     = 0
.equ PB7        = 7  
.equ PB6        = 6
.equ PB5        = 5
.equ PB4        = 4
.equ PB3        = 3
.equ PB2        = 2
.equ PB1        = 1
.equ PB0        = 0

; *** DDRB ***
.equ DDB7       = 7  
.equ DDB6       = 6
.equ DDB5       = 5
.equ DDB4       = 4
.equ DDB3       = 3
.equ DDB2       = 2
.equ DDB1       = 1
.equ DDB0       = 0

; *** PINB ***
.equ PINB7      = 7  
.equ PINB6      = 6
.equ PINB5      = 5
.equ PINB4      = 4
.equ PINB3      = 3
.equ PINB2      = 2
.equ PINB1      = 1
.equ PINB0      = 0

; *** PORTA ***
.equ PORTA7     = 7  
.equ PORTA6     = 6
.equ PORTA5     = 5
.equ PORTA4     = 4
.equ PORTA3     = 3
.equ PORTA2     = 2
.equ PORTA1     = 1
.equ PORTA0     = 0
.equ PA7        = 7  
.equ PA6        = 6
.equ PA5        = 5
.equ PA4        = 4
.equ PA3        = 3
.equ PA2        = 2
.equ PA1        = 1
.equ PA0        = 0

; *** DDRA ***
.equ DDA7       = 7  
.equ DDA6       = 6
.equ DDA5       = 5
.equ DDA4       = 4
.equ DDA3       = 3
.equ DDA2       = 2
.equ DDA1       = 1
.equ DDA0       = 0

; *** PINA ***
.equ PINA7      = 7  
.equ PINA6      = 6
.equ PINA5      = 5
.equ PINA4      = 4
.equ PINA3      = 3
.equ PINA2      = 2
.equ PINA1      = 1
.equ PINA0      = 0

;*****************************************************************************
; CPU Register Declarations
;*****************************************************************************

.def    XL  = r26       ; X pointer low
.def    XH  = r27       ; X pointer high
.def    YL  = r28       ; Y pointer low
.def    YH  = r29       ; Y pointer high
.def    ZL  = r30       ; Z pointer low
.def    ZH  = r31       ; Z pointer high


;*****************************************************************************
; Data Memory Declarations
;*****************************************************************************

.equ    RAMEND    = 0x04FF  ; Highest internal data memory (SRAM) address.
                            ;(1k RAM + IO + REG)
.equ    EEPROMEND = 0x01FF  ; Highest EEPROM address.
                            ;(512 byte)
;*****************************************************************************
; Program Memory Declarations
;*****************************************************************************

.equ    FLASHEND  = 0x1FFF  ;  Highest program memory (flash) address
                            ; (When addressed as 16 bit words)
                            ; ( 8k words , 16k byte ) 
        
;**** Boot Vectors ****
                        ;   byte groups
                        ;  /--\/--\/--\/--\ 
.equ    SMALLBOOTSTART  =0b0001111110000000  ;(0x1F80) smallest boot block is 128W
.equ    SECONDBOOTSTART =0b0001111100000000  ;(0x1F00) second boot block size is 256W
.equ    THIRDBOOTSTART  =0b0001111000000000  ;(0x1E00) third boot block size is 512W
.equ    LARGEBOOTSTART  =0b0001110000000000  ;(0x1C00) largest boot block is 1024W

;**** Page Size ****
.equ    PAGESIZE    = 64    ;number of WORDS in a page

;*****************************************************************************
;**** Interrupt Vectors ****        
;*****************************************************************************
.equ    INT0addr      = 0x002   ;External Interrupt 0 Vector
.equ    PCINT0addr    = 0x004   ;Pin Change 0 Interrupt Vector 
.equ    PCINT1addr    = 0x006   ;Pin Change 1 Interrupt Vector
.equ    OC2addr       = 0x008   ;Timer/Counter2 Compare Match Interrupt Vector
.equ    OVF2addr      = 0x00A   ;Timer/Counter2 Overflow Interrupt Vector
.equ    ICP1addr      = 0x00C   ;Timer/Counter1 Capture Event Interrupt Vector
.equ    OC1Aaddr      = 0x00E   ;Timer/Counter1 Compare Match A Interrupt Vector
.equ    OC1Baddr      = 0x010   ;Timer/Counter1 Compare Match B Interrupt Vector 
.equ    OVF1addr      = 0x012   ;Timer/Counter1 Overflow Interrupt Vector
.equ    OC0addr       = 0x014   ;Timer/Counter0 Compare Match Interrupt Vector
.equ    OVF0addr      = 0x016   ;Timer/Counter0 Overflow Interrupt Vector
.equ    SPIaddr       = 0x018   ;SPI Serial Transfer Complete Interrupt Vector
.equ    URXC0addr     = 0x01A   ;USART, Rx Complete Interrupt Vector
.equ    UDRE0addr     = 0x01C   ;USART, Data Register Empty Interrupt Vector
.equ    UTXC0addr     = 0x01E   ;USART, Tx Complete Interrupt Vector
.equ    USI_STARTaddr = 0x020   ;USI Start Condition Interrupt Vector   
.equ    USI_OVFaddr   = 0x022   ;USI Overflow Interrupt Vector  
.equ    ACIaddr       = 0x024   ;Analog Comparator Interrupt Vector
.equ    ADCCaddr      = 0x026   ;ADC Conversion Complete Interrupt Vector
.equ    ERDYaddr      = 0x028   ;EEPROM Ready Interrupt Vector
.equ    SPMRaddr      = 0x02A   ;Store Program Memory Ready Interrupt Vector
.equ    LCDSFaddr     = 0x02C   ;LCD Start of Frame Interrupt Vector

;*****************************************************************************
;UART/USART/USART0 compatibility
;*****************************************************************************
.equ UMSEL0     = UMSEL  
.equ UPM01      = UPM1 
.equ UPM00      = UPM0 
.equ USBS0      = USBS 
.equ UCSZ01     = UCSZ1
.equ UCSZ00     = UCSZ0
.equ UCPOL0     = UCPOL
.equ RXCIE0     = RXCIE  
.equ TXCIE0     = TXCIE
.equ UDRIE0     = UDRIE
.equ RXEN0      = RXEN 
.equ TXEN0      = TXEN 
.equ UCSZ02     = UCSZ2
.equ RXB80      = RXB8 
.equ TXB80      = TXB8 
.equ RXC0       = RXC   
.equ TXC0       = TXC 
.equ UDRE0      = UDRE
.equ FE0        = FE  
.equ DOR0       = DOR 
.equ UPE0       = UPE
.equ U2X0       = U2X 
.equ MPCM0      = MPCM

.equ UDR0       = UDR
.equ UBRR0H     = UBRRH
.equ UBRR0L     = UBRRL
.equ UBRR0      = UBRRL
.equ UBRR       = UBRRL
.equ UCSR0C     = UCSRC
.equ UCSR0B     = UCSRB
.equ UCR        = UCSRB
.equ UCSR0A     = UCSRA
.equ USR        = UCSRA

.equ URXCaddr   = URXC0addr
.equ UDREaddr   = UDRE0addr
.equ UTXCaddr   = UTXC0addr

