%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void yyerror(const char *s);
int yylex(void);

FILE *fichier_asm;
FILE *fichier_temp;
extern char current_id[100];
extern char current_string[1000];
char affectation_var[100];
int etiquette_counter = 0;
int etiquette_stack[10];
int stack_ptr = 0;
int string_counter = 0;
%}

%token DEBUT FIN TYPE_ENTIER LIRE ECRIRE 
%token SI ALORS SINON FINSI 
%token SELON CAS DEFAUT FINSELON SORTIR
%token TANT_QUE FAIRE FINTANT
%token POUR DE A PAS FINPOUR
%token REPETER JUSQUA
%token AFFECTATION EGAL DIFFERENT SUP_EGAL INF_EGAL SUPERIEUR INFERIEUR
%token PLUS MOINS FOIS DIVISE MODULO
%token POINT_VIRGULE VIRGULE PAREN_OUV PAREN_FERM DEUX_POINTS
%token NOMBRE_ENTIER IDENTIFICATEUR CHAINE_CARACTERES

%nonassoc INFERIEUR SUPERIEUR EGAL DIFFERENT SUP_EGAL INF_EGAL
%left PLUS MOINS
%left FOIS DIVISE MODULO
%nonassoc PAREN_OUV PAREN_FERM

%%

programme:
    DEBUT { 
        fichier_temp = fopen("temp_strings.asm", "w");
        
        fichier_asm = fopen("programme.asm", "w");
        fprintf(fichier_asm, "; Programme francais avec chaines\n");
        fprintf(fichier_asm, "section .data\n");
        fprintf(fichier_asm, "    format_int db '%%d', 10, 0\n");
        fprintf(fichier_asm, "    format_string db '%%s', 10, 0\n");
        fprintf(fichier_asm, "    input_format db '%%d', 0\n");
        fprintf(fichier_asm, "    input_msg db 'Entrez un nombre: ', 0\n");
        fprintf(fichier_asm, "    temp_limite_0 dd 0\n");
        fprintf(fichier_asm, "    temp_limite_1 dd 0\n");
        fprintf(fichier_asm, "    temp_limite_2 dd 0\n");
        fprintf(fichier_asm, "    temp_switch_0 dd 0\n");
        fprintf(fichier_asm, "    temp_switch_1 dd 0\n");
        fprintf(fichier_asm, "    temp_switch_2 dd 0\n");
        
        string_counter = 0;
        printf("Debut de compilation avec chaines...\n");
    } 
    bloc 
    FIN { 
        /* Insérer les chaînes du fichier temporaire */
        fclose(fichier_temp);
        
        FILE *temp_read = fopen("temp_strings.asm", "r");
        if (temp_read) {
            char buffer[1000];
            while (fgets(buffer, sizeof(buffer), temp_read)) {
                fprintf(fichier_asm, "%s", buffer);
            }
            fclose(temp_read);
        }
        
        remove("temp_strings.asm");
        
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
    } instructions {
        /* CORRECTION: Ajout du return à la fin de main */
        fprintf(fichier_asm, "    ret\n");
    }
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
    | ecriture_chaine
    | conditionnelle
    | boucle_tant_que
    | boucle_pour
    | boucle_repeter
    | structure_selon
    | sortir_instruction
    ;

affectation:
    IDENTIFICATEUR {
        strcpy(affectation_var, current_id);
    } AFFECTATION expression POINT_VIRGULE {
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
        fprintf(fichier_asm, "    pop ebx\n");
        fprintf(fichier_asm, "    pop eax\n");
        fprintf(fichier_asm, "    add eax, ebx\n");
        fprintf(fichier_asm, "    push eax\n");
    }
    | expression_arith MOINS terme {
        fprintf(fichier_asm, "    pop ebx\n");
        fprintf(fichier_asm, "    pop eax\n");
        fprintf(fichier_asm, "    sub eax, ebx\n");
        fprintf(fichier_asm, "    push eax\n");
    }
    ;

