LED_digit.o: LED_digit.asm	
	avra --includepath /home/sproff/Documents/Programs/avr/Appnotes LED_digit.asm
build: LED_digit.hex
	avrdude -p m48 -c usbasp -U flash:w:LED_digit.hex
