#include <reg51.h>

void UART_Tx(unsigned char val)
{
	SCON = 0x90;
	SBUF = val;
}

void main()
{
	while(1)
	UART_Tx(0x150);

}