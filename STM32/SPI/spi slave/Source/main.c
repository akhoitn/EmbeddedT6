#include "../Header/delay.h"

#define SCK  GPIO_Pin_13
#define MOSI GPIO_Pin_15
#define SS  GPIO_Pin_12

void config();
uint8_t receive();

int main() {
	
	config();
	TIM2_INT_Init();
	uint8_t data =0;
	
	again:
	while (1) {
		data = receive();
		if(data != 24) {
			goto again;
		}
	}
	return 0;
	
}
/*
* Function: config
* Description: This is configuration function for GPIO
* Input:
	Nope
* Output:
*  Nope
*/
void config () {
	
	//turn on clock for GPIOB, GPIOC
	GPIO_InitTypeDef gpio;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB | RCC_APB2Periph_GPIOC, ENABLE);
	
	//Initialize GPIO
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

/*
* Function: receive
* Description: use receive data form master
* Input:
	Nope
* Output:
*  data: data form master
*/
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