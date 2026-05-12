%{
#include <stdio.h>

int verb = 0, adverb = 0, preposition = 0, conjunction = 0;
%}

/* Word groups */
VERB        (is|am|are|were|go)
ADVERB      (very|simply|quickly|gently)
PREP        (to|from|behind|between)
CONJ        (if|then)

%%

{VERB}      { printf("%s --> Verb\n", yytext); verb++; }

{ADVERB}    { printf("%s --> Adverb\n", yytext); adverb++; }

{PREP}      { printf("%s --> Preposition\n", yytext); preposition++; }

{CONJ}      { printf("%s --> Conjunction\n", yytext); conjunction++; }

[a-zA-Z]+   { printf("%s --> Unknown Word\n", yytext); }

[ \t\n]+    ;

.           { printf("Invalid character: %s\n", yytext); }

%%

int main()
{
    printf("Enter words:\n");
    yylex();

    printf("\nSummary:\n");
    printf("Verbs = %d\n", verb);
    printf("Adverbs = %d\n", adverb);
    printf("Prepositions = %d\n", preposition);
    printf("Conjunctions = %d\n", conjunction);

    return 0;
}

int yywrap()
{
    return 1;
}