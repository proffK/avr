;***************************************************************************
;* A P P L I C A T I O N   N O T E   F O R   T H E   A V R   F A M I L Y
;*
;* Number         : AVR000
;* File Name      : "can128def.inc"
;* Title          : Register/Bit Definitions for the AT90CAN128
;* Date           : March 15th, 2004
;* Version        : 1.0.4
;* Support tel    : -
;* Support Web    : http://www.atmel.com/dyn/products/tech_support.asp?Faq=y
;* Target MCU     : AT90CAN128
;*
;* DESCRIPTION
;* When including this file in the assembly program file, all I/O register
;* names and I/O register bit names appearing in the data book can be used.
;* In addition, the six registers forming the three data pointers X, Y and
;* Z have been assigned names XL - ZH. Highest RAM address for Internal
;* SRAM is also defined.
;*
;* The Register names are represented by their hexadecimal address.
;*
;* The Register Bit names are represented by their bit number (0-7).
;*
;* Please observe the difference in using the bit names with instructions
;* such as "sbr"/"cbr" (set/clear bit in register) and "sbrs"/"sbrc" (skip
;* if bit in register set/cleared). The following example illustrates this:
;*
;* in   r16,PORTB             ; read PORTB latch
;* sbr  r16,(1<<PB6)+(1<<PB5) ; set PB6 and PB5 (use masks, not bit#)
;* out  PORTB,r16             ; output to PORTB
;*
;* in   r16,TIFR0             ; read the Timer Interrupt Flag Register
;* sbrc r16,TOV0              ; test the overflow flag (use bit#)
;* rjmp TOV0_is_set           ; jump if set
;* ...                        ; otherwise do something else
;*
;***************************************************************************

;**** Specify Device ****
.device AT90CAN128



;***************************************************************************
; I/O Register Definitions
;***************************************************************************

;**** Memory Mapped I/O Register Definitions  ****

; *** C.A.N ***
.equ  CANMSG    = $FA
.equ  CANSTMH   = $F9
.equ  CANSTML   = $F8
.equ  CANIDM1   = $F7
.equ  CANIDM2   = $F6
.equ  CANIDM3   = $F5
.equ  CANIDM4   = $F4
.equ  CANIDT1   = $F3
.equ  CANIDT2   = $F2
.equ  CANIDT3   = $F1
.equ  CANIDT4   = $F0
.equ  CANCDMOB  = $EF
.equ  CANSTMOB  = $EE
.equ  CANPAGE   = $ED
.equ  CANHPMOB  = $EC
.equ  CANREC    = $EB
.equ  CANTEC    = $EA
.equ  CANTTCH   = $E9
.equ  CANTTCL   = $E8
.equ  CANTIMH   = $E7
.equ  CANTIML   = $E6
.equ  CANTCON   = $E5
.equ  CANBT3    = $E4
.equ  CANBT2    = $E3
.equ  CANBT1    = $E2
.equ  CANSIT1   = $E1
.equ  CANSIT2   = $E0
.equ  CANIE1    = $DF
.equ  CANIE2    = $DE
.equ  CANEN1    = $DD
.equ  CANEN2    = $DC
.equ  CANGIE    = $DB
.equ  CANGIT    = $DA
.equ  CANGSTA   = $D9
.equ  CANGCON   = $D8

; *** USART1 ***
.equ  UDR1      = $CE
.equ  UBRR1H    = $CD
.equ  UBRR1L    = $CC
.equ  UCSR1C    = $CA
.equ  UCSR1B    = $C9
.equ  UCSR1A    = $C8

; *** USART0 ***
.equ  UDR0      = $C6
.equ  UBRR0H    = $C5
.equ  UBRR0L    = $C4
.equ  UCSR0C    = $C2
.equ  UCSR0B    = $C1
.equ  UCSR0A    = $C0

; *** T.W.I ***
.equ  TWCR      = $BC
.equ  TWDR      = $BB
.equ  TWAR      = $BA
.equ  TWSR      = $B9
.equ  TWBR      = $B8

; *** TIMER-2 (Async) ***
.equ  ASSR      = $B6
.equ  OCR2A     = $B3
.equ  TCNT2     = $B2
.equ  TCCR2A    = $B0

; *** TIMER-3 ***
.equ  OCR3CH    = $9D
.equ  OCR3CL    = $9C
.equ  OCR3BH    = $9B
.equ  OCR3BL    = $9A
.equ  OCR3AH    = $99
.equ  OCR3AL    = $98
.equ  ICR3H     = $87
.equ  ICR3L     = $96
.equ  TCNT3H    = $95
.equ  TCNT3L    = $94
.equ  TCCR3C    = $92
.equ  TCCR3B    = $91
.equ  TCCR3A    = $90

; *** TIMER-1 ***
.equ  OCR1CH    = $8D
.equ  OCR1CL    = $8C
.equ  OCR1BH    = $8B
.equ  OCR1BL    = $8A
.equ  OCR1AH    = $89
.equ  OCR1AL    = $88
.equ  ICR1H     = $87
.equ  ICR1L     = $86
.equ  TCNT1H    = $85
.equ  TCNT1L    = $84
.equ  TCCR1C    = $82
.equ  TCCR1B    = $81
.equ  TCCR1A    = $80

; *** D.I.D
.equ  DIDR1     = $7F
.equ  DIDR0     = $7E

; ***  A.D.C ***
.equ  ADMUX     = $7C
.equ  ADCSRB    = $7B
.equ  ADCSRA    = $7A
.equ  ADCH      = $79
.equ  ADCL      = $78

; *** XRAM ***
.equ  XMCRB     = $75
.equ  XMCRA     = $74

; *** TIMER INT MASK ***
.equ  TIMSK3    = $71
.equ  TIMSK2    = $70
.equ  TIMSK1    = $6F
.equ  TIMSK0    = $6E

; *** EXTERNAL INT CTRL ***
.equ  EICRB     = $6A
.equ  EICRA     = $69

; *** CLOCK ***
.equ  OSCCAL    = $66
.equ  CLKPR     = $61

; *** WATCHDOG ***
.equ  WDTCR     = $60

; *** MCU ***
.equ  SREG      = $3F
.equ  SPH       = $3E
.equ  SPL       = $3D
.equ  RAMPZ     = $3B
.equ  SPMCSR    = $37
.equ  MCUCR     = $35
.equ  MCUSR     = $34
.equ  SMCR      = $33

; *** O.C.D ***
.equ  OCDR      = $31

; *** ANALOG COMP ***
.equ  ACSR      = $30

; *** S.P.I ***
.equ  SPDR      = $2E
.equ  SPSR      = $2D
.equ  SPCR      = $2C

; *** G.P.I.O ***
.equ  GPIOR2    = $2B
.equ  GPIOR1    = $2A
.equ  GPIOR0    = $1E

; *** TIMER-0 (Sync) ***
.equ  OCR0A     = $27
.equ  TCNT0     = $26
.equ  TCCR0A    = $24

; *** GENERAL TIMER ***
.equ  GTCCR     = $23

; *** EEPROM ***
.equ  EEARH     = $22
.equ  EEARL     = $21
.equ  EEDR      = $20
.equ  EECR      = $1F

; *** EXTERNAL INT MASK ***
.equ  EIMSK     = $1D
.equ  EIFR      = $1C

; *** TIMER INT FLAG ***
.equ  TIFR3     = $18
.equ  TIFR2     = $17
.equ  TIFR1     = $16
.equ  TIFR0     = $15

; *** PORT A upto G ***
.equ  PORTG     = $14
.equ  DDRG      = $13
.equ  PING      = $12
.equ  PORTF     = $11
.equ  DDRF      = $10
.equ  PINF      = $0F
.equ  PORTE     = $0E
.equ  DDRE      = $0D
.equ  PINE      = $0C
.equ  PORTD     = $0B
.equ  DDRD      = $0A
.equ  PIND      = $09
.equ  PORTC     = $08
.equ  DDRC      = $07
.equ  PINC      = $06
.equ  PORTB     = $05
.equ  DDRB      = $04
.equ  PINB      = $03
.equ  PORTA     = $02
.equ  DDRA      = $01
.equ  PINA      = $00

;*****************************************************************************
; Bit Definitions
;*****************************************************************************

; *** CANIDM4 : CAN Identifier Mask 4 Register ***
.equ  RTRMSK    = 2
.equ  IDEMSK    = 0

; *** CANIDT4 : CAN Identifier Tag 4 Register ***
.equ  RTRTAG    = 2
.equ  RB1TAG    = 1
.equ  RB0TAG    = 0

; *** CANCDMOB : CAN MOB Control Register ***
.equ  CONMOB    = 6
.equ  RPLY      = 5
.equ  IDE       = 4
.equ  DLC       = 0

; *** CANSTMOB : CAN MOB Status Register ***
.equ  DLCW      = 7
.equ  TXOK      = 6
.equ  RXOK      = 5
.equ  BERR      = 4
.equ  SERR      = 3
.equ  CERR      = 2
.equ  FERR      = 1
.equ  AERR      = 0

; *** CANPAGE : CAN MOB Page Register ***
.equ  MOBNB     = 4
.equ  AINC      = 3
.equ  INDX      = 0

; *** CANHPMOB : CAN Highest Priority MOB Register ***
.equ  HPMOB     = 4
.equ  CGP       = 0

; *** CANBT3: CAN Bit Timing 3 Register ***
.equ  PHS2      = 4
.equ  PHS1      = 1
.equ  SMP       = 0

; *** CANBT2: CAN Bit Timing 2 Register ***
.equ  SJW       = 5
.equ  PRS       = 1

; *** CANBT1: CAN Bit Timing 1 Register ***
.equ  BRP       = 1

; *** CANGIE : CAN General Interrupt Enable Register ***
.equ  ENIT      = 7
.equ  ENBOFF    = 6
.equ  ENRX      = 5
.equ  ENTX      = 4
.equ  ENERMOB   = 3
.equ  ENBUF     = 2
.equ  ENERG     = 1
.equ  ENOVRT    = 0

; *** CANGIT : CAN General Interrupt Register ***
.equ  CANIT     = 7
.equ  BOFFIT    = 6
.equ  OVRTIM    = 5
.equ  OVRBUF    = 4
.equ  SERG      = 3
.equ  CERG      = 2
.equ  FERG      = 1
.equ  AERG      = 0

; *** CANGSTA : CAN General Status Register ***
.equ  OVFG      = 6
.equ  TXBSY     = 4
.equ  RXBSY     = 3
.equ  ENFG      = 2
.equ  BOFF      = 1
.equ  ERRP      = 0

; *** CANGCON : CAN General Control Register ***
.equ  ABRQ      = 7
.equ  OVRQ      = 6
.equ  TTC       = 5
.equ  SYNCTTC   = 4
.equ  LISTEN    = 3
.equ  ENA       = 1
.equ  SWRES     = 0

; *** UCSR1C : USART1 Control and Status Register C ***
.equ  UMSEL1    = 6
.equ  UPM11     = 5
.equ  UPM10     = 4
.equ  USBS1     = 3
.equ  UCSZ11    = 2
.equ  UCSZ10    = 1
.equ  UCPOL1    = 0

; *** UCSR1B : USART1 Control and Status Register B ***
.equ  RXCIE1    = 7
.equ  TXCIE1    = 6
.equ  UDRIE1    = 5
.equ  RXEN1     = 4
.equ  TXEN1     = 3
.equ  UCSZ12    = 2
.equ  RXB81     = 1
.equ  TXB81     = 0

; *** UCSR1A : USART1 Control and Status Register A ***
.equ  RXC1      = 7
.equ  TXC1      = 6
.equ  UDRE1     = 5
.equ  FE1       = 4
.equ  DOR1      = 3
.equ  UPE1      = 2
.equ  U2X1      = 1
.equ  MPCM1     = 0

; *** UCSR0C : USART0 Control and Status Register C ***
.equ  UMSEL0    = 6
.equ  UPM01     = 5
.equ  UPM00     = 4
.equ  USBS0     = 3
.equ  UCSZ01    = 2
.equ  UCSZ00    = 1
.equ  UCPOL0    = 0

; *** UCSR0B : USART0 Control and Status Register B ***
.equ  RXCIE0    = 7
.equ  TXCIE0    = 6
.equ  UDRIE0    = 5
.equ  RXEN0     = 4
.equ  TXEN0     = 3
.equ  UCSZ02    = 2
.equ  RXB80     = 1
.equ  TXB80     = 0

; *** UCSR0A : USART0 Control and Status Register A ***
.equ  RXC0      = 7
.equ  TXC0      = 6
.equ  UDRE0     = 5
.equ  FE0       = 4
.equ  DOR0      = 3
.equ  UPE0      = 2
.equ  U2X0      = 1
.equ  MPCM0     = 0

; *** TWCR : TWI Control Register ***
.equ  TWINT     = 7
.equ  TWEA      = 6
.equ  TWSTA     = 5
.equ  TWSTO     = 4
.equ  TWWC      = 3
.equ  TWEN      = 2
.equ  TWIE      = 0

; *** TWAR : TWI (slave) Address Register ****
.equ  TWA6      = 7
.equ  TWA5      = 6
.equ  TWA4      = 5
.equ  TWA3      = 4
.equ  TWA2      = 3
.equ  TWA1      = 2
.equ  TWA0      = 1
.equ  TWGCE     = 0

; *** TWSR : TWI Status Register ***
.equ  TWS7      = 7
.equ  TWS6      = 6
.equ  TWS5      = 5
.equ  TWS4      = 4
.equ  TWS3      = 3
.equ  TWPS1     = 1
.equ  TWPS0     = 0

; *** ASSR : Timer-2 Asynchronous Mode Status Register ***
.equ  EXCLK     = 4
.equ  AS2       = 3
.equ  TCN2UB    = 2
.equ  OCR2UB    = 1
.equ  TCR2UB    = 0

; *** TCCR2A : Timer/Counter 2 Control Register A  ***
.equ  FOC2      = 7
.equ  WGM20     = 6
.equ  COM2A1    = 5
.equ  COM2A0    = 4
.equ  WGM21     = 3
.equ  CS22      = 2
.equ  CS21      = 1
.equ  CS20      = 0

; *** TCCR3C : Timer/Counter 3 Control Register C ***
.equ  FOC3A     = 7
.equ  FOC3B     = 6
.equ  FOC3C     = 5

; *** TCCR3B : Timer/Counter 3 Control Register B ***
.equ  ICNC3     = 7
.equ  ICES3     = 6
.equ  WGM33     = 4
.equ  WGM32     = 3
.equ  CS32      = 2
.equ  CS31      = 1
.equ  CS30      = 0

; *** TCCR3A : Timer/Counter 3 Control Register A ***
.equ  COM3A1    = 7
.equ  COM3A0    = 6
.equ  COM3B1    = 5
.equ  COM3B0    = 4
.equ  COM3C1    = 3
.equ  COM3C0    = 2
.equ  WGM31     = 1
.equ  WGM30     = 0

; *** TCCR1C : Timer/Counter 1 Control Register C ***
.equ  FOC1A     = 7
.equ  FOC1B     = 6
.equ  FOC1C     = 5

; *** TCCR1B : Timer/Counter 1 Control Register B ***
.equ  ICNC1     = 7
.equ  ICES1     = 6
.equ  WGM13     = 4
.equ  WGM12     = 3
.equ  CS12      = 2
.equ  CS11      = 1
.equ  CS10      = 0

; *** TCCR1A : Timer/Counter 1 Control Register A ***
.equ  COM1A1    = 7
.equ  COM1A0    = 6
.equ  COM1B1    = 5
.equ  COM1B0    = 4
.equ  COM1C1    = 3
.equ  COM1C0    = 2
.equ  WGM11     = 1
.equ  WGM10     = 0

; *** DIDR0 : Digital Input Disable Register 0 ***
.equ  ADC7D     = 7
.equ  ADC6D     = 6
.equ  ADC5D     = 5
.equ  ADC4D     = 4
.equ  ADC3D     = 3
.equ  ADC2D     = 2
.equ  ADC1D     = 1
.equ  ADC0D     = 0

; *** DIDR1 : Digital Input Disable Register 1 ***
.equ  AIN1D     = 1
.equ  AIN0D     = 0

; *** ADMUX : ADC Multiplexer Selection Register ***
.equ  REFS1     = 7
.equ  REFS0     = 6
.equ  ADLAR     = 5
.equ  MUX4      = 4
.equ  MUX3      = 3
.equ  MUX2      = 2
.equ  MUX1      = 1
.equ  MUX0      = 0

; *** ADCSRB : ADC Control and Status Register B ***
.equ  ADHSM     = 7
.equ  ACME      = 6
.equ  ADTS2     = 2
.equ  ADTS1     = 1
.equ  ADTS0     = 0

; *** ADCSRA : ADC Control and Status Register A ***
.equ  ADEN      = 7
.equ  ADSC      = 6
.equ  ADRF      = 5
.equ  ADIF      = 4
.equ  ADIE      = 3
.equ  ADPS2     = 2
.equ  ADPS1     = 1
.equ  ADPS0     = 0

; *** XMCRB : External Memory Control B Register ***
.equ  XMBK      = 7
.equ  XMM2      = 2
.equ  XMM1      = 1
.equ  XMM0      = 0

; *** XMCRA : External Memory Control A Register ***
.equ  SRE       = 7
.equ  SRL2      = 6
.equ  SRL1      = 5
.equ  SRL0      = 4
.equ  SRW11     = 3
.equ  SRW10     = 2
.equ  SRW01     = 1
.equ  SRW00     = 0

; *** TIMSK3 : Timer Interrupt Mask Register3 ***
.equ  ICIE3     = 5
.equ  OCIE3C    = 3
.equ  OCIE3B    = 2
.equ  OCIE3A    = 1
.equ  TOIE3     = 0

; *** TIMSK2 : Timer Interrupt Mask Register2 ***
.equ  OCIE2A    = 1
.equ  TOIE2     = 0

; *** TIMSK1 : Timer Interrupt Mask Register1 ***
.equ  ICIE1     = 5
.equ  OCIE1C    = 3
.equ  OCIE1B    = 2
.equ  OCIE1A    = 1
.equ  TOIE1     = 0

; *** TIMSK0 : Timer Interrupt Mask Register0 ***
.equ  OCIE0A    = 1
.equ  TOIE0     = 0

; *** EICRB : External Interrupt Control B Register ***
.equ  ISC71     = 7
.equ  ISC70     = 6
.equ  ISC61     = 5
.equ  ISC60     = 4
.equ  ISC51     = 3
.equ  ISC50     = 2
.equ  ISC41     = 1
.equ  ISC40     = 0

; *** EICRA : External Interrupt Control A Register  ***
.equ  ISC31     = 7
.equ  ISC30     = 6
.equ  ISC21     = 5
.equ  ISC20     = 4
.equ  ISC11     = 3
.equ  ISC10     = 2
.equ  ISC01     = 1
.equ  ISC00     = 0

; *** OSCCAL : Internal Oscillator Calibration Register ***
.equ  CAL6      = 6
.equ  CAL5      = 5
.equ  CAL4      = 4
.equ  CAL3      = 3
.equ  CAL2      = 2
.equ  CAL1      = 1
.equ  CAL0      = 0

; *** CLKPR : Source Clock Prescaler Register ***
.equ  CLKPCE    = 7
.equ  CLKPS3    = 3
.equ  CLKPS2    = 2
.equ  CLKPS1    = 1
.equ  CLKPS0    = 0

; *** WDTCR : Watchdog Timer Control Register ***
.equ  WDCE      = 4
.equ  WDE       = 3
.equ  WDP2      = 2
.equ  WDP1      = 1
.equ  WDP0      = 0

; *** SREG : MCU Status Register ***
.equ  I         = 7
.equ  T         = 6
.equ  H         = 5
.equ  S         = 4
.equ  V         = 3
.equ  N         = 2
.equ  Z         = 1
.equ  C         = 0

; *** SPH : Stack Pointer High ***
.equ  SP15      = 7
.equ  SP14      = 6
.equ  SP13      = 5
.equ  SP12      = 4
.equ  SP11      = 3
.equ  SP10      = 2
.equ  SP9       = 1
.equ  SP8       = 0

; *** SPL : Stack Pointer Low ***
.equ  SP7       = 7
.equ  SP6       = 6
.equ  SP5       = 5
.equ  SP4       = 4
.equ  SP3       = 3
.equ  SP2       = 2
.equ  SP1       = 1
.equ  SP0       = 0

; *** RAMPZ : RAM Page Z Select Register ***
.equ  RAMPZ0    = 0

; *** SPMCSR : Store Program Memory Control and Status Register ***
.equ  SPMIE     = 7
.equ  RWWSB     = 6
.equ  RWWSRE    = 4
.equ  BLBSET    = 3
.equ  PGWRT     = 2
.equ  PGERS     = 1
.equ  SPMEN     = 0

; *** MCUCR : MCU general Control Register ***
.equ  JTD       = 7
.equ  PUD       = 4
.equ  IVSEL     = 1
.equ  IVCE      = 0

; *** MCUSR : MCU general Status Register ***
.equ  JTRF      = 4
.equ  WDRF      = 3
.equ  BORF      = 2
.equ  EXTRF     = 1
.equ  PORF      = 0

; *** SMCR : Sleep Mode Control Register ***
.equ  SM2       = 3
.equ  SM1       = 2
.equ  SM0       = 1
.equ  SE        = 0

; *** OCDR : On-Chip Debug Register ***
.equ  IDRD      = 7
.equ  OCDR7     = 7
.equ  OCDR6     = 6
.equ  OCDR5     = 5
.equ  OCDR4     = 4
.equ  OCDR3     = 3
.equ  OCDR2     = 2
.equ  OCDR1     = 1
.equ  OCDR0     = 0

; *** ACSR : Analog Comparator Control and Status Register ***
.equ  ACD       = 7
.equ  ACBG      = 6
.equ  ACO       = 5
.equ  ACI       = 4
.equ  ACIE      = 3
.equ  ACIC      = 2
.equ  ACIS1     = 1
.equ  ACIS0     = 0

; *** SPSR : SPI Status Register ***
.equ  SPIF      = 7
.equ  WCOL      = 6
.equ  SPI2X     = 0

; *** SPCR : SPI Control Register ***
.equ  SPIE      = 7
.equ  SPE       = 6
.equ  DORD      = 5
.equ  MSTR      = 4
.equ  CPOL      = 3
.equ  CPHA      = 2
.equ  SPR1      = 1
.equ  SPR0      = 0

; *** TCCR0A : Timer/Counter 0 Control Register ***
.equ  FOC0A     = 7
.equ  WGM00     = 6
.equ  COM0A1    = 5
.equ  COM0A0    = 4
.equ  WGM01     = 3
.equ  CS02      = 2
.equ  CS01      = 1
.equ  CS00      = 0

; *** GTCCR : General Timer Control Register ***
.equ  TSM       = 7
.equ  PSR2      = 1
.equ  PSR310    = 0

; To make tim8pwm_def.inc file part independent.
.equ  PSR0      = PSR310
.equ  PSR1      = PSR310
.equ  PSR3      = PSR310

; *** EECR : EEPROM Control Register ***
.equ  EERIE     = 3
.equ  EEMWE     = 2
.equ  EEWE      = 1
.equ  EERE      = 0

; *** GPIOR0 : General Purpose I/O Register 0 ***
.equ  GPIOR07   = 7
.equ  GPIOR06   = 6
.equ  GPIOR05   = 5
.equ  GPIOR04   = 4
.equ  GPIOR03   = 3
.equ  GPIOR02   = 2
.equ  GPIOR01   = 1
.equ  GPIOR00   = 0

; *** EIMSK : External Interrupt Mask Register ***
.equ  INT7      = 7
.equ  INT6      = 6
.equ  INT5      = 5
.equ  INT4      = 4
.equ  INT3      = 3
.equ  INT2      = 2
.equ  INT1      = 1
.equ  INT0      = 0

; *** EIFR : External Interrupt Flag Register ***
.equ  INTF7     = 7
.equ  INTF6     = 6
.equ  INTF5     = 5
.equ  INTF4     = 4
.equ  INTF3     = 3
.equ  INTF2     = 2
.equ  INTF1     = 1
.equ  INTF0     = 0

; *** TIFR3 : Timer/Counter Interrupt Flag Register 3 ***
.equ  ICF3      = 5
.equ  OCF3C     = 3
.equ  OCF3B     = 2
.equ  OCF3A     = 1
.equ  TOV3      = 0

; *** TIFR2 : Timer/Counter Interrupt Flag Register 2 ***
.equ  OCF2A     = 1
.equ  TOV2      = 0

; *** TIFR1 : Timer/Counter Interrupt Flag Register 1 ***
.equ  ICF1      = 5
.equ  OCF1C     = 3
.equ  OCF1B     = 2
.equ  OCF1A     = 1
.equ  TOV1      = 0

; *** TIFR0 : Timer/Counter Interrupt Flag Register 0 ***
.equ  OCF0A     = 1
.equ  TOV0      = 0

; *** PORTG : Data Register, Port G ***
.equ  PORTG4    = 4
.equ  PORTG3    = 3
.equ  PORTG2    = 2
.equ  PORTG1    = 1
.equ  PORTG0    = 0
.equ  PG4       = 4
.equ  PG3       = 3
.equ  PG2       = 2
.equ  PG1       = 1
.equ  PG0       = 0

; *** DDRG : Data Direction Register, Port G ***
.equ  DDG4      = 4
.equ  DDG3      = 3
.equ  DDG2      = 2
.equ  DDG1      = 1
.equ  DDG0      = 0

; *** PING : Input Pin Register, Port G ***
.equ  PING5     = 5
.equ  PING4     = 4
.equ  PING3     = 3
.equ  PING2     = 2
.equ  PING1     = 1
.equ  PING0     = 0

; *** PORTF : Data Register, Port F ***
.equ  PORTF7    = 7
.equ  PORTF6    = 6
.equ  PORTF5    = 5
.equ  PORTF4    = 4
.equ  PORTF3    = 3
.equ  PORTF2    = 2
.equ  PORTF1    = 1
.equ  PORTF0    = 0
.equ  PF7       = 7
.equ  PF6       = 6
.equ  PF5       = 5
.equ  PF4       = 4
.equ  PF3       = 3
.equ  PF2       = 2
.equ  PF1       = 1
.equ  PF0       = 0

; *** DDRF : Data Direction Register, Port F ***
.equ  DDF7      = 7
.equ  DDF6      = 6
.equ  DDF5      = 5
.equ  DDF4      = 4
.equ  DDF3      = 3
.equ  DDF2      = 2
.equ  DDF1      = 1
.equ  DDF0      = 0

; *** PINF : Input Pin Register, Port F ***
.equ  PINF7     = 7
.equ  PINF6     = 6
.equ  PINF5     = 5
.equ  PINF4     = 4
.equ  PINF3     = 3
.equ  PINF2     = 2
.equ  PINF1     = 1
.equ  PINF0     = 0

; *** PORTE : Data Register, Port E ***
.equ  PORTE7    = 7
.equ  PORTE6    = 6
.equ  PORTE5    = 5
.equ  PORTE4    = 4
.equ  PORTE3    = 3
.equ  PORTE2    = 2
.equ  PORTE1    = 1
.equ  PORTE0    = 0
.equ  PE7       = 7
.equ  PE6       = 6
.equ  PE5       = 5
.equ  PE4       = 4
.equ  PE3       = 3
.equ  PE2       = 2
.equ  PE1       = 1
.equ  PE0       = 0

; *** DDRE : Data Direction Register, Port E ***
.equ  DDE7      = 7
.equ  DDE6      = 6
.equ  DDE5      = 5
.equ  DDE4      = 4
.equ  DDE3      = 3
.equ  DDE2      = 2
.equ  DDE1      = 1
.equ  DDE0      = 0

; *** PINE : Input Pin Register, Port E ***
.equ  PINE7     = 7
.equ  PINE6     = 6
.equ  PINE5     = 5
.equ  PINE4     = 4
.equ  PINE3     = 3
.equ  PINE2     = 2
.equ  PINE1     = 1
.equ  PINE0     = 0

; *** PORTD : Data Register, Port D ***
.equ  PORTD7    = 7
.equ  PORTD6    = 6
.equ  PORTD5    = 5
.equ  PORTD4    = 4
.equ  PORTD3    = 3
.equ  PORTD2    = 2
.equ  PORTD1    = 1
.equ  PORTD0    = 0
.equ  PD7       = 7
.equ  PD6       = 6
.equ  PD5       = 5
.equ  PD4       = 4
.equ  PD3       = 3
.equ  PD2       = 2
.equ  PD1       = 1
.equ  PD0       = 0

; *** DDRD : Data Direction Register, Port D ***
.equ  DDD7      = 7
.equ  DDD6      = 6
.equ  DDD5      = 5
.equ  DDD4      = 4
.equ  DDD3      = 3
.equ  DDD2      = 2
.equ  DDD1      = 1
.equ  DDD0      = 0

; *** PIND : Input Pin Register, Port D ***
.equ  PIND7     = 7
.equ  PIND6     = 6
.equ  PIND5     = 5
.equ  PIND4     = 4
.equ  PIND3     = 3
.equ  PIND2     = 2
.equ  PIND1     = 1
.equ  PIND0     = 0

; *** PORTC : Data Register, Port C ***
.equ  PORTC7    = 7
.equ  PORTC6    = 6
.equ  PORTC5    = 5
.equ  PORTC4    = 4
.equ  PORTC3    = 3
.equ  PORTC2    = 2
.equ  PORTC1    = 1
.equ  PORTC0    = 0
.equ  PC7       = 7
.equ  PC6       = 6
.equ  PC5       = 5
.equ  PC4       = 4
.equ  PC3       = 3
.equ  PC2       = 2
.equ  PC1       = 1
.equ  PC0       = 0

; *** DDRC : Data Direction Register, Port C ***
.equ  DDC7      = 7
.equ  DDC6      = 6
.equ  DDC5      = 5
.equ  DDC4      = 4
.equ  DDC3      = 3
.equ  DDC2      = 2
.equ  DDC1      = 1
.equ  DDC0      = 0

; *** PINC : Input Pin Register, Port C ***
.equ  PINC7     = 7
.equ  PINC6     = 6
.equ  PINC5     = 5
.equ  PINC4     = 4
.equ  PINC3     = 3
.equ  PINC2     = 2
.equ  PINC1     = 1
.equ  PINC0     = 0

; *** PORTB : Data Register, Port B ***
.equ  PORTB7    = 7
.equ  PORTB6    = 6
.equ  PORTB5    = 5
.equ  PORTB4    = 4
.equ  PORTB3    = 3
.equ  PORTB2    = 2
.equ  PORTB1    = 1
.equ  PORTB0    = 0
.equ  PB7       = 7
.equ  PB6       = 6
.equ  PB5       = 5
.equ  PB4       = 4
.equ  PB3       = 3
.equ  PB2       = 2
.equ  PB1       = 1
.equ  PB0       = 0

; *** DDRB : Data Direction Register, Port B ***
.equ  DDB7      = 7
.equ  DDB6      = 6
.equ  DDB5      = 5
.equ  DDB4      = 4
.equ  DDB3      = 3
.equ  DDB2      = 2
.equ  DDB1      = 1
.equ  DDB0      = 0

; *** PINB : Input Pin Register, Port B ***
.equ  PINB7     = 7
.equ  PINB6     = 6
.equ  PINB5     = 5
.equ  PINB4     = 4
.equ  PINB3     = 3
.equ  PINB2     = 2
.equ  PINB1     = 1
.equ  PINB0     = 0

; *** PORTA : Data Register, Port A ***
.equ  PORTA7    = 7
.equ  PORTA6    = 6
.equ  PORTA5    = 5
.equ  PORTA4    = 4
.equ  PORTA3    = 3
.equ  PORTA2    = 2
.equ  PORTA1    = 1
.equ  PORTA0    = 0
.equ  PA7       = 7
.equ  PA6       = 6
.equ  PA5       = 5
.equ  PA4       = 4
.equ  PA3       = 3
.equ  PA2       = 2
.equ  PA1       = 1
.equ  PA0       = 0

; *** DDRA : Data Direction Register, Port A ***
.equ  DDA7      = 7
.equ  DDA6      = 6
.equ  DDA5      = 5
.equ  DDA4      = 4
.equ  DDA3      = 3
.equ  DDA2      = 2
.equ  DDA1      = 1
.equ  DDA0      = 0

; *** PINA : Input Pin Register, Port A ***
.equ  PINA7     = 7
.equ  PINA6     = 6
.equ  PINA5     = 5
.equ  PINA4     = 4
.equ  PINA3     = 3
.equ  PINA2     = 2
.equ  PINA1     = 1
.equ  PINA0     = 0

;*****************************************************************************
; CPU Register Declarations
;*****************************************************************************

.def  XL        = r26        ; X pointer Low
.def  XH        = r27        ; X pointer High
.def  YL        = r28        ; Y pointer Low
.def  YH        = r29        ; Y pointer High
.def  ZL        = r30        ; Z pointer Low
.def  ZH        = r31        ; Z pointer High

;*****************************************************************************
; Data Memory Declarations
;*****************************************************************************

.equ  IOEND     = $00FF      ; 256 bytes I/O + REG
.equ  RAMSIZE   = $1000      ; 4K byte RAM

.equ  RAMEND = IOEND+RAMSIZE ;($10FF) Highest internal data memory (SRAM) add.
                             ;(4k bytes RAM + I/O + REG)
.equ  EEPROMEND = $0FFF      ; Highest EEPROM address.
                             ;(4k bytes)

.equ  EEADRBITS = 12         ; no. of bits in EEPROM address register

;*****************************************************************************
; Program Memory Declarations
;*****************************************************************************

.equ  FLASHEND  = $FFFF      ;  Highest program memory (Flash) address
                             ; (When addressed as 16-bit words)
                             ; ( 64k words , 128k bytes )

;**** Boot Vectors ****
.equ  SMALLBOOTSTART  = 0b1111111000000000 ; ($FE00) Smallest boot block is 512W
.equ  SECONDBOOTSTART = 0b1111110000000000 ; ($FC00) 2'nd boot block size is 1KW
.equ  THIRDBOOTSTART  = 0b1111100000000000 ; ($F800) 3'rd boot block size is 2KW
.equ  LARGEBOOTSTART  = 0b1111000000000000 ; ($F000) Largest boot block is 4KW

;**** Page Size ****
.equ  PAGESIZE	= 128   ; number of WORDS in a Flash page
.equ	EEPAGESIZE	= 8     ; number of BYTES in an EEPROM page

;**** Interrupt Vectors ****
;.equ RESETaddr     = $000   ; RESET Vector Address
.equ  INT0addr      = $002   ; External Interrupt0 Vector Address
.equ  INT1addr      = $004   ; External Interrupt1 Vector Address
.equ  INT2addr      = $006   ; External Interrupt2 Vector Address
.equ  INT3addr      = $008   ; External Interrupt3 Vector Address
.equ  INT4addr      = $00A   ; External Interrupt4 Vector Address
.equ  INT5addr      = $00C   ; External Interrupt5 Vector Address
.equ  INT6addr      = $00E   ; External Interrupt6 Vector Address
.equ  INT7addr      = $010   ; External Interrupt7 Vector Address
.equ  OC2addr       = $012   ; Timer/Counter2 Compare Match Interrupt Address
.equ  OVF2addr      = $014   ; Timer/Counter2 Overflow Interrupt Address
.equ  ICP1addr      = $016   ; Timer/Counter1 Input Capture Interrupt Address
.equ  OC1Aaddr      = $018   ; Timer/Counter1 Output CompareA Interrupt Address
.equ  OC1Baddr      = $01A   ; Timer/Counter1 Output CompareB Interrupt Address
.equ  OC1Caddr      = $01C   ; Timer/Counter1 Output CompareC Interrupt Address
.equ  OVF1addr      = $01E   ; Timer/Counter1 Overflow Interrupt Address
.equ  OC0addr       = $020   ; Timer/Counter0 Compare Match Interrupt Address
.equ  OVF0addr      = $022   ; Timer/Counter0 Overflow Interrupt Address
.equ  CANITaddr     = $024   ; CAN Transfer Complete or Error Address
.equ  OVRITaddr     = $026   ; CAN Timer Overrun Address
.equ  SPIaddr       = $028   ; SPI Interrupt Address
.equ  URXC0addr     = $02A   ; USART-0 Receive Complete Interrupt Address
.equ  UDRE0addr     = $02C   ; USART-0 Data Register Empty Interrupt Address
.equ  UTXC0addr     = $02E   ; USART-0 Transmit Complete Interrupt Address
.equ  ACIaddr       = $030   ; Analog Comparator Interrupt Address
.equ  ADCCaddr      = $032   ; ADC Conversion Complete Interrupt Address
.equ  ERDYaddr      = $034   ; EEPROM Write Complete Interrupt Address
.equ  ICP3addr      = $036   ; Timer/Counter3 Input Capture Interrupt Address
.equ  OC3Aaddr      = $038   ; Timer/Counter3 Output CompareA Interrupt Address
.equ  OC3Baddr      = $03A   ; Timer/Counter3 Output CompareB Interrupt Address
.equ  OC3Caddr      = $03C   ; Timer/Counter3 Output CompareC Interrupt Address
.equ  OVF3addr      = $03E   ; Timer/Counter3 Overflow Interrupt Address
.equ  URXC1addr     = $040   ; USART-1 Receive Complete Interrupt Address
.equ  UDRE1addr     = $042   ; USART-1 Data Register Empty Interrupt Address
.equ  UTXC1addr     = $044   ; USART-1 Transmit Complete Interrupt Address
.equ  TWIaddr       = $046   ; TWI Interrupt Vector Address
.equ  SPMRaddr      = $048   ; Store Program Memory Ready Interrupt Address

;**** End of File ****
