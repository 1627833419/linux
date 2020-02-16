.global _start

_start:

@enable all clock
ldr r0, =0x020c4068
ldr r1, =0xffffffff
str r1, [r0]

ldr r0, =0x020c406c
str r1, [r0]

ldr r0, =0x020c4070
str r1, [r0]

ldr r0, =0x020c4074
str r1, [r0]

ldr r0, =0x020c4078
str r1, [r0]

ldr r0, =0x020c407c
str r1, [r0]

ldr r0, =0x020c4080
str r1, [r0]

@set IO to GPIO
ldr r0, =0x020e0068
ldr r1, =0x5
str r1, [r0]

@set GPIO
ldr r0, =0x020e02f4
ldr r1, =0x10b0
str r1, [r0]

@set GPIO to output
ldr r0, =0x0209c004
ldr r1, =0x8
str r1, [r0]


@output low
ldr r0, =0x0209c000
ldr r1, =0
str r1, [r0]
loop:
    b loop

