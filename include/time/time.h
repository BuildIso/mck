#ifndef MCK_TIME_H
#define MCK_TIME_H

#include "core.h"

/* Time unit: 1 tick = user-defined duration (ms or arbitrary) */

void     mck_time_init(mck_u32 tick_ms);
void     mck_time_tick(void);
mck_u32  mck_time_ticks(void);
mck_u32  mck_time_ms(void);
mck_u32  mck_time_seconds(void);

#endif
