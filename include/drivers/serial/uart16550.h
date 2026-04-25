#ifndef MCK_UART16550_H
#define MCK_UART16550_H

#include "core.h"

typedef struct {
    unsigned short base_port;
} mck_uart16550;

void mck_uart16550_init(mck_uart16550 *u, unsigned short base_port);
void mck_uart16550_putc(mck_uart16550 *u, char c);
void mck_uart16550_write(mck_uart16550 *u, const char *s);

#endif
