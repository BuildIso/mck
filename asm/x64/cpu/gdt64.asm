; gdt64.asm - Minimal 64-bit GDT

BITS 64

GLOBAL gdt64_load
GLOBAL gdt64_descriptor

gdt64_start:
    dq 0x0000000000000000          ; null
    dq 0x00AF9A000000FFFF          ; code
    dq 0x00AF92000000FFFF          ; data
gdt64_end:

gdt64_descriptor:
    dw gdt64_end - gdt64_start - 1
    dq gdt64_start

gdt64_load:
    lgdt [gdt64_descriptor]
    ret
