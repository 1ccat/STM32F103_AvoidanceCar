#include "encoder.h"

//编码器计数初始化
void Encoder_Count_Init(void)
{
    HAL_TIM_Encoder_Start(&htim4, TIM_CHANNEL_ALL);
    HAL_TIM_Encoder_Start(&htim3, TIM_CHANNEL_ALL);
}

//编码器数据读取
int16_t Encoder_Value(uint8_t n)
{
    if (n == 1)
    {
        return (int16_t)(__HAL_TIM_GET_COUNTER(&htim3));
    }
    else if (n == 2)
    {
        return (int16_t)(__HAL_TIM_GET_COUNTER(&htim4));
    }
    else
    {
        return 0;
    }
}

//编码器清零
void Encoder_Count_Clear(uint8_t n)
{
    if (n == 1)
    {
        __HAL_TIM_SET_COUNTER(&htim3, 0);
    }
    else if (n == 2)
    {
        __HAL_TIM_SET_COUNTER(&htim4, 0);
    }
}


