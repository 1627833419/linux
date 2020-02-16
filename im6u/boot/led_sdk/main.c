#include "MCIMX6Y2.h"
#include "fsl_common.h"
#include "fsl_iomuxc.h"

void clock_enable()
{
    CCM->CCGR0 = 0xffffffff;
    CCM->CCGR1 = 0xffffffff;
    CCM->CCGR2 = 0xffffffff;
    CCM->CCGR3 = 0xffffffff;
    CCM->CCGR4 = 0xffffffff;
    CCM->CCGR5 = 0xffffffff;
    CCM->CCGR6 = 0xffffffff;
}

void led_init(void)
{
    //将IO复用GPIO
    IOMUXC_SetPinMux(IOMUXC_GPIO1_IO03_GPIO1_IO03,0);
    //配置GPIO的属性
    IOMUXC_SetPinConfig(IOMUXC_GPIO1_IO03_GPIO1_IO03,0x10b0);

    GPIO1->GDIR|=(1<<3);

    GPIO1->DR  |=(1<<3);
}
void delay(volatile unsigned int n)
{
    while(n--)
    {
        volatile unsigned int i=0x7ff;
        while(i--);
    }
}
int main()
{
    clock_enable();
    led_init();
    while(1)
    {
        GPIO1->DR|=(1<<3);
        delay(1000);
        GPIO1->DR&=~(1<<3);
        delay(1000);
    }
}
