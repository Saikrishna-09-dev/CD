%{
#include <stdio.h>
#include <stdlib.h>
// Fix for implicit declaration warnings
int yylex(void);
int yyerror(const char *s);
%}
%token NUMBER%left '+' '-'
%left '*' '/'
%left UMINUS
%%
input:
| input line
;
line:
'\n'
| expr '\n' { printf("Result = %d\n", $1); }
;
expr:
NUMBER
{ $$ = $1; }
| expr '+' expr { $$ = $1 + $3; }
| expr '-' expr { $$ = $1 - $3; }
| expr '*' expr { $$ = $1 * $3; }
| expr '/' expr {
if ($3 == 0) {
printf("Error: Division by zero\n");
exit(1);
}
$$ = $1 / $3;
}
| '-' expr %prec UMINUS { $$ = -$2; }
| '(' expr ')'
{ $$ = $2; }
;
%%
int main() {
printf("Enter expressions (Ctrl+D to exit):\n");
yyparse();
return 0;
}
int yyerror(const char *s) {fprintf(stderr, "Parse error: %s\n", s);
return 1;
}