expression_comp:
    expression_arith SUPERIEUR expression_arith {
        fprintf(fichier_asm, "    pop ebx\n");
        fprintf(fichier_asm, "    pop eax\n");
        fprintf(fichier_asm, "    cmp eax, ebx\n");
        fprintf(fichier_asm, "    setg al\n");
        fprintf(fichier_asm, "    movzx eax, al\n");
        fprintf(fichier_asm, "    push eax\n");
    }
    | expression_arith INFERIEUR expression_arith {
        fprintf(fichier_asm, "    pop ebx\n");
        fprintf(fichier_asm, "    pop eax\n");
        fprintf(fichier_asm, "    cmp eax, ebx\n");
        fprintf(fichier_asm, "    setl al\n");
        fprintf(fichier_asm, "    movzx eax, al\n");
        fprintf(fichier_asm, "    push eax\n");
    }
    | expression_arith EGAL expression_arith {
        fprintf(fichier_asm, "    pop ebx\n");
        fprintf(fichier_asm, "    pop eax\n");
        fprintf(fichier_asm, "    cmp eax, ebx\n");
        fprintf(fichier_asm, "    sete al\n");
        fprintf(fichier_asm, "    movzx eax, al\n");
        fprintf(fichier_asm, "    push eax\n");
    }
    | expression_arith DIFFERENT expression_arith {
        fprintf(fichier_asm, "    pop ebx\n");
        fprintf(fichier_asm, "    pop eax\n");
        fprintf(fichier_asm, "    cmp eax, ebx\n");
        fprintf(fichier_asm, "    setne al\n");
        fprintf(fichier_asm, "    movzx eax, al\n");
        fprintf(fichier_asm, "    push eax\n");
    }
    | expression_arith INF_EGAL expression_arith {
        fprintf(fichier_asm, "    pop ebx\n");
        fprintf(fichier_asm, "    pop eax\n");
        fprintf(fichier_asm, "    cmp eax, ebx\n");
        fprintf(fichier_asm, "    setle al\n");
        fprintf(fichier_asm, "    movzx eax, al\n");
        fprintf(fichier_asm, "    push eax\n");
    }
    | expression_arith SUP_EGAL expression_arith {
        fprintf(fichier_asm, "    pop ebx\n");
        fprintf(fichier_asm, "    pop eax\n");
        fprintf(fichier_asm, "    cmp eax, ebx\n");
        fprintf(fichier_asm, "    setge al\n");
        fprintf(fichier_asm, "    movzx eax, al\n");
        fprintf(fichier_asm, "    push eax\n");
    }
    ;

terme:
    facteur
    | terme FOIS facteur {
        fprintf(fichier_asm, "    pop ebx\n");
        fprintf(fichier_asm, "    pop eax\n");
        fprintf(fichier_asm, "    imul eax, ebx\n");
        fprintf(fichier_asm, "    push eax\n");
    }
    | terme DIVISE facteur {
        fprintf(fichier_asm, "    pop ebx\n");
        fprintf(fichier_asm, "    pop eax\n");
        fprintf(fichier_asm, "    cdq\n");
        fprintf(fichier_asm, "    idiv ebx\n");
        fprintf(fichier_asm, "    push eax\n");
    }
    | terme MODULO facteur {
        fprintf(fichier_asm, "    pop ebx\n");
        fprintf(fichier_asm, "    pop eax\n");
        fprintf(fichier_asm, "    cdq\n");
        fprintf(fichier_asm, "    idiv ebx\n");
        fprintf(fichier_asm, "    push edx\n");
    }
    ;

facteur:
    NOMBRE_ENTIER {
        fprintf(fichier_asm, "    push %d\n", yylval);
        printf("Constante: %d\n", yylval);
    }
    | IDENTIFICATEUR {
        fprintf(fichier_asm, "    push dword [%s]\n", current_id);
        printf("Variable utilisee: %s\n", current_id);
    }
    | PAREN_OUV expression PAREN_FERM
    ;

