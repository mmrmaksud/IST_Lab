%{
#include <stdio.h>
%}

FLOAT   [0-9]+\.[0-9]+

%%

{FLOAT}   { printf("%s --> Float\n", yytext); }

[ \t\n]+ { }

. { }

%%

int yywrap() {
    return 1;
}

int main() {
    printf("Enter float numbers:\n");
    yylex();
    return 0;
}