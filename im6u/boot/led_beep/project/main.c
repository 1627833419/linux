#include "main.h"

int main()
{
    clock_enable();
    led_init();
    beep_init();
    while(1)
    {
        led_switch(led0,led_on);
        beep_switch(beep_on);
        delay_ms(500);
        led_switch(led0,led_off);
        beep_switch(beep_off);
        delay_ms(500);
    }
}
