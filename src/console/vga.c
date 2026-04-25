#include "console/vga.h"
#include "console/console.h"

static mck_u16 *g_vga_buf = 0;
static mck_u32 g_cols = 0;
static mck_u32 g_rows = 0;
static mck_u32 g_x = 0;
static mck_u32 g_y = 0;
static mck_u8 g_color = 0x07;

static void mck_console_vga_clear_impl(void) {
    mck_u32 i;
    mck_u16 v = ((mck_u16)g_color << 8) | ' ';
    for (i = 0; i < g_cols * g_rows; ++i) g_vga_buf[i] = v;
    g_x = 0;
    g_y = 0;
}

static void mck_console_vga_scroll(void) {
    mck_u32 x, y;
    mck_u32 last = g_rows - 1;
    for (y = 0; y < last; ++y) {
        for (x = 0; x < g_cols; ++x) {
            g_vga_buf[y * g_cols + x] = g_vga_buf[(y + 1) * g_cols + x];
        }
    }
    {
        mck_u32 i;
        mck_u16 v = ((mck_u16)g_color << 8) | ' ';
        for (i = 0; i < g_cols; ++i) g_vga_buf[last * g_cols + i] = v;
    }
}

static void mck_console_vga_putc(char c) {
    if (c == '\n') {
        g_x = 0;
        if (++g_y >= g_rows) {
            g_y = g_rows - 1;
            mck_console_vga_scroll();
        }
        return;
    }
    g_vga_buf[g_y * g_cols + g_x] = ((mck_u16)g_color << 8) | (mck_u8)c;
    if (++g_x >= g_cols) {
        g_x = 0;
        if (++g_y >= g_rows) {
            g_y = g_rows - 1;
            mck_console_vga_scroll();
        }
    }
}

static void mck_console_vga_write_impl(const char *text) {
    char c;
    while ((c = *text++)) mck_console_vga_putc(c);
}

void mck_console_vga_init(mck_u16 *buffer, mck_u32 cols, mck_u32 rows) {
    g_vga_buf = buffer;
    g_cols = cols;
    g_rows = rows;
    g_x = 0;
    g_y = 0;
    mck_console_vga_clear_impl();
    mck_console_set_write(mck_console_vga_write_impl);
    mck_console_set_clear(mck_console_vga_clear_impl);
}

void mck_console_vga_set_color(mck_u8 fg, mck_u8 bg) {
    g_color = (mck_u8)((bg << 4) | (fg & 0x0F));
}
