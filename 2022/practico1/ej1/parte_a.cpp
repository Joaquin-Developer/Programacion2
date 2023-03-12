#include <stdio.h>

struct rep_fecha
{
    unsigned int d;
    unsigned int m;
    unsigned int a;
};

typedef struct rep_fecha *TFecha;

void sortArray(rep_fecha *arr)
{
    for (int i = 0; i < 3; i++)
        printf("%d\n", arr[i].d);
}

int main()
{
    rep_fecha a;
    a.d = 10;
    a.m = 10;
    a.a = 2022;

    rep_fecha b;
    a.d = 15;
    a.m = 5;
    a.a = 2022;

    rep_fecha c;
    a.d = 20;
    a.m = 12;
    a.a = 1992;

    struct rep_fecha arr[3] = {a, b, c};

    sortArray(arr);

    return 0;
}
