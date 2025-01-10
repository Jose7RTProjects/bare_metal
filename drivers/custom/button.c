#include "button.h"

#define GPIOAEN (1U << 0)
#define BTN_PIN (1U << 0)

void button_init(void)
{
    RCC->AHB1ENR |= GPIOAEN;

    GPIOA->MODER &= ~(1U << 0);
    GPIOA->MODER &= ~(1U << 1); 
}

int get_button_state(void)
{
    if (GPIOA->IDR & BTN_PIN)
    {
        return 1;
    } 
    else 
    {
        return 0;
    }
}