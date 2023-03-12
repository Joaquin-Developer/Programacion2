#include <stdio.h>

struct rep_fecha
{
    unsigned int dia, mes, anio;
};

typedef rep_fecha *TFecha;

int main()
{
    TFecha fecha = new rep_fecha;
    fecha->dia = 1;
    fecha->mes = 3;
    fecha->anio = 2023;

    printf("%d/%d/%d\n", fecha->dia, fecha->mes, fecha->anio);
    printf("\n");

    return 0;
}