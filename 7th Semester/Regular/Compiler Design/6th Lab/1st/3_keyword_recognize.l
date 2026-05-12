%{
#include <stdio.h>
%}

%%

/* Keywords */
if|else|for|while|do|int|float|char|double|return|break|continue|switch|case|default
        { printf("%s --> Keyword\n", yytext); }

/* Numbers */
[0-9]+  
        { printf("%s --> Number\n", yytext); }

/* Identifiers */
[a-zA-Z_][a-zA-Z0-9_]*
        { printf("%s --> Identifier\n", yytext); }

/* Operators */
\+\+    { printf("%s --> Operator (++)\n", yytext); }
\+      { printf("%s --> Operator (+)\n", yytext); }
\-      { printf("%s --> Operator (-)\n", yytext); }
\*      { printf("%s --> Operator (*)\n", yytext); }
\/      { printf("%s --> Operator (/)\n", yytext); }
=       { printf("%s --> Operator (=)\n", yytext); }
==      { printf("%s --> Operator (==)\n", yytext); }
!=      { printf("%s --> Operator (!=)\n", yytext); }
<=      { printf("%s --> Operator (<=)\n", yytext); }
>=      { printf("%s --> Operator (>=)\n", yytext); }
<       { printf("%s --> Operator (<)\n", yytext); }
>       { printf("%s --> Operator (>)\n", yytext); }

/* Special Symbols (SAFE INDIVIDUAL RULES) */
\.      { printf("%s --> Dot\n", yytext); }
\?      { printf("%s --> Question Mark\n", yytext); }
\!      { printf("%s --> Exclamation\n", yytext); }
\,      { printf("%s --> Comma\n", yytext); }
\;      { printf("%s --> Semicolon\n", yytext); }
\:      { printf("%s --> Colon\n", yytext); }
\(      { printf("%s --> Open Bracket\n", yytext); }
\)      { printf("%s --> Close Bracket\n", yytext); }

/* Ignore whitespace */
[ \t\n]+   ;

/* Anything else */
.        
        { printf("%s --> Invalid Symbol\n", yytext); }

%%

int main()
{
    printf("Enter input:\n");
    yylex();
    return 0;
}

int yywrap()
{
    return 1;
}