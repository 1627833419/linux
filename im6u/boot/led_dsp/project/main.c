#include "imx6ul.h"
#include "led.h"
#include "delay.h"
#include "clock.h"

int main()
{
    clock_enable();
    led_init();
    while(1)
    {
        led_switch(LED0,ON);
        delay_ms(500);
        led_switch(LED0,OFF);
        delay_ms(500);
    }
}
