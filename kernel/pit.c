#include "pit.h"
#include "port.h"
#include "debug.h"

#define PIT_COMMAND 0x43
#define PIT_CHANNEL0 0x40

void pit_init()
{
    unsigned int divisor = 1193180 / 100; // 100 Hz

    outb(PIT_COMMAND, 0x36);

    outb(PIT_CHANNEL0, divisor & 0xFF);
    outb(PIT_CHANNEL0, (divisor >> 8) & 0xFF);

    debug_print("PIT initialized\n");
}
