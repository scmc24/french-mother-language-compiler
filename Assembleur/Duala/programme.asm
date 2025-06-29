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
    global main
    extern printf, scanf
main:
    push ebp
    mov ebp, esp
    ; Lecture de limite
    push input_msg
    call printf
    add esp, 4
    push limite
    push input_format
    call scanf
    add esp, 8          ; Restauration de la pile après scanf
    ; Constante 1
    push 1
    ; Variable limite
    push dword [limite]
    ; Initialisation de la boucle POUR limite
    pop ebx
    pop eax
    mov [limite], eax      ; Valeur initiale de limite
    mov [limite_pour_1], ebx  ; Limite de la boucle
    mov dword [pas_pour_1], 1  ; Pas par défaut
debut_pour_1:
    mov eax, [limite]
    cmp eax, [limite_pour_1]
    jg fin_pour_1  ; Si >, sortir de la boucle
    ; Using default step of 1
    ; Variable i
    push dword [i]
    ; Ecriture
    pop eax
    push eax
    push format_int
    call printf
    add esp, 8          ; Restauration de la pile après printf
    ; Incrémentation du compteur et vérification de la condition
    mov eax, [i]
    add eax, 1  ; Incrémenter la variable de boucle
    mov [i], eax
    jmp debut_pour_1
fin_pour_1:
    ; Fin du programme
    mov eax, 0          ; Code de retour 0 (succès)
    mov esp, ebp        ; Restauration du pointeur de pile
    pop ebp             ; Restauration du pointeur de base
    ret                 ; Retour au système d'exploitation
