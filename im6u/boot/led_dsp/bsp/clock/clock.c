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