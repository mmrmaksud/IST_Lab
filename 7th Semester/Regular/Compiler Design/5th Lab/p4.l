%{
#include <stdio.h>
%}

/* Definitions section */
KEYWORD     int|float|char|double|void|if|else|while|for|return
IDENTIFIER  [a-zA-Z_][a-zA-Z0-9_]*

INTEGER     [+-]?[0-9]+
REAL        [+-]?[0-9]*"."[0-9]+
SCIENTIFIC  [+-]?[0-9]+(\.[0-9]+)?[eE][+-]?[0-9]+

OPERATOR    [+\-*/%=]
SPECIAL     [;,]
PAREN       [(){}[\]]

%%

{KEYWORD} {
    printf("%s -> KEYWORD\n", yytext);
}

{SCIENTIFIC} {
    printf("%s -> SCIENTIFIC NUMBER\n", yytext);
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

{OPERATOR} {
    printf("%s -> OPERATOR\n", yytext);
}

{PAREN} {
    printf("%s -> PARENTHESIS\n", yytext);
}

{SPECIAL} {
    printf("%s -> SPECIAL CHARACTER\n", yytext);
}

[ \t\n]+   ;   /* ignore whitespace */
. {
    printf("%s -> UNKNOWN CHARACTER\n", yytext);
}

%%

int yywrap() {
    return 1;
}

int main() {
    printf("Enter input:\n");
    yylex();
    return 0;
}
