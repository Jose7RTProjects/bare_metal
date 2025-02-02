#include "tim.h"

#define TIM2EN  (1U << 0)
#define CR1_CEN (1U << 0)
#define SR_UIF (1U << 0)

void tim2_1hz_init(void)
{
    RCC->APB1ENR |= TIM2EN;
    TIM2->PSC = 1600 - 1;
    TIM2->ARR = 10000 - 1;    
}

void tim2_s_delay(uint16_t delay)
{
    TIM2->CNT = 0;
    TIM2->CR1 = CR1_CEN;

    for (uint16_t i = 0; i < delay; i++)
    {
        while(!(TIM2->SR & SR_UIF));
        TIM2->SR &= ~SR_UIF;
    }

    TIM2->CR1 &= ~CR1_CEN;
}