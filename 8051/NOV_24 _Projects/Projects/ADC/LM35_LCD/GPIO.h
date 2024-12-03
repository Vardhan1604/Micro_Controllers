#include <reg51.h>

sbit RD1 = P3^2;
sbit WR1 = P3^3;
sbit INTR = P3^4;
sfr anlog_Read = 0x90;

sbit RS = P0^0;
sbit RW = P0^1;
sbit EN = P0^2;
sbit Busy = P2^7;
sfr LCD = 0xA0;