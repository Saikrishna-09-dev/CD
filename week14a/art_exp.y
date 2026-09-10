%{
#include <stdio.h>
#include <stdlib.h>
int yylex(void);
void yyerror(const char *s);
%}
%token NUMBER
// Operator precedence and associativity
%left '+' '-'
%left '*' '/'
%right UMINUS
%%
input:
/* empty */
| input expr '\n' { printf("Result = %d\n", $2); }
;
expr:
expr '+' expr { $$ = $1 + $3; }
| expr '-' expr { $$ = $1 - $3; }
| expr '*' expr { $$ = $1 * $3; }
| expr '/' expr {
if ($3 == 0) {
yyerror("Division by zero");
$$ = 0;
} else {
$$ = $1 / $3;
}
}
| '-' expr %prec UMINUS { $$ = -$2; }
| '(' expr ')' { $$ = $2; }
| NUMBER { $$ = $1; }
;
%%
void yyerror(const char *s) {
fprintf(stderr, "Syntax error: %s\n", s);

}
int main() {
printf("Enter arithmetic expressions (Ctrl+D to quit):\n");
yyparse();
return 0;
}