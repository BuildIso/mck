#include "sys/sys.h"

static mck_sys_halt_fn g_halt = 0;
static mck_sys_reboot_fn g_reboot = 0;
static mck_sys_sleep_fn g_sleep = 0;

void mck_sys_set_halt(mck_sys_halt_fn fn) { g_halt = fn; }
void mck_sys_set_reboot(mck_sys_reboot_fn fn) { g_reboot = fn; }
void mck_sys_set_sleep(mck_sys_sleep_fn fn) { g_sleep = fn; }

void mck_sys_halt(void) {
    if (g_halt) g_halt();
}

void mck_sys_reboot(void) {
    if (g_reboot) g_reboot();
}

void mck_sys_sleep(unsigned long ms) {
    if (g_sleep) g_sleep(ms);
}
