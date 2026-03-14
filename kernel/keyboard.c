#include "keyboard.h"
#include "port.h"
#include "debug.h"

void keyboard_init()
{
    unsigned char status = inb(0x64);
    if (status & 1)
        inb(0x60);

    debug_print("PS/2 keyboard initialized\n");
}