conditionnelle:
    SI PAREN_OUV expression PAREN_FERM ALORS {
        int etiq = etiquette_counter++;
        etiquette_stack[stack_ptr++] = etiq;
        fprintf(fichier_asm, "    pop eax\n");
        fprintf(fichier_asm, "    test eax, eax\n");
        fprintf(fichier_asm, "    jz sinon_%d\n", etiq);
        printf("Debut condition SI\n");
    } instructions partie_sinon_opt FINSI {
        int etiq = etiquette_stack[--stack_ptr];
        fprintf(fichier_asm, "fin_si_%d:\n", etiq);
        printf("Fin condition SI\n");
    }
    ;

partie_sinon_opt:
    /* vide */ {
        int etiq = etiquette_stack[stack_ptr-1];
        fprintf(fichier_asm, "sinon_%d:\n", etiq);
    }
    | SINON {
        int etiq = etiquette_stack[stack_ptr-1];
        fprintf(fichier_asm, "    jmp fin_si_%d\n", etiq);
        fprintf(fichier_asm, "sinon_%d:\n", etiq);
        printf("Partie SINON\n");
    } instructions
    ;

/* CORRECTION MAJEURE: Structure selon complètement réécrite */
structure_selon:
    SELON PAREN_OUV expression PAREN_FERM {
        int etiq = etiquette_counter++;
        etiquette_stack[stack_ptr++] = etiq;
        fprintf(fichier_asm, "    pop eax\n");
        fprintf(fichier_asm, "    mov [temp_switch_%d], eax\n", etiq % 3);
        printf("SELON (switch) - etiquette %d\n", etiq);
    } liste_cas partie_defaut_opt FINSELON {
        int etiq = etiquette_stack[--stack_ptr];
        fprintf(fichier_asm, "fin_selon_%d:\n", etiq);
        printf("Fin SELON - etiquette %d\n", etiq);
    }
    ;

liste_cas:
    /* vide */
    | liste_cas cas_simple
    ;

cas_simple:
    CAS expression DEUX_POINTS {
        int etiq_selon = etiquette_stack[stack_ptr-1];  /* Étiquette du selon parent */
        int cas_etiq = etiquette_counter++;
        
        fprintf(fichier_asm, "    pop ebx\n");
        fprintf(fichier_asm, "    mov eax, [temp_switch_%d]\n", etiq_selon % 3);
        fprintf(fichier_asm, "    cmp eax, ebx\n");
        fprintf(fichier_asm, "    jne cas_suivant_%d\n", cas_etiq);
        
        printf("CAS - etiquette %d, selon parent %d\n", cas_etiq, etiq_selon);
        
        /* Empiler l'étiquette du cas */
        etiquette_stack[stack_ptr] = cas_etiq;
        stack_ptr++;
    } instructions {
        int cas_etiq = etiquette_stack[--stack_ptr];
        int etiq_selon = etiquette_stack[stack_ptr-1];
        
        /* Saut automatique vers la fin du selon (pas de fall-through) */
        fprintf(fichier_asm, "    jmp fin_selon_%d\n", etiq_selon);
        fprintf(fichier_asm, "cas_suivant_%d:\n", cas_etiq);
    }
    ;

partie_defaut_opt:
    /* vide */
    | DEFAUT DEUX_POINTS {
        printf("CAS DEFAUT\n");
    } instructions
    ;

sortir_instruction:
    SORTIR POINT_VIRGULE {
        if (stack_ptr > 0) {
            /* Trouver l'étiquette du selon le plus proche */
            int etiq = etiquette_stack[stack_ptr-1];
            /* Si c'est un cas, prendre l'étiquette du selon parent */
            if (stack_ptr > 1) {
                etiq = etiquette_stack[stack_ptr-2];
            }
            fprintf(fichier_asm, "    jmp fin_selon_%d\n", etiq);
            printf("SORTIR (break) vers fin_selon_%d\n", etiq);
        }
    }
    ;

boucle_tant_que:
    TANT_QUE {
        int etiq = etiquette_counter++;
        etiquette_stack[stack_ptr++] = etiq;
        fprintf(fichier_asm, "debut_boucle_%d:\n", etiq);
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
        printf("Fin boucle TANT_QUE\n");
    }
    ;

