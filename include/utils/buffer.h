#ifndef MCK_UTILS_BUFFER_H
#define MCK_UTILS_BUFFER_H

/* Minimal growable byte buffer for mck */

typedef struct {
    unsigned char *data;
    unsigned long size;
    unsigned long capacity;
} mck_buffer;

void mck_buffer_init(mck_buffer *b, void *storage, unsigned long capacity);
int mck_buffer_push(mck_buffer *b, unsigned char value);

#endif
