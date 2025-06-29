%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void yyerror(const char *s);
int yylex(void);

FILE *fichier_c;
extern char current_id[100];
char affectation_var[100];
char expression_buffer[1000];
int label_counter = 0;
%}

%union {
    int ival;
    char *sval;
}

%token DEBUT FIN TYPE_ENTIER LIRE ECRIRE 
%token SI ALORS SINON FINSI TANT_QUE FAIRE FINTANT
%token SELON CAS DEFAUT FINSELON SORTIR 
%token POUR DE A PAS FINPOUR
%token REPETER JUSQUA
%token AFFECTATION EGAL DIFFERENT SUP_EGAL INF_EGAL SUPERIEUR INFERIEUR
%token PLUS MOINS FOIS DIVISE MODULO
%token POINT_VIRGULE VIRGULE PAREN_OUV PAREN_FERM DEUX_POINTS
%token <ival> NOMBRE_ENTIER
%token <sval> IDENTIFICATEUR

%type <sval> expression terme facteur

%left EGAL DIFFERENT SUP_EGAL INF_EGAL SUPERIEUR INFERIEUR
%left PLUS MOINS
%left FOIS DIVISE MODULO

%%

programme:
    DEBUT { 
        fichier_c = fopen("programme.c", "w");
        fprintf(fichier_c, "#include <stdio.h>\n");
        fprintf(fichier_c, "#include <stdlib.h>\n\n");
        fprintf(fichier_c, "int main() {\n");
        printf("🔧 Mbɔmbɔ génération du code C...\n");
    } 
    bloc 
    FIN { 
        fprintf(fichier_c, "    printf(\"\\n--- Suka programme ---\\n\");\n");
        fprintf(fichier_c, "    return 0;\n");
        fprintf(fichier_c, "}\n");
        fclose(fichier_c);
        printf("✅ Code C généré na programme.c\n"); 
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
        fprintf(fichier_c, "    int %s = 0;  // Variable déclarée\n", current_id);
        printf("📝 Variable déclarée: %s\n", current_id);
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
        fprintf(fichier_c, "    %s = %s;\n", affectation_var, $4);
        printf("⬅️  Affectation: %s = %s\n", affectation_var, $4);
        free($4);
    }
    ;

expression:
    terme { 
        $$ = $1; 
    }
    | expression PLUS terme {
        $$ = malloc(100);
        sprintf($$, "(%s + %s)", $1, $3);
        free($1);
        free($3);
    }
    | expression MOINS terme {
        $$ = malloc(100);
        sprintf($$, "(%s - %s)", $1, $3);
        free($1);
        free($3);
    }
    | expression SUPERIEUR terme {
        $$ = malloc(100);
        sprintf($$, "(%s > %s)", $1, $3);
        free($1);
        free($3);
    }
    | expression INFERIEUR terme {
        $$ = malloc(100);
        sprintf($$, "(%s < %s)", $1, $3);
        free($1);
        free($3);
    }
    | expression EGAL terme {
        $$ = malloc(100);
        sprintf($$, "(%s == %s)", $1, $3);
        free($1);
        free($3);
    }
    | expression DIFFERENT terme {
        $$ = malloc(100);
        sprintf($$, "(%s != %s)", $1, $3);
        free($1);
        free($3);
    }
    | expression SUP_EGAL terme {
        $$ = malloc(100);
        sprintf($$, "(%s >= %s)", $1, $3);
        free($1);
        free($3);
    }
    | expression INF_EGAL terme {
        $$ = malloc(100);
        sprintf($$, "(%s <= %s)", $1, $3);
        free($1);
        free($3);
    }
    ;

terme:
    facteur { 
        $$ = $1; 
    }
    | terme FOIS facteur {
        $$ = malloc(100);
        sprintf($$, "(%s * %s)", $1, $3);
        free($1);
        free($3);
    }
    | terme DIVISE facteur {
        $$ = malloc(100);
        sprintf($$, "(%s / %s)", $1, $3);
        free($1);
        free($3);
    }
    | terme MODULO facteur {
        $$ = malloc(100);
        sprintf($$, "(%s %% %s)", $1, $3);
        free($1);
        free($3);
    }
    ;

facteur:
    NOMBRE_ENTIER {
        $$ = malloc(20);
        sprintf($$, "%d", $1);
        printf("🔢 Constante: %d\n", $1);
    }
    | IDENTIFICATEUR {
        $$ = malloc(strlen(current_id) + 1);
        strcpy($$, current_id);
        printf("📊 Variable utilisée: %s\n", current_id);
    }
    | PAREN_OUV expression PAREN_FERM {
        $$ = malloc(strlen($2) + 3);
        sprintf($$, "(%s)", $2);
        free($2);
    }
    ;

