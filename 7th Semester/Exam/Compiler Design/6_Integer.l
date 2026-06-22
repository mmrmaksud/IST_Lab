%{
#include <stdio.h>
%}

INT   [-+]?[0-9]+

%%

{INT}   { printf("%s --> Integer\n", yytext); }

[ \t\n]+ { }

. { }

%%

int yywrap() {
    return 1;
}

int main() {
    printf("Enter integers:\n");
    yylex();
    return 0;
}