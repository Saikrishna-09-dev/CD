#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

// List of C keywords
const char *keywords[] = {
    "int", "float", "char", "double", "if", "else", "while", "for", "return", "void", "main"
};

int keywordCount = sizeof(keywords) / sizeof(keywords[0]);

int isKeyword(const char *str) {
    for (int i = 0; i < keywordCount; i++) {
        if (strcmp(str, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

int main() {
    char ch, buffer[MAX];
    int i = 0;

    FILE *fp = fopen("input.c", "r");
    if (fp == NULL) {
        printf("Error: Cannot open input.c\n");
        return 1;
    }

    printf("Lexical Analysis Output:\n");

    while ((ch = fgetc(fp)) != EOF) {
        // Skip whitespace
        if (isspace(ch))
            continue;

        // Identifiers and keywords
        if (isalpha(ch) || ch == '_') {
            buffer[i++] = ch;
            while (isalnum(ch = fgetc(fp)) || ch == '_') {
                buffer[i++] = ch;
            }
            buffer[i] = '\0';
            i = 0;
            ungetc(ch, fp);
            if (isKeyword(buffer))
                printf("Keyword: %s\n", buffer);
            else
                printf("Identifier: %s\n", buffer);
        }
        // Numbers
        else if (isdigit(ch)) {
            buffer[i++] = ch;
            while (isdigit(ch = fgetc(fp)) || ch == '.') {
                buffer[i++] = ch;
            }
            buffer[i] = '\0';
            i = 0;
            ungetc(ch, fp);
            printf("Number: %s\n", buffer);
        }
        // String literals
        else if (ch == '"') {
            buffer[i++] = ch;
            while ((ch = fgetc(fp)) != '"' && ch != EOF) {
                buffer[i++] = ch;
            }
            buffer[i++] = '"';
            buffer[i] = '\0';
            i = 0;
            printf("String Literal: %s\n", buffer);
        }
        // Multi-character operators
        else if (ch == '=' || ch == '!' || ch == '<' || ch == '>') {
            char next = fgetc(fp);
            if (next == '=') {
                printf("Operator: %c%c\n", ch, next);
            } else {
                ungetc(next, fp);
                printf("Operator: %c\n", ch);
            }
        }
        // Single-character operators
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%') {
            printf("Operator: %c\n", ch);
        }
        // Special characters
        else if (ch == ';' || ch == ',' || ch == '(' || ch == ')' || ch == '{' || ch == '}') {
            printf("Special Character: %c\n", ch);
        }
        // Unknown characters
        else {
            printf("Unknown Character: %c\n", ch);
        }
    }

    fclose(fp);
    return 0;
}