#include "main.h"

int main()
{
    clock_enable();
    led_init();
    beep_init();
    int i=0;
    unsigned char state=0;
    while(1)
    {
        if(key_value())
        {
           beep_switch(beep_on); 
           delay_ms(100);
           beep_switch(beep_off);
        }
        i++;
        if(i==50)
        {
            state!=state;
            led_switch(led0,state);
        }
        delay_ms(10);
    }
}
