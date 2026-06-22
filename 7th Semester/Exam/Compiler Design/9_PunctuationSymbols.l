%{
#include <stdio.h>
%}

PUNC   [.,;:!?(){}]

%%

{PUNC}   { printf("%s --> Punctuation\n", yytext); }

[ \t\n]+ { }

. { }

%%

int yywrap() {
    return 1;
}

int main() {
    printf("Enter punctuation symbols:\n");
    yylex();
    return 0;
}