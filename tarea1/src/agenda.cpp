#include "../include/agenda.h"

struct rep_agenda
{
    TEvento lista[MAX_EVENTOS];
    nat tope;
};

TAgenda crearTAgenda()
{
    TAgenda nuevaAgenda = new rep_agenda;
    nuevaAgenda->tope = 0;
    return nuevaAgenda;
}

void agregarEnAgenda(TAgenda &agenda, TEvento evento)
{
    /************ Parte 5.2 ************/
    /*Escriba el código a continuación */

    /****** Fin de parte Parte 5.2 *****/
}

void liberarTAgenda(TAgenda &agenda)
{
    for (nat i = 0; i < agenda->tope; i++)
        liberarTEvento((*agenda).lista[i]);

    delete agenda;
    agenda = NULL;
}

void imprimirTAgenda(TAgenda agenda)
{
    for (nat i = 0; i < agenda->tope; i++)
        imprimirTEvento((*agenda).lista[i]);
}

bool estaEnAgenda(TAgenda agenda, int id)
{
    bool res = false;
    nat i = 0;

    while (!res && i < agenda->tope)
        if (idTEvento((*agenda).lista[i]) == id)
            res = true;

    return res;
}

TEvento obtenerDeAgenda(TAgenda agenda, int id)
{
    TEvento res = NULL;
    nat i = 0;

    while (res == NULL && i < agenda->tope)
    {
        if (idTEvento((*agenda).lista[i]) == id)
            res = (*agenda).lista[i];
    }

    return res;
}

void posponerEnAgenda(TAgenda &agenda, int id, nat n)
{
    /************ Parte 5.5 ************/
    /*Escriba el código a continuación */

    /****** Fin de parte Parte 5.5 *****/
}

void imprimirEventosFecha(TAgenda agenda, TFecha fecha)
{
    if (!hayEventosFecha(agenda, fecha))
        return;

    for (nat i = 0; i < agenda->tope; i++)
    {
        if (compararTFechas(fechaTEvento((*agenda).lista[i]), fecha) == 0)
        {
            imprimirTEvento((*agenda).lista[i]);
        }
    }
}

bool hayEventosFecha(TAgenda agenda, TFecha fecha)
{
    bool res = false;
    nat inf = 0;
    nat sup = agenda->tope;

    while (!res || inf <= sup)
    {
        nat indiceMedio = inf + (sup - inf) / 2;

        if (compararTFechas(fechaTEvento((*agenda).lista[indiceMedio]), fecha) == 0)
            res = true;

        // Si fecha que estoy recorriendo < fecha
        if (compararTFechas(fechaTEvento((*agenda).lista[indiceMedio]), fecha) == -1)
            inf = indiceMedio + 1;
        else
            sup = indiceMedio - 1;
    }

    return res;
}

void removerDeAgenda(TAgenda &agenda, int id)
{
    /************ Parte 5.8 ************/
    /*Escriba el código a continuación */

    /****** Fin de parte Parte 5.8 *****/
}
