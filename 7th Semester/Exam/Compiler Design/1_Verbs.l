%{
#include <stdio.h>
int verb_count = 0;
%}

VERB   (is|am|are|were|was|be|being|been|do|does|did|will|would|should|can|could|has|have|had|go)

%%

{VERB}   { printf("Verb Found: %s\n", yytext); verb_count++; }

[ \t\n]+  { }

.         { }

%%

int yywrap() {
    return 1;
}

int main() {
    printf("Enter text:\n");
    yylex();
    printf("\nTotal Verbs = %d\n", verb_count);
    return 0;
}