#ifndef MCK_TTY_H
#define MCK_TTY_H

/* Minimal TTY abstraction for mck */

typedef void (*mck_tty_write_fn)(const char *text);
typedef void (*mck_tty_putc_fn)(char c);

void mck_tty_set_write(mck_tty_write_fn fn);
void mck_tty_set_putc(mck_tty_putc_fn fn);

void mck_tty_write(const char *text);
void mck_tty_putc(char c);

#endif
