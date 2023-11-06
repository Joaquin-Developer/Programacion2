#include "../include/fecha.h"

struct rep_fecha
{
    nat dia, mes, anio;
};

TFecha crearTFecha(nat dia, nat mes, nat anio)
{
    TFecha nuevaFecha = new rep_fecha;
    nuevaFecha->dia = dia;
    nuevaFecha->mes = mes;
    nuevaFecha->anio = anio;
    return nuevaFecha;
}

void liberarTFecha(TFecha &fecha)
{
    delete fecha;
    fecha = NULL;
}

void imprimirTFecha(TFecha fecha)
{
    printf("%d/%d/%d\n", fecha->dia, fecha->mes, fecha->anio);
}

bool anioEsBisiesto(nat anio)
{
    if (anio % 4 != 0)
        return false;
    if (anio % 4 == 0 && anio % 100 != 0)
        return true;
    if (anio % 4 == 0 && anio % 100 == 0 && anio % 400 != 0)
        return false;
    if (anio % 4 == 0 && anio % 100 == 0 && anio % 400 == 0)
        return true;
    return false;
}

nat diasMes(nat mes, nat anio)
{
    if (anioEsBisiesto(anio) && mes == 2)
        return 29;

    if (mes == 2)
        return 28;

    if ((mes < 8 && mes % 2 == 0) || (mes >= 8 && mes % 2 != 0))
        return 30;
    else
        return 31;
}

void aumentarTFecha(TFecha &fecha, nat dias)
{
    fecha->dia += dias;
    while (fecha->dia > diasMes(fecha->mes, fecha->anio))
    {
        fecha->dia -= diasMes(fecha->mes, fecha->anio);
        fecha->mes++;

        if (fecha->mes > 12)
        {
            fecha->mes = 1;
            fecha->anio++;
        }
    }
}

int compararTFechas(TFecha fecha1, TFecha fecha2)
{
    int res = 0;

    if ((fecha1->anio > fecha2->anio) || (fecha1->anio == fecha2->anio && fecha1->mes > fecha2->mes) || (fecha1->anio == fecha2->anio && fecha1->mes == fecha2->mes && fecha1->dia > fecha2->dia))
        res = 1;

    else if (fecha1->dia == fecha2->dia && fecha1->mes == fecha2->mes && fecha1->anio == fecha2->anio)
        res = 0;
    else
        res = -1;
    return res;
}
