#ifndef MCK_CONSOLE_VGA_H
#define MCK_CONSOLE_VGA_H

#include "core.h"

void mck_console_vga_init(mck_u16 *buffer, mck_u32 cols, mck_u32 rows);
void mck_console_vga_set_color(mck_u8 fg, mck_u8 bg);

#endif
