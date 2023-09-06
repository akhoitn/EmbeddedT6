#include "delay.h"

#define SCK  GPIO_Pin_6
#define MOSI GPIO_Pin_7
#define SS  GPIO_Pin_8

void config();
void check();
uint8_t receive();

int main() {
	
	config();
	TIM2_INT_Init();
	uint8_t data =0;
	
	while (1) {
		data = receive();
		if(data == 170) {
			while(1){
				check();
			}
		}
	}
	return 0;
	
}

void config () {
	
	GPIO_InitTypeDef gpio;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB | RCC_APB2Periph_GPIOC, ENABLE);
	
	gpio.GPIO_Pin = SCK | MOSI;
	gpio.GPIO_Mode = GPIO_Mode_IPD;
	gpio.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(GPIOB, &gpio);
	
	gpio.GPIO_Pin = SS;
	gpio.GPIO_Mode = GPIO_Mode_IPU;
	gpio.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(GPIOB, &gpio);
	
	gpio.GPIO_Pin = GPIO_Pin_13; 
	gpio.GPIO_Mode = GPIO_Mode_Out_PP;
	gpio.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(GPIOC, &gpio);
}

void check() {
	GPIO_ResetBits(GPIOC, GPIO_Pin_13);
	delayMs(200);
	GPIO_SetBits(GPIOC, GPIO_Pin_13);
	delayMs(200);
}

uint8_t receive() {
	uint8_t data =0;
	while(GPIO_ReadInputDataBit(GPIOB, SS) == 1);
	
	for(uint8_t i =0 ;i < 8; i++)
	{
		while(GPIO_ReadInputDataBit(GPIOB, SCK) == 0);
		
		if(GPIO_ReadInputDataBit(GPIOB, MOSI) == 1) data = data | (0x80 >> i);
		
		while(GPIO_ReadInputDataBit(GPIOB, SCK) == 1);
	}
	
	return data;
}