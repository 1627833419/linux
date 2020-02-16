#include "led.h"


void led_init(void)
{
    /*初始化IO复用*/
    IOMUXC_SetPinMux(IOMUXC_GPIO1_IO03_GPIO1_IO03, 0);
    /*配置GPIO属性*/
    IOMUXC_SetPinConfig(IOMUXC_GPIO1_IO03_GPIO1_IO03,0x10b0);
    /*输出*/
    GPIO1->GDIR |=(1<<3);
    /*输出低电平*/
    GPIO1->DR &=~(1<<3);
}

void led_switch(int led,int status)
{
    switch(led)
    {
        case LED0:
            if(status== ON)
                GPIO1->DR &=~(1<<3);
            else if(status==OFF)
                GPIO1->DR |=(1<<3);
    }
}