#include "pci.h"
#include "port.h"
#include "debug.h"

static unsigned int pci_read(unsigned bus, unsigned slot, unsigned func)
{
    unsigned int address =
        (bus << 16) | (slot << 11) | (func << 8) | 0x80000000;

    outl(0xCF8, address);
    return inl(0xCFC);
}

void pci_scan()
{
    for (int bus = 0; bus < 8; bus++)
        for (int dev = 0; dev < 32; dev++)
        {
            unsigned int data = pci_read(bus, dev, 0);
            if (data != 0xFFFFFFFF)
                debug_print("PCI device found\n");
        }
}
