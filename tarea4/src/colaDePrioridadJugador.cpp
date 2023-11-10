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

  // si solo hay 1 o ningun elemento, no debo invertir nada
  if (cp->cantidad <= 1)
    return;

  nat i = 1;
  nat j = cp->cantidad;

  while (i < j)
  {
    TJugador aux = cp->heapJugadores[i];
    cp->heapJugadores[i] = cp->heapJugadores[j];
    cp->heapJugadores[j] = aux;
    i++;
    j--;
  }
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
  while (pos > 1 && edadTJugador(cp->heapJugadores[pos / 2]) >= edadTJugador(cp->heapJugadores[pos]))
  {
    TJugador aux = cp->heapJugadores[pos];
    cp->heapJugadores[pos] = cp->heapJugadores[pos / 2];
    cp->heapJugadores[pos / 2] = aux;
    pos = pos / 2;
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
  nat indiceIzq = 2 * pos;
  nat indiceDer = 2 * pos + 1;
  nat min = pos;

  if (indiceIzq <= cp->cantidad && edadTJugador(cp->heapJugadores[indiceIzq]) < edadTJugador(cp->heapJugadores[pos]))
    min = indiceIzq;

  if (indiceDer <= cp->cantidad && edadTJugador(cp->heapJugadores[indiceDer]) < edadTJugador(cp->heapJugadores[indiceIzq]))
    min = indiceDer;

  if (min != pos)
  {
    TJugador aux = cp->heapJugadores[pos];
    cp->heapJugadores[pos] = cp->heapJugadores[min];
    cp->heapJugadores[min] = aux;
    filtradoDescendienteCP(min, cp);
  }
}

void eliminarPrioritario(TColaDePrioridadJugador &cp)
{
  if (estaVaciaCP(cp))
    return;

  cp->prioridades[idTJugador(cp->heapJugadores[1])] = 0;
  liberarTJugador(cp->heapJugadores[1]);

  // si era el unico elemento, no hago nada mas.
  if (cp->cantidad == 1)
  {
    // cp->heapJugadores[1] = NULL;   // ya se hace en liberarJugador
    cp->cantidad--;
    return;
  }

  // el del final del arbol pasa a ser la raiz
  nat indiceUltimo = cp->cantidad;
  cp->heapJugadores[1] = cp->heapJugadores[indiceUltimo];
  cp->heapJugadores[indiceUltimo] = NULL;
  cp->cantidad--;
  // luego, aplico filtrado descenciente
  filtradoDescendienteCP(1, cp);
}

bool estaEnCP(nat id, TColaDePrioridadJugador cp)
{
  return cp->prioridades[id] != 0;
}

nat prioridad(nat id, TColaDePrioridadJugador cp)
{
  return cp->prioridades[id];
}
