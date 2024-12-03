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
#define USART1_TX_Pin GPIO_PIN_12
#define USART1_TX_GPIO_Port GPIOB
#define LD2_Pin GPIO_PIN_11
#define LD2_GPIO_Port GPIOB
#define USART1_RX_Pin GPIO_PIN_8
#define USART1_RX_GPIO_Port GPIOA
#define LD3_Pin GPIO_PIN_8
#define LD3_GPIO_Port GPIOB
#define RCC_OSC32_OUT_Pin GPIO_PIN_15
#define RCC_OSC32_OUT_GPIO_Port GPIOC
#define RCC_OSC32_IN_Pin GPIO_PIN_14
#define RCC_OSC32_IN_GPIO_Port GPIOC
#define B1_Pin GPIO_PIN_13
#define B1_GPIO_Port GPIOC
#define B1_EXTI_IRQn EXTI13_IRQn
#define B3_Pin GPIO_PIN_7
#define B3_GPIO_Port GPIOB
#define B3_EXTI_IRQn EXTI7_IRQn
#define B2_Pin GPIO_PIN_6
#define B2_GPIO_Port GPIOB
#define B2_EXTI_IRQn EXTI6_IRQn
#define LD1_Pin GPIO_PIN_4
#define LD1_GPIO_Port GPIOB
#define DEBUG_JTCK_SWCLK_Pin GPIO_PIN_14
#define DEBUG_JTCK_SWCLK_GPIO_Port GPIOA
#define DEBUG_JTMS_SWDIO_Pin GPIO_PIN_13
#define DEBUG_JTMS_SWDIO_GPIO_Port GPIOA

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
