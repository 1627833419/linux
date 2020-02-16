#ifndef __MAIN_H
#define __MAIN_H

#define CCM_CCGR0           *((volatile unsigned int *)0X020c4068)
#define CCM_CCGR1           *((volatile unsigned int *)0X020C406C)
#define CCM_CCGR2           *((volatile unsigned int *)0X020C4070)
#define CCM_CCGR3           *((volatile unsigned int *)0X020C4074)
#define CCM_CCGR4           *((volatile unsigned int *)0X020C4078)
#define CCM_CCGR5           *((volatile unsigned int *)0X020C407C)
#define CCM_CCGR6           *((volatile unsigned int *)0X020C4080)

/*
* IOMUX 相关寄存器地址
*/
#define SW_MUX_GPIO1_IO03   *((volatile unsigned int *)0X020E0068)
#define SW_PAD_GPIO1_IO03   *((volatile unsigned int *)0X020E02F4)
/*
* GPIO1 相关寄存器地址
*/
#define GPIO1_DR            *((volatile unsigned int *)0X0209C000)
#define GPIO1_GDIR          *((volatile unsigned int *)0X0209C004)

#endif