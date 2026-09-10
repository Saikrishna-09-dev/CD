%{
#include <stdio.h>
#include <stdlib.h> // Required for the exit() function
// Function prototypes for yylex and yyerror
extern int yylex();
extern int yyerror(const char *);
%}
%token LET DIG
%%
variable: var
;
var: var DIG
| var LET
| LET
;
%%
int main() {
printf("Enter the variable:\n");
yyparse();
printf("Valid variable\n");
return 0;
}
int yyerror(const char *s) {
printf("Invalid variable \n");
exit(0);
}