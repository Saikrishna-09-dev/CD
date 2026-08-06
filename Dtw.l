%{
#include <stdio.h>
%}
%%
0 { printf("Zero "); }
1 { printf("One "); }
2 { printf("Two "); }
3 { printf("Three "); }
4 { printf("Four "); }
5 { printf("Five "); }
6 { printf("Six "); }
7 { printf("Seven "); }
8 { printf("Eight "); }
9 { printf("Nine "); }
[ \t\n] { ECHO; } /* keep spaces, tabs, newlines */
.
{ ECHO; } /* echo other characters unchanged */
%%
int yywrap() {
return 1; /* end of input */
}
int main() {
yylex();
return 0;
}

