%{
#include <stdio.h>

extern FILE *yyin;

int yylex();
void yyerror(const char *s);
%}

%define parse.error verbose

%union {
	char* stype;
	int itype;
	float ftype;
}

%token INT STRING FLOAT
%token <itype> INTEGER 
%token <ftype> FLOATL
%token <stype> STRINGL ID

%left '+' '-'
%left '*' '/'

// TODO: Change this
//%type <my_type> expression

%start translation_unit

%%

data_type:
      INT
    | FLOAT
    | STRING
    ;

constant:
      INTEGER
    | FLOATL
    ;

primary_expression:
      ID
    | STRINGL
    ;

expression:
      primary_expression
    | constant
    | expression '+' expression
    | expression '-' expression
    | expression '*' expression
    | expression '/' expression
    ;

assign_expr:
      ID '=' expression
    ;

var_assign: assign_expr;

var_dec:
      data_type ID
    | data_type assign_expr
    ;
    
func_call:
      ID '(' ')'
    ;

statement:
      var_dec ';'
    | var_assign ';'
    | func_call ';'
    ;

statement_list:
      statement
    | statement_list statement
    ;

block:
      '{' '}'
    | '{' statement_list '}'
    ;

function:
      data_type ID '(' ')' block
    ;

function_list:
      function
    | function_list function
    ;

translation_unit:
      function_list
    | translation_unit function_list
    ;
%%

//Our parsing function
void parse(const char *path)
{
	yyin = fopen(path, "r");
	yyparse();
}

//Handle syntax errors
void yyerror(const char *s)
{
	printf("Syntax error: %s\n", s);
}

