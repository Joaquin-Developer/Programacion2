#include <stdio.h>

void printArray(int *array, int length)
{
    for (int i = 0; i < length; i++)
        printf("Array[%i] = %d \n", i, array[i]);
}

void insertionSort(int *array, int length)
{
    for (int i = 1; i < length; i++)
    {
        int j = i;
        while (j >= 1 && array[j] < array[j - 1])
        {
            // intercambio arr[j] por arr[j-1]
            int aux = array[j];
            array[j] = array[j - 1];
            array[j - 1] = aux;
            j--;
        }
    }
}

void selectionSort(int *array)
{
    // implementar
}

int main()
{
    int lengthArray = 6;
    int array[lengthArray] = {4, 1, 6, 5, 3, 2};
    insertionSort(array, lengthArray);
    printArray(array, lengthArray);

    return 0;
}