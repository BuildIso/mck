; io.asm - Port I/O

BITS 32

global outb
global inb

outb:
    mov dx, [esp+4]
    mov al, [esp+8]
    out dx, al
    ret

inb:
    mov dx, [esp+4]
    in al, dx
    ret
