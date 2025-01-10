#include "led.h"
#include "button.h"

int btn_state;

int main(void)
{
    led_init();
    button_init();

    while(1)
    {
        btn_state = get_button_state();
        
        if (btn_state)
        {
            led_on();
        }
        else
        {
            led_off();
        }
    }
}