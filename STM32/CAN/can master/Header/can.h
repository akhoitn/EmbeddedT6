#ifndef _CAN_H
#define _CAN_H

#include "stm32f10x.h"
#include "stm32f10x_can.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_gpio.h"

void Init_CAN(uint16_t can_id);
void send_Can_Message(uint32_t id, uint8_t *data, uint8_t len);

#endif