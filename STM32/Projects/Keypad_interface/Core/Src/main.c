/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include"i2c-lcd.h"
#include <string.h> // For strcmp
#include <stdio.h>  // For memset/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

I2C_HandleTypeDef hi2c1;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_ICACHE_Init(void);
static void MX_I2C1_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/*
char keypad_scan[4][4]={{'D','0','#','*'},
			            {'C','8','9','7'},
					    {'B','5','6','4'},
	                    {'A','2','3','1'}};
*/



#define INPUT_SIZE 5 // Define size to include null terminator
#define MUSK_SIZE 5  // Size for the masked input
char input[INPUT_SIZE];
char MUSK[MUSK_SIZE]; // Array to store masked input
int i = 0;
int j = 0; // Index for masked input
int last_key = 0;

// Presumably defined elsewhere
const char* pass = "1234"; // Example password

unsigned char num;

char keypad_press()
{

	HAL_GPIO_WritePin(GPIOB,R1_Pin|R4_Pin|R2_Pin|R3_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB,R1_Pin, GPIO_PIN_RESET);
	if((HAL_GPIO_ReadPin(GPIOB, C1_Pin)== 0)){HAL_Delay(250); num = 'D';}
	if((HAL_GPIO_ReadPin(GPIOB, C2_Pin)== 0)){HAL_Delay(250); num = 'c';}
	if((HAL_GPIO_ReadPin(GPIOA, C3_Pin)== 0)){HAL_Delay(250); num = 'B';}
	if((HAL_GPIO_ReadPin(GPIOA, C4_Pin)== 0)){HAL_Delay(250); num = 'A';}
	HAL_GPIO_WritePin(GPIOB,R1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB,R2_Pin, GPIO_PIN_RESET);
	if((HAL_GPIO_ReadPin(GPIOB, C1_Pin)== 0)){HAL_Delay(250);  num = '0';}
	if((HAL_GPIO_ReadPin(GPIOB, C2_Pin)== 0)){HAL_Delay(250);  num = '8';}
	if((HAL_GPIO_ReadPin(GPIOA, C3_Pin)== 0)){HAL_Delay(250);  num = '5';}
	if((HAL_GPIO_ReadPin(GPIOA, C4_Pin)== 0)){HAL_Delay(250);  num = '2';}
	HAL_GPIO_WritePin(GPIOB,R2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB,R3_Pin, GPIO_PIN_RESET);
	if((HAL_GPIO_ReadPin(GPIOB, C1_Pin)== 0)){HAL_Delay(250);  num = '#';}
	if((HAL_GPIO_ReadPin(GPIOB, C2_Pin)== 0)){HAL_Delay(250);  num = '9';}
	if((HAL_GPIO_ReadPin(GPIOA, C3_Pin)== 0)){HAL_Delay(250);  num = '6';}
	if((HAL_GPIO_ReadPin(GPIOA, C4_Pin)== 0)){HAL_Delay(250);  num = '3';}
	HAL_GPIO_WritePin(GPIOB,R3_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB,R4_Pin, GPIO_PIN_RESET);
	if((HAL_GPIO_ReadPin(GPIOB, C1_Pin)== 0)){HAL_Delay(250);  num = '*';}
	if((HAL_GPIO_ReadPin(GPIOB, C2_Pin)== 0)){HAL_Delay(250);  num = '7';}
	if((HAL_GPIO_ReadPin(GPIOA, C3_Pin)== 0)){HAL_Delay(250);  num = '4';}
	if((HAL_GPIO_ReadPin(GPIOA, C4_Pin)== 0)){HAL_Delay(250);  num = '1';}
	HAL_GPIO_WritePin(GPIOB,R4_Pin, GPIO_PIN_SET);

    if(num != '\0')
    {
    	return num;
    }
    else
    {
    	return 0;
    }
}


unsigned char Enter_Password() {
    char key = keypad_press(); // Read the key from the keypad
    int result = 0; // Initialize result for comparison

    if (key != 0 && key != last_key) {
        if (i < INPUT_SIZE - 1) { // Ensure there's space for the null terminator
            input[i++] = key; // Store the actual key
            input[i] = '\0'; // Null-terminate the string

            if (j < MUSK_SIZE - 1) { // Ensure space for the masked input
                MUSK[j++] = '*'; // Store a mask character
                MUSK[j] = '\0'; // Null-terminate the masked string
            }

            lcd_put_cur(1, 0);
            lcd_send_string(MUSK); // Display the masked input
        }

        last_key = key; // Update last_key to the currently pressed key
    } else if (key == 0) {
        last_key = 0; // Reset last_key when no key is pressed
    }

    if (i == 4) { // Check if the password is of expected length
        result = strcmp(pass, input);

        lcd_put_cur(1, 0);
        if (result == 0) {
            lcd_send_string("match  "); // Display "match"
        } else {
            lcd_send_string("not match");
            HAL_Delay(1000);
            lcd_clear();
        }

        // Reset input for the next attempt
        memset(input, 0, INPUT_SIZE); // Clear the input buffer
        memset(MUSK, 0, MUSK_SIZE); // Clear the masked input
        i = 0; // Reset index for next input
        j = 0; // Reset masked input index
    }

    return (i == 4 && result == 0) ? 1 : 0; // Return 1 if password matches, else return 0
}



