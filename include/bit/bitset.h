#ifndef MCK_BITSET_H
#define MCK_BITSET_H

#include "core.h"

typedef struct mck_bitset {
    mck_u32 *data;
    mck_u32  bit_count;
} mck_bitset;

void mck_bitset_init(mck_bitset *bs, mck_u32 *buffer, mck_u32 bit_count);
void mck_bitset_set(mck_bitset *bs, mck_u32 index);
void mck_bitset_clear(mck_bitset *bs, mck_u32 index);
int  mck_bitset_test(const mck_bitset *bs, mck_u32 index);

#endif
