;***************************************************************************
;* A P P L I C A T I O N   N O T E   F O R   T H E   A V R   F A M I L Y
;* 
;* Number				:AVR000
;* File Name			:"m161cdef.inc"
;* Title				:Register/Bit Definitions for the ATmega162 in 
;*                      :ATmega161 compatibility mode
;* Date                 :2003.09.22
;* Version              :1.00
;* Support E-mail		:avr@atmel.no
;* Target MCU			:ATmega161
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
;* in	r16,PORTB		;read PORTB latch
;* sbr	r16,(1<<PB6)+(1<<PB5)	;set PB6 and PB5 (use masks, not bit#)
;* out  PORTB,r16		;output to PORTB
;*
;* in	r16,TIFR		;read the Timer Interrupt Flag Register
;* sbrc	r16,TOV0		;test the overflow flag (use bit#)
;* rjmp	TOV0_is_set		;jump if set
;* ...				;otherwise do something else
;***************************************************************************

;***** Specify Device
.device ATmega161
	
				
;***** I/O Register Definitions	
.equ	SREG	=$3f
.equ	SPH		=$3e
.equ	SPL		=$3d
.equ	GIMSK	=$3b
.equ	GIFR	=$3a
.equ	TIMSK	=$39
.equ	TIFR	=$38
.equ	SPMCR	=$37
.equ	EMCUCR	=$36
.equ	MCUCR	=$35
.equ    MCUSR   =$34
.equ	TCCR0	=$33
.equ	TCNT0	=$32
.equ	OCR0	=$31
.equ	SFIOR	=$30
.equ	TCCR1A	=$2f
.equ	TCCR1B	=$2e
.equ	TCNT1H	=$2d
.equ	TCNT1L	=$2c
.equ	OCR1AH	=$2b
.equ	OCR1AL	=$2a
.equ	OCR1BH	=$29
.equ	OCR1BL	=$28
.equ	TCCR2	=$27
.equ    ASSR    =$26
.equ	ICR1H	=$25
.equ	ICR1L	=$24
.equ	TCNT2	=$23
.equ	OCR2	=$22
.equ	WDTCR	=$21
.equ    UBRRHI  =$20
.equ	EEARH	=$1f
.equ	EEARL	=$1e
.equ	EEDR	=$1d
.equ	EECR	=$1c
.equ	PORTA	=$1b
.equ	DDRA	=$1a
.equ	PINA	=$19
.equ	PORTB	=$18
.equ	DDRB	=$17
.equ	PINB	=$16
.equ	PORTC	=$15
.equ	DDRC	=$14
.equ	PINC	=$13
.equ	PORTD	=$12
.equ	DDRD	=$11
.equ	PIND	=$10
.equ	SPDR	=$0f
.equ	SPSR	=$0e
.equ	SPCR	=$0d
.equ	UDR0	=$0c
.equ	UDR		=$0c		;for compatibility with s8515
.equ	UCSR0A	=$0b
.equ	USR		=$0b		;for compatibility with s8515
.equ	UCSR0B	=$0a
.equ	UCR		=$0a		;for compatibility with s8515
.equ	UBRR0	=$09
.equ    UBRR0L  =$09        ;for upwards compatibility
.equ	UBRR	=$09		;for compatibility with s8515
.equ	ACSR	=$08
.equ	PORTE	=$07
.equ	DDRE	=$06
.equ	PINE	=$05
.equ	UDR1	=$03
.equ	UCSR1A	=$02
.equ	UCSR1B	=$01
.equ	UBRR1	=$00		
.equ    UBRR1L  =$00        ;for upwards compatibility

;***** Bit Definitions
			
;GIMSK
.equ	INT1	=7
.equ	INT0	=6
.equ	INT2	=5
	
;GIFR
.equ	INTF1	=7
.equ	INTF0	=6
.equ	INTF2	=5
	
;TIMSK
.equ	TOIE1	=7
.equ	OCIE1A	=6
.equ	OCIE1B	=5
.equ    OCIE2   =4
.equ	TICIE1	=3
.equ    TOIE2   =2
.equ	TOIE0	=1
.equ	OCIE0	=0

;TIFR
.equ	TOV1	=7
.equ	OCF1A	=6
.equ	OCF1B	=5
.equ	OCF2	=4
.equ	ICF1	=3
.equ	TOV2	=2
.equ	TOV0	=1
.equ	OCF0	=0

;SPMCR
.equ    SPMIE   =7
.equ    RWWSB   =6
.equ    RWWSRE  =4
.equ	BLBSET	=3
.equ	PGWRT	=2
.equ	PGERS	=1
.equ	SPMEN	=0

;EMCUCR
.equ    SM0     =7
.equ	SRL2	=6
.equ	SRL1	=5
.equ	SRL0	=4
.equ	SRW01	=3
.equ	SRW00	=2
.equ	SRW11	=1
.equ	ISC2	=0

;MCUCR
.equ	SRE		=7
.equ	SRW		=6		;for compatibility with s8515
.equ	SRW10	=6
.equ	SE		=5
.equ	SM		=4		;for compatibility with s8515
.equ	SM1		=4
.equ	ISC11	=3
.equ	ISC10	=2
.equ	ISC01	=1
.equ	ISC00	=0

;MCUSR
.equ	WDRF	=3
.equ	BORF	=2
.equ	EXTRF	=1
.equ	PORF	=0

;TCCR0
.equ    FOC0    =7
.equ	WGM00	=6
.equ    PWM0    =6		; OBSOLETE! Use WGM00
.equ	COM01	=5
.equ	COM00	=4
.equ	WGM01	=3
.equ	CTC0	=3		; OBSOLETE! Use WGM01
.equ	CS02	=2
.equ	CS01	=1
.equ	CS00	=0

;SFIOR
.equ    PSR2    =1
.equ    PSR10   =0		; Note:	The prescaler reset is shared
						; between timer 0 and 1.
.equ    PSR1	=0
.equ    PSR0	=0

;TCCR1A
.equ	COM1A1	=7
.equ	COM1A0	=6
.equ	COM1B1	=5
.equ	COM1B0	=4
.equ    FOC1A   =3
.equ    FOC1B   =2
.equ	PWM11	=1		; OBSOLETE! Use WGM11
.equ	WGM11	=1
.equ	PWM10	=0		; OBSOLETE! Use WGM10
.equ	WGM10	=0

;TCCR1B
.equ	ICNC1	=7
.equ	ICES1	=6
.equ	CTC1	=3		; OBSOLETE! Use WGM12
.equ	WGM12	=3
.equ	CS12	=2
.equ	CS11	=1
.equ	CS10	=0

;TCCR2
.equ    FOC2    =7
.equ	WGM20	=6
.equ    PWM2    =6		; OBSOLETE! Use WGM20
.equ	COM21	=5
.equ	COM20	=4  
.equ	WGM21	=3
.equ	CTC2	=3		; OBSOLETE! Use WGM21
.equ	CS22	=2
.equ	CS21	=1
.equ	CS20	=0

;ASSR
.equ	AS2	=3
.equ	TCN2UB	=2
.equ	OCR2UB	=1
.equ	TCR2UB	=0

;WDTCR
.equ    WDDE    =4      ;obsolete
.equ	WDTOE	=4
.equ    WDCE    =4      ;for upwards compatibility
.equ	WDE	    =3
.equ	WDP2	=2
.equ	WDP1	=1
.equ	WDP0	=0

;EECR
.equ    EERIE   =3
.equ	EEMWE	=2
.equ	EEWE	=1
.equ	EERE	=0

;PORTA
.equ	PORTA7	=7
.equ	PORTA6	=6
.equ	PORTA5	=5
.equ	PORTA4	=4
.equ	PORTA3	=3
.equ	PORTA2	=2
.equ	PORTA1	=1
.equ	PORTA0	=0

;DDRA
.equ	DDA7	=7
.equ	DDA6	=6
.equ	DDA5	=5
.equ	DDA4	=4
.equ	DDA3	=3
.equ	DDA2	=2
.equ	DDA1	=1
.equ	DDA0	=0

;PINA
.equ	PINA7	=7
.equ	PINA6	=6
.equ	PINA5	=5
.equ	PINA4	=4
.equ	PINA3	=3
.equ	PINA2	=2
.equ	PINA1	=1
.equ	PINA0	=0

;PORTB
.equ	PORTB7	=7
.equ	PORTB6	=6
.equ	PORTB5	=5
.equ	PORTB4	=4
.equ	PORTB3	=3
.equ	PORTB2	=2
.equ	PORTB1	=1
.equ	PORTB0	=0

;DDRB
.equ	DDB7	=7
.equ	DDB6	=6
.equ	DDB5	=5
.equ	DDB4	=4
.equ	DDB3	=3
.equ	DDB2	=2
.equ	DDB1	=1
.equ	DDB0	=0

;PINB
.equ	PINB7	=7
.equ	PINB6	=6
.equ	PINB5	=5
.equ	PINB4	=4
.equ	PINB3	=3
.equ	PINB2	=2
.equ	PINB1	=1
.equ	PINB0	=0

;PORTC
.equ	PORTC7	=7
.equ	PORTC6	=6
.equ	PORTC5	=5
.equ	PORTC4	=4
.equ	PORTC3	=3
.equ	PORTC2	=2
.equ	PORTC1	=1
.equ	PORTC0	=0

;DDRC
.equ	DDC7	=7
.equ	DDC6	=6
.equ	DDC5	=5
.equ	DDC4	=4
.equ	DDC3	=3
.equ	DDC2	=2
.equ	DDC1	=1
.equ	DDC0	=0

;PINC
.equ	PINC7	=7
.equ	PINC6	=6
.equ	PINC5	=5
.equ	PINC4	=4
.equ	PINC3	=3
.equ	PINC2	=2
.equ	PINC1	=1
.equ	PINC0	=0

;PORTD
.equ	PORTD7	=7
.equ	PORTD6	=6
.equ	PORTD5	=5
.equ	PORTD4	=4
.equ	PORTD3	=3
.equ	PORTD2	=2
.equ	PORTD1	=1
.equ	PORTD0	=0

;DDRD
.equ	DDD7	=7
.equ	DDD6	=6
.equ	DDD5	=5
.equ	DDD4	=4
.equ	DDD3	=3
.equ	DDD2	=2
.equ	DDD1	=1
.equ	DDD0	=0

;PIND
.equ	PIND7	=7
.equ	PIND6	=6
.equ	PIND5	=5
.equ	PIND4	=4
.equ	PIND3	=3
.equ	PIND2	=2
.equ	PIND1	=1
.equ	PIND0	=0

;PORTE
.equ	PORTE2	=2
.equ	PORTE1	=1
.equ	PORTE0	=0

;DDRE
.equ	DDE2	=2
.equ	DDE1	=1
.equ	DDE0	=0

;PINE
.equ	PINE2	=2
.equ	PINE1	=1
.equ	PINE0	=0

;USR (for compatibility with s8515)
.equ	RXC		=7
.equ	TXC		=6
.equ	UDRE	=5
.equ	FE		=4
.equ	OR		=3
.equ	U2X		=1

;UCSR0A
.equ	RXC0	=7
.equ	TXC0	=6
.equ	UDRE0	=5
.equ	FE0		=4
.equ	OR0		=3		; Old name kept for compatibilty
.equ	DOR0	=3
.equ	U2X0	=1
.equ	MPCM0	=0

;UCSR1A
.equ	RXC1	=7
.equ	TXC1	=6
.equ	UDRE1	=5
.equ	FE1		=4
.equ	OR1		=3		; Old name kept for compatibilty
.equ	DOR1	=3
.equ	U2X1	=1
.equ	MPCM1	=0

;SPCR
.equ	SPIE	=7
.equ	SPE		=6
.equ	DORD	=5
.equ	MSTR	=4
.equ	CPOL	=3
.equ	CPHA	=2
.equ	SPR1	=1
.equ	SPR0	=0

;SPSR
.equ	SPIF	=7
.equ	WCOL	=6
.equ	SPI2X	=0

;UCR (for compatibility with s8515)
.equ	RXCIE	=7
.equ	TXCIE	=6
.equ	UDRIE	=5
.equ	RXEN	=4
.equ	TXEN	=3
.equ	CHR9	=2		; Old name kept for compatibilty
.equ	UCSZ2	=2
.equ	RXB8	=1
.equ	TXB8	=0

; UCSR0B
.equ	RXCIE0	=7
.equ	TXCIE0	=6
.equ	UDRIE0	=5
.equ	RXEN0	=4
.equ	TXEN0	=3
.equ	CHR90	=2		; Old name kept for compatibilty
.equ	UCSZ02	=2
.equ	RXB80	=1
.equ	TXB80	=0

; UCSR1B
.equ	RXCIE1	=7
.equ	TXCIE1	=6
.equ	UDRIE1	=5
.equ	RXEN1	=4
.equ	TXEN1	=3
.equ	CHR91	=2		; Old name kept for compatibilty
.equ	UCSZ12	=2
.equ	RXB81	=1
.equ	TXB81	=0
	
;ACSR
.equ	ACD		=7
.equ	AINBG	=6		
.equ    ACBG    =6      ;for upwards compatibility
.equ	ACO		=5
.equ	ACI		=4
.equ	ACIE	=3
.equ	ACIC	=2
.equ	ACIS1	=1
.equ	ACIS0	=0


; Boot loader Lock bit
.equ	BLB12	=5
.equ	BLB11	=4
.equ	BLB02	=3
.equ	BLB01	=2

;X,Y,Z pointer
.def    XL  =r26
.def    XH  =r27
.def    YL  =r28
.def    YH  =r29
.def    ZL  =r30
.def    ZH  =r31

.equ    FLASHEND    =$1FFF
.equ    E2END       =$1FF
.equ    RAMEND      =$45F
.equ    XRAMEND     =$FFFF

.equ    SMALLBOOTSTART  =0b1111110000000  ;($1F80) smallest boot block is 256B
.equ    SECONDBOOTSTART =0b1111100000000  ;($1F00) second boot block size is 512B
.equ    THIRDBOOTSTART  =0b1111000000000  ;($1E00) third boot block size is 1KB
.equ    LARGEBOOTSTART  =0b1110000000000  ;($1C00) largest boot block is 2KB
.equ    BOOTSTART   =THIRDBOOTSTART  ;OBSOLETE!!! kept for compatibility
.equ    PAGESIZE    =64     ;number of WORDS in a page

.equ    INT0addr    =$002   ;External   Interrupt0 Vector Address
.equ    INT1addr    =$004   ;External Interrupt1 Vector Address
.equ    INT2addr    =$006   ;External Interrupt1 Vector Address
.equ    CMP2addr    =$008   ;Input Capture1 Interrupt Vector Address
.equ    OVF2addr    =$00a   ;Overflow1 Interrupt Vector Address
.equ    ICP1addr    =$00c   ;Input Capture1 Interrupt Vector Address
.equ    OC1Aaddr    =$00e   ;Output Compare1A Interrupt Vector Address
.equ    OC1Baddr    =$010   ;Output Compare1B Interrupt Vector Address
.equ    OVF1addr    =$012   ;Overflow1 Interrupt Vector Address
.equ    CMP0addr    =$014   ;Overflow1 Interrupt Vector Address
.equ    OVF0addr    =$016   ;Overflow0 Interrupt Vector Address
.equ    SPIaddr     =$018   ;SPI Interrupt Vector Address
.equ    URXC0addr   =$01a   ;UART Receive Complete Interrupt Vector Address
.equ    URXC1addr   =$01c   ;UART Receive Complete Interrupt Vector Address
.equ    UDRE0addr   =$01e   ;UART Data Register Empty Interrupt Vector Address
.equ    UDRE1addr   =$020   ;UART Data Register Empty Interrupt Vector Address
.equ    UTXC0addr   =$022   ;UART Transmit Complete Interrupt Vector Address
.equ    UTXC1addr   =$024   ;UART Transmit Complete Interrupt Vector Address
.equ    EERDYaddr   =$026   ;UART Transmit Complete Interrupt Vector Address
.equ    ACIaddr     =$028   ;Analog Comparator Interrupt Vector Address

;for compatibility with s8515
.equ    URXCaddr    =$01a   ;UART Receive Complete Interrupt Vector Address
.equ    UDREaddr    =$01e   ;UART Data Register Empty Interrupt Vector Address
.equ    UTXCaddr    =$022   ;UART Transmit Complete Interrupt Vector Address
