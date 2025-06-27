%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "francais.h"

char current_id[100];
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
"tant_que"      { return TANT_QUE; }
"faire"         { return FAIRE; }
"fintant"       { return FINTANT; }

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

";"             { return POINT_VIRGULE; }
","             { return VIRGULE; }
"("             { return PAREN_OUV; }
")"             { return PAREN_FERM; }

[0-9]+          { yylval.ival = atoi(yytext); return NOMBRE_ENTIER; }
[a-zA-Z][a-zA-Z0-9_]* { 
    strcpy(current_id, yytext); 
    yylval.sval = strdup(yytext); 
    return IDENTIFICATEUR; 
}

[ \t\n]+        { /* ignorer espaces */ }

.               { printf("Caractere non reconnu: %s\n", yytext); }

%%

int yywrap() {
    return 1;
}