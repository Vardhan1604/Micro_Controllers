//#include <reg51.h>

#include <reg51.h>
#include <../../../Lib/Uart/Uart.h>

void main() {
	unsigned int i = 300;
  Uart_Init(9600); 	        
	
	while(1)
	{
		Uart_Tx_Str("123");
		while(--i);
	}
}