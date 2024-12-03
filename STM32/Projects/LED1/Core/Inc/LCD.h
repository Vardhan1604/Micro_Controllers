#ifndef LCD_H
#define LCD_H

#include <stm32wba52xx.h>

#include "main.h"


// Data pins array for D0 to D7
extern GPIO_TypeDef* data_ports[8];
extern uint16_t data_pins[8];

// Function prototypes
void LCD_cmd(unsigned char cmd);
void LCD_data(unsigned char data);
void LCD_init(void);
void LCD_Print(const char *str);

#endif // LCD_H
