; cpu64.asm - CPU utilities for x86_64

BITS 64

GLOBAL cpu64_halt
GLOBAL cpu64_cli
GLOBAL cpu64_sti

cpu64_halt:
    hlt
    ret

cpu64_cli:
    cli
    ret

cpu64_sti:
    sti
    ret
