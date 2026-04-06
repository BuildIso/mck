; startup.asm - minimal 64-bit kernel startup
BITS 64

GLOBAL _start
EXTERN kmain_entry

_start:
    ; Bootloader must have:
    ; - enabled long mode
    ; - set up paging
    ; - set up stack
    ; - jumped here in 64-bit mode

    call kmain_entry

.hang:
    hlt
    jmp .hang
