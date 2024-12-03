#include <reg51.h> 

sbit TX_PIN = P2^0 ;
sbit RX_PIN = P2^1 ;
int i;
void Delay(unsigned int num)
{
	unsigned int i,j;
  for(i = 0; i < num; i++)
	{
		for(j = 0; j < 127; j++);
	}
}
void Tdelay() {
	
     TMOD = 0x01;
	  TH0 =0xff;
	  TL0 = -57;  // at 9600 baud rate
	  TR0 = 1;
	  while( TF0 == 0);
	  TF0 = 0;
	  TR0 = 0;
}


void Uart_Send(unsigned char data_) {
    unsigned char i;

    
    TX_PIN = 0;  
    Tdelay();  

    
    for (i = 0; i < 8; i++) {
        TX_PIN = (data_ >> i) & 0x01; 
        Tdelay(); 
    }

    TX_PIN = 1;  
    Tdelay();  
}
void Send_Str(unsigned char *Str)
{
	while(*Str)
	{
		Uart_Send(*Str);
		Str++;
		Delay(1);
	}		
}
void main() {
        Send_Str("WEL COME");
			  Delay(1);
	while(1);
}