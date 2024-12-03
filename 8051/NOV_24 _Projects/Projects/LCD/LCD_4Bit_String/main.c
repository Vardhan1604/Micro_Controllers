#include "D:\Micro_Controller\8051\NOV_24 _Projects\Lib\LCD_4Bit_Mode\LCD.h"
#include "D:\Micro_Controller\8051\NOV_24 _Projects\Lib\Delay\Delay.h"
#include "GPIO.h"

void main()
{
	LCD_Init();
	while(1)
	{
		LCD_Cmd_Write(0x80);
		Sprint("Welcome");
	}
}