#include "led.h"

#define GPIODEN (1U << 3)
#define LED_BS12 (1U << 12)
#define LED_BR12 (1U << 28)

void led_init(void)
{
    RCC->AHB1ENR |= GPIODEN;

    GPIOD->MODER |= (1U << 24);
    GPIOD->MODER &= ~(1U << 25);
}

void led_on(void)
{
    GPIOD->BSRR |= LED_BS12;
}

void led_off(void)
{
    GPIOD->BSRR |= LED_BR12;
}