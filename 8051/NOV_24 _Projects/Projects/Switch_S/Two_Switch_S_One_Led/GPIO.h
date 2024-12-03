#include <reg51.h>

sbit LED1 = P2^0;
sbit LED2 = P2^1;
sbit Sw   = P1^0;
sbit Sw1  = P1^1;


sfr Port1 = 0xA0;