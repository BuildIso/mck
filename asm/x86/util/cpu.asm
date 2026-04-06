; cpu.asm - CPU utilities

BITS 32

global cpu_halt
global cpu_cli
global cpu_sti

cpu_halt:
    hlt
    ret

cpu_cli:
    cli
    ret

cpu_sti:
    sti
    ret
