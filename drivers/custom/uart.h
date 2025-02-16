#ifndef UART_H_
#define UART_H_

#include "stm32f4xx.h"

void uart_init(void);
void uart_write(uint8_t ch);

#endif // UART_H_