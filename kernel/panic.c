#include "panic.h"
#include "debug.h"

void kernel_panic(const char* msg)
{
    debug_clear();
    debug_print("LAMNYA KERNEL PANIC\n\n");
    debug_print(msg);

    while (1) {
        __asm__("cli");
        __asm__("hlt");
    }
}
