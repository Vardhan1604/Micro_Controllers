/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32wbaxx_hal.h"
#include "stm32wbaxx_nucleo.h"
#include <stdio.h>

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define DHT11_Pin GPIO_PIN_1
#define DHT11_GPIO_Port GPIOA
#define D2_Pin GPIO_PIN_9
#define D2_GPIO_Port GPIOB
#define RCC_OSC32_OUT_Pin GPIO_PIN_15
#define RCC_OSC32_OUT_GPIO_Port GPIOC
#define RCC_OSC32_IN_Pin GPIO_PIN_14
#define RCC_OSC32_IN_GPIO_Port GPIOC
#define RS_Pin GPIO_PIN_7
#define RS_GPIO_Port GPIOB
#define RW_Pin GPIO_PIN_6
#define RW_GPIO_Port GPIOB
#define D7_Pin GPIO_PIN_3
#define D7_GPIO_Port GPIOB
#define D6_Pin GPIO_PIN_15
#define D6_GPIO_Port GPIOA
#define DEBUG_JTCK_SWCLK_Pin GPIO_PIN_14
#define DEBUG_JTCK_SWCLK_GPIO_Port GPIOA
#define DEBUG_JTMS_SWDIO_Pin GPIO_PIN_13
#define DEBUG_JTMS_SWDIO_GPIO_Port GPIOA
#define D5_Pin GPIO_PIN_12
#define D5_GPIO_Port GPIOA
#define D1_Pin GPIO_PIN_0
#define D1_GPIO_Port GPIOB
#define D3_Pin GPIO_PIN_15
#define D3_GPIO_Port GPIOB
#define D4_Pin GPIO_PIN_9
#define D4_GPIO_Port GPIOA
#define D0_Pin GPIO_PIN_14
#define D0_GPIO_Port GPIOB
#define EN_Pin GPIO_PIN_13
#define EN_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
