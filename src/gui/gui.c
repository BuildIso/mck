#include "gui/gui.h"

static gui_surface *surf;

void gui_set_surface(gui_surface *s) {
    surf = s;
}

void gui_fill_rect(unsigned long x, unsigned long y, unsigned long w, unsigned long h, unsigned long color) {
    if (!surf) return;
    unsigned long i, j;
    for (j = 0; j < h; j++) {
        for (i = 0; i < w; i++) {
            unsigned long off = (y + j) * surf->pitch + (x + i) * 4;
            unsigned long *p = (unsigned long *)((unsigned char *)surf->buffer + off);
            *p = color;
        }
    }
}

void gui_blit(unsigned long x, unsigned long y, const void *src, unsigned long w, unsigned long h) {
    if (!surf) return;
    unsigned long i, j;
    const unsigned long *s = src;
    for (j = 0; j < h; j++) {
        for (i = 0; i < w; i++) {
            unsigned long off = (y + j) * surf->pitch + (x + i) * 4;
            unsigned long *p = (unsigned long *)((unsigned char *)surf->buffer + off);
            *p = s[j * w + i];
        }
    }
}
