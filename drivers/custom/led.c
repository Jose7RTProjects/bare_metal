#include "led.h"

#define GPIODEN (1U << 3)
#define LED_PIN (1U << 12)

void led_init(void)
{
    RCC->AHB1ENR |= GPIODEN;

    GPIOD->MODER |= (1U << 24);
    GPIOD->MODER &= ~(1U << 25);
}

void led_on(void)
{
    GPIOD->ODR |= LED_PIN;
}

void led_off(void)
{
    GPIOD->ODR &= ~LED_PIN;
}

void led_toggle(void)
{
    GPIOD->ODR ^= LED_PIN;
}