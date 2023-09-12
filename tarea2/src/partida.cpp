#include "../include/partida.h"

struct rep_partida
{
    TJugada jugada;
    TPartida sig;
};

TPartida crearTPartida()
{
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
    if (partida == NULL)
        return false;

    TPartida aux = partida;
    while (aux != NULL)
    {
        if (numeroTJugada(aux->jugada) == numeroDeJugada)
            return true;
        aux = aux->sig;
    }
    return false;
}

TJugada obtenerDeTPartida(TPartida partida, int numeroDeJugada)
{
    if (partida == NULL)
        return NULL;

    TPartida aux = partida;
    while (aux != NULL)
    {
        if (numeroTJugada(aux->jugada) == numeroDeJugada)
            return aux->jugada;
        aux = aux->sig;
    }

    return NULL;
}

void imprimirJugadasConMovimiento(TPartida partida, int pos, Movimiento mov)
{
    TPartida aux = partida;

    while (aux != NULL)
    {
        if (tieneMovimientoEnPosTJugada(aux->jugada, pos - 1, mov))
            imprimirTJugada(aux->jugada);
        aux = aux->sig;
    }
}

void removerDeTPartida(TPartida &partida, int numeroDeJugada)
{
    // jugadas contiguas al comienzo:
    while (partida != NULL && numeroTJugada(partida->jugada) == numeroDeJugada)
    {
        TPartida borrar = partida;
        partida = partida->sig;
        liberarTJugada(borrar->jugada);
        delete borrar;
    }

    if (partida == NULL)
        return;

    // jugadas intermedias o finales:
    TPartida aux = partida;
    while (aux->sig != NULL)
    {
        if (numeroTJugada(aux->sig->jugada) != numeroDeJugada)
            aux = aux->sig;
        else
        {
            TPartida borrar = aux->sig;
            aux->sig = borrar->sig;
            liberarTJugada(borrar->jugada);
            delete borrar;
        }
    }
}
