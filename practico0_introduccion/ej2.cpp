#include <stdio.h>

void primosEnIntervalo(int a, int b)
{
    for (int i = a; i <= b; i++)
    {
        bool primo = true;
        for (int j = 2; j < i && primo; j++)
        {
            // printf("division %i div  %i = %i \n", i, j, (i % j));
            if (i % j == 0)
                primo = false;
        }
        if (primo)
            printf("%i es primo \n", i);
    }
}

int main()
{
    int a = 2;
    int b = 20;
    printf("Primos entre %i y %i \n", a, b);
    primosEnIntervalo(a, b);
    return 0;
}
