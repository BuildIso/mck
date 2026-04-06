#include "time/time.h"

static mck_u32 g_tick_count = 0;
static mck_u32 g_tick_ms = 1;

void mck_time_init(mck_u32 tick_ms) {
    if (tick_ms == 0) {
        g_tick_ms = 1;
    } else {
        g_tick_ms = tick_ms;
    }
    g_tick_count = 0;
}

void mck_time_tick(void) {
    g_tick_count++;
}

mck_u32 mck_time_ticks(void) {
    return g_tick_count;
}

mck_u32 mck_time_ms(void) {
    return g_tick_count * g_tick_ms;
}

mck_u32 mck_time_seconds(void) {
    return (g_tick_count * g_tick_ms) / 1000;
}
