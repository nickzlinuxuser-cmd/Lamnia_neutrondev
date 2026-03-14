CC = gcc
ASM = nasm
LD = ld

CFLAGS = -ffreestanding -O2 -Wall -Wextra -m32
LDFLAGS = -T linker.ld -m elf_i386

# pegar automaticamente todos os arquivos
C_SRC = $(wildcard kernel/*.c)
ASM_SRC = $(wildcard kernel/*.asm)

# gerar lista de objetos
C_OBJ = $(C_SRC:.c=.o)
ASM_OBJ = $(ASM_SRC:.asm=.o)

OBJ = $(C_OBJ) $(ASM_OBJ)

all: iso

# compilar kernel
kernel.bin: $(OBJ)
	$(LD) $(LDFLAGS) -o kernel.bin $(OBJ)

# compilar C
kernel/%.o: kernel/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# compilar ASM
kernel/%.o: kernel/%.asm
	$(ASM) -f elf32 $< -o $@

# criar ISO
iso: kernel.bin
	mkdir -p iso/boot/grub
	cp kernel.bin iso/boot/kernel.bin
	cp boot/grub.cfg iso/boot/grub/grub.cfg
	grub-mkrescue -o lamnya.iso iso

# rodar
run:
	qemu-system-i386 -cdrom lamnya.iso

# limpar
clean:
	rm -rf kernel/*.o *.o kernel.bin iso lamnya.iso
