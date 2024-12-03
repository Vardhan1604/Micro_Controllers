#ifndef LCD_H  
#define LCD_H

 void LCD_Busy(void);
 void LCD_Cmd_Write(unsigned char);
 void LCD_Data_Write(unsigned char);
 void LCD_Init(void); 
 void LCD_Sprint(const char*);
 
 #endif