#include "D:\Micro_Controller\8051\NOV_24 _Projects\Lib\Delay\Delay.h"
#include "D:\Micro_Controller\8051\NOV_24 _Projects\Lib\LCD\LCD.h"
#include "D:\Micro_Controller\8051\NOV_24 _Projects\Lib\ADC\ADC.h"

#include "GPIO.h"

void main()
{
    char display[30];
    int i;
    LCD_Init();
    ADC_Init();
    LCD_Sprint("WELCOME");
    Delay_1ms(1000);
    LCD_Cmd_Write(0x01);
    while (1)
    {
        float Voltage;
        Voltage = ADC_Data_Read();
        Voltage = ((Voltage/255) * 5);
			  HEXA_TO_ASCII(Voltage , display);
        LCD_Cmd_Write(0x80);
        for (i = 0; display[i] != '\0'; i++)
        {
            LCD_Data_Write(display[i]);
        }
        Delay_1ms(1000);
        LCD_Cmd_Write(0x01);
    }
}
