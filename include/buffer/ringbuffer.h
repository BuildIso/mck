#ifndef MCK_RINGBUFFER_H
#define MCK_RINGBUFFER_H

#include "core.h"

typedef struct mck_ringbuffer {
    mck_u8  *data;
    mck_u32 capacity;
    mck_u32 head;
    mck_u32 tail;
    mck_u32 count;
} mck_ringbuffer;

void mck_ringbuffer_init(mck_ringbuffer *rb, mck_u8 *buffer, mck_u32 capacity);
int  mck_ringbuffer_push(mck_ringbuffer *rb, mck_u8 value);
int  mck_ringbuffer_pop(mck_ringbuffer *rb, mck_u8 *out);

#endif
