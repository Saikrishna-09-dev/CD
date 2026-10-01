%{
#include <stdio.h>
#include <ctype.h>
%}
%token let dig
%%
TERM : XTERM '\n'
{
printf (" \nAccepted\n" );
exit(0);
}
| error
{
printf (" \nRejected\n" );
exit(0);
}
XTERM : XTERM let
| XTERM dig
| let
;
%%
yylex()
{
char ch;
while ((ch = getchar())==' ');
if(isalpha(ch))

return let;
if(isdigit(ch))
return dig;
return ch;
}
main()
{
printf ("Enter a variable : ");
yyparse ();
}
int yyerror()
{
return 0;
}