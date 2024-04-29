/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    usart.c
  * @brief   This file provides code for the configuration
  *          of the USART instances.
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
/* Includes ------------------------------------------------------------------*/
#include "usart.h"

/* USER CODE BEGIN 0 */
//TODO
#include "PE4x.h"



uint8_t U1RxBuffer[RXBUFFERSIZE] = {0};
uint8_t U1RXdata_len = 0;
uint8_t u1_aRxBuffer;			
uint8_t Uart1_Rx_Cnt = 0;		
uint8_t uart1_rxstate = 0;
uint8_t uart1_rx_finish = 0;
uint8_t uart1_tx_finish = 0;


uint8_t U3RxBuffer[RXBUFFERSIZE] = {0};
uint8_t U3RXdata_len = 0;
//uint8_t u3_aRxBuffer;
uint8_t u3_aRxBuffer[36]         = {0};			
uint8_t Uart3_Rx_Cnt = 0;		
uint8_t uart3_rxstate = 0;
uint8_t uart3_rx_finish = 0;
uint8_t uart3_tx_finish = 0;


//TODO
/* USER CODE END 0 */

UART_HandleTypeDef huart1;
UART_HandleTypeDef huart3;

/* USART1 init function */

void MX_USART1_UART_Init(void)
{

  /* USER CODE BEGIN USART1_Init 0 */

  /* USER CODE END USART1_Init 0 */

  /* USER CODE BEGIN USART1_Init 1 */

  /* USER CODE END USART1_Init 1 */
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 115200;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART1_Init 2 */

  /* USER CODE END USART1_Init 2 */

}
/* USART3 init function */

void MX_USART3_UART_Init(void)
{

  /* USER CODE BEGIN USART3_Init 0 */

  /* USER CODE END USART3_Init 0 */

  /* USER CODE BEGIN USART3_Init 1 */

  /* USER CODE END USART3_Init 1 */
  huart3.Instance = USART3;
  huart3.Init.BaudRate = 115200;
  huart3.Init.WordLength = UART_WORDLENGTH_8B;
  huart3.Init.StopBits = UART_STOPBITS_1;
  huart3.Init.Parity = UART_PARITY_NONE;
  huart3.Init.Mode = UART_MODE_TX_RX;
  huart3.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart3.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart3) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART3_Init 2 */

  /* USER CODE END USART3_Init 2 */

}

