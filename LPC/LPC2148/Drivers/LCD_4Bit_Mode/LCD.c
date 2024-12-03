#include "LCD.h"
#include "D:\Micro_Controller\8051\NOV_24 _Projects\Lib\Delay\Delay.h"

void LCD_Cmd_Write(unsigned char Cmd)
{
    IOPIN0 = (IOPIN0 & ~LCD) | (Cmd & 0xF0); 	
    IOCLR0 = RS; 															
    IOSET0 = EN;															
    Delay_1ms(1);
    IOCLR0 = EN; 														

    IOPIN0 = (IOPIN0 & ~LCD) | ((Cmd & 0x0F) << 4); 
    IOSET0 = EN; 															
    Delay_1ms(1);
    IOCLR0 = EN; 														
}

void LCD_Data_Write(unsigned char lcd_data)
{
    IOPIN0 = (IOPIN0 & ~LCD) | (lcd_data & 0xF0); 
    IOSET0 = RS; 
    IOSET0 = EN; 
    Delay_1ms(1);
    IOCLR0 = EN; 

    IOPIN0 = (IOPIN0 & ~LCD) | ((lcd_data & 0x0F) << 4); 
    IOSET0 = EN; 
    Delay_1ms(1);
    IOCLR0 = EN; 
}

void LCD_Init(void)
{
    unsigned char a[6] = {0x02, 0x28, 0x0C, 0x01, 0x06, 0x80}; 
    unsigned int i;
    IODIR0 |= (LCD | RS | EN);

    Delay_1ms(20); 
    for (i = 0; i < 6; i++)
    {
        LCD_Cmd_Write(a[i]); 
        Delay_1ms(10);
    }
}

void Sprint(const char *str)
{
    while (*str)
    {
        LCD_Data_Write(*str);
        str++;
    }
}