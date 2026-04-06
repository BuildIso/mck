#include "event/event.h"

void mck_event_queue_init(mck_event_queue *q, mck_event *buffer, mck_u32 capacity) {
    q->events = buffer;
    q->capacity = capacity;
    q->count = 0;
}

int mck_event_push(mck_event_queue *q, mck_event_handler fn, void *userdata) {
    if (q->count >= q->capacity) return 0;
    q->events[q->count].handler = fn;
    q->events[q->count].userdata = userdata;
    q->count++;
    return 1;
}

void mck_event_dispatch(mck_event_queue *q) {
    mck_u32 i;
    for (i = 0; i < q->count; ++i) {
        q->events[i].handler(q->events[i].userdata);
    }
    q->count = 0;
}
