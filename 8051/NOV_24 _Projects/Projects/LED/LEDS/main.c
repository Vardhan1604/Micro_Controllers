
#include "../../../Lib/Digital_Write/Digital_Write.h"
#include "../../../Lib/Digital_Read/Digital_Read.h"
#include "../../../Lib/Delay/Delay.h"
#include "GPIO.h"

void main()
	  
   
{
	while (1)
    {
       
        if (Digital_Read(SW1) == 1)  
        {
            Digital_Write(LED1, HIGH);  
        }
        else
        {
            Digital_Write(LED1, LOW);   
        }

        
        Delay_1ms(50); 
    }
}