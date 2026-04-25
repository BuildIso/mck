#ifndef MCK_MM_HEAP_H
#define MCK_MM_HEAP_H

typedef struct {
    unsigned char *base;
    unsigned long size;
    unsigned long used;
} mck_heap;

void mck_heap_init(mck_heap *h, void *buffer, unsigned long size);
void *mck_heap_alloc(mck_heap *h, unsigned long size, unsigned long align);
void mck_heap_reset(mck_heap *h);

#endif
