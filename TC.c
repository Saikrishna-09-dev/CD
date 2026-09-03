#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// Symbol Table Entry
struct Symbol {
char name[20];
char type[10]; // "int", "float", "string"
};
// Global Symbol Table
struct Symbol symbolTable[100];
int symbolCount = 0;
// Add symbol to table
void addSymbol(char* name, char* type) {
strcpy(symbolTable[symbolCount].name, name);
strcpy(symbolTable[symbolCount].type, type);
symbolCount++;
}
// Lookup symbol type
char* getType(char* name) {
    for (int i = 0; i < symbolCount; i++) {
        if (strcmp(symbolTable[i].name, name) == 0) {
            return symbolTable[i].type;
        }
    }
    return "undefined";
}
// Type Checking Function
char* typeCheck(char* leftType, char* rightType, char* operator) {
    if (strcmp(operator, "+") == 0 || strcmp(operator, "-") == 0 || strcmp(operator, "*") ==0) {
        if (strcmp(leftType, "int") == 0 && strcmp(rightType, "int") == 0)
            return "int";
        else if ((strcmp(leftType, "float") == 0) || (strcmp(rightType, "float") == 0))
            return "float"; // coercion

        else
            return "error";
    }
    if (strcmp(operator, "/") == 0) {
        if ((strcmp(leftType, "int") == 0 && strcmp(rightType, "int") == 0) ||(strcmp(leftType, "float") == 0) || (strcmp(rightType, "float") == 0))
            return "float"; // division result is float
        else
            return "error";
        }
    return "error";
}


int main() {
// Step 1: Add variables to symbol table
    addSymbol("a", "int");
    addSymbol("b", "int");
    addSymbol("c", "int");
    // Step 2: Example expression: c = a + b
    char* leftType = getType("a");
    char* rightType = getType("b");
    char* resultType = typeCheck(leftType, rightType, "+");
    printf("Expression: c = a + b\n");
    if (strcmp(resultType, "error") == 0) {
        printf("Type Error: incompatible types (%s + %s)\n", leftType, rightType);
    } else {
    // Check assignment compatibility
    char* assignType = getType("c");
    if (strcmp(assignType, resultType) == 0) {
        printf("Type Check Passed: %s assigned to %s\n", resultType, assignType);
    } else {
        printf("Type Error: cannot assign %s to %s\n", resultType, assignType);
    }
    }
    return 0;
}