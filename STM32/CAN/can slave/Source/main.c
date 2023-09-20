#include "../Header/can.h"


int main(){
	  
  Init_CAN();
	
  uint8_t data[20] = {0};
  receive_Can_Message(data);

	
	GPIO_SetBits(GPIOC, GPIO_Pin_13);
    
}