%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "duala.h"

char current_id[100];
%}

%%

"mbɔmbɔ"        { printf("LEX: DEBUT\n"); return DEBUT; }
"suka"          { printf("LEX: FIN\n"); return FIN; }
"ndambo"        { printf("LEX: TYPE_ENTIER\n"); return TYPE_ENTIER; }
"yɛnɛ"          { printf("LEX: LIRE\n"); return LIRE; }
"kɔma"          { printf("LEX: ECRIRE\n"); return ECRIRE; }
"sɔ"            { printf("LEX: SI\n"); return SI; }
"kɛma"          { printf("LEX: SINON (kɛma)\n"); return SINON; }
"sukasi"        { printf("LEX: FINSI\n"); return FINSI; }
"mbɛlɛ"         { printf("LEX: TANT_QUE\n"); return TANT_QUE; }
"sala"          { printf("LEX: FAIRE\n"); return FAIRE; }
"sukambɛlɛ"     { printf("LEX: FINTANT\n"); return FINTANT; }

"ndɔŋ"          { return SELON; }
"kɛs"           { return CAS; }
"bɔsɔ"          { return DEFAUT; }
"sukandɔŋ"      { return FINSELON; }
"bima"          { return SORTIR; }

"pɔ"            { printf("LEX: POUR\n"); return POUR; }
"na"            { printf("LEX: DE\n"); return DE; }
"tɛ"            { printf("LEX: ALORS (tɛ)\n"); return ALORS; }
"mbɛn"          { printf("LEX: PAS (mbɛn)\n"); return PAS; }
"sukapɔ"        { printf("LEX: FINPOUR\n"); return FINPOUR; }

"sɔŋɔlɔ"        { printf("LEX: REPETER (sɔŋɔlɔ)\n"); return REPETER; }
"tɛmbɛlɛ"       { printf("LEX: JUSQUA (tɛmbɛlɛ)\n"); return JUSQUA; }

"<-"            { printf("LEX: AFFECTATION (<-)\n"); return AFFECTATION; }
"<"             { printf("LEX: INFERIEUR (<)\n"); return INFERIEUR; }
">"             { printf("LEX: SUPERIEUR (>)\n"); return SUPERIEUR; }
"<="            { printf("LEX: INF_EGAL (<=)\n"); return INF_EGAL; }
">="            { printf("LEX: SUP_EGAL (>=)\n"); return SUP_EGAL; }
"=="            { printf("LEX: EGAL (==)\n"); return EGAL; }
"!="            { printf("LEX: DIFFERENT (!=)\n"); return DIFFERENT; }

"+"             { printf("LEX: PLUS (+)\n"); return PLUS; }
"-"             { printf("LEX: MOINS (-)\n"); return MOINS; }
"*"             { printf("LEX: FOIS (*)\n"); return FOIS; }
"/"             { 
        printf("LEX: DIVISE (/) - Ligne %d, yylval.sval = %s\n", yylineno, yytext); 
        return DIVISE; 
    }
"%"             { printf("LEX: MODULO (%%)\n"); return MODULO; }

";"             { printf("LEX: POINT_VIRGULE (;)\n"); return POINT_VIRGULE; }
","             { printf("LEX: VIRGULE (,)\n"); return VIRGULE; }
"("             { printf("LEX: PAREN_OUV (()\n"); return PAREN_OUV; }
")"             { printf("LEX: PAREN_FERM ())\n"); return PAREN_FERM; }
":"             { printf("LEX: DEUX_POINTS (:)\n"); return DEUX_POINTS; }

[0-9]+          { 
    yylval.ival = atoi(yytext);
    printf("LEX: NOMBRE_ENTIER: %d\n", yylval.ival);
    return NOMBRE_ENTIER; 
}

[a-zA-Z_][a-zA-Z0-9_]* { 
    strcpy(current_id, yytext); 
    yylval.sval = strdup(yytext);
    printf("LEX: IDENTIFICATEUR: %s\n", current_id);
    return IDENTIFICATEUR; 
}

\"[^\"\\]*(?:\\.[^\"\\]*)*\" { 
    // Remove the surrounding quotes and handle escape sequences
    char *str = yytext + 1;  // Skip opening quote
    int len = strlen(str);
    if (len > 0) str[len-1] = '\0';  // Remove closing quote
    
    // Allocate memory for the string
    yylval.sval = strdup(str);
    return CHAINE_CARACTERE;
}

[ \t\n]+        { /* ignorer espaces */ }

.               { printf("Caractere non reconnu: %s\n", yytext); }

%%

int yywrap() {
    return 1;
}
