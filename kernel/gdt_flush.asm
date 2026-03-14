[bits 32]
global gdt_flush

gdt_flush:
    mov eax, [esp + 4]   ; ponteiro para struct GDTR
    lgdt [eax]

    mov ax, 0x10         ; data segment selector
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ss, ax

    jmp 0x08:.flush      ; far jump para recarregar CS
.flush:
    ret
