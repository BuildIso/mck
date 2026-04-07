#include "math/extra/random.h"

static unsigned long g_state = 1UL;

void mck_rand_seed(unsigned long seed) {
    if (seed == 0) {
        seed = 1UL;
    }
    g_state = seed;
}

unsigned long mck_rand_next(void) {
    g_state = g_state * 1664525UL + 1013904223UL;
    return g_state;
}