boucle_pour:
    POUR IDENTIFICATEUR {
        strcpy(affectation_var, current_id);
    } DE expression A expression FAIRE {
        int etiq = etiquette_counter++;
        etiquette_stack[stack_ptr++] = etiq;
        
        /* CORRECTION: Inverser l'ordre - limite en premier, puis valeur initiale */
        fprintf(fichier_asm, "    pop eax\n");                    /* limite (expression A) */
        fprintf(fichier_asm, "    mov [temp_limite_%d], eax\n", etiq % 3);
        fprintf(fichier_asm, "    pop eax\n");                    /* valeur initiale (expression DE) */
        fprintf(fichier_asm, "    mov [%s], eax\n", affectation_var);
        
        fprintf(fichier_asm, "debut_pour_%d:\n", etiq);
        fprintf(fichier_asm, "    mov eax, [%s]\n", affectation_var);
        fprintf(fichier_asm, "    cmp eax, [temp_limite_%d]\n", etiq % 3);
        fprintf(fichier_asm, "    jg fin_pour_%d\n", etiq);       /* Si variable > limite, sortir */
        
        printf("POUR %s de [valeur] a [limite]\n", affectation_var);
    } instructions FINPOUR {
        int etiq = etiquette_stack[--stack_ptr];
        
        /* CORRECTION: Vérifier la limite avant d'incrémenter pour éviter les boucles infinies */
        fprintf(fichier_asm, "    mov eax, [%s]\n", affectation_var);
        fprintf(fichier_asm, "    cmp eax, [temp_limite_%d]\n", etiq % 3);
        fprintf(fichier_asm, "    jge fin_pour_%d\n", etiq);      /* Si variable >= limite, sortir */
        fprintf(fichier_asm, "    inc dword [%s]\n", affectation_var);
        fprintf(fichier_asm, "    jmp debut_pour_%d\n", etiq);
        fprintf(fichier_asm, "fin_pour_%d:\n", etiq);
        
        printf("Fin POUR\n");
    }
    ;

boucle_repeter:
    REPETER {
        int etiq = etiquette_counter++;
        etiquette_stack[stack_ptr++] = etiq;
        fprintf(fichier_asm, "debut_repeter_%d:\n", etiq);
        printf("REPETER (do-while)\n");
    } instructions JUSQUA PAREN_OUV expression PAREN_FERM POINT_VIRGULE {
        int etiq = etiquette_stack[--stack_ptr];
        
        fprintf(fichier_asm, "    pop eax\n");
        fprintf(fichier_asm, "    test eax, eax\n");
        fprintf(fichier_asm, "    jz debut_repeter_%d\n", etiq);
        
        printf("JUSQUA (condition)\n");
    }
    ;

lecture:
    LIRE IDENTIFICATEUR POINT_VIRGULE {
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
        fprintf(fichier_asm, "    pop eax\n");
        fprintf(fichier_asm, "    push eax\n");
        fprintf(fichier_asm, "    push format_int\n");
        fprintf(fichier_asm, "    call printf\n");
        fprintf(fichier_asm, "    add esp, 8\n");
        printf("Ecriture d'une expression numerique\n");
    }
    ;

ecriture_chaine:
    ECRIRE CHAINE_CARACTERES POINT_VIRGULE {
        fprintf(fichier_temp, "    string_%d db %s, 0\n", string_counter, current_string);
        
        fprintf(fichier_asm, "    push string_%d\n", string_counter);
        fprintf(fichier_asm, "    push format_string\n");
        fprintf(fichier_asm, "    call printf\n");
        fprintf(fichier_asm, "    add esp, 8\n");
        
        printf("Ecriture d'une chaine: %s\n", current_string);
        string_counter++;
    }
    ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Erreur de syntaxe: %s\n", s);
}

int main() {
    printf("=== Compilateur Francais avec Chaines ===\n");
    printf("Entrez votre programme:\n");
    return yyparse();
}