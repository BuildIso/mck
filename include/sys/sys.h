#ifndef MCK_SYS_H
#define MCK_SYS_H

/* Minimal system abstraction for mck */

typedef void (*mck_sys_halt_fn)(void);
typedef void (*mck_sys_reboot_fn)(void);
typedef void (*mck_sys_sleep_fn)(unsigned long ms);

void mck_sys_set_halt(mck_sys_halt_fn fn);
void mck_sys_set_reboot(mck_sys_reboot_fn fn);
void mck_sys_set_sleep(mck_sys_sleep_fn fn);

void mck_sys_halt(void);
void mck_sys_reboot(void);
void mck_sys_sleep(unsigned long ms);

#endif
