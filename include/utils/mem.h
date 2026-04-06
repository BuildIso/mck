#ifndef MCK_MEM_H
#define MCK_MEM_H

#include "core.h"

/* Simple memory operations */
void mck_mem_set(void *ptr, mck_u8 value, mck_u32 size);
void mck_mem_copy(void *dst, const void *src, mck_u32 size);

/* Minimal arena allocator */
typedef struct mck_arena {
    mck_u8  *base;
    mck_u32  size;
    mck_u32  offset;
} mck_arena;

void mck_arena_init(mck_arena *arena, void *buffer, mck_u32 size);
void *mck_arena_alloc(mck_arena *arena, mck_u32 size);

#endif
