#include "debug.h"
#include "gdt.h"
#include "idt.h"
#include "pit.h"
#include "pci.h"
#include "keyboard.h"

void kernel_main()
{
    debug_clear();

    debug_print("LAMNYA OS\n");
    debug_print("Kernel booting...\n");

    gdt_init();
    debug_print("GDT OK\n");

    idt_init();
    debug_print("IDT OK\n");

    pit_init();
    debug_print("PIT OK\n");

    keyboard_init();
    debug_print("Keyboard OK\n");

    pci_scan();
    debug_print("PCI scan done\n");

    debug_print("System ready.\n");

    while (1) {
       __asm__("hlt");
    }
}
