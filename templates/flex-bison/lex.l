%{
#include <stdio.h>
#include <string.h>

#include "parser.yy.h"
%}

%%
int                         { return INT; }
string                      { return STRING; }
float                       { return FLOAT; }
"="                         { return '='; }
";"                         { return ';'; }
"{"                         { return '{'; }
"}"                         { return '}'; }
"("                         { return '('; }
")"                         { return ')'; }
L?\"(\\.|[^\\"\n])*\"	    { yylval.stype = strdup(yytext); return STRINGL;}
[ \t\n]                     {}
[0-9]+					    { yylval.itype = atoi(yytext); return INTEGER;}
([0-9]*[.])?[0-9]+		    { yylval.ftype = atof(yytext); return FLOATL;}
[_]?[A-Za-z]*([0-9]+)?	    { yylval.stype = strdup(yytext); return ID;}
%%

// Other REGEX's
/*
\'[A-Za-z]\'                { yylval.chtype = yytext[1]; return CHARL; }
0[xX][0-9A-Fa-f]+           { yylval.htype = (unsigned char)strtol(yytext, NULL, 16); return HEX; }
0[0-7]+                     { yylval.stype = strdup(yytext); return OCTALL; }
*/

int yywrap() { return 1; }
