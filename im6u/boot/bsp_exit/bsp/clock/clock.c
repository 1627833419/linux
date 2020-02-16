#include "clock.h"

void clock_enable()
{
    CCM->CCGR0=enable;
    CCM->CCGR1=enable;
    CCM->CCGR2=enable;
    CCM->CCGR3=enable;
    CCM->CCGR4=enable;
    CCM->CCGR5=enable;
    CCM->CCGR6=enable;
}

void imx6u_clockinit(void )
{
    unsigned int reg = 0;
    if((((CCM->CCSR)>>2)&0x1)==0)// arm_clock  is PLL1_main_clk
    {
        CCM->CCSR &=~(1<<8);
        CCM->CCSR |=(1<<2);
    }

    CCM_ANALOG->PLL_ARM =(1<<13)|((88<<0)&0x7F);//set
    CCM->CCSR &= ~(1<<2);//clock switch to PLL1_main_clk
    CCM->CACRR =1;  //two frequency division
}