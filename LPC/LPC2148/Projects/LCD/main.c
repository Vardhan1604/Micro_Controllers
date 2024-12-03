
#include "D:\Micro_Controller\LPC\LPC2148\Drivers\LCD_4Bit_Mode\LCD.h"

int main()
{
	LCD_Init();
	
	while(1)
	{
		
		LCD_Cmd_Write(0x80);
    Sprint("WELCOME");
	}
}
