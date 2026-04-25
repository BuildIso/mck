#include "input/input.h"

#define INPUT_QUEUE_MAX 64

static input_event queue[INPUT_QUEUE_MAX];
static unsigned long qcount;
static input_handler handler;

void input_init(void) {
    qcount = 0;
    handler = 0;
}

void input_set_handler(input_handler h) {
    handler = h;
}

void input_push(int code, int value) {
    if (qcount >= INPUT_QUEUE_MAX) return;
    queue[qcount].code = code;
    queue[qcount].value = value;
    qcount++;
}

void input_poll(void) {
    unsigned long i;
    if (!handler) {
        qcount = 0;
        return;
    }
    for (i = 0; i < qcount; i++) handler(&queue[i]);
    qcount = 0;
}
