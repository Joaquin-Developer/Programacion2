#include "../include/agenda.h"

struct rep_agenda
{
    TEvento lista[MAX_EVENTOS];
    nat tope;
};

TAgenda crearTAgenda()
{
    TAgenda nuevaAgenda = new rep_agenda;
    (*nuevaAgenda).tope = 0;
    // nuevaAgenda->tope = 0;
    return nuevaAgenda;
}

/* funcion auxiliar para obtener tamanio de agenda */
nat tamanioAgenda(TAgenda agenda)
{
    return (*agenda).tope;
}

void agregarEnAgenda(TAgenda &agenda, TEvento evento)
{
    // Si esta llena no hacemos nada
    if (tamanioAgenda(agenda) == MAX_EVENTOS)
        return;

    // Agregar - caso que este vacia:
    if (tamanioAgenda(agenda) == 0)
    {
        (*agenda).tope++;
        (*agenda).lista[0] = evento;
        return;
    }
    // Agregar - resto de los casos:

    // calculo el índice de donde voy a tener que insertarlo:
    int indiceInsertar = -1;

    // si fecha insertar es mayor a ultima fecha, entonces inserto al final.
    if (compararTFechas(fechaTEvento(evento), fechaTEvento((*agenda).lista[tamanioAgenda(agenda) - 1])) == 1)
        indiceInsertar = tamanioAgenda(agenda);
    else
    {
        nat i = 0;
        while (indiceInsertar == -1 && i < tamanioAgenda(agenda))
        {
            // si fecha actual >= fecha insertar, entonces inserto en indice actual.
            if (compararTFechas(fechaTEvento((*agenda).lista[0]), fechaTEvento(evento)) >= 0)
                indiceInsertar = i;
            i++;
        }
    }

    (*agenda).tope++;
    // recorro y voy moviendo hacia la derecha:
    for (int i = tamanioAgenda(agenda); i > indiceInsertar; i--)
        (*agenda).lista[i] = (*agenda).lista[i - 1];

    (*agenda).lista[indiceInsertar] = evento;
}

void liberarTAgenda(TAgenda &agenda)
{
    for (nat i = 0; i < tamanioAgenda(agenda); i++)
        liberarTEvento((*agenda).lista[i]);

    delete agenda;
    agenda = NULL;
}

void imprimirTAgenda(TAgenda agenda)
{
    for (nat i = 0; i < tamanioAgenda(agenda); i++)
        imprimirTEvento((*agenda).lista[i]);
}

bool estaEnAgenda(TAgenda agenda, int id)
{
    bool res = false;
    nat i = 0;

    while (!res && i < tamanioAgenda(agenda))
    {
        if (idTEvento((*agenda).lista[i]) == id)
            res = true;
        i++;
    }

    return res;
}

TEvento obtenerDeAgenda(TAgenda agenda, int id)
{
    TEvento res = NULL;
    nat i = 0;

    while (res == NULL && i < tamanioAgenda(agenda))
    {
        if (idTEvento((*agenda).lista[i]) == id)
            res = (*agenda).lista[i];
    }

    return res;
}

void posponerEnAgenda(TAgenda &agenda, int id, nat n)
{
}

void imprimirEventosFecha(TAgenda agenda, TFecha fecha)
{
    if (!hayEventosFecha(agenda, fecha))
        return;

    for (nat i = 0; i < tamanioAgenda(agenda); i++)
    {
        if (compararTFechas(fechaTEvento((*agenda).lista[i]), fecha) == 0)
        {
            imprimirTEvento((*agenda).lista[i]);
        }
    }
}

bool hayEventosFecha(TAgenda agenda, TFecha fecha)
{
    if (tamanioAgenda(agenda) == 0)
        return false;

    bool res = false;
    nat inf = 0;
    nat sup = tamanioAgenda(agenda) - 1;

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
