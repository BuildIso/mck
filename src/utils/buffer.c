#include "utils/buffer.h"

void mck_buffer_init(mck_buffer *b, void *storage, unsigned long capacity) {
    b->data = (unsigned char *)storage;
    b->size = 0;
    b->capacity = capacity;
}

int mck_buffer_push(mck_buffer *b, unsigned char value) {
    if (b->size >= b->capacity) {
        return 0;
    }
    b->data[b->size++] = value;
    return 1;
}
