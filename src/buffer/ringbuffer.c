#include "buffer/ringbuffer.h"

void mck_ringbuffer_init(mck_ringbuffer *rb, mck_u8 *buffer, mck_u32 capacity) {
    rb->data = buffer;
    rb->capacity = capacity;
    rb->head = 0;
    rb->tail = 0;
    rb->count = 0;
}

int mck_ringbuffer_push(mck_ringbuffer *rb, mck_u8 value) {
    if (rb->count >= rb->capacity) return 0;

    rb->data[rb->head] = value;
    rb->head = (rb->head + 1) % rb->capacity;
    rb->count++;
    return 1;
}

int mck_ringbuffer_pop(mck_ringbuffer *rb, mck_u8 *out) {
    if (rb->count == 0) return 0;

    *out = rb->data[rb->tail];
    rb->tail = (rb->tail + 1) % rb->capacity;
    rb->count--;
    return 1;
}
