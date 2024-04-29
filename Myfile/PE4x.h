#ifndef __PE4X_H
#define __PE4X_H

#include "main.h"
#include "tim.h"


/*--test--*/
#define DEG1P4_2dB  0x000108
#define DEG90_2dB   0x014008
#define DEG180_2dB  0x008008
#define DEG180_16dB 0x008040
#define DEG90_16dB  0x000140


#define P_DEG1P4  0x000100
#define P_DEG5P6  0x000400
#define P_DEG22P5  0x001000
#define P_DEG45  0x002000
#define P_DEG90  0x014000
#define P_DEG180 0x008000
#define P_DEG358P6  0x01ff00
#define A_1dB 0x04
#define A_2dB 0x08
#define A_16dB 0x40
#define A_31P75dB 0x7f
/*--test--*/


#define PE_LE(level)  HAL_GPIO_WritePin(PE_LE_GPIO_Port, PE_LE_Pin, level?GPIO_PIN_SET:GPIO_PIN_RESET)
#define PE_CLK(level)  HAL_GPIO_WritePin(PE_CLK_GPIO_Port, PE_CLK_Pin, level?GPIO_PIN_SET:GPIO_PIN_RESET)
#define PE_SI1(level)  HAL_GPIO_WritePin(PE_SI1_GPIO_Port, PE_SI1_Pin, level?GPIO_PIN_SET:GPIO_PIN_RESET)
#define PE_SI2(level)  HAL_GPIO_WritePin(PE_SI2_GPIO_Port, PE_SI2_Pin, level?GPIO_PIN_SET:GPIO_PIN_RESET)
#define PE_SI3(level)  HAL_GPIO_WritePin(PE_SI3_GPIO_Port, PE_SI3_Pin, level?GPIO_PIN_SET:GPIO_PIN_RESET)
#define PE_SI4(level)  HAL_GPIO_WritePin(PE_SI4_GPIO_Port, PE_SI4_Pin, level?GPIO_PIN_SET:GPIO_PIN_RESET)
#define PE_SI5(level)  HAL_GPIO_WritePin(PE_SI5_GPIO_Port, PE_SI5_Pin, level?GPIO_PIN_SET:GPIO_PIN_RESET)
#define PE_SI6(level)  HAL_GPIO_WritePin(PE_SI6_GPIO_Port, PE_SI6_Pin, level?GPIO_PIN_SET:GPIO_PIN_RESET)
#define PE_SI7(level)  HAL_GPIO_WritePin(PE_SI7_GPIO_Port, PE_SI7_Pin, level?GPIO_PIN_SET:GPIO_PIN_RESET)
#define PE_SI8(level)  HAL_GPIO_WritePin(PE_SI8_GPIO_Port, PE_SI8_Pin, level?GPIO_PIN_SET:GPIO_PIN_RESET)
#define PE_SI9(level)  HAL_GPIO_WritePin(PE_SI9_GPIO_Port, PE_SI9_Pin, level?GPIO_PIN_SET:GPIO_PIN_RESET)
#define PE_SI10(level)  HAL_GPIO_WritePin(PE_SI10_GPIO_Port, PE_SI10_Pin, level?GPIO_PIN_SET:GPIO_PIN_RESET)
#define PE_SI11(level)  HAL_GPIO_WritePin(PE_SI11_GPIO_Port, PE_SI11_Pin, level?GPIO_PIN_SET:GPIO_PIN_RESET)
#define PE_SI12(level)  HAL_GPIO_WritePin(PE_SI12_GPIO_Port, PE_SI12_Pin, level?GPIO_PIN_SET:GPIO_PIN_RESET)
#define PE_SI13(level)  HAL_GPIO_WritePin(PE_SI13_GPIO_Port, PE_SI13_Pin, level?GPIO_PIN_SET:GPIO_PIN_RESET)
#define PE_SI14(level)  HAL_GPIO_WritePin(PE_SI14_GPIO_Port, PE_SI14_Pin, level?GPIO_PIN_SET:GPIO_PIN_RESET)
#define PE_SI15(level)  HAL_GPIO_WritePin(PE_SI15_GPIO_Port, PE_SI15_Pin, level?GPIO_PIN_SET:GPIO_PIN_RESET)
#define PE_SI16(level)  HAL_GPIO_WritePin(PE_SI16_GPIO_Port, PE_SI16_Pin, level?GPIO_PIN_SET:GPIO_PIN_RESET)
#define PE_Delay()  user_delay_us(10)


extern bool send_flag;
extern uint16_t DSAdata_buffer[16], DPSdata_buffer[16]; 


void user_delay_us(uint32_t nus);
void delay_ms_tim(uint16_t nms);
void set_SIx(uint8_t channel_index, uint8_t level);
void PE_WriteSingle(uint8_t channel_index, uint32_t data);
void PE_WriteAll_16(uint16_t DSAdata[], uint16_t DPSdata[]);
int SetChannel_Amp(uint8_t channel_index, float amp_value);
int SetChannel_Phase(uint8_t channel_index, float ph_value);
void SetChannel_AmpPhase(uint8_t channel_index, float amp_value, float ph_value);


#endif


