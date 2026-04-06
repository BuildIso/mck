; gdt.asm - Minimal GDT

BITS 32

global gdt_load
global gdt_descriptor

gdt_start:
    dq 0x0000000000000000
    dq 0x00CF9A000000FFFF
    dq 0x00CF92000000FFFF
gdt_end:

gdt_descriptor:
    dw gdt_end - gdt_start - 1
    dd gdt_start

gdt_load:
    lgdt [gdt_descriptor]
    ret
