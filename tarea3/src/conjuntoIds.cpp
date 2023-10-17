#include "../include/conjuntoIds.h"

struct rep_conjuntoIds
{
    nat *idJugadores;
    nat cardinal;
    nat cantidadMaxima;
};

TConjuntoIds crearTConjuntoIds(nat cantMax)
{
    TConjuntoIds conjunto = new rep_conjuntoIds;
    conjunto->idJugadores = new nat[cantMax];
    conjunto->cantidadMaxima = cantMax;

    for (nat i = 0; i < cantMax; i++)
        conjunto->idJugadores[i] = 0;

    conjunto->cardinal = 0;
    return conjunto;
};

bool esVacioTConjuntoIds(TConjuntoIds c)
{
    return c->cardinal == 0;
};

void insertarTConjuntoIds(nat id, TConjuntoIds &c)
{
    if (c != NULL && 0 < id && id <= c->cantidadMaxima)
    {
        c->idJugadores[id - 1] = 1;
        c->cardinal++;
    }
};

void borrarTConjuntoIds(nat id, TConjuntoIds &c)
{
    if (c != NULL && 0 < id && id <= c->cantidadMaxima)
    {
        c->idJugadores[id - 1] = 0;
        c->cardinal--;
    }
};

bool perteneceTConjuntoIds(nat id, TConjuntoIds c)
{
    if (c != NULL && 0 < id && id <= c->cantidadMaxima)
        return c->idJugadores[id - 1] == 1;
    return false;
};

nat cardinalTConjuntoIds(TConjuntoIds c)
{
    return c->cardinal;
};

nat cantMaxTConjuntoIds(TConjuntoIds c)
{
    return c->cantidadMaxima;
};

void imprimirTConjuntoIds(TConjuntoIds c)
{
    for (nat i = 0; i < c->cantidadMaxima; i++)
        if (c->idJugadores[i] == 1)
            printf("%i ", i + 1);
    printf("\n");
};

void liberarTConjuntoIds(TConjuntoIds &c)
{
    if (c != NULL)
    {
        delete[] c->idJugadores;
        delete c;
        c = NULL;
    }
};

TConjuntoIds unionTConjuntoIds(TConjuntoIds c1, TConjuntoIds c2)
{
    TConjuntoIds conjuntoUnion = crearTConjuntoIds(c1->cantidadMaxima);

    for (nat i = 1; i <= c1->cantidadMaxima; i++)
        if (perteneceTConjuntoIds(i, c1) || perteneceTConjuntoIds(i, c2))
            insertarTConjuntoIds(i, conjuntoUnion);

    return conjuntoUnion;
};

TConjuntoIds interseccionTConjuntoIds(TConjuntoIds c1, TConjuntoIds c2)
{
    return NULL;
};

TConjuntoIds diferenciaTConjuntoIds(TConjuntoIds c1, TConjuntoIds c2)
{
    return NULL;
};
