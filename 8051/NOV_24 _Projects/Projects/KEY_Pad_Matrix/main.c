
#include "D:\Micro_Controller\8051\NOV_24 _Projects\Lib\Matrix_Key_Pad\KEYPAD.h"
#include "D:\Micro_Controller\8051\NOV_24 _Projects\Lib\LCD\LCD.h"
#include  "D:\Micro_Controller\8051\NOV_24 _Projects\Lib\Delay/Delay.h"


void main()
{
	unsigned char Key;
	Key = KeyPad_SCAN();
  LCD_Init();
	if(Key != 0)
	{
		LCD_Data_Write(Key);
	}
}