#include <reg51.h>
#include <LCD.h>
#include <Delay.h>
#include <Uart.h>
sbit sw = P2^0;

void main() {
	  
	  Uart_Init(9600);
    LCD_Init();
	  Sprint("UART IS Ready");
	  Uart_Tx_Str("UART IS Ready");
	  Delay(1000);
	  LCD_Cmd(0x01);
    
						if(sw == 0)
						{
							Delay(500);
							Uart_Tx_Str("Bluetooth With 8051");
						}
            }
        }
