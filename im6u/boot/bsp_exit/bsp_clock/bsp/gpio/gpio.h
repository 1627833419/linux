#ifndef __GPIO_H
#define __GPIO_H
#include "imx6ul.h"
typedef enum _gpio_pin_direction
{
    GPIO_Input = 0U,
    GPIO_Output = 1U,
}gpio_pin_direction;

typedef struct _gpio_pin_config
{
    gpio_pin_direction direction ;
    uint8_t outputLogic;
}gpio_pin_config;

void gpio_init(GPIO_Type *base,int pin, gpio_pin_config *config);
void gpio_pinwrte(GPIO_Type *base,int pin,int value);
int  read_pin(GPIO_Type *base ,int pin);

#endif