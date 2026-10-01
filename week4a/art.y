%{
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
%}
%token num let
%left '+' '-'
%left '*' '/'
%%
Stmt : Stmt '\n'
{ printf ("\n.. Valid Expression.. \n");
exit(0);
}
| expr
| error '\n'
{ printf ("\n..Invalid ..\n");
exit(0);
}
;

expr : num
| let
| expr '+' expr
| expr '-' expr
| expr '*' expr
| expr '/' expr

| '('expr ')'
;
%%
main ( )
{
printf ("Enter an expression to validate :" );
yyparse( );
}
yylex()
{
int ch;
while ( ( ch = getchar() ) == ' ' );
if ( isdigit(ch) )
return num; // return token num
if ( isalpha(ch) )
return let; // return token let
return ch;
}
yyerror (char *s)
{
printf ( "%s", s );
}