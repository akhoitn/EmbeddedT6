#include "../Header/delay.h"
#include "stm32f10x.h"

#define ADDRESS 0x4D

#define SCK GPIO_Pin_12
#define SDA GPIO_Pin_15
#define WIRTE 0

void setOutputSDA();
void setInputSDA();
void I2c_Slave();
void waitStart();
uint8_t receiveAddress();
uint8_t receiveData();
void config();
void check();

uint8_t address_Receive = 0;
uint8_t data[2] = {0};

int main() {
	config();
	TIM2_INT_Init();
	
	while(1) {
		I2c_Slave();
		delayMs(100);
	}
}

/*
* Function: I2c_Slave
* Description: Control, check, receive data from master
* Input:
	Nope
* Output:
	Nope
*/
void I2c_Slave() {
	waitStart();
	
	uint8_t address_WirteOrRead = receiveAddress();
	
	setOutputSDA();
	address_Receive = address_WirteOrRead >> 1;
	if(address_Receive == ADDRESS) GPIO_ResetBits(GPIOB, SDA);
	else {
		GPIO_SetBits(GPIOB, SDA);
		while(GPIO_ReadInputDataBit(GPIOB, SCK) == 0);
		setInputSDA();
		return;
	}
	
	while(GPIO_ReadInputDataBit(GPIOB, SCK) == 0);
	setInputSDA();
	
	if((address_WirteOrRead & 1) == 0) {
		
		data[0] = receiveData();
		setOutputSDA();
		GPIO_ResetBits(GPIOB, SDA);
		while(GPIO_ReadInputDataBit(GPIOB, SCK)  == 0);
		setInputSDA();
		
		data[1] = receiveData();
		setOutputSDA();
		GPIO_ResetBits(GPIOB, SDA);
		while(GPIO_ReadInputDataBit(GPIOB, SCK) == 0);
		setInputSDA();
		return;
	}else {}
			
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
	gpio.GPIO_Pin = SCK | SDA;
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
	delayMs(100);
	GPIO_SetBits(GPIOC, GPIO_Pin_13);
	delayMs(100);
	
}
/*
* Function: waitStart
* Description: wait	for signal SCK and SDA from master
* Input:
	Nope
* Output:
	Nope
*/
void waitStart() {
	
	while(GPIO_ReadInputDataBit(GPIOB, SCK) == 1){
		if(GPIO_ReadInputDataBit(GPIOB, SDA) == 0) {
			while(GPIO_ReadInputDataBit(GPIOB, SCK) == 1);
			return;
		}
	}
}
/*
* Function: receiveAddress
* Description: receive bit address form master 
* Input:
	Nope
* Output:
	Nope
*/
uint8_t receiveAddress () {
	
	uint8_t address =0;
	for(uint8_t i =0; i < 8; i++) {
		
		while(GPIO_ReadInputDataBit(GPIOB, SCK) == 0);
		if(GPIO_ReadInputDataBit(GPIOB, SDA) == 1) address = address | 0x80 >> i;
			while(GPIO_ReadInputDataBit(GPIOB, SCK) == 1);
	}
	
	return address;
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
	
	uint8_t data =0;
	for(uint8_t i =0; i < 8; i++) {
		
		while(GPIO_ReadInputDataBit(GPIOB, SCK) == 0);
		if(GPIO_ReadInputDataBit(GPIOB, SDA) == 1) data = data | 0x80 >> i;
			while(GPIO_ReadInputDataBit(GPIOB, SCK) == 1);
	}
	
	return data;
}
/*
* Function: setOutputSDA
* Description: use set mode output of GPIO
* Input:
	Nope
* Output:
	Nope
*/
void setOutputSDA () {
	GPIOB ->CRL &= ~ (GPIO_CRH_MODE15 | GPIO_CRH_MODE15);
	GPIOB->CRL |= GPIO_CRH_MODE15_0;
	GPIOB->BSRR = GPIO_Pin_15;
}
/*
* Function: setInputSDA
* Description: use set mode  input of GPIO
* Input:
	Nope
* Output:
	Nope
*/
void setInputSDA() {
	GPIOB ->CRL &= ~ (GPIO_CRH_MODE15 | GPIO_CRH_MODE15);
	GPIOB->CRL |= GPIO_CRH_MODE15_1;
	GPIOB->BRR = GPIO_Pin_15;
}