%{
#include <stdio.h>
%}

DIGIT   [0-9]

%%

{DIGIT}   { printf("%s --> Digit\n", yytext); }

[ \t\n]+  { }

. { }

%%

int yywrap() {
    return 1;
}

int main() {
    printf("Enter digits:\n");
    yylex();
    return 0;
}