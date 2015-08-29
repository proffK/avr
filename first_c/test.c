#include <avr/io.h>
#include <util/delay.h>

int main(void)
{   
    DDRD |=(1<<7); // PD7 как выход
    while (1) {
        PORTD ^= (1<<7); // и установим на нем лог 1
        _delay_ms(100); 
        
    }
}
