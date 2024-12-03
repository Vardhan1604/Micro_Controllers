#include "dht11.h"

// GPIO Pin and Port configuration (Adjust according to your setup)
#define DHT11_GPIO_PORT GPIOA
#define DHT11_PIN GPIO_PIN_1

static void DHT11_Delay(uint16_t delay)
{
    HAL_Delay(delay);
}

static void DHT11_GPIO_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    __HAL_RCC_GPIOB_CLK_ENABLE(); // Enable GPIOB clock (adjust if using a different port)

    GPIO_InitStruct.Pin = DHT11_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(DHT11_GPIO_PORT, &GPIO_InitStruct);
}

static void DHT11_Start(void)
{
    HAL_GPIO_WritePin(DHT11_GPIO_PORT, DHT11_PIN, GPIO_PIN_RESET);
    DHT11_Delay(18); // Wait for 18ms
    HAL_GPIO_WritePin(DHT11_GPIO_PORT, DHT11_PIN, GPIO_PIN_SET);
    DHT11_Delay(20); // Wait for 20us
}

static HAL_StatusTypeDef DHT11_Check_Response(void)
{
    uint32_t timeout = HAL_GetTick() + DHT11_TIMEOUT;

    while (HAL_GPIO_ReadPin(DHT11_GPIO_PORT, DHT11_PIN) == GPIO_PIN_SET)
    {
        if (HAL_GetTick() > timeout)
        {
            return HAL_TIMEOUT;
        }
    }

    timeout = HAL_GetTick() + DHT11_TIMEOUT;

    while (HAL_GPIO_ReadPin(DHT11_GPIO_PORT, DHT11_PIN) == GPIO_PIN_RESET)
    {
        if (HAL_GetTick() > timeout)
        {
            return HAL_TIMEOUT;
        }
    }

    timeout = HAL_GetTick() + DHT11_TIMEOUT;

    while (HAL_GPIO_ReadPin(DHT11_GPIO_PORT, DHT11_PIN) == GPIO_PIN_SET)
    {
        if (HAL_GetTick() > timeout)
        {
            return HAL_TIMEOUT;
        }
    }

    return HAL_OK;
}

static uint8_t DHT11_Read_Byte(void)
{
    uint8_t byte = 0;

    for (int i = 0; i < 8; i++)
    {
        while (HAL_GPIO_ReadPin(DHT11_GPIO_PORT, DHT11_PIN) == GPIO_PIN_RESET);

        DHT11_Delay(40);

        if (HAL_GPIO_ReadPin(DHT11_GPIO_PORT, DHT11_PIN) == GPIO_PIN_SET)
        {
            byte |= (1 << (7 - i));
        }

        while (HAL_GPIO_ReadPin(DHT11_GPIO_PORT, DHT11_PIN) == GPIO_PIN_SET);
    }

    return byte;
}

HAL_StatusTypeDef DHT11_Init(void)
{
    DHT11_GPIO_Init();
    return HAL_OK;
}

HAL_StatusTypeDef DHT11_Read(uint8_t *temperature, uint8_t *humidity)
{
    uint8_t data[5];
    HAL_StatusTypeDef status;

    DHT11_Start();
    status = DHT11_Check_Response();

    if (status != HAL_OK)
    {
        return status;
    }

    for (int i = 0; i < 5; i++)
    {
        data[i] = DHT11_Read_Byte();
    }

    if (data[0] + data[1] + data[2] + data[3] + data[4] != data[4])
    {
        return HAL_ERROR; // Check for checksum
    }

    *humidity = data[0];
    *temperature = data[2];

    return HAL_OK;
}
