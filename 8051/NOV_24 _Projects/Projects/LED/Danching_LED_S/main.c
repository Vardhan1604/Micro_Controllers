#include "../../../Lib/LED/LED.h"   
#include "../../../Lib/Delay/Delay.h" 


void main()
{
	while(1)
	{
	  Even_LED_S();
		Delay_1ms(500);
		ODD_LED_S();
		Delay_1ms(1000);
	}
}
