#ifndef _DELAY_H
#define _DELAY_H

#include "stm32f10x.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_tim.h"

void TIM2_INT_Init();

void delayMs(int delayMilis);

#endif