
#include "../../../Lib/LED/LED.h"   
#include "../../../Lib/Switch/Switch.h"


void main()
{
    while(1)
    {
       if(Switch1() == 1)
			 {
				 LED1_ON();
				 LED2_OFF();
			 }
			 else if(Switch2() == 1)
			 {
				 LED2_ON();
				 LED1_OFF();
			 }
				
    }
}
