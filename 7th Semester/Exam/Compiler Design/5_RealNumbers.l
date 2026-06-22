%{
#include <stdio.h>
%}

REAL   [0-9]+(\.[0-9]+)?

%%

{REAL}   { printf("%s --> Real Number\n", yytext); }

[ \t\n]+ { }

. { }

%%

int yywrap() {
    return 1;
}

int main() {
    printf("Enter real numbers:\n");
    yylex();
    return 0;
}