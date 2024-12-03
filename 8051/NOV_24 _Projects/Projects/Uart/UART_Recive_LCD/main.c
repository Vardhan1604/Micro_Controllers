
#include <../../../Lib/LCD/LCD.h>
#include <../../../Lib/Delay/Delay.h>
#include <../../../Lib/Uart/Uart.h>

void main()
{

    Uart_Init(9600);
    LCD_Init();
    Sprint("UART IS Ready");
    Delay_1ms(1000);
    LCD_Cmd_Write(0x01);
    while (1)
    {
        LCD_Data_Write(Uart_Rx());
    }
}
