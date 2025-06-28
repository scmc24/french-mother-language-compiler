; Programme en duala compile
section .data
    format_int db '%d', 10, 0
    input_format db '%d', 0
    input_msg db 'Tɔlɛ ndambo: ', 0
    a dd 0
    b dd 0
    max dd 0
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
    ; Comparaison >
    pop ebx
    pop eax
    cmp eax, ebx
    setg al
    movzx eax, al
    push eax
    ; Debut SI
    pop eax
    test eax, eax
    jz fin_si_0
    ; Variable a
    push dword [a]
    ; Affectation a max
    pop eax
    mov [max], eax
    ; Variable max
    push dword [max]
    ; Ecriture
    pop eax
    push eax
    push format_int
    call printf
    add esp, 8
    jmp fin_si_0
sinon_0:
    ; Variable b
    push dword [b]
    ; Affectation a max
    pop eax
    mov [max], eax
    ; Variable max
    push dword [max]
    ; Ecriture
    pop eax
    push eax
    push format_int
    call printf
    add esp, 8
fin_si_0:
    ; Fin SI
    ; Constante 999
    push 999
    ; Ecriture
    pop eax
    push eax
    push format_int
    call printf
    add esp, 8

section .text
    global _start
    extern printf, scanf
_start:
    call main
    mov eax, 1
    mov ebx, 0
    int 0x80
main:
