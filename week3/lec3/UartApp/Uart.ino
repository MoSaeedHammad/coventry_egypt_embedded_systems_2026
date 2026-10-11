#if !defined(__AVR_ATmega328P__)
#include <avr/iom328p.h>
#endif

#include "Uart.h"


void Uart_Init(void) {

    Uart_SetBaudRate(9600);

    /* Enable USART transmitter/receiver */
    UCSR0B = (1 << TXEN0) | (1 << RXEN0);

    /* 8 data bits, 1 stop bit */
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
}

void Uart_SetBaudRate(unsigned long BuadRate)
{
    unsigned short UBBR = ( (F_CPU / 16) /  BuadRate ) - 1;
    UBRR0L = (UBBR & 0xFF);
    UBRR0H = (( UBBR >> 8 ) & 0xFF);
}

void Uart_SendChar(unsigned char DataByte)
{
    // Wait until Write buffer is empty
    while ( ! (UCSR0A & ( 1 << UDRE0)) );
    UDR0 = DataByte;
}

unsigned char Uart_ReadData(void) {
    // Wait until data is received
    while ( ! (UCSR0A & ( 1 << RXC0)) );
    return UDR0;
}

void Uart_SendString(char DataString[], unsigned char Size){
    int i;
    for (i=0; i<Size; i++)
    {
        Uart_SendChar(DataString[i]);
    }
}