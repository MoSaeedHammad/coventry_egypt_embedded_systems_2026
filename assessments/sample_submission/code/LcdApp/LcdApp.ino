#include <util/delay.h>
#include "Lcd.h"

int main()
{

	LCD_Init();			/* Initialize LCD */

	LCD_String("TKH Embedded Systems");	/* write string on 1st line of LCD*/
	LCD_Command(0xC0);		            /* Go to 2nd line*/
	LCD_String("Hello World");	        /* Write string on 2nd line*/
    while(1);
	return 0;
}
