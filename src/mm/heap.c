#include "mm/heap.h"

static unsigned long mck_heap_align_up(unsigned long v, unsigned long align) {
    unsigned long m = align - 1;
    return (v + m) & ~m;
}

void mck_heap_init(mck_heap *h, void *buffer, unsigned long size) {
    h->base = (unsigned char *)buffer;
    h->size = size;
    h->used = 0;
}

void *mck_heap_alloc(mck_heap *h, unsigned long size, unsigned long align) {
    unsigned long offset = mck_heap_align_up(h->used, align ? align : 1);
    unsigned long end = offset + size;
    if (end > h->size) return 0;
    h->used = end;
    return h->base + offset;
}

void mck_heap_reset(mck_heap *h) {
    h->used = 0;
}