conditionnelle:
    SI PAREN_OUV expression PAREN_FERM ALORS {
        fprintf(fichier_c, "    if (%s) {\n", $3);
        printf("🔀 Mbɔmbɔ condition SƆ\n");
        free($3);
    } instructions partie_sinon_opt FINSI {
        fprintf(fichier_c, "    }  // Suka SƆ\n");
        printf("🔚 Suka condition SƆ\n");
    }
    ;

partie_sinon_opt:
    /* vide */
    | SINON {
        fprintf(fichier_c, "    } else {\n");
        printf("🔄 Partie KƐMA\n");
    } instructions
    ;

boucle_tant_que:
    TANT_QUE PAREN_OUV expression PAREN_FERM FAIRE {
        fprintf(fichier_c, "    while (%s) {\n", $3);
        printf("🔄 Mbɔmbɔ boucle MBƐLƐ\n");
        free($3);
    } instructions FINTANT {
        fprintf(fichier_c, "    }  // Suka MBƐLƐ\n");
        printf("🔚 Suka boucle MBƐLƐ\n");
    }
    ;

lecture:
    LIRE IDENTIFICATEUR POINT_VIRGULE {
        fprintf(fichier_c, "    printf(\"Tɔlɛ valeur na %s: \");\n", current_id);
        fprintf(fichier_c, "    scanf(\"%%d\", &%s);\n", current_id);
        printf("📥 Yɛnɛ: %s\n", current_id);
    }
    ;

ecriture:
    ECRIRE expression POINT_VIRGULE {
        fprintf(fichier_c, "    printf(\"Résultat: %%d\\n\", %s);\n", $2);
        printf("📤 Kɔma expression\n");
        free($2);
    }
    ;

structure_selon:
    SELON PAREN_OUV expression PAREN_FERM {
        fprintf(fichier_c, "    switch (%s) {\n", $3);
        printf("🔀 NDƆŊ (switch)\n");
        free($3);
    } liste_cas partie_defaut_opt FINSELON {
        fprintf(fichier_c, "    } // Suka NDƆŊ\n");
        printf("🔚 Suka NDƆŊ\n");
    }
    ;

liste_cas: 
    /* vide */ 
    | liste_cas cas_simple
    ;

cas_simple:
    CAS expression DEUX_POINTS {
        fprintf(fichier_c, "        case %s:\n", $2);
        printf("📋 KƐS %s\n", $2);
        free($2);
    } instructions
    ;

partie_defaut_opt:
    /* vide */
    | DEFAUT DEUX_POINTS {
        fprintf(fichier_c, "        default:\n");
        printf("📋 KƐS BƆSƆ\n");
    } instructions
    ;

sortir_instruction:
    SORTIR POINT_VIRGULE {
        fprintf(fichier_c, "        break;\n");
        printf("🚪 BIMA (break)\n");
    }
    ;

boucle_pour:
    POUR IDENTIFICATEUR DE expression A expression {
        char *var = current_id;
        fprintf(fichier_c, "    for (%s = %s; %s <= %s; %s++) {\n", 
                var, $4, var, $6, var);
        printf("🔄 PƆ %s na %s tɛ %s\n", var, $4, $6);
        free($4); free($6);
    } FAIRE instructions FINPOUR {
        fprintf(fichier_c, "    }  // Suka PƆ\n");
        printf("🔚 Suka PƆ\n");
    }
    | POUR IDENTIFICATEUR DE expression A expression PAS expression {
        char *var = current_id;
        fprintf(fichier_c, "    for (%s = %s; %s <= %s; %s += %s) {\n", 
                var, $4, var, $6, var, $8);
        printf("🔄 PƆ %s na %s tɛ %s mbɛn %s\n", var, $4, $6, $8);
        free($4); free($6); free($8);
    } FAIRE instructions FINPOUR {
        fprintf(fichier_c, "    }  // Suka PƆ na mbɛn\n");
        printf("🔚 Suka PƆ na mbɛn\n");
    }
    ;

boucle_repeter:
    REPETER {
        fprintf(fichier_c, "    do {\n");
        printf("🔄 SƆŊƆLƆ (do-while)\n");
    } instructions JUSQUA PAREN_OUV expression PAREN_FERM POINT_VIRGULE {
        fprintf(fichier_c, "    } while (%s);\n", $6);
        printf("🔚 TƐMBƐLƐ (condition)\n");
        free($6);
    }
    ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "❌ Erreur de syntaxe: %s\n", s);
}

int main() {
    printf("🇨🇲 === COMPILATEUR DUALA VERS C ===\n");
    printf("📝 Tɔlɛ programme na wo:\n\n");
    return yyparse();
}
