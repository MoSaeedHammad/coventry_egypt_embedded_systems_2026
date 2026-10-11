#include <avr/io.h>
#include <util/delay.h>

int main(void){
    init();
     DDRB = 0xFF;
    while (1)
    {
        PORTB = 0b00100000;
        _delay_ms(1000);
        PORTB = 0b00000000;
        _delay_ms(1000);

    }
    return 0; 
}

void init(){
    DDRB = 0b00100000;
}