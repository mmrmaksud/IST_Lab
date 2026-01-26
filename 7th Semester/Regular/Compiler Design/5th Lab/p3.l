%{
#include <stdio.h>
%}

/* Definitions section */
KEYWORD     int|float|char|double|void|if|else|while|for|return
IDENTIFIER  [a-zA-Z_][a-zA-Z0-9_]*
REAL        [0-9]+"."[0-9]+
INTEGER     [0-9]+

%%

{KEYWORD} {
    printf("%s -> KEYWORD\n", yytext);
}

{REAL} {
    printf("%s -> REAL NUMBER\n", yytext);
}

{INTEGER} {
    printf("%s -> INTEGER NUMBER\n", yytext);
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
