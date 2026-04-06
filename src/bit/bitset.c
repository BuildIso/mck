#include "bit/bitset.h"

void mck_bitset_init(mck_bitset *bs, mck_u32 *buffer, mck_u32 bit_count) {
    bs->data = buffer;
    bs->bit_count = bit_count;
}

void mck_bitset_set(mck_bitset *bs, mck_u32 index) {
    mck_u32 word = index / 32;
    mck_u32 bit  = index % 32;
    bs->data[word] |= (1UL << bit);
}

void mck_bitset_clear(mck_bitset *bs, mck_u32 index) {
    mck_u32 word = index / 32;
    mck_u32 bit  = index % 32;
    bs->data[word] &= ~(1UL << bit);
}

int mck_bitset_test(const mck_bitset *bs, mck_u32 index) {
    mck_u32 word = index / 32;
    mck_u32 bit  = index % 32;
    return (bs->data[word] >> bit) & 1U;
}
