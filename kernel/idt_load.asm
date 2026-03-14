[bits 32]
global idt_load

idt_load:
    mov eax, [esp + 4]   ; ponteiro para struct IDTR
    lidt [eax]
    ret
