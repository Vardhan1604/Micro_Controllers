#include "D:\Micro_Controller\8051\NOV_24 _Projects\Lib\Delay\Delay.h"
#include "I2C.h"
#include <reg51.h>

sbit SDA = P2^0;
sbit SCL = P2^1;

void I2C_Start() {
    SDA = 1;  
    SCL = 1;  
    Delay_1ms(1);  
    SDA = 0;  
    Delay_1ms(1);  
    SCL = 0; 
}

void I2C_Stop() {
    SCL = 1; 
    Delay_1ms(1);  
    SDA = 0;  
    Delay_1ms(1);  
    SDA = 1;  
}

void Send_Data(unsigned char data1) {
    int i;
    for (i = 7; i >= 0; i--) {
        SDA = (data1 >> i) & 0x01;  
        Delay_1ms(1);  
        SCL = 1;  
        Delay_1ms(1);  
        SCL = 0;  
        Delay_1ms(1); 
    }
    if (SDA == 0) {
        SCL = 1;  
        Delay_1ms(1);  
        SCL = 0;  
        Delay_1ms(1); 
    } else {
        I2C_Stop();
        while(1);  
    }
}
