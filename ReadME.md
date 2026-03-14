Lamnya OS

Lamnya OS is an experimental microkernel-oriented operating system written in C and Assembly.
The goal of this project is to explore low-level system programming, hardware initialization, and kernel architecture.

The project currently provides a minimal kernel capable of booting through GRUB and initializing core system structures such as the GDT, IDT, timer, and basic hardware scanning.

---

Project Overview

Lamnya OS currently implements:

- Multiboot2 boot through GRUB
- VGA text debug console
- Kernel panic screen
- Global Descriptor Table (GDT)
- Interrupt Descriptor Table (IDT)
- Programmable Interval Timer (PIT)
- Basic PS/2 keyboard initialization
- Basic PCI device scanning

This project is currently an early prototype focused on kernel infrastructure.

---

Project Structure

The repository is organized as follows:

lamnya-os/
│
├── Makefile
├── linker.ld
├── README.md
│
├── boot/
│   └── grub.cfg
│
├── kernel/
│   ├── kernel.c
│   ├── panic.c
│   ├── panic.h
│   ├── debug.c
│   ├── debug.h
│   ├── gdt.c
│   ├── gdt.h
│   ├── idt.c
│   ├── idt.h
│   ├── isr.c
│   ├── isr.h
│   ├── pit.c
│   ├── pit.h
│   ├── pci.c
│   ├── pci.h
│   ├── keyboard.c
│   ├── keyboard.h
│   ├── port.h
│   ├── gdt_flush.asm
│   └── idt_load.asm

Explanation:

- boot/ contains the bootloader configuration.
- kernel/ contains all kernel source code.
- Makefile builds the kernel and bootable ISO.
- linker.ld controls kernel memory layout.

---

Requirements

To build Lamnya OS, the following tools must be installed:

- GCC
- NASM
- GRUB
- Xorriso
- QEMU

These tools provide the compiler, assembler, bootloader utilities, ISO generator, and emulator required for OS development.

---

Building the System

Navigate to the project root directory and run:

make

This will:

1. Compile the kernel source code.
2. Link the kernel binary.
3. Create a bootable ISO image.

After building, the file generated will be:

lamnya.iso

---

Running the Operating System

You can run Lamnya OS using an emulator.

Run:

make run

This will launch the system using QEMU.

Alternatively you can run it manually:

qemu-system-i386 -cdrom lamnya.iso

When the system boots successfully, GRUB will load the kernel and the debug console will display initialization messages.

---

Boot Process

The boot sequence is:

1. The system firmware starts the bootloader.
2. GRUB loads the Lamnya kernel using the Multiboot2 protocol.
3. The kernel initializes core system structures.
4. Hardware components such as timers and keyboard are initialized.
5. The system enters its main kernel loop.

---

Debug Console

Lamnya OS currently uses a simple VGA text console located at memory address:

0xB8000

This console is used for debugging messages during system initialization.

---

Kernel Panic

If a critical error occurs during initialization, the kernel panic handler is triggered.

The panic screen clears the VGA console and prints a fatal error message before halting the system.

---

Development Goals

Future development plans include:

- Physical memory manager
- Virtual memory and paging
- Task scheduler
- System calls
- User-space processes
- Filesystem support
- Device drivers

---

Educational Purpose

Lamnya OS is primarily an educational project designed to explore:

- x86 architecture
- operating system design
- low-level programming
- hardware interaction

---

License

This project is an experimental educational system and currently distributed as open source.
