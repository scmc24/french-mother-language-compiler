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
%token AFFECTATION EGAL DIFFERENT SUP_EGAL INF_EGAL SUPERIEUR INFERIEUR
%token PLUS MOINS FOIS DIVISE
%token POINT_VIRGULE VIRGULE PAREN_OUV PAREN_FERM
%token <ival> NOMBRE_ENTIER
%token <sval> IDENTIFICATEUR

%type <sval> expression terme facteur

%left EGAL DIFFERENT SUP_EGAL INF_EGAL SUPERIEUR INFERIEUR
%left PLUS MOINS
%left FOIS DIVISE

%%

programme:
    DEBUT { 
        fichier_c = fopen("programme.c", "w");
        fprintf(fichier_c, "#include <stdio.h>\n");
        fprintf(fichier_c, "#include <stdlib.h>\n\n");
        fprintf(fichier_c, "int main() {\n");
        printf("🔧 Génération du code C...\n");
    } 
    bloc 
    FIN { 
        fprintf(fichier_c, "    printf(\"\\n--- Fin du programme ---\\n\");\n");
        fprintf(fichier_c, "    return 0;\n");
        fprintf(fichier_c, "}\n");
        fclose(fichier_c);
        printf("✅ Code C généré dans programme.c\n"); 
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
    | boucle_tant_que
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
        printf("🔀 Début condition SI\n");
        free($3);
    } instructions partie_sinon_opt FINSI {
        fprintf(fichier_c, "    }  // Fin SI\n");
        printf("🔚 Fin condition SI\n");
    }
    ;

partie_sinon_opt:
    /* vide */
    | SINON {
        fprintf(fichier_c, "    } else {\n");
        printf("🔄 Partie SINON\n");
    } instructions
    ;

boucle_tant_que:
    TANT_QUE PAREN_OUV expression PAREN_FERM FAIRE {
        fprintf(fichier_c, "    while (%s) {\n", $3);
        printf("🔄 Début boucle TANT_QUE\n");
        free($3);
    } instructions FINTANT {
        fprintf(fichier_c, "    }  // Fin TANT_QUE\n");
        printf("🔚 Fin boucle TANT_QUE\n");
    }
    ;

lecture:
    LIRE IDENTIFICATEUR POINT_VIRGULE {
        fprintf(fichier_c, "    printf(\"Entrez la valeur de %s: \");\n", current_id);
        fprintf(fichier_c, "    scanf(\"%%d\", &%s);\n", current_id);
        printf("📥 Lecture de: %s\n", current_id);
    }
    ;

ecriture:
    ECRIRE expression POINT_VIRGULE {
        fprintf(fichier_c, "    printf(\"Résultat: %%d\\n\", %s);\n", $2);
        printf("📤 Écriture d'une expression\n");
        free($2);
    }
    ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "❌ Erreur de syntaxe: %s\n", s);
}

int main() {
    printf("🇫🇷 === COMPILATEUR FRANÇAIS VERS C ===\n");
    printf("📝 Entrez votre programme:\n\n");
    return yyparse();
}