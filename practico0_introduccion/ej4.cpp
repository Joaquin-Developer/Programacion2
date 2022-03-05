#include <stdio.h>

bool esPalindrome()
{
    return false;
}

int main()
{
    char palabra[8];

    for (int i = 0; i < 8; i++)
    {
        char c;
        scanf("Ingrese letra: %c", &c);
        palabra[i] = c;
    }

    for (int i = 0; i < 8; i++)
        printf("%c", palabra[i]);
    printf("\n");

    return 0;
}