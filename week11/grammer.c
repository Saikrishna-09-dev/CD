#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 10

char productions[MAX][MAX];
char first[26][MAX];
int n = 0;

int isTerminal(char symbol) {
    return !isupper(symbol) && symbol != '#';
}

void addToFirst(char nonTerminal, char symbol) {
    int idx = nonTerminal - 'A';
    for (int i = 0; first[idx][i] != '\0'; i++) {
        if (first[idx][i] == symbol)
            return;
    }
    int len = strlen(first[idx]);
    first[idx][len] = symbol;
    first[idx][len + 1] = '\0';
}

void findFirst(char nonTerminal) {
    for (int i = 0; i < n; i++) {
        if (productions[i][0] == nonTerminal) {
            char next = productions[i][2];

            if (isTerminal(next)) {
                addToFirst(nonTerminal, next);
            } else if (next != nonTerminal) {
                if (first[next - 'A'][0] == '\0')
                    findFirst(next);

                for (int k = 0; first[next - 'A'][k] != '\0'; k++) {
                    addToFirst(nonTerminal, first[next - 'A'][k]);
                }
            }

            if (next == '#') {
                addToFirst(nonTerminal, '#');
            }
        }
    }
}

int main() {
    printf("Enter number of productions:\n");
    scanf("%d", &n);

    printf("Enter productions (e.g., E=TR for E -> TR, use # for epsilon):\n");
    for (int i = 0; i < n; i++) {
        scanf("%s", productions[i]);
    }

    for (int i = 0; i < n; i++) {
        char nonTerminal = productions[i][0];
        findFirst(nonTerminal);
    }

    printf("\nFIRST sets:\n");
    for (int i = 0; i < n; i++) {
        char nonTerminal = productions[i][0];

        if (first[nonTerminal - 'A'][0] != '\0') {
            printf("FIRST(%c) = { ", nonTerminal);

            for (int j = 0; first[nonTerminal - 'A'][j] != '\0'; j++) {
                printf("%c ", first[nonTerminal - 'A'][j]);
            }

            printf("}\n");
        }
    }

    return 0;
}