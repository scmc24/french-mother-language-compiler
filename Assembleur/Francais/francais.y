%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void yyerror(const char *s);
int yylex(void);

FILE *fichier_asm;
extern char current_id[100];
char affectation_var[100];
int etiquette_counter = 0;
int etiquette_stack[10];
int stack_ptr = 0;
%}

%token DEBUT FIN TYPE_ENTIER LIRE ECRIRE 
%token SI ALORS SINON FINSI TANT_QUE FAIRE FINTANT
%token AFFECTATION EGAL DIFFERENT SUP_EGAL INF_EGAL SUPERIEUR INFERIEUR
%token PLUS MOINS FOIS DIVISE
%token POINT_VIRGULE VIRGULE PAREN_OUV PAREN_FERM
%token NOMBRE_ENTIER IDENTIFICATEUR

%nonassoc INFERIEUR SUPERIEUR EGAL DIFFERENT SUP_EGAL INF_EGAL
%left PLUS MOINS
%left FOIS DIVISE
%nonassoc PAREN_OUV PAREN_FERM

%%

programme:
    DEBUT { 
        fichier_asm = fopen("programme.asm", "w");
        fprintf(fichier_asm, "; Programme en francais compile\n");
        fprintf(fichier_asm, "section .data\n");
        fprintf(fichier_asm, "    format_int db '%%d', 10, 0\n");
        fprintf(fichier_asm, "    input_format db '%%d', 0\n");
        fprintf(fichier_asm, "    input_msg db 'Entrez un nombre: ', 0\n");
        printf("Debut de compilation...\n");
    } 
    bloc 
    FIN { 
        fprintf(fichier_asm, "    ret\n");
        fclose(fichier_asm);
        printf("Compilation terminee avec succes!\n"); 
    }
    ;

bloc:
    declarations { 
        fprintf(fichier_asm, "\nsection .text\n");
        fprintf(fichier_asm, "    global _start\n");
        fprintf(fichier_asm, "    extern printf, scanf\n");
        fprintf(fichier_asm, "_start:\n");
        fprintf(fichier_asm, "    call main\n");
        fprintf(fichier_asm, "    mov eax, 1\n");
        fprintf(fichier_asm, "    mov ebx, 0\n");
        fprintf(fichier_asm, "    int 0x80\n");
        fprintf(fichier_asm, "main:\n");
    } instructions
    ;

declarations:
    /* vide */
    | declarations declaration
    ;

declaration:
    TYPE_ENTIER IDENTIFICATEUR POINT_VIRGULE {
        fprintf(fichier_asm, "    %s dd 0\n", current_id);
        printf("Variable declaree: %s\n", current_id);
    }
    ;

instructions:
    /* vide */
    | instructions instruction
    ;

instruction:
    affectation
    | lecture
    | ecriture
    | conditionnelle
    | boucle_tant_que
    ;

affectation:
    IDENTIFICATEUR {
        strcpy(affectation_var, current_id);
    } AFFECTATION expression POINT_VIRGULE {
        fprintf(fichier_asm, "    ; Affectation a %s\n", affectation_var);
        fprintf(fichier_asm, "    pop eax\n");
        fprintf(fichier_asm, "    mov [%s], eax\n", affectation_var);
        printf("Affectation a: %s\n", affectation_var);
    }
    ;

expression:
    expression_arith
    | expression_comp
    ;

expression_arith:
    terme
    | expression_arith PLUS terme {
        fprintf(fichier_asm, "    ; Addition\n");
        fprintf(fichier_asm, "    pop ebx\n");
        fprintf(fichier_asm, "    pop eax\n");
        fprintf(fichier_asm, "    add eax, ebx\n");
        fprintf(fichier_asm, "    push eax\n");
    }
    | expression_arith MOINS terme {
        fprintf(fichier_asm, "    ; Soustraction\n");
        fprintf(fichier_asm, "    pop ebx\n");
        fprintf(fichier_asm, "    pop eax\n");
        fprintf(fichier_asm, "    sub eax, ebx\n");
        fprintf(fichier_asm, "    push eax\n");
    }
    ;

expression_comp:
    expression_arith SUPERIEUR expression_arith {
        fprintf(fichier_asm, "    ; Comparaison >\n");
        fprintf(fichier_asm, "    pop ebx\n");
        fprintf(fichier_asm, "    pop eax\n");
        fprintf(fichier_asm, "    cmp eax, ebx\n");
        fprintf(fichier_asm, "    setg al\n");
        fprintf(fichier_asm, "    movzx eax, al\n");
        fprintf(fichier_asm, "    push eax\n");
    }
    | expression_arith INFERIEUR expression_arith {
        fprintf(fichier_asm, "    ; Comparaison <\n");
        fprintf(fichier_asm, "    pop ebx\n");
        fprintf(fichier_asm, "    pop eax\n");
        fprintf(fichier_asm, "    cmp eax, ebx\n");
        fprintf(fichier_asm, "    setl al\n");
        fprintf(fichier_asm, "    movzx eax, al\n");
        fprintf(fichier_asm, "    push eax\n");
    }
    | expression_arith EGAL expression_arith {
        fprintf(fichier_asm, "    ; Comparaison ==\n");
        fprintf(fichier_asm, "    pop ebx\n");
        fprintf(fichier_asm, "    pop eax\n");
        fprintf(fichier_asm, "    cmp eax, ebx\n");
        fprintf(fichier_asm, "    sete al\n");
        fprintf(fichier_asm, "    movzx eax, al\n");
        fprintf(fichier_asm, "    push eax\n");
    }
    ;

