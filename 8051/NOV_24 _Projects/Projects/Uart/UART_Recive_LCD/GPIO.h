#include<reg51.h>
sbit RS=P3^2;
sbit RW=P3^3;
sbit EN=P3^4;
sbit Busy=P2^7;
sfr LCD=0XA0;
