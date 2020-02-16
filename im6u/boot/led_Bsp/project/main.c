#include "main.h"

int main()
{
    clock_enable();
    led_init();
    while(1)
    {
        led_switch(led0,led_on);
        delay_ms(500);
        led_switch(led0,led_off);
        delay_ms(500);
    }
}
