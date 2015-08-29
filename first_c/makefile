# Задаем имя проекта, в результате получатся файлы test.hex test.bin
TARG=test
CC = avr-gcc
OBJCOPY = avr-objcopy
PROG= avrdude
#   
# Задаем из каких файлов собирать проект, можно указать несколько файлов
SRCS= test.c 
 
OBJS = $(SRCS:.c=.o)
	 
# Задаем для какого микроконтроллера будем компилировать (atmega8)
MCU=atmega48 
FREQ=8000000
PROG_NAME=usbasp
PROG_MCU_NAME=m48

# Флаги компилятора, при помощи F_CPU определяем частоту на которой будет работать контроллер,
CFLAGS = -mmcu=$(MCU) -Wall -g -Os -Werror -lm  -mcall-prologues -DF_CPU=$(FREQ)
LDFLAGS = -mmcu=$(MCU)  -Wall -g -Os  -Werror 
PROGFLAGS = -p $(PROG_MCU_NAME) -c $(PROG_NAME) 
	  
all: $(TARG)
	 
$(TARG): $(OBJS)
		$(CC) $(LDFLAGS) -o $@.elf  $(OBJS) -lm
			$(OBJCOPY) -O binary -R .eeprom -R .nwram  $@.elf $@.bin
				$(OBJCOPY) -O ihex -R .eeprom -R .nwram  $@.elf $@.hex
				 
%.o: %.c
		$(CC) $(CFLAGS) -c -o $@ $<

flash:	$(TARG).hex
		
		$(PROG) $(PROGFLAGS) -U flash:w:$^
		 
clean:
		rm -f *.elf *.bin *.hex  $(OBJS) *.map
