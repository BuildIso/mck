#ifndef GUI_H
#define GUI_H

typedef struct {
    void *buffer;
    unsigned long width;
    unsigned long height;
    unsigned long pitch;
} gui_surface;

void gui_set_surface(gui_surface *s);
void gui_fill_rect(unsigned long x, unsigned long y, unsigned long w, unsigned long h, unsigned long color);
void gui_blit(unsigned long x, unsigned long y, const void *src, unsigned long w, unsigned long h);

#endif
