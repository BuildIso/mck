; isr.asm - Interrupt stubs

BITS 32

global isr_stub_table

%macro ISR_NOERR 1
global isr%1
isr%1:
    push dword 0
    push dword %1
    jmp isr_common
%endmacro

%macro ISR_ERR 1
global isr%1
isr%1:
    push dword %1
    jmp isr_common
%endmacro

isr_common:
    ; Placeholder: user will implement handler in C
    add esp, 8
    iret

isr_stub_table:
%assign i 0
%rep 32
    dd isr%+i
%assign i i+1
%endrep
