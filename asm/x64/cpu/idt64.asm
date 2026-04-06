; idt64.asm - Minimal 64-bit IDT

BITS 64

GLOBAL idt64_load
GLOBAL idt64_descriptor

idt64_start:
    times 256 dq 0
idt64_end:

idt64_descriptor:
    dw idt64_end - idt64_start - 1
    dq idt64_start

idt64_load:
    lidt [idt64_descriptor]
    ret
