#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

const char *input;
char lookahead;
char identifier[100];

// Forward declarations
void E();
void Eprime();
void T();
void Tprime();
void F();
void match(char);
void syntaxError(const char *msg);
void parseIdentifier();

// Read next non-space character
void nextToken() {
    while (*input == ' ') input++; // skip whitespace
    lookahead = *input++;
}

// Report syntax error and exit
void syntaxError(const char *msg) {
    printf("Syntax Error: %s at '%c'\n", msg, lookahead);
    exit(1);
}

// Match expected character
void match(char expected) {
    if (lookahead == expected) {
        printf("Matched: '%c'\n", expected);
        nextToken();
    } else {
        syntaxError("Unexpected character");
    }
}

// Parse an identifier (multi-character)
void parseIdentifier() {
    int i = 0;
    while (isalpha(lookahead)) {
        identifier[i++] = lookahead;
        nextToken();
    }
    identifier[i] = '\0'; // Null terminate the identifier
    printf("Matched identifier: '%s'\n", identifier);
}

// F -> (E) | id
void F() {
    if (lookahead == '(') {
        printf("Entering F -> (E)\n");
        match('(');
        E();
        match(')');
        printf("Exiting F -> (E)\n");
    } else if (isalpha(lookahead)) {
        printf("Entering F -> id\n");
        parseIdentifier(); // Match identifier (multi-character)
        printf("Exiting F -> id\n");
    } else {
        syntaxError("Expected identifier or '('");
    }
}

// T' -> * F T' | ε
void Tprime() {
    if (lookahead == '*') {
        printf("Entering T' -> * F T'\n");
        match('*');
        F();
        Tprime();
        printf("Exiting T' -> * F T'\n");
    } else {
        printf("T' -> ε\n");
    }
}

// T -> F T'
void T() {
    printf("Entering T -> F T'\n");
    F();
    Tprime();
    printf("Exiting T -> F T'\n");
}

// E' -> + T E' | ε
void Eprime() {
    if (lookahead == '+') {
        printf("Entering E' -> + T E'\n");
        match('+');
        T();
        Eprime();
        printf("Exiting E' -> + T E'\n");
    } else {
        printf("E' -> ε\n");
    }
}

// E -> T E'
void E() {
    printf("Entering E -> T E'\n");
    T();
    Eprime();
    printf("Exiting E -> T E'\n");
}

// Main function
int main() {
    char expr[100];
    printf("Enter an expression: ");
    fgets(expr, sizeof(expr), stdin);
    input = expr;
    nextToken(); // Initialize lookahead
    E(); // Start parsing from E
    if (lookahead == '\0' || lookahead == '\n') {
        printf("Parsing successful.\n");
    } else {
        syntaxError("Extra input after valid expression");
    }
    return 0;
}