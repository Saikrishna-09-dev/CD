%{
#include <stdio.h>
%}
%%
[a-zA-Z_][a-zA-Z0-9_]* { printf("Valid Identifier: %s\n", yytext); }
[0-9][a-zA-Z0-9_]*
{ printf("Invalid Identifier: %s\n", yytext); }
[ \n\t]+ ; /* ignore whitespace */
.
{ printf("Unknown: %s\n", yytext); }
%%
int yywrap() { return 1; }
int main() {
yylex();
return 0;
}
