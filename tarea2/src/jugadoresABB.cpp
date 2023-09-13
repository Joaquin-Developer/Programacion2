#include "../include/jugadoresABB.h"

struct rep_jugadoresABB
{
    TJugador jugador;
    TJugadoresABB izq;
    TJugadoresABB der;
};

TJugadoresABB crearTJugadoresABB()
{
    return NULL;
}

bool esVacioTJugadoresABB(TJugadoresABB jugadoresABB)
{
    return jugadoresABB == NULL;
}

void insertarTJugadoresABB(TJugadoresABB &jugadoresABB, TJugador jugador)
{
    // caso base - jugadoresABB es null, creo un rep_jugadoresABB
    if (jugadoresABB == NULL)
    {
        jugadoresABB = new rep_jugadoresABB;
        jugadoresABB->jugador = jugador;
        jugadoresABB->der = jugadoresABB->izq = NULL;
        return;
    }
    // recursivamente voy iterando el arbol binario:

    if (idTJugador(jugador) > idTJugador(jugadoresABB->jugador))
    {
        // si el id del jugador a insertar es mayor al del nodo, inserto sobre la derecha
        insertarTJugadoresABB(jugadoresABB->der, jugador);
    }
    else
    {
        // si no, inserto sobre la izquierda
        insertarTJugadoresABB(jugadoresABB->izq, jugador);
    }
}

void liberarTJugadoresABB(TJugadoresABB &jugadoresABB)
{
    if (jugadoresABB == NULL)
        return;

    liberarTJugadoresABB(jugadoresABB->izq);
    liberarTJugadoresABB(jugadoresABB->der);

    liberarTJugador(jugadoresABB->jugador);
    delete jugadoresABB;
    jugadoresABB = NULL;
}

void imprimirTJugadoresABB(TJugadoresABB jugadoresABB)
{
    if (jugadoresABB == NULL)
        return;

    imprimirTJugadoresABB(jugadoresABB->izq);
    imprimirTJugador(jugadoresABB->jugador);
    imprimirTJugadoresABB(jugadoresABB->der);
}

nat cantidadTJugadoresABB(TJugadoresABB jugadoresABB)
{
    if (jugadoresABB == NULL)
        return 0;
    return 1 + cantidadTJugadoresABB(jugadoresABB->izq) + cantidadTJugadoresABB(jugadoresABB->der);
}

TJugador maxIdJugador(TJugadoresABB jugadoresABB)
{
    return NULL;
}

void removerTJugadoresABB(TJugadoresABB &jugadoresABB, nat id)
{
}

bool estaTJugadoresABB(TJugadoresABB jugadoresABB, nat id)
{
    return false;
}

TJugador obtenerDeTJugadoresABB(TJugadoresABB jugadoresABB, nat id)
{
    return NULL;
}

nat alturaTJugadoresABB(TJugadoresABB jugadoresABB)
{
    return 0;
}

bool esPerfectoTJugadoresABB(TJugadoresABB jugadoresABB)
{
    return false;
}

TJugadoresABB mayoresTJugadoresABB(TJugadoresABB jugadoresABB, nat edad)
{
    return NULL;
}