#include "../../../Lib/LED/LED.h"   
#include "../../../Lib/Delay/Delay.h" 


void main()
{
	while(1)
	{
		LED1_ON();
		Delay_1ms(1000);
		LED2_OFF();
		Delay_1ms(1000);
    LED2_ON();
		Delay_1ms(1000);
		LED1_OFF();
		Delay_1ms(1000);		
	}
}
