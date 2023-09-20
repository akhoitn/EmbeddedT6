
#include "../Header/can.h"

int main(){
	  
	Init_CAN(0x0000);
	
		
  uint8_t data[8]= {24, 11, 0, 30, 1, 20, 4};

  send_Can_Message(0x6B, data, 8);

	GPIO_SetBits(GPIOC, GPIO_Pin_13);
		
}