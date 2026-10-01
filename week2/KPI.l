%{
#include <stdio.h>
#include <string.h>
int keyword_flag = 0;
// List of keywords for demo purposes
char *keywords[] = {"int", "float", "return", "if", "else", "while", "for", "char"};
%}
%%
"int"|"float"|"return"|"if"|"else"|"while"|"for"|"char" { printf("Keyword: %s\n", yytext);
keyword_flag = 1; }
[a-zA-Z_][a-zA-Z0-9_]* { if (!keyword_flag) printf("Identifier: %s\n", yytext); keyword_flag = 0; }
[0-9]+(\.[0-9]+)? { printf("Number: %s\n", yytext); }
"+"|"-"|"*"|"/"|"="|"=="|"!="|"&&"|"||" { printf("Operator: %s\n", yytext); }
[\n\t ] { /* Ignore whitespace */ }
. { printf("Unknown symbol: %s\n", yytext); }
%%
int yywrap() {
return 1;
}
int main() {
yylex(); // Start lexical analysis
return 0;
}