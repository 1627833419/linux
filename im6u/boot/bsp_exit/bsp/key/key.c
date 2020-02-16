#include "key.h"


void key_init()//22k上拉
{
    IOMUXC_SetPinMux(IOMUXC_UART1_CTS_B_GPIO1_IO18,0);
    IOMUXC_SetPinConfig(IOMUXC_UART1_CTS_B_GPIO1_IO18,0xf080);
    GPIO1->GDIR &=~(1<<18);
}

int read_key(void)
{
    int ret;
    ret = (GPIO1->DR>>18);
    return ret;
}
int key_value(void)
{
    static unsigned char flag=1;
    if((flag==1)&&(read_key()==0))//按键被释放
    {
        delay_ms(10);
        if(read_key()==0)
        {
            flag=0;
            return 1;
        }
    }
    else if(read_key()==1)
    {
        flag=1;
        return 0;
    }
    return 0;
}
