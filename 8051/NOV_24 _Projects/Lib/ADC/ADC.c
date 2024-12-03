
#include "GPIO.h"
#include "ADC.h"
#include "D:\Micro_Controller\8051\NOV_24 _Projects\Lib\Delay\Delay.h"
#include "D:\Micro_Controller\8051\NOV_24 _Projects\Lib\LCD\LCD.h"

void ADC_Init(void)
{
	INTR = 1;
	RD1 = 1;
	WR1 = 1;
	anlog_Read = 0xff;
}
unsigned char ADC_Data_Read(void)
{

    unsigned char mydata;
    WR1 = 0;
		Delay_1ms(10);
		WR1 = 1;
	  while(INTR == 1);
		RD1 = 0;
		mydata = anlog_Read;
		RD1 =1;
		return mydata;
}
void HEXA_TO_ASCII(float num, unsigned char *str) {
    int intPart = (int)num;  
    int fracPart = (int)((num - intPart) * 100);  
    
    str[0] = (intPart / 100) % 10 + '0';
    str[1] = (intPart / 10) % 10 + '0';
    str[2] = intPart % 10 + '0';
    str[3] = '.';  
    str[4] = (fracPart / 10) + '0';
    str[5] = fracPart % 10 + '0';
    str[6] = '\0';
}

