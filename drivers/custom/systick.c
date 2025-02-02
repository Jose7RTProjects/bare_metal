#include "systick.h"

// By default the frequency of the MCU is 16 MHz
#define ONE_MSEC_LOAD  16000

void systick_ms_delay(uint32_t delay)
{
    SysTick->LOAD = ONE_MSEC_LOAD - 1;
    SysTick->VAL = 0;
    SysTick->CTRL = SysTick_CTRL_CLKSOURCE_Msk;
    SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;

    for(uint32_t i = 0; i < delay; i++)
    {
        while(!(SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk));
    }

    SysTick->CTRL = 0;
}