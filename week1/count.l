%{
#include <stdio.h>
int chars=0, words=0, lines=0;
%}
%%
[a-zA-Z0-9]+ { words++; chars += yyleng; }
\n
{ lines++; }
.
{ chars++; }
%%
int main() {
yylex();
printf("Characters = %d\n", chars);
printf("Words = %d\n", words);
printf("Lines = %d\n", lines);
return 0;
}
int yywrap() {
return 1; // tells Lex: stop scanning after one file
}
