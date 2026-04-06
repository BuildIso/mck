#ifndef MCK_KEYBOARD_AZERTY_H
#define MCK_KEYBOARD_AZERTY_H

#include <core.h>

/* AZERTY keyboard layout mapping for scancodes 0–127 */

extern const char mck_kb_azerty_normal[128];
extern const char mck_kb_azerty_shift[128];

/* Returns ASCII char from scancode + shift state */
char mck_kb_azerty_translate(unsigned char scancode, int shift);

#endif /* MCK_KEYBOARD_AZERTY_H */
