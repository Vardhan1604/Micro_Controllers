
#include "GPIO.h"
#include "D:\Micro_Controller\8051\NOV_24 _Projects\Lib\Delay\Delay.h"
#include "D:\Micro_Controller\8051\NOV_24 _Projects\Lib\LCD\LCD.h"


void LCD_Busy(void)
{
    Busy = 1;
    RS = 0;
    RW = 1;
    while (Busy == 0);
}

void LCD_Cmd_Write(unsigned char Cmd)
{
    LCD_Busy();
    LCD = Cmd;
    RS = 0;
    RW = 0;
    EN = 1;
    Delay_1ms(1);
    EN = 0;
}

void LCD_Data_Write(unsigned char lcd_data)
{
    LCD_Busy();
    LCD = lcd_data;
    RS = 1;
    RW = 0;
    EN = 1;
    Delay_1ms(1);
    EN = 0;
}

void LCD_Init(void)
{
    unsigned char a[6] = {0x38, 0x0e, 0x01, 0x06, 0x0c, 0x80};
    unsigned int i;
    for (i = 0; i < 6; i++)
    {
        LCD_Cmd_Write(a[i]);
        Delay_1ms(10);
    }
}
void LCD_Sprint(unsigned char *str)
{
    while (*str)
    {
        LCD_Data_Write(*str);
        str++;
    }
}
