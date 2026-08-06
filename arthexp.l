%{
#include <stdio.h>
%}
%%
[0-9]+ { printf("Number: %s\n", yytext); }
[+*/-] { printf("Operator: %s\n", yytext); }
[()] { printf("Parenthesis: %s\n", yytext); }
[ \t\n]+ ; /* ignore whitespace */
.
{ printf("Unknown: %s\n", yytext); }
%%
int yywrap() { return 1; }
int main() {
yylex();
return 0;
}
