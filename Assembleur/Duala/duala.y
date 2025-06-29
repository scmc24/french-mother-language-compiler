%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void yyerror(const char *s);
int yylex(void);

/* Line number tracking */
extern int yylineno;

FILE *fichier_asm;
extern char current_id[100];
char affectation_var[100];
int etiquette_counter = 0;
int etiquette_stack[10];
int stack_ptr = 0;

/* String literal handling */
char string_literals[100][256];
char string_labels[100][50];
int is_string_expression = 0;
int string_count = 0;

/* For loop limit variables tracking */
int for_limit_count = 0;
int for_limit_labels[50];
%}

%token DEBUT FIN TYPE_ENTIER LIRE ECRIRE 
%token SI ALORS SINON FINSI MBELE SALA SUKAMBELESE
%token SELON CAS DEFAUT FINSELON SORTIR 
%token POUR DE A PAS FINPOUR
%token REPETER JUSQUA
%token AFFECTATION EGAL DIFFERENT SUP_EGAL INF_EGAL SUPERIEUR INFERIEUR
%token PLUS MOINS FOIS DIVISE MODULO
%token POINT_VIRGULE VIRGULE PAREN_OUV PAREN_FERM DEUX_POINTS
%token NOMBRE_ENTIER IDENTIFICATEUR STRING_LITERAL

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
        fprintf(fichier_asm, "    format_str db '%%s', 10, 0\n");
        fprintf(fichier_asm, "    input_format db '%%d', 0\n");
        fprintf(fichier_asm, "    input_msg db 'Tɔlɛ ndambo: ', 0\n");
        printf("Mbɔmbɔ compilation...\n");
    } 
    bloc 
    FIN { 
        fprintf(fichier_asm, "    ret\n");
        
        /* Add string literals and for loop variables to data section by reopening and inserting */
        if (string_count > 0 || for_limit_count > 0) {
            fclose(fichier_asm);
            
            /* Read the entire file */
            FILE *read_file = fopen("programme.asm", "r");
            fseek(read_file, 0, SEEK_END);
            long file_size = ftell(read_file);
            fseek(read_file, 0, SEEK_SET);
            
            char *content = malloc(file_size + 1);
            fread(content, 1, file_size, read_file);
            content[file_size] = '\0';
            fclose(read_file);
            
            /* Find where to insert strings (before section .text) */
            char *text_section = strstr(content, "section .text");
            if (text_section) {
                /* Rewrite file with strings and variables */
                fichier_asm = fopen("programme.asm", "w");
                
                /* Write everything before section .text */
                size_t before_text = text_section - content;
                fwrite(content, 1, before_text, fichier_asm);
                
                /* Add string definitions */
                for (int i = 0; i < string_count; i++) {
                    fprintf(fichier_asm, "    %s db %s, 0\n", string_labels[i], string_literals[i]);
                }
                
                /* Add for loop limit and step variables */
                for (int i = 0; i < for_limit_count; i++) {
                    fprintf(fichier_asm, "    limite_pour_%d dd 0\n", for_limit_labels[i]);
                    fprintf(fichier_asm, "    pas_pour_%d dd 0\n", for_limit_labels[i]);
                }
                
                fprintf(fichier_asm, "\n");
                
                /* Write the rest (section .text onwards) */
                fprintf(fichier_asm, "%s", text_section);
                
                fclose(fichier_asm);
            }
            free(content);
        } else {
            fclose(fichier_asm);
        }
        printf("Compilation suka na malamu!\n"); 
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
    expression_arith { printf("PARSER: expression -> expression_arith\n"); }
    | expression_comp { printf("PARSER: expression -> expression_comp\n"); }
    ;

expression_arith:
    terme { printf("PARSER: expression_arith -> terme\n"); }
    | expression_arith PLUS terme { printf("PARSER: expression_arith -> expression_arith PLUS terme\n"); } {
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
    expression_arith SUPERIEUR expression_arith { printf("PARSER: expression_comp -> expression_arith SUPERIEUR expression_arith\n"); } {
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
    | STRING_LITERAL {
        char string_label[50];
        sprintf(string_label, "str_%d", string_count);
        
        /* Store string literal for later addition to data section */
        strcpy(string_literals[string_count], current_id);
        strcpy(string_labels[string_count], string_label);
        string_count++;
        
        /* Mark this as a string expression */
        is_string_expression = 1;
        
        fprintf(fichier_asm, "    ; Chaine %s\n", current_id);
        fprintf(fichier_asm, "    push %s\n", string_label);
        printf("Chaine: %s\n", current_id);
    }
    | PAREN_OUV expression PAREN_FERM {
        /* Parenthesized expression - nothing extra to do */
        printf("Expression parenthesee\n");
    }
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
    MBELE PAREN_OUV expression PAREN_FERM SALA {
        int etiq = etiquette_counter++;
        etiquette_stack[stack_ptr++] = etiq;
        fprintf(fichier_asm, "debut_boucle_%d:\n", etiq);
        fprintf(fichier_asm, "    ; Debut MBELE\n");
        fprintf(fichier_asm, "    pop eax\n");
        fprintf(fichier_asm, "    test eax, eax\n");
        fprintf(fichier_asm, "    jz fin_boucle_%d\n", etiq);
        printf("Mbombɔ boucle MBELE\n");
    } instructions SUKAMBELESE fin_boucle
    ;

fin_boucle:
    /* Empty */ {
        int etiq = etiquette_stack[--stack_ptr];
        fprintf(fichier_asm, "    jmp debut_boucle_%d\n", etiq);
        fprintf(fichier_asm, "fin_boucle_%d:\n", etiq);
        fprintf(fichier_asm, "    ; Fin MBELE\n");
        printf("Suka boucle MBELE\n");
    }
    | POINT_VIRGULE {
        int etiq = etiquette_stack[--stack_ptr];
        fprintf(fichier_asm, "    jmp debut_boucle_%d\n", etiq);
        fprintf(fichier_asm, "fin_boucle_%d:\n", etiq);
        fprintf(fichier_asm, "    ; Fin MBELE\n");
        printf("Suka boucle MBELE (with semicolon)\n");
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
    ECRIRE { 
        printf("PARSER: [ECRIRE] Start of ECRIRE statement at line %d\n", yylineno);
        printf("PARSER: [ECRIRE] Current token: %d\n", yychar);
    } expression { 
        printf("PARSER: [ECRIRE] Successfully parsed expression\n");
        printf("PARSER: [ECRIRE] Next token (expecting POINT_VIRGULE): %d\n", yychar);
    } POINT_VIRGULE {
        printf("PARSER: [ECRIRE] Found POINT_VIRGULE after expression\n");
        fprintf(fichier_asm, "    ; Ecriture\n");
        fprintf(fichier_asm, "    pop eax\n");
        fprintf(fichier_asm, "    push eax\n");
        if (is_string_expression) {
            fprintf(fichier_asm, "    push format_str\n");
            is_string_expression = 0; /* Reset flag */
        } else {
            fprintf(fichier_asm, "    push format_int\n");
        }
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
    cas_simple
    | liste_cas cas_simple
    ;

cas_simple:
    CAS expression DEUX_POINTS {
        int etiq = etiquette_stack[stack_ptr-1];
        fprintf(fichier_asm, "    ; Cas\n");
        fprintf(fichier_asm, "    pop ebx\n");
        fprintf(fichier_asm, "    cmp eax, ebx\n");
        etiquette_counter++;
        fprintf(fichier_asm, "    jne cas_suivant_%d\n", etiquette_counter);
        printf("📋 KƐS\n");
    } instructions SORTIR POINT_VIRGULE {
        int etiq = etiquette_stack[stack_ptr-1];
        fprintf(fichier_asm, "    jmp fin_selon_%d\n", etiq);
        fprintf(fichier_asm, "cas_suivant_%d:\n", etiquette_counter);
        printf("🙪 BIMA (break)\n");
    }
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
    boucle_pour_init pas_opt SALA instructions FINPOUR {
        int etiq = etiquette_stack[--stack_ptr];
        char *var = current_id;
        /* Use the step value */
        fprintf(fichier_asm, "    mov eax, [pas_pour_%d]\n", etiq);
        fprintf(fichier_asm, "    add [%s], eax\n", var);
        fprintf(fichier_asm, "    jmp debut_pour_%d\n", etiq);
        fprintf(fichier_asm, "fin_pour_%d:\n", etiq);
        printf("<- Fin POUR\n");
    };

pas_opt:
    /* Empty - use default step of 1 */ {
        int etiq = etiquette_stack[stack_ptr-1];
        fprintf(fichier_asm, "    ; Using default step of 1\n");
    }
    | PAS expression {
        /* Handle step value */
        int etiq = etiquette_stack[stack_ptr-1];
        fprintf(fichier_asm, "    pop eax\n");  /* step value */
        fprintf(fichier_asm, "    mov [pas_pour_%d], eax\n", etiq);
    };

boucle_pour_init:
    POUR IDENTIFICATEUR DE expression A expression {
        char *var = current_id;
        etiquette_counter++;
        etiquette_stack[stack_ptr++] = etiquette_counter;
        int etiq = etiquette_counter;
        
        /* Track this for loop limit variable */
        for_limit_labels[for_limit_count++] = etiq;
        
        fprintf(fichier_asm, "    ; POUR %s\n", var);
        
        /* Store the limit value */
        fprintf(fichier_asm, "    pop ebx\n");  /* limit */
        fprintf(fichier_asm, "    pop eax\n");  /* start value */
        fprintf(fichier_asm, "    mov [%s], eax\n", var);
        fprintf(fichier_asm, "    mov [limite_pour_%d], ebx\n", etiq);
        /* Default step is 1 */
        fprintf(fichier_asm, "    mov dword [pas_pour_%d], 1\n", etiq);
        
        fprintf(fichier_asm, "debut_pour_%d:\n", etiq);
        fprintf(fichier_asm, "    mov eax, [%s]\n", var);
        fprintf(fichier_asm, "    cmp eax, [limite_pour_%d]\n", etiq);
        /* Check if we've passed the limit (handles both incrementing and decrementing) */
        fprintf(fichier_asm, "    jg fin_pour_%d\n", etiq);
        printf("-> POUR %s\n", var);
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
