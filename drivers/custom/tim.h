#ifndef TIM_H_
#define TIM_H_

#include "stm32f4xx.h"

void tim2_1hz_init(void);
void tim2_s_delay(uint16_t delay);

#endif // TIM_H_