/**
 *
  * @brief  The application entry point.
  *
  *
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_ICACHE_Init();
  MX_I2C1_Init();
  /* USER CODE BEGIN 2 */
  lcd_init();
  lcd_put_cur(0,0);
  lcd_send_string("lcd start");
  HAL_Delay(1000);
  lcd_clear();



  /* USER CODE END 2 */

while (1) {

	Enter_Password();

}
  /* Infinite loop */
  /* USER CODE BEGIN WHILE */

	}
    /* USER CODE BEGIN 3 */
  /* USER CODE END 3 *

/*
  * @brief System Clock Configuration
  * @retval None
  */

void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  if (HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB busses clocks
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL1.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB busses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2
                              |RCC_CLOCKTYPE_PCLK7|RCC_CLOCKTYPE_HCLK5;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB7CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.AHB5_PLL1_CLKDivider = RCC_SYSCLK_PLL1_DIV1;
  RCC_ClkInitStruct.AHB5_HSEHSI_CLKDivider = RCC_SYSCLK_HSEHSI_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief I2C1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_I2C1_Init(void)
{

  /* USER CODE BEGIN I2C1_Init 0 */

  /* USER CODE END I2C1_Init 0 */

  /* USER CODE BEGIN I2C1_Init 1 */

  /* USER CODE END I2C1_Init 1 */
  hi2c1.Instance = I2C1;
  hi2c1.Init.Timing = 0x00303D5B;
  hi2c1.Init.OwnAddress1 = 0;
  hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c1.Init.OwnAddress2 = 0;
  hi2c1.Init.OwnAddress2Masks = I2C_OA2_NOMASK;
  hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c1) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure Analogue filter
  */
  if (HAL_I2CEx_ConfigAnalogFilter(&hi2c1, I2C_ANALOGFILTER_ENABLE) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure Digital filter
  */
  if (HAL_I2CEx_ConfigDigitalFilter(&hi2c1, 0) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2C1_Init 2 */

  /* USER CODE END I2C1_Init 2 */

}

/**
  * @brief ICACHE Initialization Function
  * @param None
  * @retval None
  */
static void MX_ICACHE_Init(void)
{

  /* USER CODE BEGIN ICACHE_Init 0 */

  /* USER CODE END ICACHE_Init 0 */

  /* USER CODE BEGIN ICACHE_Init 1 */

  /* USER CODE END ICACHE_Init 1 */

  /** Enable instruction cache in 1-way (direct mapped cache)
  */
  if (HAL_ICACHE_ConfigAssociativityMode(ICACHE_1WAY) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_ICACHE_Enable() != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN ICACHE_Init 2 */

  /* USER CODE END ICACHE_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB,R1_Pin|LD1_Pin
                          |R4_Pin|R2_Pin|R3_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : USART1_TX_Pin */
  GPIO_InitStruct.Pin = USART1_TX_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.Alternate = GPIO_AF7_USART1;
  HAL_GPIO_Init(USART1_TX_GPIO_Port, &GPIO_InitStruct);


  /*Configure GPIO pin : USART1_RX_Pin */
  GPIO_InitStruct.Pin = USART1_RX_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.Alternate = GPIO_AF7_USART1;
  HAL_GPIO_Init(USART1_RX_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : C1_Pin C2_Pin */
  GPIO_InitStruct.Pin = C1_Pin|C2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);


  /*Configure GPIO pins : R1_Pin R4_Pin R2_Pin R3_Pin */
  GPIO_InitStruct.Pin = R1_Pin|R4_Pin|R2_Pin|R3_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : C4_Pin C3_Pin */
  GPIO_InitStruct.Pin = C4_Pin|C3_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /* EXTI interrupt init*/
  HAL_NVIC_SetPriority(EXTI7_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI7_IRQn);

  HAL_NVIC_SetPriority(EXTI13_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI13_IRQn);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
