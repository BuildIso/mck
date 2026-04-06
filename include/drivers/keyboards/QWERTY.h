#ifndef MCK_KEYBOARD_QWERTY_H
#define MCK_KEYBOARD_QWERTY_H

#include <core.h>

/* QWERTY keyboard layout mapping for scancodes 0–127 */

extern const char mck_kb_qwerty_normal[128];
extern const char mck_kb_qwerty_shift[128];

char mck_kb_qwerty_translate(unsigned char scancode, int shift);

#endif /* MCK_KEYBOARD_QWERTY_H */
