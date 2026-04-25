#include "graphics/graphics.h"

static gfx_surface *surface;

void gfx_set_surface(gfx_surface *s) {
    surface = s;
}

void gfx_putpixel(unsigned long x, unsigned long y, unsigned long color) {
    if (!surface) return;
    unsigned char *p = (unsigned char *)surface->buffer;
    unsigned long off = y * surface->pitch + x * 4;
    unsigned long *dst = (unsigned long *)(p + off);
    *dst = color;
}

void gfx_clear(unsigned long color) {
    if (!surface) return;
    unsigned long x, y;
    for (y = 0; y < surface->height; y++) {
        for (x = 0; x < surface->width; x++) {
            gfx_putpixel(x, y, color);
        }
    }
}
