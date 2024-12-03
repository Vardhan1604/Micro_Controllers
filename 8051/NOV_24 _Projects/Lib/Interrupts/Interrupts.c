
#include "Interrupts.h"

void EX0_ISR() interrupt 0
{
	LED1 =~LED1;
}
void T0_ISR() interrupt 1
{
	Wave = Wave;
}
void EX1_ISR() interrupt 2
{
	LED2 =~LED2;
}
void T1_ISR() interrupt 3
{
	Wave1 = Wave1;
}
void Uart_ISR() interrupt 4
{
	if(TI == 1)
	TI = 0;
	else
	RI = 0;
}