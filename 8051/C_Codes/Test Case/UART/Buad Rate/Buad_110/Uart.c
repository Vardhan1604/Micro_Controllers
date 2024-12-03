
#include <W78E054_052D.H>
#include <reg51.h>
#include "Uart.h"

void Uart_Init(unsigned int Value)
{
	char i;
	if( Value == 9600) i = -3;
	if( Value == 4800) i = -6;
	if( Value == 2400) i = -12;
	if( Value == 1200) i = -24;
	if( Value == 600) i = -48;
	if( Value == 300) i = -96;
	if( Value == 150) i = -192;
	if( Value == 110) i = -256;
	if (Value == 19200)
	{
		PCON = 0x80;
		i = -3;
	}
	TMOD = 0X20;
	TH1 = i;
	SCON = 0X50;
	TR1 = 1;
}


/*_________________________________________________________*/

void Uart_Tx(unsigned char Value)
{
	SBUF = Value;
	while(TI == 0);
	TI = 0;
}

/*_________________________________________________________*/


unsigned char Uart_Rx()
{
	while(RI == 0);
	RI = 0;
	return SBUF;
}

/*_________________________________________________________*/


void Uart_Tx_Str( unsigned char *Str)
{
	while(*Str)
	{
	Uart_Tx(*Str);
		Str++;
	}
}
