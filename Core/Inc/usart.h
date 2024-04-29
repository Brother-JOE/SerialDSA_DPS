/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    usart.h
  * @brief   This file contains all the function prototypes for
  *          the usart.c file
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
#ifndef __USART_H__
#define __USART_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

extern UART_HandleTypeDef huart1;

extern UART_HandleTypeDef huart3;

/* USER CODE BEGIN Private defines */
//todo
#define RXBUFFERSIZE  100


extern uint8_t U1RxBuffer[RXBUFFERSIZE];
extern uint8_t U1RXdata_len;
extern uint8_t u1_aRxBuffer;			
extern uint8_t Uart1_Rx_Cnt;		
extern uint8_t uart1_rxstate;
extern uint8_t uart1_rx_finish;
extern uint8_t uart1_tx_finish;


extern uint8_t U3RxBuffer[RXBUFFERSIZE];
extern uint8_t U3RXdata_len;
extern uint8_t u3_aRxBuffer[36];			//?
extern uint8_t Uart3_Rx_Cnt;		
extern uint8_t uart3_rxstate;
extern uint8_t uart3_rx_finish;
extern uint8_t uart3_tx_finish;

void Read_Usart(const uint8_t *rx);

//todo
/* USER CODE END Private defines */

void MX_USART1_UART_Init(void);
void MX_USART3_UART_Init(void);

/* USER CODE BEGIN Prototypes */

/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif

#endif /* __USART_H__ */

