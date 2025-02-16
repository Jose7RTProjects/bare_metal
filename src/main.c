#include <stdio.h>

#include "uart.h"
#include "tim.h"

static void write_string(const char* string);

int main(void)
{
    uart_init();
    tim2_1hz_init();

    const char* my_string = "Hello from STM32\r\n";

    while(1)
    {
        write_string(my_string);
        tim2_s_delay(1);
    }
}

static void write_string(const char* string)
{
    for (int i = 0; string[i] != '\0'; i++)
    {
        uart_write(string[i]);
    }
}