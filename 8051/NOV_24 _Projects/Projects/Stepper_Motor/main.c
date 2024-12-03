
#include <reg51.h>
#include "D:\Micro_Controller\8051\NOV_24 _Projects\Lib\Delay\Delay.h"

sbit SW = P2 ^ 0;

void main()
{
    unsigned char a[4] = {0x99, 0xcc, 0x66, 0x33};
    unsigned char i, j;
		while(1)
		{
				if (SW == 0)
				{
						Delay_1ms(50);
						if (SW == 0)
						{
								for (j = 0; j < 25; j++)
								{
										for (i = 0; i < 4; i++)
										{
												P0 = a[i];
												Delay_1ms(1);
										}
								}
						}
				}
		 }
}