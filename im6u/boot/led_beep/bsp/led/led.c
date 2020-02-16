#include "led.h"

void led_init()
{
    IOMUXC_SetPinMux(IOMUXC_GPIO1_IO03_GPIO1_IO03,0);

    IOMUXC_SetPinConfig(IOMUXC_GPIO1_IO03_GPIO1_IO03,0x10b0);

    GPIO1->GDIR |=(1<<3);

    GPIO1->DR   &=~(1<<3);
}
void led_switch(int led,int status)
{
    switch(led)
    {
        case led0 :
            if(status==led_on)
                GPIO1->DR &=~(1<<3);
            else if(status==led_off)
                GPIO1->DR |=(1<<3);
            break;
    }
}