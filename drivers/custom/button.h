#ifndef BUTTON_H_
#define BUTTON_H_

#include "stm32f4xx.h"

void button_init(void);
int get_button_state(void);

#endif // BUTTON_H_