void HAL_UART_MspInit(UART_HandleTypeDef* uartHandle)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};
  if(uartHandle->Instance==USART1)
  {
  /* USER CODE BEGIN USART1_MspInit 0 */

  /* USER CODE END USART1_MspInit 0 */
    /* USART1 clock enable */
    __HAL_RCC_USART1_CLK_ENABLE();

    __HAL_RCC_GPIOA_CLK_ENABLE();
    /**USART1 GPIO Configuration
    PA9     ------> USART1_TX
    PA10     ------> USART1_RX
    */
    GPIO_InitStruct.Pin = GPIO_PIN_9;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_10;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    /* USART1 interrupt Init */
    HAL_NVIC_SetPriority(USART1_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(USART1_IRQn);
  /* USER CODE BEGIN USART1_MspInit 1 */

  /* USER CODE END USART1_MspInit 1 */
  }
  else if(uartHandle->Instance==USART3)
  {
  /* USER CODE BEGIN USART3_MspInit 0 */

  /* USER CODE END USART3_MspInit 0 */
    /* USART3 clock enable */
    __HAL_RCC_USART3_CLK_ENABLE();

    __HAL_RCC_GPIOB_CLK_ENABLE();
    /**USART3 GPIO Configuration
    PB10     ------> USART3_TX
    PB11     ------> USART3_RX
    */
    GPIO_InitStruct.Pin = GPIO_PIN_10;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_11;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    /* USART3 interrupt Init */
    HAL_NVIC_SetPriority(USART3_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(USART3_IRQn);
  /* USER CODE BEGIN USART3_MspInit 1 */

  /* USER CODE END USART3_MspInit 1 */
  }
}

void HAL_UART_MspDeInit(UART_HandleTypeDef* uartHandle)
{

  if(uartHandle->Instance==USART1)
  {
  /* USER CODE BEGIN USART1_MspDeInit 0 */

  /* USER CODE END USART1_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_USART1_CLK_DISABLE();

    /**USART1 GPIO Configuration
    PA9     ------> USART1_TX
    PA10     ------> USART1_RX
    */
    HAL_GPIO_DeInit(GPIOA, GPIO_PIN_9|GPIO_PIN_10);

    /* USART1 interrupt Deinit */
    HAL_NVIC_DisableIRQ(USART1_IRQn);
  /* USER CODE BEGIN USART1_MspDeInit 1 */

  /* USER CODE END USART1_MspDeInit 1 */
  }
  else if(uartHandle->Instance==USART3)
  {
  /* USER CODE BEGIN USART3_MspDeInit 0 */

  /* USER CODE END USART3_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_USART3_CLK_DISABLE();

    /**USART3 GPIO Configuration
    PB10     ------> USART3_TX
    PB11     ------> USART3_RX
    */
    HAL_GPIO_DeInit(GPIOB, GPIO_PIN_10|GPIO_PIN_11);

    /* USART3 interrupt Deinit */
    HAL_NVIC_DisableIRQ(USART3_IRQn);
  /* USER CODE BEGIN USART3_MspDeInit 1 */

  /* USER CODE END USART3_MspDeInit 1 */
  }
}

/* USER CODE BEGIN 1 */
//TODO
  void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(huart);
  /* NOTE: This function Should not be modified, when the callback is needed,
           the HAL_UART_TxCpltCallback could be implemented in the user file
   */
	if(huart->Instance == USART1)//*USART1
	{

		if((u1_aRxBuffer == 0xD1)&&(uart1_rxstate == 0))
		{
			U1RxBuffer[Uart1_Rx_Cnt++] = 0xD1;
			uart1_rxstate = 1;
		}
		else if(uart1_rxstate == 1)
		{
			U1RxBuffer[Uart1_Rx_Cnt++] = u1_aRxBuffer;
			if((u1_aRxBuffer == 0xD2)||(Uart1_Rx_Cnt >= RXBUFFERSIZE))
			{
				uart1_rxstate = 2;
			}
			
		}


		if(uart1_rxstate == 2)
		{
			if((U1RxBuffer[0] == 0xD1)&&(U1RxBuffer[Uart1_Rx_Cnt-1]== 0xD2))
			{
        /*Reception Complete*/




				uart1_rxstate = 0;
				Uart1_Rx_Cnt = 0;
			}
			else
			{
				uart1_rxstate = 0;
				Uart1_Rx_Cnt = 0;
				memset(U1RxBuffer,0x00,sizeof(U1RxBuffer));
			}
			
		}
		
			
		HAL_UART_Receive_IT(&huart1, (uint8_t *)&u1_aRxBuffer, 1);   
		
	}//*USART1




  // if(huart->Instance == USART3)//*USART3
  // {

  //   if((u3_aRxBuffer == 0xD1)&&(uart3_rxstate == 0))
  //   {
  //     U3RxBuffer[Uart3_Rx_Cnt++] = 0xD1;
  //     uart3_rxstate = 1;
  //   }
  //   else if(uart3_rxstate == 1)
  //   {
  //     U3RxBuffer[Uart3_Rx_Cnt++] = u3_aRxBuffer;
  //     if((u3_aRxBuffer == 0xD2)||(Uart3_Rx_Cnt >= RXBUFFERSIZE))
  //     {
  //       uart3_rxstate = 2;
  //     }
      
  //   }
    
    
  //   if(uart3_rxstate == 2)
  //   {
  //     if((U3RxBuffer[0] == 0xD1)&&(U3RxBuffer[Uart3_Rx_Cnt-1]== 0xD2))
  //     {
  //       /*Reception Complete*/
        
  //       HAL_UART_Transmit_IT(&huart3, U3RxBuffer, Uart3_Rx_Cnt);  //?test
  //       //HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);
  //       //·¢ËÍ
  //       //send_flag = 1;

  //       uart3_rxstate = 0;
  //       Uart3_Rx_Cnt = 0;
  //     }
  //     else
  //     {
  //       uart3_rxstate = 0;
  //       Uart3_Rx_Cnt = 0;
  //       memset(U3RxBuffer,0x00,sizeof(U3RxBuffer));
  //     }
      
  //   }
    
      
    
  //   HAL_UART_Receive_IT(&huart3, (uint8_t *)&u3_aRxBuffer, 1);   
    
  // }//*USART3




    if (huart->Instance == USART3) //*USART3
    {

        if ((u3_aRxBuffer[0] == 0xEB) && (u3_aRxBuffer[1] == 0x90) && (u3_aRxBuffer[34] == 0xAA) && (u3_aRxBuffer[35] == 0x55)) {
            Read_Usart(u3_aRxBuffer);
            send_flag = 1;
        }

        HAL_UART_Receive_IT(&huart3, u3_aRxBuffer, 36);

    } //*USART3


}


void Read_Usart(const uint8_t *rx)
{
    rx += 2; // skip the 2-byte header

    float value[16][2];
    for (int i = 0; i < 16; ++i) {
        value[i][0] = ((float)rx[i] * 360.0f / 256.0f); // phase value
        value[i][1] = ((float)rx[i + 16] / 4.0f);       // amplitude value
    }
    for (int i = 0; i < 16; ++i) {
        SetChannel_AmpPhase(i + 1, value[i][1], value[i][0]);
    }
    //
}


//TODO
/* USER CODE END 1 */
