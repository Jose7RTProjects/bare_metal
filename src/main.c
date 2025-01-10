#include "led.h"
#include "systick.h"

int btn_state;

int main(void)
{
    led_init();

    while(1)
    {
        led_toggle();
        systick_ms_delay(10000);
    }
}