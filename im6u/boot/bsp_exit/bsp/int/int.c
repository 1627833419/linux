#include "int.h"


static unsigned int irqNesting;
//使用数组储存中断
static sys_irq_handle_t     irqTable [NUMBER_OF_INT_VECTORS];

void int_init(void)
{
    GIC_Init();
    system_irqtable_init();
    __set_VBAR((uint32_t)0x87800000);
}


void system_irqtable_init(void)
{
    unsigned int i=0;
    irqNesting=0;
    for(i=0;i<NUMBER_OF_INT_VECTORS;i++)
    {
        system_register_irqhandler(  (IRQn_Type) i,default_irqhandler,NULL);
    }
}

void system_register_irqhandler(IRQn_Type irq , system_irq_handler_t handler,void *userParam)
{
    irqTable[irq].irqHandler=handler;
    irqTable[irq].userParam = userParam;
}
//汇编调用c函数时，参数少于4个将通过r0-r4传递
//这里参数则是在调用函数时将r0的值作为参数
void system_irqhandler(unsigned int giccIar) 
{
    uint32_t intNum =giccIar &0x3fffUL;//获得中断ID 号

    if((intNum == 1020)||(intNum >=NUMBER_OF_INT_VECTORS))
    {
        return;
    }
    irqNesting++;
    irqTable[intNum].irqHandler(intNum, irqTable[ intNum].userParam);

    irqNesting--;
}


void default_irqhandler(unsigned int giccIar, void *userParam)
{
    while(1)
    {
    }
}