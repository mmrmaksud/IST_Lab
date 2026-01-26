%{
#include <stdio.h>
%}

/* Definitions section */
KEYWORD     int|float|char|double|void|if|else|while|for|return
IDENTIFIER  [a-zA-Z_][a-zA-Z0-9_]*

%%

{KEYWORD} {
    printf("%s -> KEYWORD\n", yytext);
}

{IDENTIFIER} {
    printf("%s -> IDENTIFIER\n", yytext);
}

[ \t\n]+   ;   /* ignore whitespace */
.          ;   /* ignore other characters */

%%

int yywrap() {
    return 1;
}

int main() {
    printf("Enter input:\n");
    yylex();
    return 0;
}