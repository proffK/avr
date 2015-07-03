timer_study.o: timer_study.asm	
	avra --includepath /home/sproff/Documents/Programs/avr/Appnotes timer_study.asm
build: timer_study.hex
	avrdude -p m48 -c usbasp -U flash:w:timer_study.hex