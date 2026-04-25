#include "drivers/serial/uart16550.h"

extern void outb(unsigned short port, unsigned char value);
extern unsigned char inb(unsigned short port);

static void mck_uart16550_wait_tx(unsigned short base) {
    while ((inb(base + 5) & 0x20) == 0) {
    }
}

void mck_uart16550_init(mck_uart16550 *u, unsigned short base_port) {
    u->base_port = base_port;
    outb(base_port + 1, 0x00);
    outb(base_port + 3, 0x80);
    outb(base_port + 0, 0x01);
    outb(base_port + 1, 0x00);
    outb(base_port + 3, 0x03);
    outb(base_port + 2, 0xC7);
    outb(base_port + 4, 0x0B);
}

void mck_uart16550_putc(mck_uart16550 *u, char c) {
    mck_uart16550_wait_tx(u->base_port);
    outb(u->base_port + 0, (unsigned char)c);
}

void mck_uart16550_write(mck_uart16550 *u, const char *s) {
    char c;
    while ((c = *s++)) {
        if (c == '\n') {
            mck_uart16550_putc(u, '\r');
        }
        mck_uart16550_putc(u, c);
    }
}
