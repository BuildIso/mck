#include "audio/beep.h"

extern void outb(unsigned short port, unsigned char value);

void beep_play(unsigned long freq) {
    unsigned long div = 1193180 / freq;
    outb(0x43, 0xB6);
    outb(0x42, div & 0xFF);
    outb(0x42, (div >> 8) & 0xFF);
    unsigned char tmp = 0;
    outb(0x61, tmp | 3);
}

void beep_stop(void) {
    unsigned char tmp = 0;
    outb(0x61, tmp & ~3);
}
