#ifndef DHT11_H
#define DHT11_H

#include "main.h"
#include"stm32wbaxx_hal_tim.h"

#define DHT11_PORT GPIOB
#define DHT11_PIN GPIO_PIN_7

extern uint8_t RHI, RHD, TCI, TCD, SUM; // Declare the variables as extern
extern float tCelsius, tFahrenheit, RH; // Also declare float variables

uint8_t DHT11_Start(void);
uint8_t DHT11_Read(void);
void microDelay(uint16_t delay);
void DHT_SCAN(float *tCelsius, float *RH);

#endif // DHT11_H
