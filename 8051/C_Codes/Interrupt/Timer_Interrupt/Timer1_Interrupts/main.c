#include <reg51.h>

sbit LED = P0^3;
sbit wave = P1^0;

void Delay(unsigned char num)
{
	unsigned int i,j;
	
	for(i = 0; i < num; i++)
	{
		for(j = 0; j < 123; j++);
	}
}

void T0_ISR() interrupt 3
{
	wave=~wave;
}

void main()
{
	
	TMOD = 0x20;
	TH1 = 0xff;
	TR1 = 1;
	IE = 0x88;
	while(1)
	{
		LED = ~ LED;
		Delay(1000);
	}
}