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
%token SELON CAS DEFAUT FINSELON SORTIR 
%token POUR DE A PAS FINPOUR
%token REPETER JUSQUA
%token AFFECTATION EGAL DIFFERENT SUP_EGAL INF_EGAL SUPERIEUR INFERIEUR
%token PLUS MOINS FOIS DIVISE MODULO
%token POINT_VIRGULE VIRGULE PAREN_OUV PAREN_FERM DEUX_POINTS
%token NOMBRE_ENTIER IDENTIFICATEUR

%nonassoc INFERIEUR SUPERIEUR EGAL DIFFERENT SUP_EGAL INF_EGAL
%left PLUS MOINS
%left FOIS DIVISE MODULO
%nonassoc PAREN_OUV PAREN_FERM

%%

programme:
    DEBUT { 
        fichier_asm = fopen("programme.asm", "w");
        fprintf(fichier_asm, "; Programme en duala compile\n");
        fprintf(fichier_asm, "section .data\n");
        fprintf(fichier_asm, "    format_int db '%%d', 10, 0\n");
        fprintf(fichier_asm, "    input_format db '%%d', 0\n");
        fprintf(fichier_asm, "    input_msg db 'Tɔlɛ ndambo: ', 0\n");
        printf("Mbɔmbɔ compilation...\n");
    } 
    bloc 
    FIN { 
        fprintf(fichier_asm, "\nsection .text\n");
        fprintf(fichier_asm, "    global _start\n");
        fprintf(fichier_asm, "    extern printf, scanf\n");
        fprintf(fichier_asm, "_start:\n");
        fprintf(fichier_asm, "    call main\n");
        fprintf(fichier_asm, "    mov eax, 1\n");
        fprintf(fichier_asm, "    mov ebx, 0\n");
        fprintf(fichier_asm, "    int 0x80\n");
        fprintf(fichier_asm, "main:\n");
        fclose(fichier_asm);
        printf("Compilation suka na malamu!\n"); 
    }
    ;

bloc:
    declarations instructions
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
    | structure_selon
    | sortir_instruction
    | boucle_tant_que
    | boucle_pour
    | boucle_repeter
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
    | terme MODULO facteur {
        fprintf(fichier_asm, "    ; Modulo\n");
        fprintf(fichier_asm, "    pop ebx\n");
        fprintf(fichier_asm, "    pop eax\n");
        fprintf(fichier_asm, "    cdq\n");
        fprintf(fichier_asm, "    idiv ebx\n");
        fprintf(fichier_asm, "    push edx\n");
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
        printf("Mbɔmbɔ condition SƆ\n");
    } instructions partie_sinon_opt FINSI {
        int etiq = etiquette_stack[--stack_ptr];
        fprintf(fichier_asm, "fin_si_%d:\n", etiq);
        fprintf(fichier_asm, "    ; Fin SI\n");
        printf("Suka condition SƆ\n");
    }
    ;

partie_sinon_opt:
    /* vide */
    | SINON {
        int etiq = etiquette_stack[stack_ptr-1];
        fprintf(fichier_asm, "    jmp fin_si_%d\n", etiq);
        fprintf(fichier_asm, "sinon_%d:\n", etiq);
        printf("Partie KƐMA\n");
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
        printf("Mbɔmbɔ boucle MBƐLƐ\n");
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
        printf("Suka boucle MBƐLƐ\n");
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
        printf("Yɛnɛ: %s\n", current_id);
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
        printf("Kɔma expression\n");
    }
    ;

structure_selon:
    SELON PAREN_OUV expression PAREN_FERM {
        fprintf(fichier_asm, "    ; NDƆŊ (switch)\n");
        fprintf(fichier_asm, "    pop eax\n");
        etiquette_counter++;
        etiquette_stack[stack_ptr++] = etiquette_counter;
        printf("🔀 NDƆŊ (switch)\n");
    } liste_cas partie_defaut_opt FINSELON {
        int etiq = etiquette_stack[--stack_ptr];
        fprintf(fichier_asm, "fin_selon_%d:\n", etiq);
        printf("🔚 Suka NDƆŊ\n");
    }
    ;

liste_cas: 
    /* vide */ 
    | liste_cas cas_simple
    ;

cas_simple:
    CAS expression DEUX_POINTS {
        int etiq = etiquette_stack[stack_ptr-1];
        fprintf(fichier_asm, "    cmp eax, %s\n", "valeur_cas");
        fprintf(fichier_asm, "    jne cas_suivant_%d\n", etiq);
        printf("📋 KƐS\n");
    } instructions
    ;

partie_defaut_opt:
    /* vide */
    | DEFAUT DEUX_POINTS {
        fprintf(fichier_asm, "    ; CAS DEFAUT\n");
        printf("📋 KƐS BƆSƆ\n");
    } instructions
    ;

sortir_instruction:
    SORTIR POINT_VIRGULE {
        int etiq = etiquette_stack[stack_ptr-1];
        fprintf(fichier_asm, "    jmp fin_selon_%d\n", etiq);
        printf("🚪 BIMA (break)\n");
    }
    ;

boucle_pour:
    POUR IDENTIFICATEUR DE expression A expression {
        char *var = current_id;
        etiquette_counter++;
        etiquette_stack[stack_ptr++] = etiquette_counter;
        int etiq = etiquette_counter;
        fprintf(fichier_asm, "    ; PƆ %s\n", var);
        fprintf(fichier_asm, "    pop eax\n");
        fprintf(fichier_asm, "    mov [%s], eax\n", var);
        fprintf(fichier_asm, "debut_pour_%d:\n", etiq);
        fprintf(fichier_asm, "    mov eax, [%s]\n", var);
        fprintf(fichier_asm, "    cmp eax, [limite_pour_%d]\n", etiq);
        fprintf(fichier_asm, "    jg fin_pour_%d\n", etiq);
        printf("🔄 PƆ %s\n", var);
    } FAIRE instructions FINPOUR {
        int etiq = etiquette_stack[--stack_ptr];
        char *var = current_id;
        fprintf(fichier_asm, "    inc dword [%s]\n", var);
        fprintf(fichier_asm, "    jmp debut_pour_%d\n", etiq);
        fprintf(fichier_asm, "fin_pour_%d:\n", etiq);
        printf("🔚 Suka PƆ\n");
    }
    ;

boucle_repeter:
    REPETER {
        etiquette_counter++;
        etiquette_stack[stack_ptr++] = etiquette_counter;
        int etiq = etiquette_counter;
        fprintf(fichier_asm, "debut_repeter_%d:\n", etiq);
        printf("🔄 SƆŊƆLƆ (do-while)\n");
    } instructions JUSQUA PAREN_OUV expression PAREN_FERM POINT_VIRGULE {
        int etiq = etiquette_stack[--stack_ptr];
        fprintf(fichier_asm, "    pop eax\n");
        fprintf(fichier_asm, "    cmp eax, 0\n");
        fprintf(fichier_asm, "    jne debut_repeter_%d\n", etiq);
        printf("🔚 TƐMBƐLƐ (condition)\n");
    }
    ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Erreur de syntaxe: %s\n", s);
}

int main() {
    printf("=== Compilateur Duala ===\n");
    printf("Tɔlɛ programme na wo:\n");
    return yyparse();
}
