
#include "delay.h"

void delay_ms(volatile unsigned int n)
{
    volatile unsigned int i;
    while(n--)
    {
        i=0x7ff;
        while(i--);
    }
}