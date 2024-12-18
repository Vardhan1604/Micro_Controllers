#include "dht11.h"
#include "i2c-lcd.h"


uint8_t RHI, RHD, TCI, TCD, SUM;
uint32_t pMillis, cMillis;
float tCelsius = 0;
float tFahrenheit = 0;
float RH = 0;



uint8_t DHT11_Start(void) {
    uint8_t Response = 0;
    GPIO_InitTypeDef GPIO_InitStructPrivate = {0};
    GPIO_InitStructPrivate.Pin = DHT11_PIN;
    GPIO_InitStructPrivate.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStructPrivate.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_InitStructPrivate.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(DHT11_PORT, &GPIO_InitStructPrivate); // set the pin as output
    HAL_GPIO_WritePin(DHT11_PORT, DHT11_PIN, 0);   // pull the pin low
    HAL_Delay(20);   // wait for 20ms
    HAL_GPIO_WritePin(DHT11_PORT, DHT11_PIN, 1);   // pull the pin high
    microDelay(30);   // wait for 30us
    GPIO_InitStructPrivate.Mode = GPIO_MODE_INPUT;
    GPIO_InitStructPrivate.Pull = GPIO_PULLUP;
    HAL_GPIO_Init(DHT11_PORT, &GPIO_InitStructPrivate); // set the pin as input
    microDelay(40);

    if (!(HAL_GPIO_ReadPin(DHT11_PORT, DHT11_PIN))) {
        microDelay(80);
        if ((HAL_GPIO_ReadPin(DHT11_PORT, DHT11_PIN))) Response = 1;
    }

    pMillis = HAL_GetTick();
    cMillis = HAL_GetTick();
    while ((HAL_GPIO_ReadPin(DHT11_PORT, DHT11_PIN)) && (pMillis + 2 > cMillis)) {
        cMillis = HAL_GetTick();
    }
    return Response;
}

uint8_t DHT11_Read(void) {
    uint8_t a, b = 0; // Initialize b
    for (a = 0; a < 8; a++) {
        pMillis = HAL_GetTick();
        cMillis = HAL_GetTick();
        while (!(HAL_GPIO_ReadPin(DHT11_PORT, DHT11_PIN)) && (pMillis + 2 > cMillis)) {
            cMillis = HAL_GetTick();
        }
        microDelay(40);   // wait for 40 us
        if (!(HAL_GPIO_ReadPin(DHT11_PORT, DHT11_PIN))) {
            b &= ~(1 << (7 - a));
        } else {
            b |= (1 << (7 - a));
        }
        pMillis = HAL_GetTick();
        cMillis = HAL_GetTick();
        while ((HAL_GPIO_ReadPin(DHT11_PORT, DHT11_PIN)) && (pMillis + 2 > cMillis)) {
            cMillis = HAL_GetTick();
        }
    }
    return b;
}
void DHT_SCAN(float *tCelsius, float *RH) {
    if (DHT11_Start()) {
        uint8_t RHI = DHT11_Read(); // Relative humidity integral
        uint8_t RHD = DHT11_Read(); // Relative humidity decimal
        uint8_t TCI = DHT11_Read(); // Celsius integral
        uint8_t TCD = DHT11_Read(); // Celsius decimal
        uint8_t SUM = DHT11_Read(); // Check sum

        if (RHI + RHD + TCI + TCD == SUM) {
            *tCelsius = (float)TCI + (float)(TCD / 10.0);
            *RH = (float)RHI + (float)(RHD / 10.0);
        } else {
            lcd_put_cur(0, 0);
            lcd_send_string("error");
        }
    }
}
