#include "delay.h"
#include "stm32f10x.h"

#define SLAVE_ADDRESS 0x5B
#define SCK GPIO_Pin_7
#define SDA GPIO_Pin_8
#define ACK 0
#define NACK 1

void setOutputSDA();
void setInputSDA();
void I2c_Master();
void setStatus();
void startCondition();
void endCondition();
void transmit7BitAddress(uint8_t address);
void transmitData(uint8_t data);
void clock();
void config();
void check();

int main() {
	
	config();
	TIM2_INT_Init();
	
	while(1) {
		I2c_Master ();
	}
}

void I2c_Master() {
	
	again:
	
	setStatus();
	delayMs(500);
	
	startCondition();
	transmit7BitAddress(SLAVE_ADDRESS);
	
	setInputSDA();
	if(GPIO_ReadInputDataBit(GPIOB, SDA) == ACK){
		
		setOutputSDA();
		transmitData(170);
		
		setInputSDA();
		if(GPIO_ReadInputDataBit(GPIOB, SDA) == ACK){
			
			setOutputSDA();
			transmitData(78);
			
			setInputSDA();
			if(GPIO_ReadInputDataBit(GPIOB, SDA) == ACK) {
				
				setOutputSDA();
				endCondition();
			}else {
				setOutputSDA();
				goto again;
			}
		}else {
			setOutputSDA();
			goto again;
		}
	}else {
		setOutputSDA();
		goto again;
	}
			
}
			
void setStatus() {
	GPIO_SetBits(GPIOB, SDA);
	GPIO_SetBits(GPIOB, SCK);
}

void startCondition() {
	GPIO_ResetBits(GPIOB, SDA);
	delayMs(50);
	GPIO_ResetBits(GPIOB, SCK);
}

void endCondition() {
	
	GPIO_ResetBits(GPIOB, SDA);
	GPIO_SetBits(GPIOB, SCK);
	delayMs(50);
	GPIO_ResetBits(GPIOB, SDA);
}

void clock() {
	GPIO_SetBits(GPIOB, SCK);
	delayMs(50);
	GPIO_ResetBits(GPIOB, SCK);
	delayMs(50);
} 

void transmit7BitAddress(uint8_t address) {
	
	for(uint8_t i =0 ;i <7; i++){
		if(address & (0x40 >> i)) GPIO_SetBits(GPIOB, SDA);
		else GPIO_ResetBits(GPIOB, SDA);
		
		clock();
}
	GPIO_SetBits(GPIOB, SDA);
	clock();
}

void transmitData(uint8_t data) {
		
	for(uint8_t i =0; i <8; i++){
		if(data & (0x80 >> i)) GPIO_SetBits(GPIOB, SDA);
		else GPIO_ResetBits(GPIOB, SDA);
		clock();
	}
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

void config () {
	
	GPIO_InitTypeDef gpio;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
	gpio.GPIO_Pin = SCK | SDA;
	gpio.GPIO_Mode = GPIO_Mode_Out_PP;
	gpio.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(GPIOB, &gpio);
	
}
