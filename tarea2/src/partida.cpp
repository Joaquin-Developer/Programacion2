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
    if (partida == NULL)
        return NULL;

    TPartida partidaCopia = new rep_partida;
    partidaCopia->jugada = copiarTJugada(partida->jugada);
    partidaCopia->sig = copiarTPartida(partida->sig);
    return partidaCopia;
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