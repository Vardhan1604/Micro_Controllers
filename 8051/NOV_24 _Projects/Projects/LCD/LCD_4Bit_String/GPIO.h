

#include <reg51.h>
sbit RS = P2^0;
sbit RW = P2^1;
sbit EN = P2^2;
sbit Busy = P2^7;
sfr LCD = 0xA0;
