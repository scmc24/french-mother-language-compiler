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
    a dd 0
    b dd 0
    resultat dd 0

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
    push a
    push input_format
    call scanf
    add esp, 8
    push input_msg
    call printf
    add esp, 4
    push b
    push input_format
    call scanf
    add esp, 8
    push dword [a]
    push dword [b]
    pop ebx
    pop eax
    cdq
    idiv ebx
    push edx
    pop eax
    mov [resultat], eax
    push dword [resultat]
    pop eax
    push eax
    push format_int
    call printf
    add esp, 8
    ret
