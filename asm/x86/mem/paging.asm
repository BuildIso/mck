; paging.asm - Minimal paging setup

BITS 32

global paging_enable
global page_directory

section .bss
align 4096
page_directory:
    resd 1024

paging_enable:
    mov eax, page_directory
    mov cr3, eax

    mov eax, cr0
    or eax, 0x80000000
    mov cr0, eax
    ret
