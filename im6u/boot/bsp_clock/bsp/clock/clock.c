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

    //设置PLL2 PFD0-4 
    //读出原来的值，然后将需要操作的位清零
    reg = CCM_ANALOG->PFD_528;
    reg &=~(0x3f3f3f3f);
    //将要需要操作的值写入
    reg |= (32<<24);
    reg |= (24<<16);
    reg |= (16<<8);
    reg |= (27<<0);
    CCM_ANALOG->PFD_528 = reg;
    reg=0;
    reg = CCM_ANALOG->PFD_480;
    reg &= ~(0x3f3f3f3f);
    reg |= (19<<24);
    reg |= (17<<16);
    reg |= (16<<8);
    reg |= (12<<0);
    CCM_ANALOG->PFD_480=reg;
}