; Duala
section .data
    format_int db '%d', 10, 0
    format_string db '%s', 10, 0
    input_format db '%d', 0
    input_msg db 'Tol  na mb m b  mbɔmbɔ? ', 0
    temp_limite_0 dd 0
    temp_limite_1 dd 0
    temp_limite_2 dd 0
    temp_switch_0 dd 0
    temp_switch_1 dd 0
    temp_switch_2 dd 0
    n dd 0
    i dd 0
    produit_scalaire dd 0
    x1 dd 0
    x2 dd 0
    y1 dd 0
    y2 dd 0

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
    push n
    push input_format
    call scanf
    add esp, 8
    push 0
    pop eax
    mov [produit_scalaire], eax
    push dword [n]
    pop eax
    mov [temp_switch_0], eax
    push 1
    pop ebx
    mov eax, [temp_switch_0]
    cmp eax, ebx
    jne cas_suivant_1
    push input_msg
    call printf
    add esp, 4
    push x1
    push input_format
    call scanf
    add esp, 8
    push input_msg
    call printf
    add esp, 4
    push y1
    push input_format
    call scanf
    add esp, 8
    push dword [x1]
    push dword [y1]
    pop ebx
    pop eax
    imul eax, ebx
    push eax
    pop eax
    mov [produit_scalaire], eax
    jmp fin_selon_0
    jmp fin_selon_0
cas_suivant_1:
    push 2
    pop ebx
    mov eax, [temp_switch_0]
    cmp eax, ebx
    jne cas_suivant_2
    push input_msg
    call printf
    add esp, 4
    push x1
    push input_format
    call scanf
    add esp, 8
    push input_msg
    call printf
    add esp, 4
    push x2
    push input_format
    call scanf
    add esp, 8
    push input_msg
    call printf
    add esp, 4
    push y1
    push input_format
    call scanf
    add esp, 8
    push input_msg
    call printf
    add esp, 4
    push y2
    push input_format
    call scanf
    add esp, 8
    push dword [x1]
    push dword [y1]
    pop ebx
    pop eax
    imul eax, ebx
    push eax
    push dword [x2]
    push dword [y2]
    pop ebx
    pop eax
    imul eax, ebx
    push eax
    pop ebx
    pop eax
    add eax, ebx
    push eax
    pop eax
    mov [produit_scalaire], eax
    jmp fin_selon_0
    jmp fin_selon_0
cas_suivant_2:
    push string_0
    push format_string
    call printf
    add esp, 8
fin_selon_0:
    push dword [produit_scalaire]
    pop eax
    push eax
    push format_int
    call printf
    add esp, 8
    ret
    string_0 db "Dimension non supportée", 0
