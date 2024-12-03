#ifndef LCD_H  
#define LCD_H

#include <LPC21xx.h>

#define RS (1 << 9)
#define EN (1 << 10)
#define LCD 0xF0


 
 
void LCD_Busy(void);
void LCD_Cmd_Write(unsigned char cmd);
void LCD_Data_Write(unsigned char data);
void LCD_Init(void);
void Sprint(const char*);

#endif  
