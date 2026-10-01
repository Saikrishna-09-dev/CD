%{
#include <stdio.h>
%}
%%
"<" { printf("LESS THAN\n"); }
"<=" { printf("LESS THAN OR EQUAL\n"); }
">" { printf("GREATER THAN\n"); }
">=" { printf("GREATER THAN OR EQUAL\n"); }
"==" { printf("EQUAL TO\n"); }
"!=" { printf("NOT EQUAL\n"); }
[ \n\t]+ ;
. { printf("Unknown: %s\n", yytext); }
%%
int main() {
yylex();
return 0;
}
int yywrap() {
return 1;
}

