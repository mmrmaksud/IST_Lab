%{
#include <stdio.h>
%}

KEYWORD   (int|float|char|if|else|while|for|return)

%%

{KEYWORD}   { printf("%s --> Keyword\n", yytext); }

[ \t\n]+    { }

.           { }

%%

int yywrap() {
    return 1;
}

int main() {
    printf("Enter words:\n");
    yylex();
    return 0;
}