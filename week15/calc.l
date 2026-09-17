%{
#include <stdio.h>
#include "y.tab.h"

int c;
extern int yylval;
%}

%%

[ \t]       ;       /* Ignore spaces and tabs */

[a-z] {
    c = yytext[0];
    yylval = c - 'a';
    return LETTER;
}

[0-9] {
    c = yytext[0];
    yylval = c - '0';
    return DIGIT;
}

\n {
    return '\n';
}

. {
    c = yytext[0];
    return c;
}

%%
