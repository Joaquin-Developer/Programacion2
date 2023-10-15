#include "../include/pilaJugador.h"

struct rep_nodo_pila
{
  TJugador jugador;
  rep_nodo_pila *siguiente;
};

typedef rep_nodo_pila *TNodoPila;

struct rep_pilaJugador
{
  nat cantidad;   // cantidad (length) de la Pila
  TNodoPila cima; // puntero al primer elemento de la pila
};

TPilaJugador crearTPilaJugador()
{
  TPilaJugador pila = new rep_pilaJugador;
  pila->cantidad = 0;
  pila->cima = NULL;
  return pila;
}

void liberarTPilaJugador(TPilaJugador &p)
{
  while (p->cantidad != 0)
  {
    TNodoPila borrar = p->cima;
    p->cima = p->cima->siguiente;
    p->cantidad--;
    liberarTJugador(borrar->jugador);
    delete borrar;
    borrar = NULL;
  }
  delete p;
  p = NULL;
}

nat cantidadEnTPilaJugador(TPilaJugador p)
{
  return p->cantidad;
}

void apilarEnTPilaJugador(TPilaJugador &p, TJugador jugador)
{
  TNodoPila insertar = new rep_nodo_pila;
  insertar->jugador = copiarTJugador(jugador);
  insertar->siguiente = p->cima;
  p->cima = insertar;
  p->cantidad++;
}

TJugador cimaDeTPilaJugador(TPilaJugador p)
{
  return p->cima->jugador;
}

void desapilarDeTPilaJugador(TPilaJugador &p)
{
  TNodoPila borrar = p->cima;
  p->cima = p->cima->siguiente;
  p->cantidad--;
  liberarTJugador(borrar->jugador);
  delete borrar;
  borrar = NULL;
}
