/*
 * @Author: DuRuofu duruofu@qq.com
 * @Date: 2023-07-13 17-52-31
 * @LastEditors: DuRuofu
 * @LastEditTime: 2023-07-13 18-16-54
 * @FilePath: \MDK-ARMd:\duruofu\Project\Avoidance_Car\project\STM32ZET6\Users\USART\usart_2.c
 * @Description: 串口2的驱动代码(用于蓝牙调试)
 * Copyright (c) 2023 by duruofu@foxmail.com All Rights Reserved. 
 */

#include "usart_2.h"
#include "string.h"

#define RXBUFFERSIZE_2  256     //最大接收字节数

//定义串口句柄,使用串口1
#define UART_HANDLE huart2

//定义数据缓冲区
uint8_t RxBuffer_2[RXBUFFERSIZE_2];
uint8_t Uart_RxBuffer_2;      //接收中断缓冲
uint8_t Uart_Rx_Cnt_2 = 0;     //接收缓冲计数

void USART2_Init(void)
{
  /*串口硬件配置代码(使用cudeMX则不需要此部分)
  Init the GPIO of USART1
  */
  //使能 USART1 的接收中断
  __HAL_UART_ENABLE_IT(&UART_HANDLE,UART_IT_RXNE);
  //开启 USART1 的连续接收中断，并指定接收缓冲区的地址和长度
  HAL_UART_Receive_IT(&UART_HANDLE,&Uart_RxBuffer_2,1);
}

//串口1接收完成回调函数
void UART2_RxCpltCallback(UART_HandleTypeDef *huart)
{
    /* Prevent unused argument(s) compilation warning */
  UNUSED(huart);
  /* NOTE: This function Should not be modified, when the callback is needed,
           the HAL_UART_TxCpltCallback could be implemented in the user file
   */
 
	if(Uart_Rx_Cnt_2 >= 255)  //溢出判断
	{
		Uart_Rx_Cnt_2 = 0;
		memset(RxBuffer_2,0x00,sizeof(RxBuffer_2));
		HAL_UART_Transmit(&UART_HANDLE, (uint8_t *)"数据溢出", 10,0xFFFF); 	
	}
	else
	{
		RxBuffer_2[Uart_Rx_Cnt_2++] = Uart_RxBuffer_2;   
	
		
		if((RxBuffer_2[Uart_Rx_Cnt_2-1] == 0x0A)&&(RxBuffer_2[Uart_Rx_Cnt_2-2] == 0x0D)) //判断结束位
		{
      //这里可以写多字节消息的判断
			HAL_UART_Transmit(&UART_HANDLE, (uint8_t *)&RxBuffer_2, Uart_Rx_Cnt_2,0xFFFF); //将收到的信息发送出去
      //while(HAL_UART_GetState(&UART_HANDLE) == HAL_UART_STATE_BUSY_TX);//检测UART发送结束

      //复位
			Uart_Rx_Cnt_2 = 0;
			memset(RxBuffer_2,0x00,sizeof(RxBuffer_2)); //清空数组
		}
	}
	
	HAL_UART_Receive_IT(&UART_HANDLE, (uint8_t *)&Uart_RxBuffer_2, 1);   //因为接收中断使用了一次即关闭，所以在最后加入这行代码即可实现无限使用

}

//串口1错误回调函数(主要用来清除溢出中断)
void UART2_ErrorCallback(UART_HandleTypeDef *huart)
{
  if(HAL_UART_ERROR_ORE)
  {
     uint32_t temp = huart->Instance->SR;
     temp = huart->Instance->DR;
  }
}

/*****************  发送字符串 **********************/
void Usart2_SendString(uint8_t *str)
{
	unsigned int k=0;
  do 
  {
      HAL_UART_Transmit(&UART_HANDLE,(uint8_t *)(str + k) ,1,1000);
      k++;
  } while(*(str + k)!='\0');
   
}
