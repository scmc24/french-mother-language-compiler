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
    push dword [c]
    push dword [b]
    pop ebx
    pop eax
    cmp eax, ebx
    setne al
    movzx eax, al
    push eax
    pop eax
    test eax, eax
    jz sinon_0
    push string_0
    push format_string
    call printf
    add esp, 8
    jmp fin_si_0
sinon_0:
    push string_1
    push format_string
    call printf
    add esp, 8
fin_si_0:
    ret
    string_0 db "Les nombres sont differents", 0
    string_1 db "Les nombres sont egaux", 0
