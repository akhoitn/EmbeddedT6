/*
* File: delay.c
* Author: Khoi
* Date: 10/03/2023
* Description: This is timer file
*/

#include "../Header/delay.h"
#include "stm32f10x.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_tim.h"

/*
* Function: TIM2_INT_Init
* Description: This is configuration function for timer
* Input:
	Nope
* Output:
*  Nope
*/
void TIM2_INT_Init()
{
	//turn on clock TIM
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruct;
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	
	TIM_TimeBaseInitStruct.TIM_Prescaler = 3600;
	TIM_TimeBaseInitStruct.TIM_Period = 19;
	TIM_TimeBaseInitStruct.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseInitStruct.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseInitStruct);
	
	TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);
	TIM_Cmd(TIM2, ENABLE);
	
	
	//Initialize NVIC
	//NVIC_InitTypeDef NVIC_InitStruct;
	
	//NVIC_InitStruct.NVIC_IRQChannel = TIM2_IRQn;
	//NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 0x00;
	//NVIC_InitStruct.NVIC_IRQChannelSubPriority = 0x00;
	//NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
	//NVIC_Init(&NVIC_InitStruct);

	
	
}

int milis = 0;

/*
* Function: TIM2_IQRHandler
* Description: The function clear TIM_IT_Update
* Input:
	Nope
* Output:
*   Nope
*/

void TIM2_IQRHandler () {
	if(TIM_GetITStatus(TIM2, TIM_IT_Update)) {
		milis++;
		
		TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
	}
}

/*
* Function: delayMs
* Description: This is function delay the program
* Input:
		ittime
* Output:
*   Nope
*/
void delayMs (unsigned int itime) {
	
	unsigned int i,j;
	for(i =0; i < itime; i++)
	for(j=0; j <1275; j++);
}