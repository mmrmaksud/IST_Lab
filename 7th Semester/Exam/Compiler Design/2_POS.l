%{
#include <stdio.h>
%}

VERB      (is|am|are|were|go)
ADVERB    (very|simply|quickly|gently)
PREP      (to|from|behind|between)
CONJ      (if|then)

%%

{VERB}      { printf("%s --> Verb\n", yytext); }

{ADVERB}    { printf("%s --> Adverb\n", yytext); }

{PREP}      { printf("%s --> Preposition\n", yytext); }

{CONJ}      { printf("%s --> Conjunction\n", yytext); }

[ \t\n]+    { }

.           { }

%%

int yywrap() {
    return 1;
}

int main() {
    printf("Enter a sentence:\n");
    yylex();
    return 0;
}