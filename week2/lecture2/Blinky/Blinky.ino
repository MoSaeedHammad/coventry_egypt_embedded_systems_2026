#if !defined(__AVR_ATmega328P__)
#include <avr/iom328p.h>
#endif
#include <util/delay.h>

int main(void){
    
    DDRB = 0xFF;

    while (1)
    {
        PORTB = 0xFF;
        _delay_ms(200);
        PORTB = 0x00;
        _delay_ms(200);

    }
    return 0; 
}

