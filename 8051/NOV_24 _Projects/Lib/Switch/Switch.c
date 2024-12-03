
#include "Switch.h"
#include "GPIO.h"
#include "../Delay/Delay.h"

unsigned char Switch1(void)
{
    if (Sw == 0)
    {
        Delay_1ms(500);
        if (Sw == 0)
        {
            return 1;
        }
    }
    return 0;
}

unsigned char Switch2(void)
{
    if (Sw1 == 0)
    {
        Delay_1ms(500);
        if (Sw1 == 0)
        {
            return 1;
        }
    }
    return 0;
}
