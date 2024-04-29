/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
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
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
//TODO
#include <string.h>
#include <stdbool.h>

//TODO
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
#define PE_LE_Pin GPIO_PIN_0
#define PE_LE_GPIO_Port GPIOA
#define PE_CLK_Pin GPIO_PIN_1
#define PE_CLK_GPIO_Port GPIOA
#define PE_SI1_Pin GPIO_PIN_2
#define PE_SI1_GPIO_Port GPIOA
#define PE_SI2_Pin GPIO_PIN_3
#define PE_SI2_GPIO_Port GPIOA
#define PE_SI3_Pin GPIO_PIN_4
#define PE_SI3_GPIO_Port GPIOA
#define PE_SI4_Pin GPIO_PIN_5
#define PE_SI4_GPIO_Port GPIOA
#define PE_SI5_Pin GPIO_PIN_6
#define PE_SI5_GPIO_Port GPIOA
#define PE_SI6_Pin GPIO_PIN_7
#define PE_SI6_GPIO_Port GPIOA
#define PE_SI10_Pin GPIO_PIN_0
#define PE_SI10_GPIO_Port GPIOB
#define PE_SI11_Pin GPIO_PIN_1
#define PE_SI11_GPIO_Port GPIOB
#define PE_SI13_Pin GPIO_PIN_12
#define PE_SI13_GPIO_Port GPIOB
#define PE_SI14_Pin GPIO_PIN_13
#define PE_SI14_GPIO_Port GPIOB
#define PE_SI15_Pin GPIO_PIN_14
#define PE_SI15_GPIO_Port GPIOB
#define PE_SI16_Pin GPIO_PIN_15
#define PE_SI16_GPIO_Port GPIOB
#define PE_SI7_Pin GPIO_PIN_8
#define PE_SI7_GPIO_Port GPIOA
#define PE_SI8_Pin GPIO_PIN_11
#define PE_SI8_GPIO_Port GPIOA
#define PE_SI9_Pin GPIO_PIN_12
#define PE_SI9_GPIO_Port GPIOA
#define RS485_RE_Pin GPIO_PIN_15
#define RS485_RE_GPIO_Port GPIOA
#define PE_SI12_Pin GPIO_PIN_3
#define PE_SI12_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
