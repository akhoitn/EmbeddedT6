#include "../Header/delay.h"
#include "stm32f10x.h"


#define RX    GPIO_Pin_12


void config();
void waitStart();
void waitEnd();
uint8_t receiveData();
void receive_Array(uint8_t data[], uint8_t lenght);
uint8_t count_Bit1(uint8_t data);

int main() {
	
	config();
	TIM2_INT_Init();
	
	uint8_t data[4] = {0};
	
	receive_Array(data, 4);
	
}
/*
* Function: receive_Array
* Description: receive datas in the array form master 
* Input:
	data[]: datas in the array
	lenght: number of elements in the array
* Output:
	Nope
*/
void receive_Array (uint8_t data[], uint8_t lenght) {
	
	for(int i =0; i < lenght; i++) {
		
		waitStart();
		data[i] = receiveData();
		
		if((count_Bit1(data[i]) % 2) && (GPIO_ReadInputDataBit(GPIOB, RX) == 0) 
			|| !(count_Bit1(data[i]) % 2) && (GPIO_ReadInputDataBit(GPIOB, RX) == 1)) return;
		
		waitEnd();
	}
}
/*
* Function: receiveData
* Description: receive data form master 
* Input:
	Nope
* Output:
	Nope
*/
uint8_t receiveData () {
	
	uint8_t data = 0;
	for(int i = 0; i < 8; i++) {
		if(GPIO_ReadInputDataBit(GPIOB, RX) == 1) data = data | (0x80 >> i);
		delayMs(100);
	}
	return data;
}
/*
* Function: waitStart
* Description: wait	for start signal from master
* Input:
	Nope
* Output:
	Nope
*/
void waitStart () {
	
	while(GPIO_ReadInputDataBit(GPIOB, RX) == 1);
	delayMs(40);
}
/*
* Function: waitEnd
* Description: wait	for end signal from master
* Input:
	Nope
* Output:
	Nope
*/
void waitEnd () {
	
	while(GPIO_ReadInputDataBit(GPIOB, RX) == 0);
	delayMs(100);
}
/*
* Function: count_Bit1
* Description: count the quantity of bit 1
* Input:
	data
* Output:
	count: the quantity bit 1
*/
uint8_t count_Bit1 (uint8_t data) {
	
	uint8_t count = 0;
	for(int i =0; i < 8; i++) {
		if(data & (0x80 >> i)) count++;
	}
	return count;
}
/*
* Function: config
* Description: This is configuration function for GPIO
* Input:
	Nope
* Output:
*  Nope
*/
void config() {
	
	//turn on clock for GPIOB, GPIOC
	GPIO_InitTypeDef gpio;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB | RCC_APB2Periph_GPIOC  , ENABLE);
	
	//Initialize GPIO
	gpio.GPIO_Pin = RX;
	gpio.GPIO_Mode = GPIO_Mode_IPU;
	gpio.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &gpio);
	
	gpio.GPIO_Pin = GPIO_Pin_13;
	gpio.GPIO_Mode = GPIO_Mode_Out_PP;
	gpio.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &gpio);
}