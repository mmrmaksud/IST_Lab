%{
#include<stdio.h>
%}

POS_INT      \+[0-9]+|[0-9]+
NEG_INT      -[0-9]+

POS_FLOAT    \+[0-9]+\.[0-9]+|[0-9]+\.[0-9]+
NEG_FLOAT    -[0-9]+\.[0-9]+

%%

{NEG_FLOAT}   { printf("%s --> Negative Float\n", yytext); }

{POS_FLOAT}   { printf("%s --> Positive Float\n", yytext); }

{NEG_INT}     { printf("%s --> Negative Integer\n", yytext); }

{POS_INT}     { printf("%s --> Positive Integer\n", yytext); }

[ \t\n]+      ;

.             ;

%%

int main()
{
    printf("Enter numbers:\n");

    yylex();

    return 0;
}

int yywrap()
{
    return 1;
}