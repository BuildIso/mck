#include "utils/mem.h"

void mck_mem_set(void *ptr, mck_u8 value, mck_u32 size) {
    mck_u32 i;
    mck_u8 *p = (mck_u8 *)ptr;
    for (i = 0; i < size; ++i) {
        p[i] = value;
    }
}

void mck_mem_copy(void *dst, const void *src, mck_u32 size) {
    mck_u32 i;
    mck_u8 *d = (mck_u8 *)dst;
    const mck_u8 *s = (const mck_u8 *)src;
    for (i = 0; i < size; ++i) {
        d[i] = s[i];
    }
}

void mck_arena_init(mck_arena *arena, void *buffer, mck_u32 size) {
    arena->base = (mck_u8 *)buffer;
    arena->size = size;
    arena->offset = 0;
}

void *mck_arena_alloc(mck_arena *arena, mck_u32 size) {
    if (arena->offset + size > arena->size) {
        return 0;
    }
    void *ptr = arena->base + arena->offset;
    arena->offset += size;
    return ptr;
}
