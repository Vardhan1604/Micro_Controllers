#include "../../../Lib/LED/LED.h"   
#include "../../../Lib/Switch/Switch.h" 

void main()
{
    while(1)
    {
        if (Switch1() == 1)  
        {
            LED1_Toggle();
        }
    }
}
