%{
#include "y.tab.h"
%}
%%
int { return INT; }
float { return FLOAT; }
[a-zA-Z_][a-zA-Z0-9_]* { return ID; }
";" { return SEMICOLON; }
[ \t\n]+ { /* skip whitespace */ }
. { return yytext[0]; }
%%
int yywrap(void)
{
return 1;
}
