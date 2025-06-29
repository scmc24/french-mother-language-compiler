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
    compteur dd 0
    limite dd 0

section .text
    global _start
    extern printf, scanf
_start:
    call main
    mov eax, 1
    mov ebx, 0
    int 0x80
main:
    push 1
    pop eax
    mov [compteur], eax
    push 5
    pop eax
    mov [limite], eax
debut_repeter_0:
    push dword [compteur]
    pop eax
    push eax
    push format_int
    call printf
    add esp, 8
    push dword [compteur]
    push 1
    pop ebx
    pop eax
    add eax, ebx
    push eax
    pop eax
    mov [compteur], eax
    push dword [compteur]
    push dword [limite]
    pop ebx
    pop eax
    cmp eax, ebx
    setg al
    movzx eax, al
    push eax
    pop eax
    test eax, eax
    jz debut_repeter_0
    push 999
    pop eax
    push eax
    push format_int
    call printf
    add esp, 8
    push 10
    pop eax
    mov [compteur], eax
debut_repeter_1:
    push dword [compteur]
    pop eax
    push eax
    push format_int
    call printf
    add esp, 8
    push dword [compteur]
    push 1
    pop ebx
    pop eax
    sub eax, ebx
    push eax
    pop eax
    mov [compteur], eax
    push dword [compteur]
    push 7
    pop ebx
    pop eax
    cmp eax, ebx
    setl al
    movzx eax, al
    push eax
    pop eax
    test eax, eax
    jz debut_repeter_1
    push 888
    pop eax
    push eax
    push format_int
    call printf
    add esp, 8
    ret
