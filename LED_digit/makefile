LED_digit.o: LED_digit_neg.asm	
	avra --includepath /home/sproff/Documents/Programs/avr/Appnotes LED_digit_neg.asm
build: LED_digit_neg.hex
	avrdude -p m48 -c usbasp -U flash:w:LED_digit_neg.hex
