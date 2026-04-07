#ifndef MCK_MATH_EXTRA_RANDOM_H
#define MCK_MATH_EXTRA_RANDOM_H

/* Minimal linear congruential generator for mck */

void mck_rand_seed(unsigned long seed);
unsigned long mck_rand_next(void);

#endif
