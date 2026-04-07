#ifndef MCK_MM_H
#define MCK_MM_H

/* Minimal bump allocator for mck */

typedef struct {
    unsigned char *base;
    unsigned long size;
    unsigned long offset;
} mck_bump;

void mck_bump_init(mck_bump *b, void *buffer, unsigned long size);
void *mck_bump_alloc(mck_bump *b, unsigned long size);

#endif
