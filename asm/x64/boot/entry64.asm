; entry64.asm - Minimal 64-bit kernel entry
; Assumes long mode already enabled, paging active, stack set.

BITS 64
GLOBAL kmain_entry

EXTERN kmain   ; C function: void kmain(void);

kmain_entry:
    ; At this point, bootloader is expected to have:
    ; - set up long mode
    ; - enabled paging
    ; - set up a valid stack
    ; We just jump into C.
    call kmain

.hang:
    hlt
    jmp .hang
