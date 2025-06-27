%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "duala.h"

char current_id[100];
%}

%%

"esika"         { return DEBUT; }
"ebwelan"       { return FIN; }
"wum"           { return TYPE_ENTIER; }
"tanga"         { return LIRE; }
"bwandisa"      { return ECRIRE; }
"nika"          { return SI; }
"nde"           { return ALORS; }
"tendo"         { return SINON; }
"ebwelan_ou_epasi_nika"         { return FINSI; }
"ndik’_eyong"   { return TANT_QUE; }
"bua_ou_bola"   { return FAIRE; }
"ebwelan_ou_epasi_ndik’_eyong"       { return FINTANT; }

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