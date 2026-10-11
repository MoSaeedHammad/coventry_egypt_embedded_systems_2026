#ifndef __UART__
#define __UART__

void Uart_Init(void);

void Uart_SetBaudRate(unsigned long);

void Uart_SendChar(unsigned char);

unsigned char Uart_ReadData();

void Uart_SendString(char [], unsigned char);

#endif
