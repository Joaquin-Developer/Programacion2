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
    if (jugadoresABB == NULL)
        return NULL;

    while (jugadoresABB->der != NULL)
        jugadoresABB = jugadoresABB->der;

    return jugadoresABB->jugador;
}

void removerTJugadoresABB(TJugadoresABB &jugadoresABB, nat id)
{
    if (jugadoresABB == NULL)
        return;

    if (id < idTJugador(jugadoresABB->jugador))
    {
        // El id a remover es menor, buscar en el subárbol izquierdo
        removerTJugadoresABB(jugadoresABB->izq, id);
    }
    else if (id > idTJugador(jugadoresABB->jugador))
    {
        // El id a remover es mayor, buscar en el subárbol derecho
        removerTJugadoresABB(jugadoresABB->der, id);
    }
    else
    {
        // Se encontró el jugador a eliminar
        if (jugadoresABB->izq == NULL && jugadoresABB->der == NULL)
        {
            // Caso 1: El nodo es una hoja, simplemente eliminarlo
            liberarTJugador(jugadoresABB->jugador);
            delete jugadoresABB;
            jugadoresABB = NULL;
        }
        else if (jugadoresABB->izq == NULL)
        {
            // Caso 2: El nodo tiene solo un hijo derecho
            TJugadoresABB temp = jugadoresABB;
            jugadoresABB = jugadoresABB->der;
            liberarTJugador(temp->jugador);
            delete temp;
        }
        else if (jugadoresABB->der == NULL)
        {
            // Caso 2: El nodo tiene solo un hijo izquierdo
            TJugadoresABB temp = jugadoresABB;
            jugadoresABB = jugadoresABB->izq;
            liberarTJugador(temp->jugador);
            delete temp;
        }
        else
        {
            // Caso 3: El nodo tiene dos hijos
            // encontrar el nodo con el id máximo en el subárbol izquierdo:
            TJugador maxIzq = maxIdJugador(jugadoresABB->izq);
            // Reemplazar el contenido del nodo actual con el contenido del nodo máximo encontrado:
            jugadoresABB->jugador = maxIzq;
            // eliminar el nodo máximo del subárbol izquierdo:
            removerTJugadoresABB(jugadoresABB->izq, idTJugador(maxIzq));
        }
    }
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