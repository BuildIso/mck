#include "mm/mm.h"

void mck_bump_init(mck_bump *b, void *buffer, unsigned long size) {
    b->base = (unsigned char *)buffer;
    b->size = size;
    b->offset = 0;
}

void *mck_bump_alloc(mck_bump *b, unsigned long size) {
    unsigned long next = b->offset + size;
    if (next > b->size) {
        return 0;
    }
    void *ptr = b->base + b->offset;
    b->offset = next;
    return ptr;
}
