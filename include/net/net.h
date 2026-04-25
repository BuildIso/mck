#ifndef NET_H
#define NET_H

typedef struct {
    unsigned char *data;
    unsigned long size;
} net_packet;

typedef void (*net_rx_handler)(net_packet *p);

void net_init(void);
void net_set_rx_handler(net_rx_handler h);
void net_send(const void *data, unsigned long size);
void net_receive(const void *data, unsigned long size);
void net_poll(void);

#endif
