#include <reg51.h>

sbit LED1 = P0^2;
sbit LED2 = P0^3;

void Delay(unsigned char num)
{
	unsigned int i,j;
	for(i = 0; i < num ; i++)
	{
		for(j = 0; j < 132 ; j++);
	}
}

void main()
{
	IE = 0x88;
	IT0 = 1;
	while(1)
		{
			LED2 =~LED2;
			Delay(1000);
		}
}

void EX0_ISR() interrupt 2
{
	LED1 =~LED1;
}