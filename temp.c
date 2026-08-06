#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

char input[100];
int i = 0; // Pointer to current character

void E();
void Eprime();
void T();
void Tprime();
void F();

void match(char c)
{
    if (input[i] == c)
    {
        i++;
    }
    else
    {
        printf("Error: expected %c at position %d\n", c, i);
        exit(1);
    }
}

void E()
{
    T();
    Eprime();
}

void Eprime()
{
    if (input[i] == '+')
    {
        match('+');
        T();
        Eprime();
    }
    // epsilon production (do nothing)
}

void T()
{
    F();
    Tprime();
}

void Tprime()
{
    if (input[i] == '*')
    {
        match('*');
        F();
        Tprime();
    }
    // epsilon production (do nothing)
}

void F()
{
    if (input[i] == '(')
    {
        match('(');
        E();
        match(')');
    }
    else if (isalpha(input[i]))
    {
        // Identifier (single alphabet)
        match(input[i]);
    }
    else
    {
        printf("Error: unexpected symbol %c at position %d\n", input[i], i);
        exit(1);
    }
}

int main()
{
    printf("Enter expression: ");
    scanf("%99s", input);

    E();

    if (input[i] == '\0')
    {
        printf("Parsing successful!\n");
    }
    else
    {
        printf("Error: extra symbols at the end.\n");
    }

    return 0;
}