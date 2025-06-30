%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "francais.h"

char current_id[100];
char current_string[1000];
%}

%%

"debut"         { return DEBUT; }
"fin"           { return FIN; }
"entier"        { return TYPE_ENTIER; }
"lire"          { return LIRE; }
"ecrire"        { return ECRIRE; }
"si"            { return SI; }
"alors"         { return ALORS; }
"sinon"         { return SINON; }
"finsi"         { return FINSI; }
"selon"         { return SELON; }
"cas"           { return CAS; }
"defaut"        { return DEFAUT; }
"finselon"      { return FINSELON; }
"sortir"        { return SORTIR; }
"tant_que"      { return TANT_QUE; }
"faire"         { return FAIRE; }
"fintant"       { return FINTANT; }
"pour"          { return POUR; }
"de"            { return DE; }
"a"             { return A; }
"pas"           { return PAS; }
"finpour"       { return FINPOUR; }
"repeter"       { return REPETER; }
"jusqua"        { return JUSQUA; }

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
"?"             { return QUESTION; }
[0-9]+          { yylval = atoi(yytext); return NOMBRE_ENTIER; }

\"[^\"]*\"      { 
    strcpy(current_string, yytext); 
    return CHAINE_CARACTERES; 
}

[a-zA-Z][a-zA-Z0-9_]* { strcpy(current_id, yytext); return IDENTIFICATEUR; }

[ \t\n]+        { }
.               { printf("Caractere non reconnu: %s\n", yytext); }

%%

int yywrap() {
    return 1;
}