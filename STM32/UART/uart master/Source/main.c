#include "../Header/delay.h"
#include "stm32f10x.h"

#define TX  GPIO_Pin_12


void config();
void transmitData (uint8_t data);
uint8_t count_Bit1(uint8_t data);
void transmitCheck(uint8_t data);
void start_Condition();
void end_Condition();


int main() {
	
	config();
	TIM2_INT_Init();

	uint8_t data[]= {24, 11, 20, 00};
	uint8_t i =0;
	
	GPIO_SetBits(GPIOB, TX);
	delayMs(2000);
	
	while (i <4) {
		
		start_Condition();
		
		transmitData (data[i]);
		
		transmitCheck(data[i]);
		
		end_Condition();
		
		i++;
	}
}
/*
* Function: startCondition
* Description: set ports to start data transmission
* Input:
	Nope
* Output:
	Nope
*/
void start_Condition() {
	
	GPIO_SetBits(GPIOB, TX);
	delayMs(100);
	GPIO_ResetBits(GPIOB, TX);
}
/*
* Function: endCondition
* Description: set port to end data transmission
* Input:
	Nope
* Output:
	Nope
*/
void end_Condition() {
	
	GPIO_SetBits(GPIOB,	TX);
	delayMs(200);
}
/*
* Function: transmitData
* Description: transmit data form master to slave
* Input:
data: data want to transmit
* Output:
	Nope
*/
void transmitData (uint8_t data)
{
	for(int i =0; i < 8; i++)
	{
		if(data & (0x80 >> i)) GPIO_SetBits(GPIOB, TX);
		else GPIO_ResetBits(GPIOB, TX);
		delayMs(100);
	}
	
}
/*
* Function: transmitCheck
* Description: check parity bit
* Input:
	data
* Output:
	Nope
*/
void transmitCheck (uint8_t data) {
	
	if (count_Bit1(data) % 2) GPIO_SetBits(GPIOB, TX);
	else GPIO_ResetBits(GPIOB, TX);
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
		if( data & (0x80 >> i)) count++;
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
	//turn on clock for GPIOB
	GPIO_InitTypeDef gpio;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB , ENABLE);
	
	//Initialize GPIO
	gpio.GPIO_Pin = TX;
	gpio.GPIO_Mode = GPIO_Mode_Out_PP;
	gpio.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &gpio);
	
}