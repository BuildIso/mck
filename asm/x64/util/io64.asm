; io64.asm - Port I/O for x86_64 (SysV-like: first arg in rdi, second in rsi, etc.)

BITS 64

GLOBAL outb64
GLOBAL inb64

; void outb64(unsigned short port, unsigned char value);
outb64:
    mov dx, di        ; port
    mov al, sil       ; value (low 8 bits of rsi)
    out dx, al
    ret

; unsigned char inb64(unsigned short port);
inb64:
    mov dx, di        ; port
    in al, dx
    ret
