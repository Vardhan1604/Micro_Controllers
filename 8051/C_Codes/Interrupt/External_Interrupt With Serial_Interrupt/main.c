#include <reg51.h>

sbit LED = P1^3;

void Delay(unsigned char num)
{
	unsigned int i,j;
	
	for(i = 0; i < num; i++)
	{
		for(j = 0; j < 123; j++);
	}
}

void E0_ISR() interrupt 0
{
  SBUF = 'm';
	Delay(1000);
}
void Serial_ISR() interrupt 4
{
	if(TI == 1)
	{
		TI = 0;
	}
	else
	{
		P0 = SBUF;
		RI = 0;
	}
}

void main()
{
	
	TMOD = 0x20;
	TH1 = -3;
	TR1 = 1;
	SCON = 0x50;
	IE = 0x91;
	while(1)
	{
		;
	}
}