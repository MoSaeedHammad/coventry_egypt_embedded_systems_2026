// #include <util/delay.h>
#include "Uart.h"

int main(void) {
 
 char inital_value;
 Uart_Init();
 Uart_SendString("Hello World!\r\n",12); /* to test */
 
 
 while (1) {
   inital_value = Uart_ReadData();
   inital_value++;
   Uart_SendChar(inital_value);
 } /* End event loop */
 return (0);
}
