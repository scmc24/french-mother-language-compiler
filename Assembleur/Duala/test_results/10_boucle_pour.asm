; Programme en duala compile
section .data
    format_int db '%d', 10, 0
    format_str db '%s', 10, 0
    input_format db '%d', 0
    input_msg db 'Tɔlɛ ndambo: ', 0
    i dd 0
    limite dd 0

    limite_pour_1 dd 0
    pas_pour_1 dd 0

section .text
    global _start
    extern printf, scanf
_start:
    call main
    mov eax, 1
    mov ebx, 0
    int 0x80
main:
    ; Lecture de limite
    push input_msg
    call printf
    add esp, 4
    push limite
    push input_format
    call scanf
    add esp, 8
    ; Constante 1
    push 1
    ; Variable limite
    push dword [limite]
    ; POUR limite
    pop ebx
    pop eax
    mov [limite], eax
    mov [limite_pour_1], ebx
    mov dword [pas_pour_1], 1
debut_pour_1:
    mov eax, [limite]
    cmp eax, [limite_pour_1]
    jg fin_pour_1
    ; Using default step of 1
    ; Variable i
    push dword [i]
    ; Ecriture
    pop eax
    push eax
    push format_int
    call printf
    add esp, 8
    mov eax, [pas_pour_1]
    add [i], eax
    jmp debut_pour_1
fin_pour_1:
    ret
