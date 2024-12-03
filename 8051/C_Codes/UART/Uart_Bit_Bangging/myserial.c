

void myserial1(Rx , Tx)
{

void Serial_Write(unsigned char x)
{
for(i =0; i < 8 ; i++)
{
 Tx = (x << 1);
 Delay();
}
}
unsigned char Serial_Read(void)
{
for(i =0; i < 8 ; i++)
{
(Rx >> 1) = val;
 Delay();
}
}
}
