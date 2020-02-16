#include "gpio.h"

//IO祖 第几引脚 输入输出 默认状态
void gpio_init(GPIO_Type *base,int pin, gpio_pin_config *config)
{
    base->IMR &=~(1U<<pin);

    if(config->direction== GPIO_Input)
    {
        base->GDIR &= ~(1<< pin);
    }
    else
    {
        base->GDIR |= 1<<pin;//
        gpio_pinwrte(base,pin,config->outputLogic);
    }
    gpio_intconfig(base, pin ,config->interruptMode);
}


void gpio_pinwrte(GPIO_Type *base,int pin,int value)
{
    if(value==0U)
    {
        base->DR &=~(1<<pin);
    }
    else
    {
        base->DR |= (1<<pin);
    }
}

int  read_pin(GPIO_Type *base ,int pin)
{
    return (((base->DR)>>pin)&0x1);
}
/*中断函数*/

void gpio_intconfig(GPIO_Type   *base, unsigned int pin ,gpio_interrupt_mode_t pin_int_mode)
{
    volatile uint32_t *icr;
    uint32_t    icrShift;
    icrShift    =   pin;
    base->EDGE_SEL &=~(1U<<pin);

    if(pin<16)
    {
        icr =&(base->ICR1);
        
    }



}
