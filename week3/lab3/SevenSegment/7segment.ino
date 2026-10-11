#include <avr/io.h>
#include <util/delay.h>

void segment(unsigned int num);

unsigned char segment_digits[10] =
{
  0b011111110,  //0
  0b001001000,  //1
  0b000111101,  //2
  0b001101101,  //3
  0b001001011,  //4
  0b011100111,  //5
  0b011110011,  //6
  0b001001100,  //7
  0b011111111,  //8
  0b011101111   //9
};

void init();

int main(void){
  init();
  int number = 0;
  while (1)
  {
    segment(number);
    number++;
    _delay_ms(700); 
  }
  return 0; 
}

void init(){
  DDRD = 0xFF;
  PORTD = 0x00;
}

void segment(unsigned int num)
{ 
  if (num > 10) 
  {
    num = num % 10;
  }
  PORTD = segment_digits[num];
}