#include <stdio.h>

void printArray(int *array)
{
    for (int i = 0; i < 3; i++)
    {
        printf("Posicion %i es %d \n", i, array[i]);
    }
}

void llenarArray(int *array)
{
    array[0] = 12;
    array[1] = 23;
    array[2] = 88;
}

void modificarNumPorReferencia(int *num)
{
    *num = 77;
}

int main()
{
    int array[3]; // = {12, 33, 88};
    int num;

    llenarArray(array);
    modificarNumPorReferencia(&num);
    printf("num = %i\n", num);
    printArray(array);

    return 0;
}