
#include "D:\Micro_Controller\8051\NOV_24 _Projects\Lib\Delay\Delay.h"

void Delay_1ms(unsigned int Num)
{
    unsigned int i, j;
    for (i = 0; i < Num; i++)
    {
        for (j = 0; j < 113; j++)
            ;
    }
}

void Delay_1s(unsigned int Num)
{
    Delay_1ms(1000 * Num);
}

void Delay_1Min(unsigned int Num)
{
    Delay_1s(60 * Num);
}