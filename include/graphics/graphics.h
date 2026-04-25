#ifndef GRAPHICS_H
#define GRAPHICS_H

typedef struct {
    void *buffer;
    unsigned long width;
    unsigned long height;
    unsigned long pitch;
} gfx_surface;

void gfx_set_surface(gfx_surface *s);
void gfx_putpixel(unsigned long x, unsigned long y, unsigned long color);
void gfx_clear(unsigned long color);

#endif
