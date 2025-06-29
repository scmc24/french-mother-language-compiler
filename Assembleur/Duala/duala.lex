%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "duala.h"

char current_id[100];
%}

%%

"mbɔmbɔ"        { return DEBUT; }
"suka"          { return FIN; }
"ndambo"        { return TYPE_ENTIER; }
"yɛnɛ"          { return LIRE; }
"kɔma"          { return ECRIRE; }
"sɔ"            { return SI; }
"tɛ"            { return ALORS; }
"kɛma"          { return SINON; }
"sukasi"        { return FINSI; }
"mbɛlɛ"         { return TANT_QUE; }
"sala"          { return FAIRE; }
"sukambɛlɛ"     { return FINTANT; }

"ndɔŋ"          { return SELON; }
"kɛs"           { return CAS; }
"bɔsɔ"          { return DEFAUT; }
"sukandɔŋ"      { return FINSELON; }
"bima"          { return SORTIR; }

"pɔ"            { return POUR; }
"na"            { return DE; }
"kɛ"            { return A; }
"mbɛn"          { return PAS; }
"sukapɔ"        { return FINPOUR; }

"sɔŋɔlɔ"        { return REPETER; }
"tɛmbɛlɛ"       { return JUSQUA; }

"<-"            { return AFFECTATION; }
"=="            { return EGAL; }
"!="            { return DIFFERENT; }
">="            { return SUP_EGAL; }
"<="            { return INF_EGAL; }
">"             { return SUPERIEUR; }
"<"             { return INFERIEUR; }
"+"             { return PLUS; }
"-"             { return MOINS; }
"*"             { return FOIS; }
"/"             { return DIVISE; }
"%"             { return MODULO; }

";"             { return POINT_VIRGULE; }
","             { return VIRGULE; }
"("             { return PAREN_OUV; }
")"             { return PAREN_FERM; }
":"             { return DEUX_POINTS; }

[0-9]+          { yylval = atoi(yytext); return NOMBRE_ENTIER; }
\"[^\"]*\"        { strcpy(current_id, yytext); return STRING_LITERAL; }
[a-zA-Z][a-zA-Z0-9_]* { strcpy(current_id, yytext); return IDENTIFICATEUR; }

[ \t\n]+        { /* ignorer espaces */ }

.               { printf("Caractere non reconnu: %s\n", yytext); }

%%

int yywrap() {
    return 1;
}
