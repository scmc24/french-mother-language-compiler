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
    precision dd 0
    x dd 0
    fx dd 0
    fpx dd 0
    dx dd 0
    iteration dd 0

section .text
    global _start
    extern printf, scanf
_start:
    call main
    mov eax, 1
    mov ebx, 0
    int 0x80
main:
    push 1500
    pop eax
    mov [x], eax
    push 10
    pop eax
    mov [precision], eax
    push 0
    pop eax
    mov [iteration], eax
    push string_0
    push format_string
    call printf
    add esp, 8
    push string_1
    push format_string
    call printf
    add esp, 8
    push 1
    push dword [precision]
    pop eax
    mov [temp_limite_0], eax
    pop eax
    mov [iteration], eax
debut_pour_0:
    mov eax, [iteration]
    cmp eax, [temp_limite_0]
    jg fin_pour_0
    push dword [x]
    push dword [x]
    pop ebx
    pop eax
    imul eax, ebx
    push eax
    push 1000
    pop ebx
    pop eax
    cdq
    idiv ebx
    push eax
    push 2000
    pop ebx
    pop eax
    sub eax, ebx
    push eax
    pop eax
    mov [fx], eax
    push 2
    push dword [x]
    pop ebx
    pop eax
    imul eax, ebx
    push eax
    pop eax
    mov [fpx], eax
    push dword [fx]
    push 1000
    pop ebx
    pop eax
    imul eax, ebx
    push eax
    push dword [fpx]
    pop ebx
    pop eax
    cdq
    idiv ebx
    push eax
    pop eax
    mov [dx], eax
    push dword [x]
    push dword [dx]
    pop ebx
    pop eax
    sub eax, ebx
    push eax
    pop eax
    mov [x], eax
    push string_2
    push format_string
    call printf
    add esp, 8
    push dword [iteration]
    pop eax
    push eax
    push format_int
    call printf
    add esp, 8
    push string_3
    push format_string
    call printf
    add esp, 8
    push dword [x]
    pop eax
    push eax
    push format_int
    call printf
    add esp, 8
    push string_4
    push format_string
    call printf
    add esp, 8
    push dword [fx]
    pop eax
    push eax
    push format_int
    call printf
    add esp, 8
    mov eax, [x]
    cmp eax, [temp_limite_0]
    jge fin_pour_0
    inc dword [x]
    jmp debut_pour_0
fin_pour_0:
    push string_5
    push format_string
    call printf
    add esp, 8
    push dword [x]
    pop eax
    push eax
    push format_int
    call printf
    add esp, 8
    push string_6
    push format_string
    call printf
    add esp, 8
    push dword [x]
    pop eax
    push eax
    push format_int
    call printf
    add esp, 8
    ret
    string_0 db "Methode de Newton pour trouver sqrt(2)", 0
    string_1 db "Valeur initiale: x = 1.500", 0
    string_2 db "Iteration", 0
    string_3 db "x =", 0
    string_4 db "f(x) =", 0
    string_5 db "Resultat final (en millièmes):", 0
    string_6 db "sqrt(2) approxime =", 0
