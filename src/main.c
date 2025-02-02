#include "led.h"
#include "tim.h"

int main(void)
{
    led_init();
    tim2_1hz_init();

    while(1)
    {
        led_toggle();
        tim2_s_delay(1);
    }
}