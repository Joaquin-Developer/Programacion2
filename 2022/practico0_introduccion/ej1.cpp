#include <stdio.h>

// Promedio de las 4 calif mas altas, entre las 5 calif obtenidas
float promClase(int c1, int c2, int c3, int c4, int c5)
{
    // tomo como pipe al c1
    int min = c1;

    if (c2 < min)
        min = c2;
    if (c3 < min)
        min = c3;
    if (c4 < min)
        min = c4;
    if (c5 < min)
        min = c5;

    return (c1 + c2 + c3 + c4 + c5 - min) / 4;
}

int main()
{
    int c1, c2, c3, c4, c5;

    printf("Ingresar nota1: ");
    scanf("%d", &c2);
    printf("Ingresar nota2: ");
    scanf("%d", &c2);
    printf("Ingresar nota3: ");
    scanf("%d", &c3);
    printf("Ingresar nota4: ");
    scanf("%d", &c4);
    printf("Ingresar nota5: ");
    scanf("%d", &c5);

    printf("El promedio es: %f", promClase(c1, c2, c3, c4, c5));
    printf("\n");
    return 0;
}
