/*
 * @Author: DuRuofu duruofu@qq.com
 * @Date: 2023-07-07 15-49-11
 * @LastEditors: DuRuofu
 * @LastEditTime: 2023-07-13 15-42-16
 * @FilePath: \MDK-ARMd:\duruofu\Project\Avoidance_Car\project\STM32ZET6\Users\PWM\pwm.c
 * @Description: PWM模块(驱动电机使用,双路同频)
 * Copyright (c) 2023 by duruofu@foxmail.com All Rights Reserved. 
 */

#include "pwm.h"

//在此设置使用的定时器和对应A,B两路PWM的通道
#define TIM  htim1
#define PWM_CHANNEL_A TIM_CHANNEL_1
#define PWM_CHANNEL_B TIM_CHANNEL_4

//设定占空比最大值(Counter Period计数值)
#define PWM_D 7200

//PWM初始化
void PWM_Init(void)
{
    // 使能定时器的通道
    HAL_TIM_PWM_Start(&TIM,PWM_CHANNEL_A);
    HAL_TIM_PWM_Start(&TIM,PWM_CHANNEL_B);
    // 设置初始占空比为0
    __HAL_TIM_SET_COMPARE(&TIM, PWM_CHANNEL_A, 0);
    __HAL_TIM_SET_COMPARE(&TIM, PWM_CHANNEL_B, 0);

} 

//PWMA占空比调节
void PWMA_Set(uint16_t pwm_d)
{
    if(pwm_d > PWM_D)
    {
        pwm_d = PWM_D;
    }
    __HAL_TIM_SET_COMPARE(&TIM, PWM_CHANNEL_A, pwm_d);
}

//PWMB占空比调节
void PWMB_Set(uint16_t pwm_d)
{
    if(pwm_d > PWM_D)
    {
        pwm_d = PWM_D;
    }
    __HAL_TIM_SET_COMPARE(&TIM, PWM_CHANNEL_B, pwm_d);
}
