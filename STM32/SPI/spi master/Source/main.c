#include "delay.h"

#define SCK GPIO_Pin_6
#define MOSI GPIO_Pin_7
#define SS GPIO_Pin_8

void 	config();
void spiInit();
void clock();
void transmit(uint8_t data);

int main() {
	
	config();
	TIM2_INT_Init();
	spiInit();
	
	while (1) {
		
		delayMs(2000);
		transmit(170);
}
	return 0;

}

void config () {
	
	GPIO_InitTypeDef gpio;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
	gpio.GPIO_Pin = SCK | MOSI |SS;
	gpio.GPIO_Mode = GPIO_Mode_Out_PP;
	gpio.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(GPIOB, &gpio);
	
}

void spiInit() {
	
	GPIO_ResetBits(GPIOB, SCK);
	GPIO_ResetBits(GPIOB, MOSI);
	GPIO_ResetBits(GPIOB, SS);
	
}

void clock() {
	
	GPIO_SetBits(GPIOB, SCK);
	delayMs(200);
	GPIO_ResetBits(GPIOB, SCK);
	delayMs(200);
}

void transmit(uint8_t data) {
	
	GPIO_ResetBits(GPIOB, SS);
	uint8_t i =0;
	for(;i <8; i++){
		if(data & (0x80 >> i)) GPIO_SetBits(GPIOB, MOSI);
		else GPIO_ResetBits(GPIOB, MOSI);
		
		clock();
}
	GPIO_SetBits(GPIOB, SS);
}