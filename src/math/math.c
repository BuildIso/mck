#include "math/math.h"

mck_u32 mck_min_u32(mck_u32 a, mck_u32 b) {
    return (a < b) ? a : b;
}

mck_u32 mck_max_u32(mck_u32 a, mck_u32 b) {
    return (a > b) ? a : b;
}

mck_u32 mck_clamp_u32(mck_u32 v, mck_u32 min, mck_u32 max) {
    if (v < min) return min;
    if (v > max) return max;
    return v;
}
