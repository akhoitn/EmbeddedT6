#include "../Header/delay.h"


#define SLAVE_ADDRESS 0x4D
#define SCK GPIO_Pin_12
#define SDA GPIO_Pin_15
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

int main() {
	
	config();
	TIM2_INT_Init();
	while(1) {
		I2c_Master();
	}
}
/*
* Function: I2c_Master
* Description: control, check and set condition that the master transmits data to slave
* Input:
	Nope
* Output:
	Nope
*/
void I2c_Master() {
	
	again:
	
	setStatus();
	delayMs(2000);
	
	startCondition();
	transmit7BitAddress(SLAVE_ADDRESS);
	
	setInputSDA();
	if(GPIO_ReadInputDataBit(GPIOB, SDA) == ACK){
		
		setOutputSDA();
		transmitData(24);
		
		setInputSDA();
		if(GPIO_ReadInputDataBit(GPIOB, SDA) == ACK){
			
			setOutputSDA();
			transmitData(11);
			
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
			
/*
* Function: setStatus
* Description: set status of ports SDA and SCK to 1
* Input:
	Nope
* Output:
	Nope
*/
void setStatus() {
	GPIO_SetBits(GPIOB, SDA);
	GPIO_SetBits(GPIOB, SCK);
}
/*
* Function: startCondition
* Description: set ports to start data transmission
* Input:
	Nope
* Output:
	Nope
*/
void startCondition() {
	GPIO_ResetBits(GPIOB, SDA);
	delayMs(50);
	GPIO_ResetBits(GPIOB, SCK);
}
/*
* Function: endCondition
* Description: set ports to end data transmission
* Input:
	Nope
* Output:
	Nope
*/
void endCondition() {
	
	GPIO_ResetBits(GPIOB, SDA);
	GPIO_SetBits(GPIOB, SCK);
	delayMs(50);
	GPIO_SetBits(GPIOB, SDA);
}

/*
* Function: clock
* Description: Generate data transmission puless
* Input:
	Nope
* Output:
	Nope
*/
void clock() {
	GPIO_SetBits(GPIOB, SCK);
	delayMs(50);
	GPIO_ResetBits(GPIOB, SCK);
	delayMs(50);
} 

/*
* Function: transmit7BitAddress
* Description: transmit bit address to slave
* Input:
	address: 7 bit address of slave want to transmit data
* Output:
	Nope
*/
void transmit7BitAddress(uint8_t address) {
	
	for(uint8_t i =0 ;i <7; i++){
		
		if(address & (0x40 >> i)) GPIO_SetBits(GPIOB, SDA);
		else GPIO_ResetBits(GPIOB, SDA);
		
		clock();
}
	GPIO_ResetBits(GPIOB, SDA);
	clock();
}

/*
* Function: transmitData
* Description: transmit data form master to slave
* Input:
data: data want to transmit
* Output:
	Nope
*/
void transmitData(uint8_t data) {
		
	for(uint8_t i =0; i <8; i++){
		if(data & (0x80 >> i)) GPIO_SetBits(GPIOB, SDA);
		else GPIO_ResetBits(GPIOB, SDA);
		clock();
	}
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
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB | RCC_APB2Periph_GPIOC, ENABLE	);
	//Initialize GPIO
	gpio.GPIO_Pin = SCK | SDA;
	gpio.GPIO_Mode = GPIO_Mode_Out_PP;
	gpio.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(GPIOB, &gpio);
	
	gpio.GPIO_Pin = GPIO_Pin_13;
	gpio.GPIO_Mode = GPIO_Mode_Out_PP;
	gpio.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(GPIOC, &gpio);
	
}
