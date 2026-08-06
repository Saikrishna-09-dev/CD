%{
#include <stdio.h>
#include <ctype.h> /* for toupper() */
%}
%%
[a-z] { printf("%c", toupper(yytext[0])); } /* convert lowercase to uppercase */
.|\n { ECHO; }
/* echo other characters unchanged */
%%
int yywrap() {
return 1; /* end of input */
}
int main() {
yylex(); /* start scanning */
return 0;
}
