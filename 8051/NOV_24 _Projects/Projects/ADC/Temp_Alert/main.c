#include "D:\Micro_Controller\8051\NOV_24 _Projects\Lib\Delay\Delay.h"
#include "D:\Micro_Controller\8051\NOV_24 _Projects\Lib\LCD\LCD.h"
#include "D:\Micro_Controller\8051\NOV_24 _Projects\Lib\ADC\ADC.h"
#include "D:\Micro_Controller\8051\NOV_24 _Projects\Lib\UART\Uart.h"
#include "GPIO.h"
#include <stdio.h>

void main()
{
    char Display[30];
    LCD_Init();
    ADC_Init();
	  Uart_Init(9600);
    LCD_Sprint("WELCOME");
    Delay_1ms(1000);
    LCD_Cmd_Write(0x01);
	  LED =0;
    while (1)
    {
        float Temperature;
        Temperature = ADC_Data_Read();
        Temperature = (Temperature * 2);
        sprintf(Display, "TEMP: %.2f *C", Temperature);
        LCD_Sprint(Display);
     
			
				if(Temperature > 36)
				{
					LED = 1;
					Uart_Tx_Str(Display);
					Uart_Tx(0x0D);
					Uart_Tx(0x0A);
					Uart_Tx_Str("Temperature Waring ");
					Uart_Tx(0x0D);
					Uart_Tx(0x0A);
					LCD_Cmd_Write(0xC0);
					LCD_Sprint("Warning");
					
				}
				else
					LED = 0;
				Delay_1ms(1000);
        LCD_Cmd_Write(0x01);
    }
		
}
