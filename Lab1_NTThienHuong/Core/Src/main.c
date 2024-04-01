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

/* Private includes ----------------------------------------------------------*/
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

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
void display7SEG(int num)
{
    uint16_t segments[] = {A_Pin, B_Pin, C_Pin, D_Pin, E_Pin, F_Pin, G_Pin};

    uint8_t patterns[] = {
        0b0111111,  // 0
        0b0000110,  // 1
        0b1011011,  // 2
        0b1001111,  // 3
        0b1100110,  // 4
        0b1101101,  // 5
        0b1111101,  // 6
        0b0000111,  // 7
        0b1111111,  // 8
        0b1101111   // 9
    };

    if (num >= 0 && num <= 9) {
        uint8_t pattern = patterns[num];

        for (int i = 0; i < 7; i++) {
            // Check if the i-th bit of pattern is set (1)
            if ((pattern >> i) & 0x01) {
                HAL_GPIO_WritePin(GPIOB, segments[i], GPIO_PIN_RESET);
            } else {
                HAL_GPIO_WritePin(GPIOB, segments[i], GPIO_PIN_SET);
            }
        }
    }
}

void display7SEG2(int num)
{
    uint16_t segments[] = {A_2_Pin, B_2_Pin, C_2_Pin, D_2_Pin, E_2_Pin, F_2_Pin, G_2_Pin};

    uint8_t patterns[] = {
        0b0111111,  // 0
        0b0000110,  // 1
        0b1011011,  // 2
        0b1001111,  // 3
        0b1100110,  // 4
        0b1101101,  // 5
        0b1111101,  // 6
        0b0000111,  // 7
        0b1111111,  // 8
        0b1101111   // 9
    };

    if (num >= 0 && num <= 9) {
        uint8_t pattern = patterns[num];

        for (int i = 0; i < 7; i++) {
            // Check if the i-th bit of pattern is set (1)
            if ((pattern >> i) & 0x01) {
                HAL_GPIO_WritePin(GPIOB, segments[i], GPIO_PIN_RESET);
            } else {
                HAL_GPIO_WritePin(GPIOB, segments[i], GPIO_PIN_SET);
            }
        }
    }
}

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
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
  /* USER CODE BEGIN 2 */
  int counterLed = 5 , counterLed2 = 3;
  int status = 1 , status2 = 0;
  HAL_GPIO_WritePin(GPIOA, LED_RED_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(GPIOA, LED_YELLOW_Pin | LED_GREEN_Pin, GPIO_PIN_RESET);

  HAL_GPIO_WritePin(GPIOA, LED_GREEN_2_Pin , GPIO_PIN_SET);
  HAL_GPIO_WritePin(GPIOA, LED_YELLOW_2_Pin | LED_RED_2_Pin, GPIO_PIN_RESET);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
//     USER CODE END WHILE

	  if (counterLed == 0){
		  counterLed--;
		  if (counterLed == 0){
			  switch (status){
			  	  case 0:
			  		counterLed = 2;
			  		HAL_GPIO_WritePin(GPIOA, LED_YELLOW_Pin , GPIO_PIN_SET);
			  		HAL_GPIO_WritePin(GPIOA, LED_RED_Pin | LED_GREEN_Pin, GPIO_PIN_RESET);
			  		status = 2;
			  		break;
			  	  case 1:
			  		counterLed = 3;
				  	HAL_GPIO_WritePin(GPIOA,  LED_GREEN_Pin, GPIO_PIN_SET);
				  	HAL_GPIO_WritePin(GPIOA, LED_YELLOW_Pin | LED_RED_Pin, GPIO_PIN_RESET);
				  	status = 0;
				  	break;
			  	  case 2:
			  		counterLed = 5;
				  	HAL_GPIO_WritePin(GPIOA, LED_RED_Pin, GPIO_PIN_SET);
				  	HAL_GPIO_WritePin(GPIOA, LED_YELLOW_Pin | LED_GREEN_Pin, GPIO_PIN_RESET);
				  	status = 1 ;
				  	break;
			  	  default:
			  		break;
			  }
		  }
	  }
	  if (counterLed2 == 0){
		  counterLed2--;
		  if (counterLed2 == 0){
			  switch (status2){
			  	  case 0:
			  		counterLed2 = 2;
			  		HAL_GPIO_WritePin(GPIOA, LED_YELLOW_2_Pin , GPIO_PIN_SET);
			  		HAL_GPIO_WritePin(GPIOA, LED_RED_2_Pin | LED_GREEN_2_Pin, GPIO_PIN_RESET);
			  		status2 = 2;
			  		break;
			  	  case 1:
			  		counterLed2 = 3;
				  	HAL_GPIO_WritePin(GPIOA,  LED_GREEN_2_Pin, GPIO_PIN_SET);
				  	HAL_GPIO_WritePin(GPIOA, LED_YELLOW_2_Pin | LED_RED_2_Pin, GPIO_PIN_RESET);
				  	status2 = 0;
				  	break;
			  	  case 2:
			  		counterLed2 = 5;
				  	HAL_GPIO_WritePin(GPIOA, LED_RED_2_Pin, GPIO_PIN_SET);
				  	HAL_GPIO_WritePin(GPIOA, LED_YELLOW_2_Pin | LED_GREEN_2_Pin, GPIO_PIN_RESET);
				  	status2 = 1 ;
				  	break;
			  	  default:
			  		break;
			  }
		  }
	  }
	  display7SEG (counterLed) ;
	  display7SEG2 (counterLed2) ;
	  HAL_Delay(1000);
//     USER CODE BEGIN 3
  }
//   USER CODE END 3
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
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
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, LED_RED_Pin|LED_YELLOW_Pin|LED_GREEN_Pin|LED_RED_2_Pin
                          |LED_YELLOW_2_Pin|LED_GREEN_2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, A_Pin|B_Pin|C_Pin|B_2_Pin
                          |C_2_Pin|D_2_Pin|E_2_Pin|F_2_Pin
                          |G_2_Pin|D_Pin|E_Pin|F_Pin
                          |G_Pin|A_2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : LED_RED_Pin LED_YELLOW_Pin LED_GREEN_Pin LED_RED_2_Pin
                           LED_YELLOW_2_Pin LED_GREEN_2_Pin */
  GPIO_InitStruct.Pin = LED_RED_Pin|LED_YELLOW_Pin|LED_GREEN_Pin|LED_RED_2_Pin
                          |LED_YELLOW_2_Pin|LED_GREEN_2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : A_Pin B_Pin C_Pin B_2_Pin
                           C_2_Pin D_2_Pin E_2_Pin F_2_Pin
                           G_2_Pin D_Pin E_Pin F_Pin
                           G_Pin A_2_Pin */
  GPIO_InitStruct.Pin = A_Pin|B_Pin|C_Pin|B_2_Pin
                          |C_2_Pin|D_2_Pin|E_2_Pin|F_2_Pin
                          |G_2_Pin|D_Pin|E_Pin|F_Pin
                          |G_Pin|A_2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

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
