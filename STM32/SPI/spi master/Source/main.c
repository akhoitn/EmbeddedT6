#include "../Header/delay.h"



#define SCK GPIO_Pin_13
#define MOSI GPIO_Pin_15
#define SS GPIO_Pin_12

void config();
void spiInit();
void clock();
void transmit(uint8_t data);

int main() {
	
	config();
	TIM2_INT_Init();
	spiInit();
	
	while (1) {
		delayMs(2000);
		transmit(24);
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
	
	GPIO_InitTypeDef gpio;
	//turn on clock for GPIOB
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
	//Initialize GPIO
	gpio.GPIO_Pin = SCK | MOSI |SS;
	gpio.GPIO_Mode = GPIO_Mode_Out_PP;
	gpio.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(GPIOB, &gpio);
	
}
/*
* Function: spiInit
* Description: The function use set ports to 0
* Input:
	Nope
* Output:
* Nope
*/
void spiInit() {
	
	GPIO_ResetBits(GPIOB, SCK);
	GPIO_ResetBits(GPIOB, MOSI);
	GPIO_ResetBits(GPIOB, SS);
	
}

/*
* Function: clock
* Description: Generate data transmission pulses
* Input:
	Nope
* Output:
* Nope
*/
void clock() {
	
	GPIO_SetBits(GPIOB, SCK);
	delayMs(200);
	GPIO_ResetBits(GPIOB, SCK);
	delayMs(200);
}

/*
* Function: transmit
* Description: transmit data to slave
* Input:
	data: data want to transmit to slave
* Output:
* Nope
*/
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