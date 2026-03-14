#include "debug.h"

static unsigned short* vga = (unsigned short*)0xB8000;
static int pos = 0;

void debug_clear()
{
    for (int i = 0; i < 80*25; i++)
        vga[i] = 0x0720;

    pos = 0;
}

void debug_print(const char* s)
{
    while (*s) {
        if (*s == '\n')
            pos += 80 - (pos % 80);
        else
            vga[pos++] = (0x07 << 8) | *s;
        s++;
    }
}
