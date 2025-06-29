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
    choix dd 0

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
    push choix
    push input_format
    call scanf
    add esp, 8
    push dword [choix]
    pop eax
    mov [temp_switch_0], eax
    push 1
    pop ebx
    mov eax, [temp_switch_0]
    cmp eax, ebx
    jne cas_suivant_1
    push string_0
    push format_string
    call printf
    add esp, 8
    jmp fin_selon_0
    jmp fin_selon_0
cas_suivant_1:
    push 2
    pop ebx
    mov eax, [temp_switch_0]
    cmp eax, ebx
    jne cas_suivant_2
    push string_1
    push format_string
    call printf
    add esp, 8
    jmp fin_selon_0
    jmp fin_selon_0
cas_suivant_2:
    push 3
    pop ebx
    mov eax, [temp_switch_0]
    cmp eax, ebx
    jne cas_suivant_3
    push string_2
    push format_string
    call printf
    add esp, 8
    jmp fin_selon_0
    jmp fin_selon_0
cas_suivant_3:
    push string_3
    push format_string
    call printf
    add esp, 8
fin_selon_0:
    ret
    string_0 db "Option un", 0
    string_1 db "Option deux", 0
    string_2 db "Option trois", 0
    string_3 db "Option inconnue", 0
