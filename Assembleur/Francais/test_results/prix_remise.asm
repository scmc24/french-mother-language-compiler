; Programme francais avec chaines
section .data
    format_int db '%d', 10, 0
    format_string db '%s', 10, 0
    input_format db '%d', 0
    input_msg db 'Entrez un nombre: ', 0
    temp_limite_0 dd 0
    temp_limite_1 dd 0
    temp_limite_2 dd 0
    temp_switch_0 dd 0
    temp_switch_1 dd 0
    temp_switch_2 dd 0
    prix_initial dd 0
    pourcentage_remise dd 0
    remise dd 0
    prix_final dd 0

section .text
    global _start
    extern printf, scanf
_start:
    call main
    mov eax, 1
    mov ebx, 0
    int 0x80
main:
    push input_msg
    call printf
    add esp, 4
    push prix_initial
    push input_format
    call scanf
    add esp, 8
    push input_msg
    call printf
    add esp, 4
    push pourcentage_remise
    push input_format
    call scanf
    add esp, 8
    push dword [prix_initial]
    push dword [pourcentage_remise]
    pop ebx
    pop eax
    imul eax, ebx
    push eax
    push 100
    pop ebx
    pop eax
    cdq
    idiv ebx
    push eax
    pop eax
    mov [remise], eax
    push dword [prix_initial]
    push dword [remise]
    pop ebx
    pop eax
    sub eax, ebx
    push eax
    pop eax
    mov [prix_final], eax
    push dword [prix_final]
    pop eax
    push eax
    push format_int
    call printf
    add esp, 8
    ret
