%{
#include <stdio.h>
int vowels=0, consonants=0;
%}
%%
[aeiouAEIOU] { vowels++; }
[a-zA-Z]
{ consonants++; }
[ \n\t]+
;
.
;
%%
int main() {
yylex();
printf("Vowels = %d\n", vowels);
printf("Consonants = %d\n", consonants);
return 0;
}
int yywrap() {
return 1;
}