terme:
    facteur
    | terme FOIS facteur {
        fprintf(fichier_asm, "    ; Multiplication\n");
        fprintf(fichier_asm, "    pop ebx\n");
        fprintf(fichier_asm, "    pop eax\n");
        fprintf(fichier_asm, "    imul eax, ebx\n");
        fprintf(fichier_asm, "    push eax\n");
    }
    | terme DIVISE facteur {
        fprintf(fichier_asm, "    ; Division\n");
        fprintf(fichier_asm, "    pop ebx\n");
        fprintf(fichier_asm, "    pop eax\n");
        fprintf(fichier_asm, "    cdq\n");
        fprintf(fichier_asm, "    idiv ebx\n");
        fprintf(fichier_asm, "    push eax\n");
    }
    ;

facteur:
    NOMBRE_ENTIER {
        fprintf(fichier_asm, "    ; Constante %d\n", yylval);
        fprintf(fichier_asm, "    push %d\n", yylval);
        printf("Constante: %d\n", yylval);
    }
    | IDENTIFICATEUR {
        fprintf(fichier_asm, "    ; Variable %s\n", current_id);
        fprintf(fichier_asm, "    push dword [%s]\n", current_id);
        printf("Variable utilisee: %s\n", current_id);
    }
    | PAREN_OUV expression PAREN_FERM
    ;

conditionnelle:
    SI PAREN_OUV expression PAREN_FERM ALORS {
        int etiq = etiquette_counter++;
        etiquette_stack[stack_ptr++] = etiq;
        fprintf(fichier_asm, "    ; Debut SI\n");
        fprintf(fichier_asm, "    pop eax\n");
        fprintf(fichier_asm, "    test eax, eax\n");
        fprintf(fichier_asm, "    jz fin_si_%d\n", etiq);
        printf("Debut condition SI\n");
    } instructions partie_sinon_opt FINSI {
        int etiq = etiquette_stack[--stack_ptr];
        fprintf(fichier_asm, "fin_si_%d:\n", etiq);
        fprintf(fichier_asm, "    ; Fin SI\n");
        printf("Fin condition SI\n");
    }
    ;

partie_sinon_opt:
    /* vide */
    | SINON {
        int etiq = etiquette_stack[stack_ptr-1];
        fprintf(fichier_asm, "    jmp fin_si_%d\n", etiq);
        fprintf(fichier_asm, "sinon_%d:\n", etiq);
        // Modifier l'etiquette de saut pour pointer vers sinon
        printf("Partie SINON\n");
    } instructions {
        // La partie sinon est terminée, on va vers fin_si
    }
    ;

boucle_tant_que:
    TANT_QUE {
        int etiq = etiquette_counter++;
        etiquette_stack[stack_ptr++] = etiq;
        fprintf(fichier_asm, "debut_boucle_%d:\n", etiq);
        fprintf(fichier_asm, "    ; Debut TANT_QUE\n");
        printf("Debut boucle TANT_QUE\n");
    } PAREN_OUV expression PAREN_FERM FAIRE {
        int etiq = etiquette_stack[stack_ptr-1];
        fprintf(fichier_asm, "    pop eax\n");
        fprintf(fichier_asm, "    test eax, eax\n");
        fprintf(fichier_asm, "    jz fin_boucle_%d\n", etiq);
    } instructions FINTANT {
        int etiq = etiquette_stack[--stack_ptr];
        fprintf(fichier_asm, "    jmp debut_boucle_%d\n", etiq);
        fprintf(fichier_asm, "fin_boucle_%d:\n", etiq);
        fprintf(fichier_asm, "    ; Fin TANT_QUE\n");
        printf("Fin boucle TANT_QUE\n");
    }
    ;

lecture:
    LIRE IDENTIFICATEUR POINT_VIRGULE {
        fprintf(fichier_asm, "    ; Lecture de %s\n", current_id);
        fprintf(fichier_asm, "    push input_msg\n");
        fprintf(fichier_asm, "    call printf\n");
        fprintf(fichier_asm, "    add esp, 4\n");
        fprintf(fichier_asm, "    push %s\n", current_id);
        fprintf(fichier_asm, "    push input_format\n");
        fprintf(fichier_asm, "    call scanf\n");
        fprintf(fichier_asm, "    add esp, 8\n");
        printf("Lecture de: %s\n", current_id);
    }
    ;

ecriture:
    ECRIRE expression POINT_VIRGULE {
        fprintf(fichier_asm, "    ; Ecriture\n");
        fprintf(fichier_asm, "    pop eax\n");
        fprintf(fichier_asm, "    push eax\n");
        fprintf(fichier_asm, "    push format_int\n");
        fprintf(fichier_asm, "    call printf\n");
        fprintf(fichier_asm, "    add esp, 8\n");
        printf("Ecriture d'une expression\n");
    }
    ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Erreur de syntaxe: %s\n", s);
}

int main() {
    printf("=== Compilateur Francais Etendu ===\n");
    printf("Entrez votre programme:\n");
    return yyparse();
}