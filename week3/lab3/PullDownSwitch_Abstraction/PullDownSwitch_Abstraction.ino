#include <util/delay.h>

#define PORT_B          (volatile uint8_t *)(0x25)
#define DDR_B          (volatile uint8_t *)(0x24)
#define PIN_B          (volatile uint8_t *)(0x23)

inline void Register_SetBit(volatile unsigned char* Register, unsigned char Bit){
  *Register = *Register | (1 << Bit);
}

inline void Register_ResetBit(volatile unsigned char* Register, unsigned char Bit){
  *Register = *Register & ~(1 << Bit);
}

inline void Register_ToggleBit(volatile unsigned char* Register, unsigned char Bit){
  *Register = *Register ^ (1 << Bit);
}

inline unsigned char Register_GetBit(volatile unsigned char* Register, unsigned char Bit){
  return (*Register >> Bit) & (unsigned char)0x01;
}

int main(void){
  init();
  while (1)
  {
    if(Register_GetBit(PIN_B, 3) == 0)   // if switch not pressed
    {
      Register_ResetBit(PORT_B, 5); // Switch OFF lED
      _delay_ms(200);
    }  
    else 
    {
      Register_SetBit(PORT_B, 5);     // Switch ON lED
      _delay_ms(200);
    }
  }
  return 0; 
}

void init(){
  Register_SetBit(DDR_B, 5);
  Register_ResetBit(DDR_B, 3);
  Register_ResetBit(PORT_B, 5);
}