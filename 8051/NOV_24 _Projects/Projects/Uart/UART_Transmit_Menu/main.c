#include <reg51.h>
#include <../../../Lib/LCD/LCD.h>
#include <../../../Lib/Delay/Delay.h>
#include <../../../Lib/Uart/Uart.h>

unsigned char City[][15] = { "Hyderabad" , "Vijayawada" , "Mumbai" ,"Goa" , "Delhi" };
void main() {
    unsigned char i;
    Uart_Init(9600);
    LCD_Init();
    Uart_Tx_Str("UART IS Ready");
	  Sprint("Ready");
	  Uart_Tx(0x0D);
    Delay_1ms(1000);
    LCD_Cmd_Write(0x01); 
        for (i = 0; i < 5;) {
            Uart_Tx_Str(City[i]); 
					  Uart_Tx(0x0D); 
						 LCD_Cmd_Write(0x80);
             Sprint(City[i]); 
						 i++;
						 LCD_Cmd_Write(0XC0);
						 Sprint(City[i]);
             Delay_1ms(1000);
             LCD_Cmd_Write(0x01);						 
            }
				while (1);
					}
					 
				 