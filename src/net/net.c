#include "net/net.h"

#define NET_QUEUE_MAX 32

static net_rx_handler handler;

static net_packet queue[NET_QUEUE_MAX];
static unsigned long qcount;

void net_init(void) {
    handler = 0;
    qcount = 0;
}

void net_set_rx_handler(net_rx_handler h) {
    handler = h;
}

void net_send(const void *data, unsigned long size) {
    (void)data;
    (void)size;
}

void net_receive(const void *data, unsigned long size) {
    if (qcount >= NET_QUEUE_MAX) return;
    queue[qcount].data = (unsigned char *)data;
    queue[qcount].size = size;
    qcount++;
}

void net_poll(void) {
    unsigned long i;
    if (!handler) {
        qcount = 0;
        return;
    }
    for (i = 0; i < qcount; i++) handler(&queue[i]);
    qcount = 0;
}
