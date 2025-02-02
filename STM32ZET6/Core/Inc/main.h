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
#define KEY_2_Pin GPIO_PIN_3
#define KEY_2_GPIO_Port GPIOE
#define KEY_1_Pin GPIO_PIN_4
#define KEY_1_GPIO_Port GPIOE
#define LED_2_Pin GPIO_PIN_5
#define LED_2_GPIO_Port GPIOE
#define PWM_1_Pin GPIO_PIN_9
#define PWM_1_GPIO_Port GPIOE
#define AIN1_Pin GPIO_PIN_10
#define AIN1_GPIO_Port GPIOE
#define AIN2_Pin GPIO_PIN_11
#define AIN2_GPIO_Port GPIOE
#define BIN1_Pin GPIO_PIN_12
#define BIN1_GPIO_Port GPIOE
#define BIN2_Pin GPIO_PIN_13
#define BIN2_GPIO_Port GPIOE
#define PWM_2_Pin GPIO_PIN_14
#define PWM_2_GPIO_Port GPIOE
#define I2C_SCL_Pin GPIO_PIN_12
#define I2C_SCL_GPIO_Port GPIOB
#define I2C_SDA_Pin GPIO_PIN_13
#define I2C_SDA_GPIO_Port GPIOB
#define Follow_2_Pin GPIO_PIN_3
#define Follow_2_GPIO_Port GPIOB
#define Follow_1_Pin GPIO_PIN_4
#define Follow_1_GPIO_Port GPIOB
#define LED_1_Pin GPIO_PIN_5
#define LED_1_GPIO_Port GPIOB
#define Follow_3_Pin GPIO_PIN_7
#define Follow_3_GPIO_Port GPIOB
#define Follow_4_Pin GPIO_PIN_8
#define Follow_4_GPIO_Port GPIOB
#define Follow_5_Pin GPIO_PIN_9
#define Follow_5_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
