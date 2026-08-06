%{
#include <stdio.h>
int digits=0, spaces=0, specials=0;
%}
%%
[0-9] { digits++; }
[ \t\n] { spaces++; }
[^a-zA-Z0-9 \t\n] { specials++; }
.;
%%
int yywrap() { return 1; }
int main() {
yylex();
printf("Digits = %d\n", digits);
printf("Spaces = %d\n", spaces);
printf("Special Characters = %d\n", specials);
return 0;
}
