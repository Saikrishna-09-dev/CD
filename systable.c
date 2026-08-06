#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TABLE_SIZE 100

typedef struct Symbol {
char *name;
char *type;
int scope;
struct Symbol *next;
} Symbol;
// Hash table
Symbol *symbolTable[TABLE_SIZE];
// Hash function
unsigned int hash(char *name) {
unsigned int hash = 0;
while (*name) {
hash = (hash << 5) + *name++;
}
return hash % TABLE_SIZE;
}
// Insert a symbol
void insert(char *name, char *type, int scope) {
unsigned int index = hash(name);
Symbol *newSymbol = malloc(sizeof(Symbol));
newSymbol->name = strdup(name);
newSymbol->type = strdup(type);
newSymbol->scope = scope;

newSymbol->next = symbolTable[index];
symbolTable[index] = newSymbol;
printf("Inserted: %s (%s) at scope %d\n", name, type, scope);
}
// Lookup a symbol
Symbol* lookup(char *name) {
unsigned int index = hash(name);
Symbol *entry = symbolTable[index];
while (entry) {
if (strcmp(entry->name, name) == 0)
return entry;
entry = entry->next;
}
return NULL;
}
// Display the symbol table
void display() {
printf("\nSymbol Table Contents:\n");
int i; // declare outside for C90 compatibility
for (i = 0; i < TABLE_SIZE; i++) {
Symbol *entry = symbolTable[i];
while (entry) {
printf("Name: %-10s Type: %-10s Scope: %d\n", entry->name, entry->type,
entry->scope);
entry = entry->next;
}
}
}
// Free memory
void freeTable() {
int i; // declare outside for C90 compatibility
for (i = 0; i < TABLE_SIZE; i++) {

Symbol *entry = symbolTable[i];
while (entry) {
Symbol *temp = entry;
entry = entry->next;
free(temp->name);
free(temp->type);
free(temp);
}
symbolTable[i] = NULL;
}
}
int main() {
// Sample usage
insert("S", "int", 1);
insert("A", "float", 1);
insert("I", "char", 2);
insert("X", "double", 2); // Same name, different scope
display();
// Lookup test
Symbol *s = lookup("A");
if (s)
printf("\n Lookup: Found %s of type %s at scope %d\n", s->name, s->type, s->scope);
else
printf("\n Lookup: Symbol not found\n");
// Cleanup
freeTable();
return 0;
}
