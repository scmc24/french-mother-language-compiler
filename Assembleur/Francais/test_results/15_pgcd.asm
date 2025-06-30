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
    p dd 0
    q dd 0
    pgcd dd 0
    temp dd 0

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
    push p
    push input_format
    call scanf
    add esp, 8
    push input_msg
    call printf
    add esp, 4
    push q
    push input_format
    call scanf
    add esp, 8
debut_boucle_0:
    push dword [q]
    push 0
    pop ebx
    pop eax
    cmp eax, ebx
    setne al
    movzx eax, al
    push eax
    pop eax
    test eax, eax
    jz fin_boucle_0
    push dword [p]
    push dword [q]
    pop ebx
    pop eax
    cdq
    idiv ebx
    push edx
    pop eax
    mov [temp], eax
    push dword [q]
    pop eax
    mov [p], eax
    push dword [temp]
    pop eax
    mov [q], eax
    jmp debut_boucle_0
fin_boucle_0:
    push dword [p]
    pop eax
    mov [pgcd], eax
    push dword [pgcd]
    pop eax
    push eax
    push format_int
    call printf
    add esp, 8
    ret
