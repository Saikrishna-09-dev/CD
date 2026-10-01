%{
#include <stdio.h>
#include <stdlib.h>
int yylex(void);
void yyerror(const char *s);
%}
%token INT FLOAT ID SEMICOLON
%%
S : type ID SEMICOLON { printf("Valid declaration\n"); } ;
type : INT | FLOAT ;
%%

void yyerror(const char *s) {
fprintf(stderr, "Syntax Error: %s\n", s);
}
int main(void) {
printf("Enter a declaration:\n");
yyparse();
return 0;
}