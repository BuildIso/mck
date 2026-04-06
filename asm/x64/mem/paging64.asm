; paging64.asm - Stub for 64-bit paging adjustments
; Real paging setup is highly project-specific.

BITS 64

GLOBAL paging64_reload_cr3

; void paging64_reload_cr3(void *pml4);
paging64_reload_cr3:
    mov rax, rdi      ; pml4 pointer
    mov cr3, rax
    ret
