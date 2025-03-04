#include "LCD.h"
#include "main.h"
// Data pins array for D0 to D7
GPIO_TypeDef* data_ports[8] = {GPIOB, GPIOB, GPIOB, GPIOB, GPIOA, GPIOA, GPIOA, GPIOB};
uint16_t data_pins[8] = {GPIO_PIN_14, GPIO_PIN_0, GPIO_PIN_9, GPIO_PIN_15, GPIO_PIN_9, GPIO_PIN_12, GPIO_PIN_15, GPIO_PIN_3};

// Function to wait until the LCD is not busy

// Function to send a command to the LCD
void LCD_cmd(unsigned char cmd) {


	// Send the command to the data pins
    for (int i = 0; i < 8; i++) {
        HAL_GPIO_WritePin(data_ports[i], data_pins[i], (cmd & (1 << i)));
    }

    HAL_GPIO_WritePin(GPIOB, RS_Pin, GPIO_PIN_RESET); // Command mode
    HAL_GPIO_WritePin(GPIOB, RW_Pin, GPIO_PIN_RESET); // Write mode
    HAL_GPIO_WritePin(GPIOB, EN_Pin, GPIO_PIN_SET);   // Enable
    HAL_Delay(1);                                     // Short delay
    HAL_GPIO_WritePin(GPIOB, EN_Pin, GPIO_PIN_RESET); // Disable
}

// Function to send data to the LCD
void LCD_data(unsigned char data) {

    // Send the data to the data pins
    for (int i = 0; i < 8; i++) {
        HAL_GPIO_WritePin(data_ports[i], data_pins[i], (data & (1 << i)));
    }

    HAL_GPIO_WritePin(GPIOB, RS_Pin, GPIO_PIN_SET);   // Data mode
    HAL_GPIO_WritePin(GPIOB, RW_Pin, GPIO_PIN_RESET); // Write mode
    HAL_GPIO_WritePin(GPIOB, EN_Pin, GPIO_PIN_SET);   // Enable
    HAL_Delay(1);                                     // Short delay
    HAL_GPIO_WritePin(GPIOB, EN_Pin, GPIO_PIN_RESET); // Disable
}

// Function to initialize the LCD
void LCD_init() {
    unsigned char init_cmds[5] = {0x01, 0x0C, 0x06, 0x38, 0x80}; // Clear, Display ON, Entry mode, Function set, Set cursor

    // Initialize the LCD with commands
    for (int i = 0; i < 5; i++) {
        LCD_cmd(init_cmds[i]);
        HAL_Delay(10); // Wait for initialization commands to complete
    }
}

// Function to print a string to the LCD
void LCD_Print(const char *str) {
    while (*str) {
        LCD_data(*str++);
    }
}
