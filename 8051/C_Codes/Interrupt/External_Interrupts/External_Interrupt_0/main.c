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
	P0 = 0x00;
	IE = 0x81;
	while(1)
		{
			LED2 =~LED2;
			Delay(1000);
		}
}

void EX0_ISR() interrupt 0
{
	LED1 =~LED1;
}