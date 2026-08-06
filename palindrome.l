%{
#include <stdio.h>
#include <string.h>
%}
%%
[a-zA-Z]+ {
char str[100];
strcpy(str, yytext);
int len = strlen(str);
int flag = 1;
int i; /* Declare loop variable here (C90 style) */
for(i = 0; i < len/2; i++) {
if(str[i] != str[len-i-1]) {
flag = 0;
break;
}
}
if(flag) printf("%s is a Palindrome\n", str);
else printf("%s is not a Palindrome\n", str);
}
[ \n\t]+ ;
.;
%%
int main() {
yylex();
return 0;
}
int yywrap() {
return 1;
}
