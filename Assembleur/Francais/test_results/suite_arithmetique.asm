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
    premier dd 0
    raison dd 0
    n dd 0
    i dd 0
    terme dd 0

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
    push premier
    push input_format
    call scanf
    add esp, 8
    push input_msg
    call printf
    add esp, 4
    push raison
    push input_format
    call scanf
    add esp, 8
    push input_msg
    call printf
    add esp, 4
    push n
    push input_format
    call scanf
    add esp, 8
    push 0
    pop eax
    mov [i], eax
debut_boucle_0:
    push dword [i]
    push dword [n]
    pop ebx
    pop eax
    cmp eax, ebx
    setl al
    movzx eax, al
    push eax
    pop eax
    test eax, eax
    jz fin_boucle_0
    push dword [premier]
    push dword [i]
    push dword [raison]
    pop ebx
    pop eax
    imul eax, ebx
    push eax
    pop ebx
    pop eax
    add eax, ebx
    push eax
    pop eax
    mov [terme], eax
    push dword [terme]
    pop eax
    push eax
    push format_int
    call printf
    add esp, 8
    push dword [i]
    push 1
    pop ebx
    pop eax
    add eax, ebx
    push eax
    pop eax
    mov [i], eax
    jmp debut_boucle_0
fin_boucle_0:
    ret
