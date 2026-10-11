#include <util/delay.h>
#include <Register.h>

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