#include "D:\Micro_Controller\8051\NOV_24 _Projects\Lib\I2C\I2C.h"

void main()
{
 int i = 300;
	while(1)
	{
		I2C_Start();
	  Send_Data(0x27 << 1);
		Send_Data('A');
		Send_Data('E');
		Send_Data('C');
		Send_Data('D');
		I2C_Stop();
		while(--i);
	}
}