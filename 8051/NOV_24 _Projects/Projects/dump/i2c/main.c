#include <reg51.h>
#include "I2C.h"

sbit SDA = P2^0; 
sbit SCL = P2^1;  

void delay_ms(unsigned int ms) {
    unsigned int i, j;
    for (i = 0; i < ms; i++) {
        for (j = 0; j < 300; j++) {  
        }
    }
}


void cmd(unsigned char cmd1) {
    unsigned char cmdl, cmdu;
    cmdl = (cmd1 & 0x0F)<<4;  
    cmdu = ((cmd1 >> 4) & 0x0F)<<4;  

    i2c_send(cmdu | 0x0C); 
	  delay_ms(1);
    i2c_send(cmdu | 0x08); 
    delay_ms(5);
    i2c_send(cmdl | 0x0C); 
	  delay_ms(1);
    i2c_send(cmdl | 0x08); 
	  delay_ms(10); 
}
void data1(unsigned char cmd1) {
    unsigned char cmdl, cmdu;
    cmdl = (cmd1 & 0x0F)<<4;  
    cmdu = ((cmd1 >> 4) & 0x0F)<<4;  

    i2c_send(cmdu | 0x0D); 
	  delay_ms(1);
    i2c_send(cmdu | 0x09); 
    delay_ms(5);
    i2c_send(cmdl | 0x0D); 
	  delay_ms(1);
    i2c_send(cmdl | 0x09); 
	  delay_ms(10); 
}
void i2c_init(unsigned char num) {
    i2c_start();           
    i2c_send(num);         
    cmd(0x02);	// Return home
		cmd(0x28);	// 4 bit mode
		cmd(0x0c);	// Display On , cursor off
		cmd(0x06);	// Increment Cursor (shift cursor to right)
		cmd(0x01); // clear display       
    cmd(0x80);	
}

void main() {
    i2c_init(0x27<<1);  
	  data1('A');
	data1('E');
    i2c_stop();      
    while(1);        
}
