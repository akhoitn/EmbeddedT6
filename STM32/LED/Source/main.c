#include "delay.h"

void config();

int main()  {
	config();
	TIM2_INT_Init();
	
	delayMs(100);
	while(1) {
		GPIO_SetBits(GPIOC, GPIO_Pin_13);
		delayMs(100);
		GPIO_ResetBits(GPIOC, GPIO_Pin_13);
		delayMs(100);
		
	}
	return 0;
	
}

void config() {
	GPIO_InitTypeDef gpio;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
	
	gpio.GPIO_Pin = GPIO_Pin_13;
	gpio.GPIO_Mode = GPIO_Mode_Out_PP;
	gpio.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(GPIOC, &gpio);
	
}