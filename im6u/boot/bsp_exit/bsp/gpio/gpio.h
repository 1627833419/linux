#ifndef __GPIO_H
#define __GPIO_H
#include "imx6ul.h"

//GPIO方向枚举
typedef enum _gpio_pin_direction
{
    GPIO_Input = 0U,
    GPIO_Output = 1U,
}gpio_pin_direction;

//GPIO终端触发类型枚举
typedef enum _gpio_interrupt_mode
{
    kGPIO_NoIntmode= 0U,
    kGPIO_IntLowLevel =1U,
    kGPIO_IntHighLevel =2U,
    kGPIO_IntRisingEdge = 3U,
    kGPIO_IntFallingEdge = 4U,
    kGPIO_IntRisingOrFallingEdge =5U,
}gpio_interrupt_mode_t;

//GPIO配置结构体
typedef struct _gpio_pin_config
{
    gpio_pin_direction direction ;
    uint8_t outputLogic;
    gpio_interrupt_mode_t interruptMode;
}gpio_pin_config;

void gpio_init(GPIO_Type *base,int pin, gpio_pin_config *config);
void gpio_pinwrte(GPIO_Type *base,int pin,int value);
int  read_pin(GPIO_Type *base ,int pin);

void gpio_intconfig(GPIO_Type   *base, unsigned int pin ,gpio_interrupt_mode_t pinInterruptMode);
void gpio_enableint(GPIO_Type *base, unsigned int pin);
void gpio_disableint(GPIO_Type  *base, unsigned int pin);
void gpio_clearintflag(GPIO_Type    *base, unsigned int pin);

#endif