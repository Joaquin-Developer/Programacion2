#include "../include/fecha.h"

// Estructura para almacenar una fecha con día, mes y año
struct rep_fecha
{
    nat dia, mes, anio;
};

// Función para crear un nuevo objeto de tipo TFecha con una fecha dada
TFecha crearTFecha(nat dia, nat mes, nat anio)
{
    TFecha fecha = new rep_fecha;
    fecha->dia = dia;
    fecha->mes = mes;
    fecha->anio = anio;
    return fecha;
}

// Función para liberar un objeto de tipo TFecha previamente creado
void liberarTFecha(TFecha &fecha)
{
    delete fecha;
    fecha = NULL;
}

// Función para imprimir una fecha representada por un objeto de tipo TFecha
void imprimirTFecha(TFecha fecha)
{
    printf("%d/%d/%d\n", fecha->dia, fecha->mes, fecha->anio);
}

// ******** funciones auxiliares:  ************

// dado un año devuelve true si es bisiesto, o false si no lo es.
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

// dado un mes y año devuelve su cantida d de días
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

// ***** end funciones auxiliares **********

// Función para aumentar una fecha en una cantidad dada de días
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

// Función para comparar dos fechas representadas por objetos de tipo TFecha
int compararTFechas(TFecha fecha1, TFecha fecha2)
{
    if ((fecha1->anio > fecha2->anio) || (fecha1->anio == fecha2->anio && fecha1->mes > fecha2->mes) || (fecha1->anio == fecha2->anio && fecha1->mes == fecha2->mes && fecha1->dia > fecha2->dia))
        return 1;

    if (fecha1->dia == fecha2->dia && fecha1->mes == fecha2->mes && fecha1->anio == fecha2->anio)
        return 0;
    return -1;
}

// Retorna una copia de la fecha
TFecha copiarTFecha(TFecha fecha)
{
    if (fecha == NULL)
        return NULL;

    return crearTFecha(fecha->dia, fecha->mes, fecha->anio);
}