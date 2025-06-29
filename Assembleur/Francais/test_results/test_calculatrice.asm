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
    c dd 0
    b dd 0
    choix dd 0
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
    push c
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
    push input_msg
    call printf
    add esp, 4
    push choix
    push input_format
    call scanf
    add esp, 8
    push dword [choix]
    push 1
    pop ebx
    pop eax
    cmp eax, ebx
    sete al
    movzx eax, al
    push eax
    pop eax
    test eax, eax
    jz sinon_0
    push dword [c]
    push dword [b]
    pop ebx
    pop eax
    add eax, ebx
    push eax
    pop eax
    mov [resultat], eax
sinon_0:
fin_si_0:
    push dword [choix]
    push 2
    pop ebx
    pop eax
    cmp eax, ebx
    sete al
    movzx eax, al
    push eax
    pop eax
    test eax, eax
    jz sinon_1
    push dword [c]
    push dword [b]
    pop ebx
    pop eax
    sub eax, ebx
    push eax
    pop eax
    mov [resultat], eax
sinon_1:
fin_si_1:
    push dword [choix]
    push 3
    pop ebx
    pop eax
    cmp eax, ebx
    sete al
    movzx eax, al
    push eax
    pop eax
    test eax, eax
    jz sinon_2
    push dword [c]
    push dword [b]
    pop ebx
    pop eax
    imul eax, ebx
    push eax
    pop eax
    mov [resultat], eax
sinon_2:
fin_si_2:
    push dword [resultat]
    pop eax
    push eax
    push format_int
    call printf
    add esp, 8
    ret
