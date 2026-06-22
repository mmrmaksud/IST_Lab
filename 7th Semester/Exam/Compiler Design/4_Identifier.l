%{
#include <stdio.h>
%}

ID   [a-zA-Z_][a-zA-Z0-9_]*

%%

{ID}   { printf("%s --> Identifier\n", yytext); }

[ \t\n]+ { }

. { }

%%

int yywrap() {
    return 1;
}

int main() {
    printf("Enter identifiers:\n");
    yylex();
    return 0;
}