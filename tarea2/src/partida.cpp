#include "../include/partida.h"

struct rep_partida
{
    TJugada jugada;
    TPartida sig;
};

TPartida crearTPartida()
{
    // TPartida partida = new rep_partida;
    // // partida->jugada = NULL;
    // // partida->sig = NULL;
    // // partida = NULL;
    // return partida;
    return NULL;
}

void agregarEnTPartida(TPartida &partida, TJugada jugada)
{
    TPartida nuevo = new rep_partida;
    nuevo->jugada = jugada;

    if (partida == NULL)
    {
        nuevo->sig = partida;
        partida = nuevo;
        return;
    }
    else if (numeroTJugada(partida->jugada) >= numeroTJugada(jugada))
    {
        nuevo->sig = partida;
        partida = nuevo;
    }
    else
    {
        TPartida aux = partida;
        while (aux->sig != NULL && numeroTJugada(aux->sig->jugada) < numeroTJugada(jugada))
            aux = aux->sig;
        nuevo->sig = aux->sig;
        aux->sig = nuevo;
    }

    // if (partida == NULL || numeroTJugada(partida->jugada) >= numeroTJugada(jugada))
    // {
    //     nuevo->sig = partida;
    //     partida = nuevo;
    // }
    // else
    // {
    //     TPartida aux = partida;
    //     while (aux->sig != NULL && numeroTJugada(aux->sig->jugada) < numeroTJugada(jugada))
    //         aux = aux->sig;
    //     nuevo->sig = aux->sig;
    //     aux->sig = nuevo;
    // }
}

// void agregarEnTPartidaV2(TPartida &partida, TJugada jugada)
// {
//     TPartida nuevaPartida = crearTPartida();
//     nuevaPartida->jugada = jugada;

//     // si recibimos una partida NULL o si no tiene jugadas, insertamos nuevaPartida en la pos. 1 de la Lista
//     if (partida == NULL || partida->jugada == NULL)
//     {
//         nuevaPartida->sig = NULL;
//         partida = nuevaPartida;
//     }
//     else
//     {
//         TPartida actual = partida;

//         if (actual->sig == NULL)
//         {
//             printf("act->sig == NULL\n");
//             // lista con 1 solo elemento
//             if (numeroTJugada(jugada) > numeroTJugada(actual->jugada))
//             {
//                 // insertar al final
//                 partida->sig = nuevaPartida;
//             }
//             else
//             {
//                 // insertar al comienzo
//                 partida = nuevaPartida;
//                 nuevaPartida->sig = actual;
//             }
//         }
//         else
//         {
//             // lista con mas de 1 elemento
//             printf("\nLista con elementos > 1\n");
//             while (actual->sig != NULL)
//             {
//                 TPartida siguiente = actual->sig;

//                 printf("(%i, %i)\n", numeroTJugada(actual->jugada), numeroTJugada(actual->sig->jugada));

//                 if (numeroTJugada(actual->jugada) < numeroTJugada(jugada) && numeroTJugada(jugada) < numeroTJugada(siguiente->jugada))
//                 {
//                     printf("inserto entre medio de actual y siguiente\n");
//                     // si actual < jugada < siguiente => inserto entre medio de actual y siguiente
//                     nuevaPartida->sig = siguiente;
//                     actual->sig = nuevaPartida;
//                     return;
//                 }
//                 actual = actual->sig;
//             }
//         }
//     }
// }

void imprimirTPartida(TPartida partida)
{
    TPartida aux = partida;

    while (aux != NULL)
    {
        imprimirTJugada(aux->jugada);
        aux = aux->sig;
    }
}

void liberarTPartida(TPartida &partida)
{
    while (partida != NULL)
    {
        TPartida aux = partida;
        partida = partida->sig;
        liberarTJugada(aux->jugada);
        delete aux;
    }
}

bool esVaciaTPartida(TPartida partida)
{
    return partida == NULL;
}

TPartida copiarTPartida(TPartida partida)
{
    return NULL;
}

bool estaEnTPartida(TPartida partida, int numeroDeJugada)
{
    return false;
}

TJugada obtenerDeTPartida(TPartida partida, int numeroDeJugada)
{
    return NULL;
}

void imprimirJugadasConMovimiento(TPartida partida, int pos, Movimiento mov)
{
    TPartida aux = partida;

    while (aux != NULL)
    {
        if (tieneMovimientoEnPosTJugada(aux->jugada, pos, mov))
            imprimirTJugada(aux->jugada);

        aux = aux->sig;
    }
}

void removerDeTPartida(TPartida &partida, int numeroDeJugada)
{
}