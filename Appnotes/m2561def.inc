;***************************************************************************
;* A P P L I C A T I O N   N O T E   F O R   T H E   A V R   F A M I L Y
;* 
;* Number            : AVR000
;* File Name         : "m2561def.inc" 
;* Title             : Register/Bit Definitions for the ATMEGA2561 
;* Date              : 04.08.2004
;* Version           : 
;* Support E-mail    : avr@atmel.com
;* Target MCU        : ATMEGA2561 
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
;* in    r16,PORTB             ;read PORTB latch
;* sbr   r16,(1<<PB6)+(1<<PB5) ;set PB6 and PB5 (use masks, not bit#)
;* out   PORTB,r16             ;output to PORTB
;* 
;* in    r16,TIFR              ;read the Timer Interrupt Flag Register
;* sbrc  r16,TOV0              ;test the overflow flag (use bit#)
;* rjmp  TOV0_is_set           ;jump if set
;* ...                         ;otherwise do something else
;***************************************************************************

;***** SPECIFY DEVICE ******************************************************
.device ATmega2561
;***** MEMORY MAPPED I/O REGISTER DEFINITIONS (&FF-$60) ********************
.equ  OCR5CH     =$12D
.equ  OCR5CL     =$12C
.equ  OCR5BH     =$12B
.equ  OCR5BL     =$12A
.equ  OCR5AH     =$129
.equ  OCR5AL     =$128
.equ  ICR5H      =$127
.equ  ICR5L      =$126
.equ  TCNT5H     =$125
.equ  TCNT5L     =$124
.equ  TCCR5C     =$122
.equ  TCCR5B     =$121
.equ  TCCR5A     =$120
.equ  UDR1       =$CE
.equ  UBRR1H     =$CD
.equ  UBRR1L     =$CC
.equ  UCSR1C     =$CA
.equ  UCSR1B     =$C9
.equ  UCSR1A     =$C8
.equ  UDR0       =$C6
.equ  UBRR0H     =$C5
.equ  UBRR0L     =$C4
.equ  UCSR0C     =$C2
.equ  UCSR0B     =$C1
.equ  UCSR0A     =$C0
.equ  TWAMR      =$BD
.equ  TWCR       =$BC
.equ  TWDR       =$BB
.equ  TWAR       =$BA
.equ  TWSR       =$B9
.equ  TWBR       =$B8
.equ  ASSR       =$B6
.equ  OCR2B      =$B4
.equ  OCR2A      =$B3
.equ  TCNT2      =$B2
.equ  TCCR2B     =$B1
.equ  TCCR2A     =$B0
.equ  OCR4CH     =$AD
.equ  OCR4CL     =$AC
.equ  OCR4BH     =$AB
.equ  OCR4BL     =$AA
.equ  OCR4AH     =$A9
.equ  OCR4AL     =$A8
.equ  ICR4H      =$A7
.equ  ICR4L      =$A6
.equ  TCNT4H     =$A5
.equ  TCNT4L     =$A4
.equ  TCCR4C     =$A2
.equ  TCCR4B     =$A1
.equ  TCCR4A     =$A0
.equ  OCR3CH     =$9D
.equ  OCR3CL     =$9C
.equ  OCR3BH     =$9B
.equ  OCR3BL     =$9A
.equ  OCR3AH     =$99
.equ  OCR3AL     =$98
.equ  ICR3H      =$97
.equ  ICR3L      =$96
.equ  TCNT3H     =$95
.equ  TCNT3L     =$94
.equ  TCCR3C     =$92
.equ  TCCR3B     =$91
.equ  TCCR3A     =$90
.equ  OCR1CH     =$8D
.equ  OCR1CL     =$8C
.equ  OCR1BH     =$8B
.equ  OCR1BL     =$8A
.equ  OCR1AH     =$89
.equ  OCR1AL     =$88
.equ  ICR1H      =$87
.equ  ICR1L      =$86
.equ  TCNT1H     =$85
.equ  TCNT1L     =$84
.equ  TCCR1C     =$82
.equ  TCCR1B     =$81
.equ  TCCR1A     =$80
.equ  DIDR1      =$7F
.equ  DIDR0      =$7E
.equ  DIDR2      =$7D
.equ  ADMUX      =$7C
.equ  ADCSRB     =$7B
.equ  ADCSRA     =$7A
.equ  ADCH       =$79
.equ  ADCL       =$78
.equ  XMCRB      =$75
.equ  XMCRA      =$74
.equ  TIMSK5     =$73
.equ  TIMSK4     =$72
.equ  TIMSK3     =$71
.equ  TIMSK2     =$70
.equ  TIMSK1     =$6F
.equ  TIMSK0     =$6E
.equ  PCMSK2     =$6D
.equ  PCMSK1     =$6C
.equ  PCMSK0     =$6B
.equ  EICRB      =$6A
.equ  EICRA      =$69
.equ  PCICR      =$68
.equ  OSCCAL     =$66
.equ  PRR1       =$65
.equ  PRR0       =$64
.equ  CLKPR      =$61
.equ  WDTCSR     =$60

;***** I/O REGISTER DEFINITIONS ($3F-$00) **********************************
.equ  SREG       =$3F
.equ  SPH        =$3E
.equ  SPL        =$3D
.equ  EIND       =$3C
.equ  RAMPZ      =$3B
.equ  SPMCSR     =$37
.equ  MCUCR      =$35
.equ  MCUSR      =$34
.equ  SMCR       =$33
.equ  OCDR       =$31
.equ  ACSR       =$30
.equ  SPDR       =$2E
.equ  SPSR       =$2D
.equ  SPCR       =$2C
.equ  GPIOR2     =$2B
.equ  GPIOR1     =$2A
.equ  OCR0B      =$28
.equ  OCR0A      =$27
.equ  TCNT0      =$26
.equ  TCCR0B     =$25
.equ  TCCR0A     =$24
.equ  GTCCR      =$23
.equ  EEARH      =$22
.equ  EEARL      =$21
.equ  EEDR       =$20
.equ  EECR       =$1F
.equ  GPIOR0     =$1E
.equ  EIMSK      =$1D
.equ  EIFR       =$1C
.equ  PCIFR      =$1B
.equ  TIFR5      =$1A
.equ  TIFR4      =$19
.equ  TIFR3      =$18
.equ  TIFR2      =$17
.equ  TIFR1      =$16
.equ  TIFR0      =$15
.equ  PORTG      =$14
.equ  DDRG       =$13
.equ  PING       =$12
.equ  PORTF      =$11
.equ  DDRF       =$10
.equ  PINF       =$0F
.equ  PORTE      =$0E
.equ  DDRE       =$0D
.equ  PINE       =$0C
.equ  PORTD      =$0B
.equ  DDRD       =$0A
.equ  PIND       =$09
.equ  PORTC      =$08
.equ  DDRC       =$07
.equ  PINC       =$06
.equ  PORTB      =$05
.equ  DDRB       =$04
.equ  PINB       =$03
.equ  PORTA      =$02
.equ  DDRA       =$01
.equ  PINA       =$00


;***** BIT DEFINITIONS *****************************************************

;**********ANALOG_COMPARATOR**********
;ADCSRB:
.equ  ACME       =6
;ACSR:
.equ  ACD        =7
.equ  ACBG       =6
.equ  ACO        =5
.equ  ACI        =4
.equ  ACIE       =3
.equ  ACIC       =2
.equ  ACIS1      =1
.equ  ACIS0      =0
;DIDR1:
.equ  AIN1D      =1
.equ  AIN0D      =0

;**********USART0*********************
;UDR0:
;UCSR0A:
.equ  RXC0       =7
.equ  TXC0       =6
.equ  UDRE0      =5
.equ  FE0        =4
.equ  DOR0       =3
.equ  UPE0       =2
.equ  U2X0       =1
.equ  MPCM0      =0
;UCSR0B:
.equ  RXCIE0     =7
.equ  TXCIE0     =6
.equ  UDRIE0     =5
.equ  RXEN0      =4
.equ  TXEN0      =3
.equ  UCSZ02     =2
.equ  RXB80      =1
.equ  TXB80      =0
;UCSR0C:
.equ  UMSEL01    =7
.equ  UMSEL00    =6
.equ  UPM01      =5
.equ  UPM00      =4
.equ  USBS0      =3
.equ  UCPOL0     =0

;**********TWI************************
;TWCR:
.equ  TWINT      =7
.equ  TWEA       =6
.equ  TWSTA      =5
.equ  TWSTO      =4
.equ  TWWC       =3
.equ  TWEN       =2
.equ  TWIE       =0
;TWSR:
.equ  TWS7       =7
.equ  TWS6       =6
.equ  TWS5       =5
.equ  TWS4       =4
.equ  TWS3       =3
.equ  TWPS1      =1
.equ  TWPS0      =0
;TWAR:
.equ  TWGCE      =0

;**********SPI************************
;SPCR:
.equ  SPIE       =7
.equ  SPE        =6
.equ  DORD       =5
.equ  MSTR       =4
.equ  CPOL       =3
.equ  CPHA       =2
.equ  SPR1       =1
.equ  SPR0       =0
;SPSR:
.equ  SPIF       =7
.equ  WCOL       =6
.equ  SPI2X      =0

;**********PORTA**********************
;PORTA:
.equ  PORTA7     =7
.equ  PA7        =7
.equ  PORTA6     =6
.equ  PA6        =6
.equ  PORTA5     =5
.equ  PA5        =5
.equ  PORTA4     =4
.equ  PA4        =4
.equ  PORTA3     =3
.equ  PA3        =3
.equ  PORTA2     =2
.equ  PA2        =2
.equ  PORTA1     =1
.equ  PA1        =1
.equ  PORTA0     =0
.equ  PA0        =0
;DDRA:
.equ  DDRA7      =7
.equ  DDRA6      =6
.equ  DDRA5      =5
.equ  DDRA4      =4
.equ  DDRA3      =3
.equ  DDRA2      =2
.equ  DDRA1      =1
.equ  DDRA0      =0
;PINA:
.equ  PINA7      =7
.equ  PINA6      =6
.equ  PINA5      =5
.equ  PINA4      =4
.equ  PINA3      =3
.equ  PINA2      =2
.equ  PINA1      =1
.equ  PINA0      =0

;**********PORTB**********************
;PORTB:
.equ  PORTB7     =7
.equ  PB7        =7
.equ  PORTB6     =6
.equ  PB6        =6
.equ  PORTB5     =5
.equ  PB5        =5
.equ  PORTB4     =4
.equ  PB4        =4
.equ  PORTB3     =3
.equ  PB3        =3
.equ  PORTB2     =2
.equ  PB2        =2
.equ  PORTB1     =1
.equ  PB1        =1
.equ  PORTB0     =0
.equ  PB0        =0
;DDRB:
.equ  DDRB7      =7
.equ  DDRB6      =6
.equ  DDRB5      =5
.equ  DDRB4      =4
.equ  DDRB3      =3
.equ  DDRB2      =2
.equ  DDRB1      =1
.equ  DDRB0      =0
;PINB:
.equ  PINB7      =7
.equ  PINB6      =6
.equ  PINB5      =5
.equ  PINB4      =4
.equ  PINB3      =3
.equ  PINB2      =2
.equ  PINB1      =1
.equ  PINB0      =0

;**********PORTC**********************
;PORTC:
.equ  PORTC7     =7
.equ  PC7        =7
.equ  PORTC6     =6
.equ  PC6        =6
.equ  PORTC5     =5
.equ  PC5        =5
.equ  PORTC4     =4
.equ  PC4        =4
.equ  PORTC3     =3
.equ  PC3        =3
.equ  PORTC2     =2
.equ  PC2        =2
.equ  PORTC1     =1
.equ  PC1        =1
.equ  PORTC0     =0
.equ  PC0        =0
;DDRC:
.equ  DDRC7      =7
.equ  DDRC6      =6
.equ  DDRC5      =5
.equ  DDRC4      =4
.equ  DDRC3      =3
.equ  DDRC2      =2
.equ  DDRC1      =1
.equ  DDRC0      =0
;PINC:
.equ  PINC7      =7
.equ  PINC6      =6
.equ  PINC5      =5
.equ  PINC4      =4
.equ  PINC3      =3
.equ  PINC2      =2
.equ  PINC1      =1
.equ  PINC0      =0

;**********PORTD**********************
;PORTD:
.equ  PORTD7     =7
.equ  PD7        =7
.equ  PORTD6     =6
.equ  PD6        =6
.equ  PORTD5     =5
.equ  PD5        =5
.equ  PORTD4     =4
.equ  PD4        =4
.equ  PORTD3     =3
.equ  PD3        =3
.equ  PORTD2     =2
.equ  PD2        =2
.equ  PORTD1     =1
.equ  PD1        =1
.equ  PORTD0     =0
.equ  PD0        =0
;DDRD:
.equ  DDRD7      =7
.equ  DDRD6      =6
.equ  DDRD5      =5
.equ  DDRD4      =4
.equ  DDRD3      =3
.equ  DDRD2      =2
.equ  DDRD1      =1
.equ  DDRD0      =0
;PIND:
.equ  PIND7      =7
.equ  PIND6      =6
.equ  PIND5      =5
.equ  PIND4      =4
.equ  PIND3      =3
.equ  PIND2      =2
.equ  PIND1      =1
.equ  PIND0      =0

;**********PORTE**********************
;PORTE:
.equ  PORTE7     =7
.equ  PE7        =7
.equ  PORTE6     =6
.equ  PE6        =6
.equ  PORTE5     =5
.equ  PE5        =5
.equ  PORTE4     =4
.equ  PE4        =4
.equ  PORTE3     =3
.equ  PE3        =3
.equ  PORTE2     =2
.equ  PE2        =2
.equ  PORTE1     =1
.equ  PE1        =1
.equ  PORTE0     =0
.equ  PE0        =0
;DDRE:
.equ  DDRE7      =7
.equ  DDRE6      =6
.equ  DDRE5      =5
.equ  DDRE4      =4
.equ  DDRE3      =3
.equ  DDRE2      =2
.equ  DDRE1      =1
.equ  DDRE0      =0
;PINE:
.equ  PINE7      =7
.equ  PINE6      =6
.equ  PINE5      =5
.equ  PINE4      =4
.equ  PINE3      =3
.equ  PINE2      =2
.equ  PINE1      =1
.equ  PINE0      =0

;**********PORTF**********************
;PORTF:
.equ  PORTF7     =7
.equ  PF7        =7
.equ  PORTF6     =6
.equ  PF6        =6
.equ  PORTF5     =5
.equ  PF5        =5
.equ  PORTF4     =4
.equ  PF4        =4
.equ  PORTF3     =3
.equ  PF3        =3
.equ  PORTF2     =2
.equ  PF2        =2
.equ  PORTF1     =1
.equ  PF1        =1
.equ  PORTF0     =0
.equ  PF0        =0
;DDRF:
.equ  DDRF7      =7
.equ  DDRF6      =6
.equ  DDRF5      =5
.equ  DDRF4      =4
.equ  DDRF3      =3
.equ  DDRF2      =2
.equ  DDRF1      =1
.equ  DDRF0      =0
;PINF:
.equ  PINF7      =7
.equ  PINF6      =6
.equ  PINF5      =5
.equ  PINF4      =4
.equ  PINF3      =3
.equ  PINF2      =2
.equ  PINF1      =1
.equ  PINF0      =0

;**********PORTG**********************
;PORTG:
.equ  PORTG5     =5
.equ  PG5        =5
.equ  PORTG4     =4
.equ  PG4        =4
.equ  PORTG3     =3
.equ  PG3        =3
.equ  PORTG2     =2
.equ  PG2        =2
.equ  PORTG1     =1
.equ  PG1        =1
.equ  PORTG0     =0
.equ  PG0        =0
;DDRG:
.equ  DDRG5      =5
.equ  DDRG4      =4
.equ  DDRG3      =3
.equ  DDRG2      =2
.equ  DDRG1      =1
.equ  DDRG0      =0
;PING:
.equ  PING5      =5
.equ  PING4      =4
.equ  PING3      =3
.equ  PING2      =2
.equ  PING1      =1
.equ  PING0      =0

;**********TIMER_COUNTER_0************
;TCCR0B:
.equ  FOC0A      =7
.equ  FOC0B      =6
.equ  WGM02      =3
.equ  CS02       =2
.equ  CS01       =1
.equ  CS00       =0
;TCCR0A:
.equ  COM0A1     =7
.equ  COM0A0     =6
.equ  COM0B1     =5
.equ  COM0B0     =4
.equ  WGM01      =1
.equ  WGM00      =0
;TIMSK0:
.equ  OCIE0B     =2
.equ  OCIE0A     =1
.equ  TOIE0      =0
;TIFR0:
.equ  OCF0B      =2
.equ  OCF0A      =1
.equ  TOV0       =0
;GTCCR:
.equ  TSM        =7
.equ  PSRSYNC    =0

;**********TIMER_COUNTER_2************
;TIMSK2:
.equ  OCIE2B     =2
.equ  OCIE2A     =1
.equ  TOIE2      =0
;TIFR2:
.equ  OCF2B      =2
.equ  OCF2A      =1
.equ  TOV2       =0
;TCCR2A:
.equ  COM2A1     =7
.equ  COM2A0     =6
.equ  COM2B1     =5
.equ  COM2B0     =4
.equ  WGM21      =1
.equ  WGM20      =0
;TCCR2B:
.equ  FOC2A      =7
.equ  FOC2B      =6
.equ  WGM22      =3
.equ  CS22       =2
.equ  CS21       =1
.equ  CS20       =0
;ASSR:
.equ  EXCLK      =6
.equ  AS2        =5
.equ  TCN2UB     =4
.equ  OCR2AUB    =3
.equ  OCR2BUB    =2
.equ  TCR2AUB    =1
.equ  TCR2BUB    =0
;GTCCR:
;.equ   TSM      =7
.equ  PSRASY     =1

;**********WATCHDOG*******************
;WDTCSR:
.equ  WDIF       =7
.equ  WDIE       =6
.equ  WDP3       =5
.equ  WDCE       =4
.equ  WDE        =3
.equ  WDP2       =2
.equ  WDP1       =1
.equ  WDP0       =0

;**********USART1*********************
;UDR1:
;UCSR1A:
.equ  RXC1       =7
.equ  TXC1       =6
.equ  UDRE1      =5
.equ  FE1        =4
.equ  DOR1       =3
.equ  UPE1       =2
.equ  U2X1       =1
.equ  MPCM1      =0
;UCSR1B:
.equ  RXCIE1     =7
.equ  TXCIE1     =6
.equ  UDRIE1     =5
.equ  RXEN1      =4
.equ  TXEN1      =3
.equ  UCSZ12     =2
.equ  RXB81      =1
.equ  TXB81      =0
;UCSR1C:
.equ  UMSEL11    =7
.equ  UMSEL10    =6
.equ  UPM11      =5
.equ  UPM10      =4
.equ  USBS1      =3
.equ  UCPOL1     =0

;**********EEPROM*********************
;EECR:
.equ  EEPM1      =5
.equ  EEPM0      =4
.equ  EERIE      =3
.equ  EEMPE      =2
.equ  EEPE       =1
.equ  EERE       =0


;**********TIMER_COUNTER_5************
;TCCR5A:
.equ  COM5A1     =7
.equ  COM5A0     =6
.equ  COM5B1     =5
.equ  COM5B0     =4
.equ  COM5C1     =3
.equ  COM5C0     =2
.equ  WGM51      =1
.equ  WGM50      =0
;TCCR5B:
.equ  ICNC5      =7
.equ  ICES5      =6
.equ  WGM53      =4
.equ  WGM52      =3
.equ  CS52       =2
.equ  CS51       =1
.equ  CS50       =0
;TCCR5C:
.equ  FOC5A      =7
.equ  FOC5B      =6
.equ  FOC5C      =5
;TIMSK5:
.equ  ICIE5      =5
.equ  OCIE5C     =3
.equ  OCIE5B     =2
.equ  OCIE5A     =1
.equ  TOIE5      =0
;TIFR5:
.equ  ICF5       =5
.equ  OCF5C      =3
.equ  OCF5B      =2
.equ  OCF5A      =1
.equ  TOV5       =0

;**********TIMER_COUNTER_4************
;TCCR4A:
.equ  COM4A1     =7
.equ  COM4A0     =6
.equ  COM4B1     =5
.equ  COM4B0     =4
.equ  COM4C1     =3
.equ  COM4C0     =2
.equ  WGM41      =1
.equ  WGM40      =0
;TCCR4B:
.equ  ICNC4      =7
.equ  ICES4      =6
.equ  WGM43      =4
.equ  WGM42      =3
.equ  CS42       =2
.equ  CS41       =1
.equ  CS40       =0
;TCCR4C:
.equ  FOC4A      =7
.equ  FOC4B      =6
.equ  FOC4C      =5
;TIMSK4:
.equ  ICIE4      =5
.equ  OCIE4C     =3
.equ  OCIE4B     =2
.equ  OCIE4A     =1
.equ  TOIE4      =0
;TIFR4:
.equ  ICF4       =5
.equ  OCF4C      =3
.equ  OCF4B      =2
.equ  OCF4A      =1
.equ  TOV4       =0

;**********TIMER_COUNTER_3************
;TCCR3A:
.equ  COM3A1     =7
.equ  COM3A0     =6
.equ  COM3B1     =5
.equ  COM3B0     =4
.equ  COM3C1     =3
.equ  COM3C0     =2
.equ  WGM31      =1
.equ  WGM30      =0
;TCCR3B:
.equ  ICNC3      =7
.equ  ICES3      =6
.equ  WGM33      =4
.equ  WGM32      =3
.equ  CS32       =2
.equ  CS31       =1
.equ  CS30       =0
;TCCR3C:
.equ  FOC3A      =7
.equ  FOC3B      =6
.equ  FOC3C      =5
;TIMSK3:
.equ  ICIE3      =5
.equ  OCIE3C     =3
.equ  OCIE3B     =2
.equ  OCIE3A     =1
.equ  TOIE3      =0
;TIFR3:
.equ  ICF3       =5
.equ  OCF3C      =3
.equ  OCF3B      =2
.equ  OCF3A      =1
.equ  TOV3       =0

;**********TIMER_COUNTER_1************
;TCCR1A:
.equ  COM1A1     =7
.equ  COM1A0     =6
.equ  COM1B1     =5
.equ  COM1B0     =4
.equ  COM1C1     =3
.equ  COM1C0     =2
.equ  WGM11      =1
.equ  WGM10      =0
;TCCR1B:
.equ  ICNC1      =7
.equ  ICES1      =6
.equ  WGM13      =4
.equ  WGM12      =3
.equ  CS12       =2
.equ  CS11       =1
.equ  CS10       =0
;TCCR1C:
.equ  FOC1A      =7
.equ  FOC1B      =6
.equ  FOC1C      =5
;TIMSK1:
.equ  ICIE1      =5
.equ  OCIE1C     =3
.equ  OCIE1B     =2
.equ  OCIE1A     =1
.equ  TOIE1      =0
;TIFR1:
.equ  ICF1       =5
.equ  OCF1C      =3
.equ  OCF1B      =2
.equ  OCF1A      =1
.equ  TOV1       =0

;**********JTAG***********************
;MCUCR:
.equ  JTD        =7
;MCUSR:
.equ  JTRF       =4

;**********EXTERNAL_INTERRUPT*********
;EICRA:
.equ  ISC31      =7
.equ  ISC30      =6
.equ  ISC21      =5
.equ  ISC20      =4
.equ  ISC11      =3
.equ  ISC10      =2
.equ  ISC01      =1
.equ  ISC00      =0
;EICRB:
.equ  ISC71      =7
.equ  ISC70      =6
.equ  ISC61      =5
.equ  ISC60      =4
.equ  ISC51      =3
.equ  ISC50      =2
.equ  ISC41      =1
.equ  ISC40      =0
;EIMSK:
.equ  INT7       =7
.equ  INT6       =6
.equ  INT5       =5
.equ  INT4       =4
.equ  INT3       =3
.equ  INT2       =2
.equ  INT1       =1
.equ  INT0       =0
;EIFR:
.equ  INTF7      =7
.equ  INTF6      =6
.equ  INTF5      =5
.equ  INTF4      =4
.equ  INTF3      =3
.equ  INTF2      =2
.equ  INTF1      =1
.equ  INTF0      =0
;PCMSK2:
.equ  PCINT23    =7
.equ  PCINT22    =6
.equ  PCINT21    =5
.equ  PCINT20    =4
.equ  PCINT19    =3
.equ  PCINT18    =2
.equ  PCINT17    =1
.equ  PCINT16    =0
;PCMSK1:
.equ  PCINT15    =7
.equ  PCINT14    =6
.equ  PCINT13    =5
.equ  PCINT12    =4
.equ  PCINT11    =3
.equ  PCINT10    =2
.equ  PCINT9     =1
.equ  PCINT8     =0
;PCMSK0:
.equ  PCINT7     =7
.equ  PCINT6     =6
.equ  PCINT5     =5
.equ  PCINT4     =4
.equ  PCINT3     =3
.equ  PCINT2     =2
.equ  PCINT1     =1
.equ  PCINT0     =0
;PCIFR:
.equ  PCIF2      =2
.equ  PCIF1      =1
.equ  PCIF0      =0
;PCICR:
.equ  PCIE2      =2
.equ  PCIE1      =1
.equ  PCIE0      =0

;**********CPU************************
;MCUCR:
;.equ   JTD      =7
.equ  PUD        =4
.equ  IVSEL      =1
.equ  IVCE       =0
;MCUSR:
;.equ   JTRF     =4
.equ  WDRF       =3
.equ  BORF       =2
.equ  EXTRF      =1
.equ  PORF       =0
;XMCRA:
.equ  SRE        =7
.equ  SRL2       =6
.equ  SRL1       =5
.equ  SRL0       =4
.equ  SRW11      =3
.equ  SRW10      =2
.equ  SRW01      =1
.equ  SRW00      =0
;XMCRB:
.equ  XMBK       =7
.equ  XMM2       =2
.equ  XMM1       =1
.equ  XMM0       =0
;CLKPR:
.equ  CPKPCE     =7
.equ  CLKPS3     =3
.equ  CLKPS2     =2
.equ  CLKPS1     =1
.equ  CLKPS0     =0
;SMCR:
.equ  SM2        =3
.equ  SM1        =2
.equ  SM0        =1
.equ  SE         =0
;EIND:
.equ  EIND0      =0
;RAMPZ:
.equ  RAMPZ1     =1
.equ  RAMPZ0     =0
;PRR1:
.equ  PRTIM5     =5
.equ  PRTIM4     =4
.equ  PRTIM3     =3
.equ  PRUSART3   =2
.equ  PRUSART2   =1
.equ  PRUSART1   =0
;PRR0:
.equ  PRTWI      =7
.equ  PRTIM2     =6
.equ  PRTIM0     =5
.equ  PRTIM1     =3
.equ  PRSPI      =2
.equ  PRUSART0   =1
.equ  PRADC      =0

;**********AD_CONVERTER***************
;ADMUX:
.equ  REFS1      =7
.equ  REFS0      =6
.equ  ADLAR      =5
.equ  MUX4       =4
.equ  MUX3       =3
.equ  MUX2       =2
.equ  MUX1       =1
.equ  MUX0       =0
;ADCSRA:
.equ  ADEN       =7
.equ  ADSC       =6
.equ  ADATE      =5
.equ  ADIF       =4
.equ  ADIE       =3
.equ  ADPS2      =2
.equ  ADPS1      =1
.equ  ADPS0      =0
;ADCSRB:
;.equ   ACME     =6
.equ  MUX5       =3
.equ  ADTS2      =2
.equ  ADTS1      =1
.equ  ADTS0      =0
;DIDR2:
.equ  ADC15D     =7
.equ  ADC14D     =6
.equ  ADC13D     =5
.equ  ADC12D     =4
.equ  ADC11D     =3
.equ  ADC10D     =2
.equ  ADC9D      =1
.equ  ADC8D      =0
;DIDR0:
.equ  ADC7D      =7
.equ  ADC6D      =6
.equ  ADC5D      =5
.equ  ADC4D      =4
.equ  ADC3D      =3
.equ  ADC2D      =2
.equ  ADC1D      =1
.equ  ADC0D      =0

;**********BOOT_LOAD******************
;SPMCSR:
.equ  SPMIE      =7
.equ  RWWSB      =6
.equ  SIGRD      =5
.equ  RWWSRE     =4
.equ  BLBSET     =3
.equ  PGWRT      =2
.equ  PGERS      =1
.equ  SPMEN      =0

;***** CPU REGISTER DEFINITIONS ********************************************
.def    XL    = r26
.def    XH    = r27
.def    YL    = r28
.def    YH    = r29
.def    ZL    = r30
.def    ZH    = r31

;***** DATA MEMORY DECLARATIONS ********************************************
.equ  RAMEND     = $21FF
.equ  XRAMEND    = $FFFF
.equ  EEPROMEND  = $FFF

;***** PROGRAM MEMORY DECLARATIONS *****************************************
.equ  FLASHEND     = $1FFFF

;***** BOOT VECTORS ********************************************************
.equ  SMALLBOOTSTART        = 0x1FE00
.equ  SECONDBOOTSTART       = 0x1FC00
.equ  THIRDBOOTSTART        = 0x1F800
.equ  LARGEBOOTSTART        = 0x1F000
.equ  PAGESIZE              = 128

;***** INTERRUPT VECTORS ***************************************************
.equ  INT0addr       = $002    ; External Interrupt Request 0
.equ  INT1addr       = $004    ; External Interrupt Request 1
.equ  INT2addr       = $006    ; External Interrupt Request 2
.equ  INT3addr       = $008    ; External Interrupt Request 3
.equ  INT4addr       = $00A    ; External Interrupt Request 4
.equ  INT5addr       = $00C    ; External Interrupt Request 5
.equ  INT6addr       = $00E    ; External Interrupt Request 6
.equ  INT7addr       = $010    ; External Interrupt Request 7
.equ  PCI0addr       = $012    ; Pin Change Interrupt Request 0
.equ  PCI1addr       = $014    ; Pin Change Interrupt Request 1
.equ  PCI2addr       = $016    ; Pin Change Interrupt Request 2
.equ  WDTaddr        = $018    ; Watchdog Time-out Interrupt
.equ  OC2Aaddr       = $01A    ; Timer/Counter2 Compare Match A
.equ  OC2Baddr       = $01C    ; Timer/Counter2 Compare Match B
.equ  OVF2addr       = $01E    ; Timer/Counter2 Overflow
.equ  ICP1addr       = $020    ; Timer/Counter1 Capture Event
.equ  OC1Aaddr       = $022    ; Timer/Counter1 Compare Match A
.equ  OC1Baddr       = $024    ; Timer/Counter1 Compare Match B
.equ  OC1Caddr       = $026    ; Timer/Counter1 Compare Match C
.equ  OVF1addr       = $028    ; Timer/Counter1 Overflow
.equ  OC0Aaddr       = $02A    ; Timer/Counter0 Compare Match A
.equ  OC0Baddr       = $02C    ; Timer/Counter0 Compare Match B
.equ  OVF0addr       = $02E    ; Timer/Counter0 Overflow
.equ  SPIaddr        = $030    ; SPI Serial Transfer Complete
.equ  URXC0addr      = $032    ; USART0, Rx Complete
.equ  UDRE0addr      = $034    ; USART0 Data register Empty
.equ  UTXC0addr      = $036    ; USART0, Tx Complete
.equ  ACIaddr        = $038    ; Analog Comparator
.equ  ADCaddr        = $03A    ; ADC Conversion Complete
.equ  ERDYaddr       = $03C    ; EEPROM Ready
.equ  ICP3addr       = $03E    ; Timer/Counter3 Capture Event
.equ  OC3Aaddr       = $040    ; Timer/Counter3 Compare Match A
.equ  OC3Baddr       = $042    ; Timer/Counter3 Compare Match B
.equ  OC3Caddr       = $044    ; Timer/Counter3 Compare Match C
.equ  OVF3addr       = $046    ; Timer/Counter3 Overflow
.equ  URXC1addr      = $048    ; USART1, Rx Complete
.equ  UDRE1addr      = $04A    ; USART1 Data register Empty
.equ  UTXC1addr      = $04C    ; USART1, Tx Complete
.equ  TWIaddr        = $04E    ; 2-wire Serial Interface
.equ  SPMRaddr       = $050    ; Store Program Memory Read
.equ  ICP4addr       = $052    ; Timer/Counter4 Capture Event
.equ  OC4Aaddr       = $054    ; Timer/Counter4 Compare Match A
.equ  OC4Baddr       = $056    ; Timer/Counter4 Compare Match B
.equ  OC4Caddr       = $058    ; Timer/Counter4 Compare Match C
.equ  OVF4addr       = $05A    ; Timer/Counter4 Overflow
.equ  ICP5addr       = $05C    ; Timer/Counter5 Capture Event
.equ  OC5Aaddr       = $05E    ; Timer/Counter5 Compare Match A
.equ  OC5Baddr       = $060    ; Timer/Counter5 Compare Match B
.equ  OC5Caddr       = $062    ; Timer/Counter5 Compare Match C
.equ  OVF5addr       = $064    ; Timer/Counter5 Overflow

;***** END OF FILE *********************************************************
