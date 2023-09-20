/*
* File: can.c
* Author: Anh Khoi
* Date: 08/09/2023
* Description: This file is created to transmit array of data by communication can
*/

#include "../Header/can.h"

/*
* Function: Init_CAN
* Description: Configuration communication CAN
* Input:
*   can_id: ID of NODE
* Ouput: 
*   None
*/
void Init_CAN(uint16_t can_id){
	
  GPIO_InitTypeDef            GPIO_InitStructure;
  CAN_InitTypeDef             CAN_InitStructure;
	
  CAN_FilterInitTypeDef       CAN_FilterInitStructure;  // bo loc can

	/* Enable clocks */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOC, ENABLE);
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_CAN1, ENABLE);
	
	/* Config pin for CAN1 */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;         // can Rx
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
 
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;         // can Tx
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	/* Pin check */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOC, &GPIO_InitStructure);
	
	
  CAN_InitStructure.CAN_TTCM = DISABLE;
  CAN_InitStructure.CAN_ABOM = DISABLE;
  CAN_InitStructure.CAN_AWUM = DISABLE; 
  CAN_InitStructure.CAN_NART = DISABLE;
  CAN_InitStructure.CAN_RFLM = DISABLE;
  CAN_InitStructure.CAN_TXFP = DISABLE;
  CAN_InitStructure.CAN_Mode = CAN_Mode_Normal;

  CAN_InitStructure.CAN_SJW = CAN_SJW_1tq;
  CAN_InitStructure.CAN_BS1 = CAN_BS1_3tq;
  CAN_InitStructure.CAN_BS2 = CAN_BS2_5tq;
	
  CAN_InitStructure.CAN_Prescaler = 4;
  CAN_Init(CAN1, &CAN_InitStructure);

	/* Config Filter*/
  CAN_FilterInitStructure.CAN_FilterNumber = 0;
  CAN_FilterInitStructure.CAN_FilterMode = CAN_FilterMode_IdMask;
  CAN_FilterInitStructure.CAN_FilterScale = CAN_FilterScale_32bit;
  CAN_FilterInitStructure.CAN_FilterIdHigh = can_id;
  CAN_FilterInitStructure.CAN_FilterIdLow = 0x0000;
  CAN_FilterInitStructure.CAN_FilterMaskIdHigh = 0x0000;
  CAN_FilterInitStructure.CAN_FilterMaskIdLow = 0x0000;
  CAN_FilterInitStructure.CAN_FilterFIFOAssignment = CAN_FIFO0;
  CAN_FilterInitStructure.CAN_FilterActivation = ENABLE;
  CAN_FilterInit(&CAN_FilterInitStructure);
}

/*
* Function: send_Can_Message
* Description: transmit data to NODE
* Input:
  id: ID of NODE
	*data: poiter of data want to transmit
	lenght: the lenght of the array of data
* Ouput: 
*   None
*/

void send_Can_Message(uint32_t id, uint8_t *data, uint8_t lenght){
	
  CanTxMsg TxMessage;
  TxMessage.StdId = id;
  TxMessage.ExtId = 0x00;
  TxMessage.RTR = CAN_RTR_DATA;
  TxMessage.IDE = CAN_ID_STD;
  TxMessage.DLC = lenght;

  for (int i = 0; i < lenght; i++) TxMessage.Data[i] = data[i];
   
  CAN_Transmit(CAN1, &TxMessage);
	
  while (CAN_TransmitStatus(CAN1, CAN_FIFO0) != CAN_TxStatus_Ok);
		
}