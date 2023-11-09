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
  bool prioridadInvertida;
};

TColaDePrioridadJugador crearCP(nat N)
{
  TColaDePrioridadJugador colaPrioridad = new rep_colaDePrioridadJugador;
  colaPrioridad->tope = N;
  colaPrioridad->cantidad = 0;
  // en ambos arreglos, no se usa la posicion 0
  colaPrioridad->heapJugadores = new TJugador[N + 1];
  colaPrioridad->prioridades = new nat[N + 1];
  colaPrioridad->prioridadInvertida = false;

  for (nat i = 0; i <= N; i++)
  {
    colaPrioridad->heapJugadores[i] = NULL;
    colaPrioridad->prioridades[i] = 0;
  }

  return colaPrioridad;
}

void invertirPrioridad(TColaDePrioridadJugador &cp)
{
  cp->prioridadInvertida = !cp->prioridadInvertida;
  // seguir...
}

void liberarCP(TColaDePrioridadJugador &cp)
{
  if (cp == NULL)
    return;

  int i = 1;
  while (cp->cantidad > 0)
  {
    liberarTJugador(cp->heapJugadores[i]);
    cp->heapJugadores[i] = NULL;
    cp->cantidad--;
    i++;
  }

  delete[] cp->heapJugadores;
  delete[] cp->prioridades;
  delete cp;
  cp = NULL;
}

// funcion auxiliar
void filtradoAscendienteCP(nat pos, TColaDePrioridadJugador &cp)
{
  if (pos > 1 && edadTJugador(cp->heapJugadores[pos / 2]) >= edadTJugador(cp->heapJugadores[pos]))
  {
    TJugador aux = cp->heapJugadores[pos];
    cp->heapJugadores[pos] = cp->heapJugadores[pos / 2];
    cp->heapJugadores[pos / 2] = aux;
    filtradoAscendienteCP(pos / 2, cp);
  }
}

void insertarEnCP(TJugador jugador, TColaDePrioridadJugador &cp)
{
  cp->heapJugadores[cp->cantidad + 1] = jugador; // usar copiarTJugador(jugador) ??
  cp->prioridades[idTJugador(jugador)] = edadTJugador(jugador);
  cp->cantidad++;

  if (cp->cantidad > 1)
    filtradoAscendienteCP(cp->cantidad, cp);
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

// funcion auxiliar
void filtradoDescendienteCP(nat pos, TColaDePrioridadJugador &cp)
{
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
