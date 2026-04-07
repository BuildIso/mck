#ifndef MCK_CONSOLE_H
#define MCK_CONSOLE_H

/* Minimal console abstraction for mck */

typedef void (*mck_console_write_fn)(const char *text);
typedef void (*mck_console_clear_fn)(void);

void mck_console_set_write(mck_console_write_fn fn);
void mck_console_set_clear(mck_console_clear_fn fn);

void mck_console_write(const char *text);
void mck_console_clear(void);

#endif
