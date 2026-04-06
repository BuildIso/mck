; idt.asm - Minimal IDT

BITS 32

global idt_load
global idt_descriptor

idt_start:
    times 256 dq 0
idt_end:

idt_descriptor:
    dw idt_end - idt_start - 1
    dd idt_start

idt_load:
    lidt [idt_descriptor]
    ret
