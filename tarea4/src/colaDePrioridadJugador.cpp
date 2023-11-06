/*
  Módulo de implementación de `TColaDePrioridadJugador`.


  Laboratorio de Programación 2.
  InCo-FIng-UDELAR
 */

#include "../include/colaDePrioridadJugador.h"
#include "../include/utils.h"

#include <assert.h>
// #include <stdlib.h>
// #include <string.h>

struct rep_colaDePrioridadJugador
{
  TJugador *heapJugadores;
  nat *prioridades;
  nat cantidad;
  nat tope;
};

TColaDePrioridadJugador crearCP(nat N)
{
  TColaDePrioridadJugador colaPrioridad = new rep_colaDePrioridadJugador;
  colaPrioridad->tope = N;
  colaPrioridad->cantidad = 0;
  // en ambos arreglos, no se usa la posicion 0
  colaPrioridad->heapJugadores = new TJugador[N + 1];
  colaPrioridad->prioridades = new nat[N + 1];

  for (int i = 0; i <= N; i++)
  {
    colaPrioridad->heapJugadores[i] = NULL;
    colaPrioridad->prioridades[i] = 0;
  }

  return colaPrioridad;
}

void invertirPrioridad(TColaDePrioridadJugador &cp)
{
}

void liberarCP(TColaDePrioridadJugador &cp)
{
}

void insertarEnCP(TJugador jugador, TColaDePrioridadJugador &cp)
{
}

bool estaVaciaCP(TColaDePrioridadJugador cp)
{
  if (cp == NULL)
    return true;
  return cp->cantidad == 0;
}

TJugador prioritario(TColaDePrioridadJugador cp)
{
  return cp->heapJugadores[1];
}

void eliminarPrioritario(TColaDePrioridadJugador &cp)
{
}

bool estaEnCP(nat id, TColaDePrioridadJugador cp)
{
  return cp->prioridades[id] != 0;
}

nat prioridad(nat id, TColaDePrioridadJugador cp)
{
  return cp->prioridades[id];
}
