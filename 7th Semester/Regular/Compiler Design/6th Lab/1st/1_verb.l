%{
#include<stdio.h>
int verb_count = 0;
%}
VERB (am|is|are|was|were|be|being|do|does|did|will|would|should|can|could|has|have|had|go|come|eat|read|write|play|run|walk)
%%
{VERB} { printf("%s --> Verb\n", yytext); verb_count++; }

[a-zA-Z]+ { printf("%s --> Not a Verb\n", yytext); }
[ \t\n]+ ;
. { printf("Invalid Character: %s\n", yytext); }
%%
int main()
{
    printf("Enter words:\n");
    yylex();
    printf("\nTotal Verbs = %d\n", verb_count);
    return 0;
}
int yywrap()
{
    return 1;
}