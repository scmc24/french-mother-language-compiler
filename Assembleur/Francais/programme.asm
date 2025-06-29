; Programme en francais compile
section .data
    format_int db '%d', 10, 0
    input_format db '%d', 0
    input_msg db 'Entrez un nombre: ', 0
    i dd 0
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
    ; Lecture de limite
    push input_msg
    call printf
    add esp, 4
    push limite
    push input_format
    call scanf
    add esp, 8
