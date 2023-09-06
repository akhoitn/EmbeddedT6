#include "delay.h"
#include "stm32f10x.h"

#define ADDRESS 0x5B

#define SCK GPIO_Pin_7
#define SDA GPIO_Pin_8
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

void config () {
	
	GPIO_InitTypeDef gpio;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB | RCC_APB2Periph_GPIOC, ENABLE);
	
	gpio.GPIO_Pin = SCK | SDA;
	gpio.GPIO_Mode = GPIO_Mode_Out_PP;
	gpio.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(GPIOB, &gpio);
	
	gpio.GPIO_Pin = GPIO_Pin_13; 
	gpio.GPIO_Mode = GPIO_Mode_Out_PP;
	gpio.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(GPIOC, &gpio);
}

void ckeck() {
	GPIO_ResetBits(GPIOC, GPIO_Pin_13);
	delayMs(100);
	GPIO_SetBits(GPIOC, GPIO_Pin_13);
	delayMs(100);
	
}

void waitStart() {
	
	while(GPIO_ReadInputDataBit(GPIOB, SCK) == 1){
		if(GPIO_ReadInputDataBit(GPIOB, SDA) == 0) {
			while(GPIO_ReadInputDataBit(GPIOB, SCK) == 1);
			return;
		}
	}
}

uint8_t receiveAddress () {
	
	uint8_t address =0;
	for(uint8_t i =0; i < 8; i++) {
		
		while(GPIO_ReadInputDataBit(GPIOB, SCK) == 0);
		if(GPIO_ReadInputDataBit(GPIOB, SDA) == 1) address = address | 0x80 >> i;
			while(GPIO_ReadInputDataBit(GPIOB, SCK) == 1);
	}
	
	return address;
}

uint8_t receiveData () {
	
	uint8_t data =0;
	for(uint8_t i =0; i < 8; i++) {
		
		while(GPIO_ReadInputDataBit(GPIOB, SCK) == 0);
		if(GPIO_ReadInputDataBit(GPIOB, SDA) == 1) data = data | 0x80 >> i;
			while(GPIO_ReadInputDataBit(GPIOB, SCK) == 1);
	}
	
	return data;
}

void setOutputSDA () {
	GPIOB ->CRL &= ~ (GPIO_CRH_MODE8 | GPIO_CRH_MODE8);
	GPIOB->CRL |= GPIO_CRH_MODE8_0;
	GPIOB->BSRR = GPIO_Pin_8;
}

void setInputSDA() {
	GPIOB ->CRL &= ~ (GPIO_CRH_MODE8 | GPIO_CRH_MODE8);
	GPIOB->CRL |= GPIO_CRH_MODE8_1;
	GPIOB->BSRR = GPIO_Pin_8;
}