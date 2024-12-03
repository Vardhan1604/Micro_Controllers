
#include "LED.h"
#include "GPIO.h"
#include "..\Delay\Delay.h"


void LED1_ON(void)
{
    LED1 = 1;
}
void LED2_ON(void)
{
   LED2 = 1;
}
void LED1_OFF(void)
{
    LED1 = 0;
}
void LED2_OFF(void)
{
	 LED2 = 0;
}
void LED1_Toggle(void)
{
	 LED1 = ~LED1;
}
void LED2_Toggle(void)
{
	 LED2 = ~LED1;
}

void Even_LED_S(void)
{
    Port1 = 0xAA;
}

void ODD_LED_S(void)
{
    Port1 = 0x55;
}

void Port1_00_FF(void)
{
    unsigned char i;
    for(i = 0;  i < 8; i++)
    {
        Port1 |= (1 << i);
        Delay_1ms(100);     
    }
}

void Port1_FF_00(void)
{
    unsigned char i;
    for(i = 0;  i < 8; i++)
    {
        Port1 &= ~(1 << i); 
        Delay_1ms(100);    
    }
}

void LED_Moving(void)
{
    unsigned char i;
    for(i = 0; i < 8; i++)
    {
        Port1 = 0;              
        Port1 |= (1 << i);      
        Delay_1ms(100);     
    }
}