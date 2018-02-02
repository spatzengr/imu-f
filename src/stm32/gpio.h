#pragma once

#include "includes.h"

extern uint32_t read_digital_input(GPIO_TypeDef * GPIOx, uint16_t GPIO_Pin);
extern void single_gpio_init(GPIO_TypeDef * port, uint16_t pin_src, uint16_t pin, uint8_t af, GPIOMode_TypeDef mode, GPIOOType_TypeDef output, GPIOPuPd_TypeDef pull);
extern void board_gpio_init(void);