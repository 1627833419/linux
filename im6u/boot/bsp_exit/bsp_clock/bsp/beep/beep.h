#ifndef __BEEP_H
#define __BEEP_H
#include "imx6ul.h"
#define beep_on  1
#define beep_off 0

void beep_init();
void beep_switch(int status);
#endif