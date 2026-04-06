#ifndef MCK_EVENT_H
#define MCK_EVENT_H

#include "core.h"

typedef void (*mck_event_handler)(void *userdata);

typedef struct mck_event {
    mck_event_handler handler;
    void             *userdata;
} mck_event;

typedef struct mck_event_queue {
    mck_event *events;
    mck_u32    capacity;
    mck_u32    count;
} mck_event_queue;

void mck_event_queue_init(mck_event_queue *q, mck_event *buffer, mck_u32 capacity);
int  mck_event_push(mck_event_queue *q, mck_event_handler fn, void *userdata);
void mck_event_dispatch(mck_event_queue *q);

#endif
