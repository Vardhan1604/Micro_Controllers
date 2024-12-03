#include "GPIO.h"
#include "LCD.h"
#include "D:\Micro_Controller\8051\NOV_24 _Projects\Lib\Delay\Delay.h"

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
    LCD = (Cmd & 0xF0);
    RS = 0;
    RW = 0;
    EN = 1;
    Delay_1ms(1);
    EN = 0;

    LCD = (Cmd << 4) & 0xF0;
    EN = 1;
    Delay_1ms(1);
    EN = 0;
}

void LCD_Data_Write(unsigned char lcd_data)
{
    LCD_Busy();
    LCD = (LCD & 0x0f)|(lcd_data & 0xF0);
    RS = 1;
    RW = 0;
    EN = 1;
    Delay_1ms(1);
    EN = 0;

    LCD =  (LCD & 0x0f)|(lcd_data << 4) & 0xF0;
    EN = 1;
    Delay_1ms(1);
    EN = 0;
}

void LCD_Init(void)
{
    unsigned char a[6] = {0x02, 0x28, 0x0c, 0x01, 0x06, 0x80};
    unsigned int i;

    for (i = 0; i < 6; i++)
    {
        LCD_Cmd_Write(a[i]);
        Delay_1ms(10);
    }
}

void Sprint(unsigned char *str)
{
    while (*str)
    {
        LCD_Data_Write(*str);
        str++;
    }
}
