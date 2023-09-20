#ifndef _CAN_H
#define _CAN_H

#include "stm32f10x.h"
#include "stm32f10x_can.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_gpio.h"

void Init_CAN();
void receive_Can_Message(uint8_t *data);

#endif