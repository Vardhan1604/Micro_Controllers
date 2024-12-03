#ifndef DHT11_H
#define DHT11_H

#include "stm32wbaxx_hal.h" // Adjust for your specific STM32WBA52 MCU header

#define DHT11_TIMEOUT 1000 // Timeout for communication

// Function prototypes
HAL_StatusTypeDef DHT11_Init(void);
HAL_StatusTypeDef DHT11_Read(uint8_t *temperature, uint8_t *humidity);

#endif // DHT11_H
