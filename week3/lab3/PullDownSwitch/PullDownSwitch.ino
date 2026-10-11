#include <avr/io.h>
#include <util/delay.h>

int main(void){
  init();
  while (1)
  {
    if(((PINB >> 3) & 1) == 0)   // if switch not pressed
    {
      PORTB = PORTB & ~(1 << 5);    // Switch OFF lED
      _delay_ms(200);
    }  
    else 
    {
      PORTB = PORTB | (1 << 5);      // Switch ON lED
      _delay_ms(200);
    }
  }
  return 0; 
}

void init(){
  DDRB = DDRB | (1 << 5);     // Make PB5 output
  DDRB = DDRB & ~(1 << 3);    // Make PB3 input
  PORTB = PORTB & ~(1 << 5);    // Switch OFF lED
}