#include "PE4x.h"


bool send_flag = 0;






/**
 * @brief tim2实现us延时
 * 
 * @param nus 
 */
void user_delay_us(uint32_t nus)
{

    uint16_t  differ = 0xffff-nus-5;
    //设置定时器2的技术初始值
    __HAL_TIM_SetCounter(&htim2,differ);
    //开启定时器
    HAL_TIM_Base_Start(&htim2);

    while( differ<0xffff-5)
    {
        differ = __HAL_TIM_GetCounter(&htim2);
    };
    //关闭定时器
    HAL_TIM_Base_Stop(&htim2);

}


void delay_ms_tim(uint16_t nms)
{
    uint32_t i;
    for(i=0;i<nms;i++) user_delay_us(1000);
}


void set_SIx(uint8_t channel_index, uint8_t level)
{
    if(channel_index == 1) PE_SI1(level);
    else if(channel_index == 2) PE_SI2(level);
    else if(channel_index == 3) PE_SI3(level);
    else if(channel_index == 4) PE_SI4(level);
    else if(channel_index == 5) PE_SI5(level);
    else if(channel_index == 6) PE_SI6(level);
    else if(channel_index == 7) PE_SI7(level);
    else if(channel_index == 8) PE_SI8(level);
    else if(channel_index == 9) PE_SI9(level);
    else if(channel_index == 10) PE_SI10(level);
    else if(channel_index == 11) PE_SI11(level);
    else if(channel_index == 12) PE_SI12(level);
    else if(channel_index == 13) PE_SI13(level);
    else if(channel_index == 14) PE_SI14(level);
    else if(channel_index == 15) PE_SI15(level);
    else PE_SI16(level);
}


/**
 * @brief for test
 * 
 * @param channel_index 
 * @param data 
 */
void PE_WriteSingle(uint8_t channel_index, uint32_t data)
{
    uint8_t wbits_DPS = 8+1+4;
    // uint8_t wbits_DSA = 8;
    uint8_t i = 0;
    uint8_t temp = 0;
    uint16_t data_1 = (data&0xff)<<5;
    uint16_t data_2 = data>>8;

    PE_LE(0);
    for(i=0; i<wbits_DPS; i++)
    {
        temp = ((data_1&0x01)==0x01)? 1:0;
        data_1 = data_1>>1;
        PE_CLK(0);
        set_SIx(channel_index, temp);
        PE_Delay();
        PE_CLK(1);
        PE_Delay();
    }
    PE_CLK(0);
    PE_Delay();
    PE_LE(1);
    PE_Delay();
    PE_LE(0);
    
    PE_Delay();
    for(i=0; i<wbits_DPS; i++)
    {
        temp = ((data_2&0x01)==0x01)? 1:0;
        data_2 = data_2>>1;
        PE_CLK(0);
        set_SIx(channel_index, temp);
        PE_Delay();
        PE_CLK(1);
        PE_Delay();
    }
    PE_CLK(0);
    PE_Delay();
    PE_LE(1);
    PE_Delay();
    PE_LE(0);
}


void PE_WriteAll_16(uint16_t DSAdata[], uint16_t DPSdata[])
{
    uint8_t wbits_DPS = 8+1+4;
    // uint8_t wbits_DSA = 8;
    uint8_t i = 0;
    uint8_t m = 0;
    uint8_t temp = 0;
    uint16_t data_1[16],data_2[16];
    for(m=0; m<16; m++)
    {
        data_1[m] = DSAdata[m]<<5;
        data_2[m] = DPSdata[m];
    }


    PE_LE(0);
    for(i=0; i<wbits_DPS; i++)
    {
        PE_CLK(0);
        for(m=0; m<16; m++){
            temp = ((data_1[m]&0x01)==0x01)? 1:0;
            data_1[m] = data_1[m]>>1;
            set_SIx(m+1, temp);
        }        
        PE_Delay();
        PE_CLK(1);
        PE_Delay();
    }
    PE_CLK(0);
    PE_Delay();
    PE_LE(1);
    PE_Delay();
    PE_LE(0);
    
    PE_Delay();
    for(i=0; i<wbits_DPS; i++)
    {
        PE_CLK(0);
        for(m=0; m<16; m++){
            temp = ((data_2[m]&0x01)==0x01)? 1:0;
            data_2[m] = data_2[m]>>1;
            set_SIx(m+1, temp);
        }        
        PE_Delay();
        PE_CLK(1);
        PE_Delay();
    }
    PE_CLK(0);
    PE_Delay();
    PE_LE(1);
    PE_Delay();
    PE_LE(0);    
}


uint16_t DSAdata_buffer[16], DPSdata_buffer[16];
int SetChannel_Amp(uint8_t channel_index, float amp_value)
{
    if(channel_index == 0||channel_index > 16)  return 0;
    if(amp_value < 0.25)    amp_value = 0.25;
    else if(amp_value > 31.75)  amp_value = 31.75;
    uint16_t state_num = (uint16_t)(amp_value*4.0f); 
    DSAdata_buffer[channel_index-1] = state_num;
    return 1;
}


int SetChannel_Phase(uint8_t channel_index, float ph_value)
{
    if(channel_index == 0||channel_index > 16)  return 0;
    if(ph_value < 0)    ph_value = 0;
    else if(ph_value > 358.6)  ph_value = 358.6;
    uint16_t state_num = (uint16_t)(ph_value*256.0f/360.0f);
    //OPT bit 
    if( (state_num&0x40)==0x40 )    state_num |= 0x100;
    else    state_num &= ~0x100;        //?
    DPSdata_buffer[channel_index-1] = state_num;
    return 1;
}


void SetChannel_AmpPhase(uint8_t channel_index, float amp_value, float ph_value)
{
    SetChannel_Amp(channel_index, amp_value);
    SetChannel_Phase(channel_index, ph_value);
}






