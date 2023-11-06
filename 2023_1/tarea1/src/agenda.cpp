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
int tamanioAgenda(TAgenda agenda)
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
        // (*agenda).tope++;
        // (*agenda).lista[0] = evento;
        agenda->tope++;
        agenda->lista[0] = evento;
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
        int i = 0;
        while (indiceInsertar == -1 && i < tamanioAgenda(agenda))
        {
            // si fecha actual >= fecha insertar, entonces inserto en indice actual.
            if (compararTFechas(fechaTEvento((*agenda).lista[i]), fechaTEvento(evento)) >= 0)
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
    for (int i = 0; i < tamanioAgenda(agenda); i++)
        liberarTEvento((*agenda).lista[i]);

    delete agenda;
    agenda = NULL;
}

void imprimirTAgenda(TAgenda agenda)
{
    for (int i = 0; i < tamanioAgenda(agenda); i++)
        imprimirTEvento((*agenda).lista[i]);
}

bool estaEnAgenda(TAgenda agenda, int id)
{
    bool res = false;
    int i = 0;

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
    int i = 0;

    while (res == NULL && i < tamanioAgenda(agenda))
    {
        if (idTEvento((*agenda).lista[i]) == id)
            res = (*agenda).lista[i];
    }

    return res;
}

// Funcion auxiliar para a partir de un id, obtengo el indice donde se ubica en el Array agenda
// PRE: El evento debe estar en la agenda
int obtenerIndiceEnArray(TAgenda agenda, int id)
{
    int indice = -1;
    int i = 0;

    while (indice == -1 && i < tamanioAgenda(agenda))
    {
        if (idTEvento((*agenda).lista[i]) == id)
            indice = i;
        i++;
    }
    return indice;
}

void posponerEnAgenda(TAgenda &agenda, int id, nat n)
{
    int indiceActual = obtenerIndiceEnArray(agenda, id);
    TEvento evento = agenda->lista[indiceActual];
    posponerTEvento(evento, n);

    for (int i = 1; i < tamanioAgenda(agenda); i++)
    {
        TEvento key = agenda->lista[i];
        int j = i - 1;

        while (j >= 0 && compararTFechas(fechaTEvento(agenda->lista[j]), fechaTEvento(key)) == 1)
        {
            agenda->lista[j + 1] = agenda->lista[j];
            j = j - 1;
        }
        agenda->lista[j + 1] = key;
    }
}

/*
void posponerEnAgenda(TAgenda &agenda, int id, nat n)
{
    int indiceActual = obtenerIndiceEnArray(agenda, id);
    TEvento evento = agenda->lista[indiceActual];

    // calculo el índice de donde voy a tener que insertarlo:
    posponerTEvento(evento, n);
    int indiceInsertar = -1;

    // si fecha evento a mover es mayor a ultima fecha, entonces muevo al final.
    if (compararTFechas(fechaTEvento(evento), fechaTEvento(agenda->lista[tamanioAgenda(agenda) - 1])) == 1)
        indiceInsertar = tamanioAgenda(agenda) - 1;
    else
    {
        int i = indiceActual;
        while (indiceInsertar == -1 && i < tamanioAgenda(agenda))
        {
            // si fecha actual >= fecha evento mover, entonces muevo a indice actual.
            if (compararTFechas(fechaTEvento(agenda->lista[i]), fechaTEvento(evento)) >= 0)
                indiceInsertar = i;
            i++;
        }
    }
    Hasta acá funciona bien, se calcula el indice a mover!ç

TEvento temp = evento;

// mover eventos hacia adelante
for (int i = indiceActual; i < indiceInsertar; i++)
{
    // liberarTEvento((*agenda).lista[i]);
    agenda->lista[i] = agenda->lista[i + 1];
}

// insertar evento en la posición correspondiente
agenda->lista[indiceInsertar] = temp;

// liberarTEvento(agenda->lista[2]);
// agenda->lista[2] = agenda->lista[0];
// liberarTEvento(agenda->lista[0]);
// agenda->lista[0] = aux;

// TEvento aux = agenda->lista[indiceActual + 1];

// for (int i = indiceActual + 1; i < indiceInsertar; i++)
// {
//     liberarTEvento(agenda->lista[i]);
//     agenda->lista[i] = agenda->lista[i + 1];
//     // agenda->lista[i] = agenda->lista[i + 1];
// }
// liberarTEvento(agenda->lista[indiceInsertar]);
// agenda->lista[indiceInsertar] = agenda->lista[indiceActual];

// agenda->lista[indiceActual] = aux;
// liberarTEvento(agenda->lista[indiceActual]);
// agenda->lista[indiceActual] = aux;

// agenda->lista[indiceInsertar] = evento;

// (*agenda).lista[indiceInsertar] = evento;
// posponerTEvento((*agenda).lista[indiceInsertar], n);
// agenda->lista[indiceInsertar] = aux;
}
*/

void imprimirEventosFecha(TAgenda agenda, TFecha fecha)
{
    if (!hayEventosFecha(agenda, fecha))
        return;

    for (int i = 0; i < tamanioAgenda(agenda); i++)
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
    int indiceBorrar = obtenerIndiceEnArray(agenda, id);

    for (int i = indiceBorrar; i < tamanioAgenda(agenda) - 1; i--)
    {
        liberarTEvento(agenda->lista[i]);
        agenda->lista[i] = agenda->lista[i + 1];
    }

    (*agenda).tope--;
}
