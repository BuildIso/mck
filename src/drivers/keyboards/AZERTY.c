#include "drivers/keyboards/AZERTY.h"

/* Normal AZERTY mapping */
const char mck_kb_azerty_normal[128] = {
    0,  27, '&', 'é', '"', '\'', '(', '-', 'è', '_', 'ç', 'à', ')', '=', 0, 0,
    'a','z','e','r','t','y','u','i','o','p','^','$', 0, 0,
    'q','s','d','f','g','h','j','k','l','m','ù','*', 0, 0,
    '<','w','x','c','v','b','n','?', '.', '/', 0, '*', 0, ' '
};

/* Shifted AZERTY mapping */
const char mck_kb_azerty_shift[128] = {
    0,  27, '1','2','3','4','5','6','7','8','9','0','°','+', 0, 0,
    'A','Z','E','R','T','Y','U','I','O','P','¨','£', 0, 0,
    'Q','S','D','F','G','H','J','K','L','M','%', 'µ', 0, 0,
    '>', 'W','X','C','V','B','N','.', '/', '§', 0, '*', 0, ' '
};

char mck_kb_azerty_translate(unsigned char scancode, int shift)
{
    if (scancode >= 128)
        return 0;

    return shift ? mck_kb_azerty_shift[scancode]
                 : mck_kb_azerty_normal[scancode];
}
