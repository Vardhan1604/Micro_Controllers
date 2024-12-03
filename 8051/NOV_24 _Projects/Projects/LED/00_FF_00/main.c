#include "D:\Micro_Controller\8051\NOV_24 _Projects\Lib\LED\LED.h"
#include "D:\Micro_Controller\8051\NOV_24 _Projects\Lib\Delay\Delay.h"


void main()
{
	Port1_00_FF();
	Delay_1ms(1000);
	Port1_FF_00();
	Delay_1ms(1000);
}