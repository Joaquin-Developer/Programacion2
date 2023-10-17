#include "../include/colaJugadoresABB.h"
#include "../include/jugadoresLDE.h"

struct rep_nodo_cola
{
  TJugadoresABB jugadoresABB;
  rep_nodo_cola *siguiente;
};

typedef rep_nodo_cola *TNodoCola;

struct rep_colaJugadoresABB
{
  TNodoCola primero;
  TNodoCola ultimo;
  nat cantidad;
};

TColaJugadoresABB crearTColaJugadoresABB()
{
  TColaJugadoresABB cola = new rep_colaJugadoresABB;
  cola->primero = cola->ultimo = NULL;
  cola->cantidad = 0;
  return cola;
}

void liberarTColaJugadoresABB(TColaJugadoresABB &c)
{
  while (c->cantidad != 0)
  {
    TNodoCola borrar = c->primero;
    c->primero = c->primero->siguiente;
    c->cantidad--;
    delete borrar;
  }
  delete c;
  c = NULL;
}

nat cantidadEnTColaJugadoresABB(TColaJugadoresABB c)
{
  return c->cantidad;
}

void encolarEnTColaJugadoresABB(TJugadoresABB t, TColaJugadoresABB &c)
{
  TNodoCola nuevo = new rep_nodo_cola;
  nuevo->jugadoresABB = t;

  nuevo->siguiente = NULL;

  if (c->ultimo == NULL)
    c->primero = c->ultimo = nuevo;
  else
  {
    c->ultimo->siguiente = nuevo;
    c->ultimo = nuevo;
  }

  c->cantidad++;
}

TJugadoresABB frenteDeTColaJugadoresABB(TColaJugadoresABB c)
{
  return c->primero->jugadoresABB;
}

void desencolarDeTColaJugadoresABB(TColaJugadoresABB &c)
{
  TNodoCola borrar = c->primero;
  c->primero = c->primero->siguiente;
  c->cantidad--;
  delete borrar;
}
