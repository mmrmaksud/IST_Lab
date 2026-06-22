%{
#include <stdio.h>
%}

%%

"+"|"-"|"*"|"/"|"%" {
    printf("Arithmetic Operator: %s\n", yytext);
}

"=="|"!="|">"|"<"|">="|"<=" {
    printf("Relational Operator: %s\n", yytext);
}

"&&"|"||"|"!" {
    printf("Logical Operator: %s\n", yytext);
}

"="|"+="|"-="|"*="|"/="|"%=" {
    printf("Assignment Operator: %s\n", yytext);
}

"++" {
    printf("Increment Operator: %s\n", yytext);
}
"--" {
    printf("Decrement Operator: %s\n", yytext);
}
[ \t\n]+    ;

. {
    printf("Invalid Input: %s\n", yytext);
}

%%

int yywrap()
{
    return 1;
}

int main()
{
    printf("Enter operators:\n");
    yylex();
    return 0;
}