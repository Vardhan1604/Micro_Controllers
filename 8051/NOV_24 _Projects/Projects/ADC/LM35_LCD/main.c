#include "D:\Micro_Controller\8051\NOV_24 _Projects\Lib\Delay\Delay.h"
#include "D:\Micro_Controller\8051\NOV_24 _Projects\Lib\LCD\LCD.h"
#include "D:\Micro_Controller\8051\NOV_24 _Projects\Lib\ADC\ADC.h"

#include "GPIO.h"
#include <stdio.h>

void main()
{
    char Display[30];
    LCD_Init();
    ADC_Init();
    LCD_Sprint("WELCOME");
    Delay_1ms(1000);
    LCD_Cmd_Write(0x01);
    while (1)
    {
        float Temperature;
        Temperature = ADC_Data_Read();
        Temperature = (Temperature * 2);
        sprintf(Display, "TEMP: %.2f *C", Temperature);
        LCD_Cmd_Write(0x80);
        LCD_Sprint(Display);
        Delay_1ms(1000);
        LCD_Cmd_Write(0x01);
    }
}
