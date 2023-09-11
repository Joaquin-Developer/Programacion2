#include "../include/partida.h"

struct rep_partida
{
    TJugada jugada;
    TPartida sig;
};

TPartida crearTPartida()
{
    TPartida partida = new rep_partida;
    partida->jugada = NULL;
    partida->sig = NULL;
    return partida;
}

void agregarEnTPartida(TPartida &partida, TJugada jugada)
{
    TPartida nuevaPartida = crearTPartida();
    nuevaPartida->jugada = jugada;

    // si recibimos una partida NULL o si no tiene jugadas, insertamos nuevaPartida en la pos. 1 de la Lista
    if (partida == NULL || partida->jugada == NULL)
    {
        nuevaPartida->sig = partida;
        partida = nuevaPartida;
    }
    else
    {
        TPartida actual = partida;

        if (actual->sig != NULL)
            printf("no es null el sig\n");
        else
            printf("SI es null el sig\n");

        while (actual->sig != NULL)
        {
            if (numeroTJugada(jugada) > numeroTJugada(actual->sig->jugada))
            {
                printf("%i\n", numeroTJugada(actual->sig->jugada));
                actual = actual->sig;
            }
            else
                break;
        }

        nuevaPartida->sig = actual->sig;
        actual->sig = nuevaPartida;
    }
}

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
        TPartida siguiente = partida->sig;
        liberarTJugada(partida->jugada);
        delete partida;
        partida = siguiente;
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