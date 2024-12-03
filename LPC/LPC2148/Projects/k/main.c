
#include <LPC214x.h>



void init()
{
	PINSEL0 |= 0x50;
	
	I2C0SCLH = 300;
	I2C0SCLL = 300;
	
	I2C0CONSET = 0x40;
	I2C0CONCLR = 0x20;
	
}
void i2c_start()
{
	I2C0CONSET = 0x20;
	while(!(I2C0CONSET & 0x08));
}
void i2c_stop()
{
	I2C0CONSET = 0x10;
	//while(!(I2C0CONSET & 0x08));
}
void send_adress(unsigned char addr)
{
	I2C0DAT = (addr << 1);
	I2C0CONCLR = 0x08;
	while(!(I2C0CONSET & 0x08));
}
void send_data(unsigned char data)
{
	I2C0DAT = data;
	I2C0CONCLR = 0x08;
	while(!(I2C0CONSET & 0x08));
}
void cmd(unsigned char cmd1) {
    unsigned char cmdl, cmdu;
    cmdl = (cmd1 & 0x0F)<<4;  
    cmdu = ((cmd1 >> 4) & 0x0F)<<4;  

    send_data(cmdu | 0x04);
    send_data(cmdu | 0x00); 
    send_data(cmdl | 0x04); 
    send_data(cmdl | 0x00); 
}
void data1(unsigned char cmd1) {
    unsigned char cmdl, cmdu;
    cmdl = (cmd1 & 0x0F)<<4;  
    cmdu = ((cmd1 >> 4) & 0x0F)<<4;  

    send_data(cmdu | 0x05); 
    send_data(cmdu | 0x01); 
    send_data(cmdl | 0x05);
    send_data(cmdl | 0x01); 
}
int main()
{
	init();
	i2c_start();
	send_adress(0x20);
	  cmd(0x02);	
		cmd(0x28);	
		cmd(0x0c);	
		cmd(0x06);	
		cmd(0x01);  
    cmd(0x80);	
	  data1('A');
	data1('B');
	data1('C');
	data1('D');
	i2c_stop();
	while(1);
}