
.global _start  		/* 全局标号 */

/*
 * 描述：	_start函数，程序从此函数开始执行，此函数主要功能是设置C
 *		 运行环境。
 */
_start:
	ldr pc, =Reset_Handler
	ldr pc, =Undefined_Handler
	ldr pc, =SVC_Handler
	ldr pc, =PrefAbort_Handler
	ldr pc, =DataAbort_Handler 
	ldr pc, =NotUsed_Handler
	ldr pc, =IRQ_Handler
	ldr pc, =FIQ_Handler

Reset_Handler:
	cpsid i //cpsid关闭全局中断   cpsie开全局中断
	
	//关闭I Cache和D Cache
	mrc		p15, 0, r0, c1, c0,0
	bic 	 r0, r0, #(0x1<<12)
	bic		r0, r0 ,#(0x1<<2)
	bic 	r0, r0 ,#(0x2)
	bic		r0, r0, #(0x1<<11)
	bic 	r0, r0, #(0x1)
	mcr 	p15, 0 , r0, c1, c0, 0

	//设置各个模式下的栈指针


	/*IRQ模式下 */
	mrs r0, cpsr 
	bic r0 ,r0, #0x1f
	orr r0, r0, #0x12
	msr cpsr , r0
	ldr sp , =0x80600000

	/*进入SYS模式 */
	mrs r0, cpsr 
	bic r0, r0 ,#0x1f
	orr r0, r0 ,#0x1f
	msr cpsr ,r0
	ldr sp , =0x80400000


	/* 进入SVC模式 */
	mrs r0, cpsr
	bic r0, r0, #0x1f 	/* 将r0寄存器中的低5位清零，也就是cpsr的M0~M4 	*/
	orr r0, r0, #0x13 	/* r0或上0x13,表示使用SVC模式					*/
	msr cpsr, r0		/* 将r0 的数据写入到cpsr_c中 					*/
	ldr sp,=0X80200000	/* 设置栈指针			 */

	cpsie i 			//开启全局中断

	b main				/* 跳转到main函数 		 */

Undefined_Handler:
	ldr r0, =Undefined_Handler
	bx r0

SVC_Handler:
	ldr r0, =SVC_Handler
	bx r0

PrefAbort_Handler:
	ldr r0, =PrefAbort_Handler
	bx r0

DataAbort_Handler:
	ldr r0, =DataAbort_Handler
	bx r0

NotUsed_Handler:
	ldr r0, =NotUsed_Handler
	bx r0
//先保存当前代码执行的位置和环境，就是各个寄存器的值
IRQ_Handler:
	//保存lr寄存器地址，lr寄存器为链接寄存器，保存下一次执行代码的地址
	push {lr}
	push {r0-r3, r12} 
	
	mrs r0, spsr
	 /*读取spsr寄存器 ,spsr 为程序状态保存寄存器。
	mrs命令用于读cpsr，spsr特殊寄存器，
	msr命令拥有写*/ 
	push {r0}	/*spsr */

	mrc p15, 4, r12,c15, c0, 0   //mrc将cp15协处理器的数据读到普通寄存器中
	//MCR{cond} p15, <opc1>, <Rt>, <CRn>, <CRm>, <opc2>
	//读取CBAR寄存器，获取GIC写处理器寄存器组的基地址
	//偏移0x2000为CPU接口端的基地址
	//再加0xc为寄存器GIC_IAR，这个寄存器中0-保存着中断id
	add r1,r1, #0x2000
	ldr r0, [r1, #0xc]
	push {r0,r1}

	cps #0x13   		//进入SVC模式
	push {lr}

	ldr r2 , =system_irqhandler//因为函数参数只有一个，所以将r0的值作为参数
	blx r2

	pop {lr}
	cps #0x12 		//进入IRQ模式
	pop {r0,r1}		
	str r0 , [r1, #0x10]   //中断执行完成，写EOIR ，相当与完成中断标志

	pop {r0}
	msr spsr_cxsf, r0

	pop {r0-r3, r12}

	pop {lr}
	subs pc, lr, #4
FIQ_Handler:
	ldr r0, =FIQ_Handler
	bx r0