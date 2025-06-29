; Programme en duala compile
section .data
    format_int db '%d', 10, 0
    format_str db '%s', 10, 0
    input_format db '%d', 0
    input_msg db 'Tɔlɛ ndambo: ', 0
    a dd 0
    b dd 0
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
    ; Lecture de a
    push input_msg
    call printf
    add esp, 4
    push a
    push input_format
    call scanf
    add esp, 8
    ; Lecture de b
    push input_msg
    call printf
    add esp, 4
    push b
    push input_format
    call scanf
    add esp, 8
    ; Variable a
    push dword [a]
    ; Variable b
    push dword [b]
    ; Soustraction
    pop ebx
    pop eax
    sub eax, ebx
    push eax
    ; Affectation a resultat
    pop eax
    mov [resultat], eax
    ; Variable resultat
    push dword [resultat]
    ; Ecriture
    pop eax
    push eax
    push format_int
    call printf
    add esp, 8
    ret
