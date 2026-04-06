; boot16.asm - Minimal 16-bit boot sector
; NASM syntax

BITS 16
ORG 0x7C00

start:
    cli
    xor ax, ax
    mov ds, ax
    mov es, ax
    mov ss, ax
    mov sp, 0x7C00

    mov si, msg
    call print_string

hang:
    hlt
    jmp hang

print_string:
    mov ah, 0x0E
.next:
    lodsb
    cmp al, 0
    je .done
    int 0x10
    jmp .next
.done:
    ret

msg: db "mck bootloader active", 0

TIMES 510-($-$$) db 0
DW 0xAA55
