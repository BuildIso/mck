#include "drivers/keyboards/QWERTY.h"

/* Normal QWERTY mapping */
const char mck_kb_qwerty_normal[128] = {
    0, 27, '1','2','3','4','5','6','7','8','9','0','-','=', 0, 0,
    'q','w','e','r','t','y','u','i','o','p','[',']', 0, 0,
    'a','s','d','f','g','h','j','k','l',';','\'','`', 0, '\\',
    'z','x','c','v','b','n','m',',','.','/', 0, '*', 0, ' '
};

/* Shifted QWERTY mapping */
const char mck_kb_qwerty_shift[128] = {
    0, 27, '!','@','#','$','%','^','&','*','(',')','_','+', 0, 0,
    'Q','W','E','R','T','Y','U','I','O','P','{','}', 0, 0,
    'A','S','D','F','G','H','J','K','L',':','"','~', 0, '|',
    'Z','X','C','V','B','N','M','<','>','?', 0, '*', 0, ' '
};

char mck_kb_qwerty_translate(unsigned char scancode, int shift)
{
    if (scancode >= 128)
        return 0;

    return shift ? mck_kb_qwerty_shift[scancode]
                 : mck_kb_qwerty_normal[scancode];
}
