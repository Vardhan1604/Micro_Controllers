#ifndef DHT11_H
#define DHT11_H

#include "main.h"

// Pin configuration
#define DHT11_PORT GPIOA
#define DHT11_PIN GPIO_PIN_1

// Function prototypes
void DHT11_Init(void);
uint8_t DHT11_Start(void);
uint8_t DHT11_Read(void);
void DHT11_GetData(float *temperature, float *humidity);
void microDelay(uint16_t delay);
#endif // DHT11_H
