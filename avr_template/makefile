template_name.o: template_pr	
	avra --includepath /home/sproff/Documents/Programs/avr/Appnotes template_pr
build: template_name.hex
	avrdude -p template_mk -c usbasp -U flash:w:template_name.hex