#include "../include/jugadoresLDE.h"

struct rep_nodo_jugadores;
typedef struct rep_nodo_jugadores *NDJugador;

struct rep_nodo_jugadores
{
    TFecha fecha;
    TJugador jugador;
    NDJugador ant;
    NDJugador sig;
};

// cabezal
struct rep_jugadoresLDE
{
    NDJugador primero;
    NDJugador ultimo;
    nat tamanio;
};

TJugadoresLDE crearTJugadoresLDE()
{
    TJugadoresLDE lista = new rep_jugadoresLDE;
    lista->primero = lista->ultimo = NULL;
    lista->tamanio = 0;
    return lista;
}

void insertarTJugadoresLDE(TJugadoresLDE &jugadores, TJugador &jugador, TFecha &fecha)
{
    NDJugador insertar = new rep_nodo_jugadores;
    insertar->fecha = fecha;
    insertar->jugador = jugador;
    insertar->ant = NULL;
    insertar->sig = NULL;

    // Caso 1 - Lista vacía
    if (jugadores->primero == NULL && jugadores->ultimo == NULL)
    {
        jugadores->primero = insertar;
        jugadores->ultimo = insertar;
        jugadores->tamanio = 1;
        return;
    }

    // Caso 2 - Lista con un elemento
    if (jugadores->primero == jugadores->ultimo)
    {
        // comparo la fecha de insertar con la fecha del único elemento en la lista.
        int comparacion = compararTFechas(insertar->fecha, jugadores->primero->fecha);

        if (comparacion == -1)
        {
            // Insertar al comienzo de la lista.
            insertar->sig = jugadores->primero;
            jugadores->primero->ant = insertar;
            jugadores->primero = insertar;
        }
        else
        {
            // Insertar al final de la lista.
            jugadores->ultimo->sig = insertar;
            insertar->ant = jugadores->ultimo;
            jugadores->ultimo = insertar;
        }
        jugadores->tamanio = 2;
        return;
    }

    // Caso 3 - Lista con más de un elemento
    NDJugador aux = jugadores->primero;

    // Comparar la fecha de insertar con la fecha del primer elemento.
    int comparacion = compararTFechas(insertar->fecha, aux->fecha);

    if (comparacion < 0)
    {
        // Insertar al comienzo de la lista.
        insertar->sig = aux;
        aux->ant = insertar;
        jugadores->primero = insertar;
        jugadores->tamanio++;
        return;
    }

    while (aux->sig != NULL)
    {
        if (compararTFechas(insertar->fecha, aux->sig->fecha) >= 0)
            aux = aux->sig; // Avanzar al siguiente nodo.
        else
        {
            // Insertar antes del nodo siguiente.
            insertar->sig = aux->sig;
            insertar->ant = aux;
            aux->sig->ant = insertar;
            aux->sig = insertar;
            jugadores->tamanio++;
            return;
        }
    }

    // Si llegamos aquí, insertar al final de la lista.
    jugadores->ultimo->sig = insertar;
    insertar->ant = jugadores->ultimo;
    jugadores->ultimo = insertar;
    jugadores->tamanio++;
}

void liberarNDJugador(NDJugador &nodo)
{
    liberarTFecha(nodo->fecha);
    liberarTJugador(nodo->jugador);
    delete nodo;
    nodo = NULL;
}

void liberarTJugadoresLDE(TJugadoresLDE &jugadoresLDE)
{
    NDJugador borrar;
    while (jugadoresLDE->primero != NULL)
    {
        borrar = jugadoresLDE->primero;
        jugadoresLDE->primero = jugadoresLDE->primero->sig;
        liberarNDJugador(borrar);
    }
    delete jugadoresLDE;
    jugadoresLDE = NULL;
}

void imprimirMayorAMenorTJugadoresLDE(TJugadoresLDE jugadores)
{
    // recorro lista de fin a principio
    NDJugador aux = jugadores->ultimo;

    while (aux != NULL)
    {
        imprimirTJugador(aux->jugador);
        imprimirTFecha(aux->fecha);
        aux = aux->ant;
    }
}

void imprimirMenorAMayorTJugadoresLDE(TJugadoresLDE jugadores)
{
    // recorro lista de principio a fin
    NDJugador aux = jugadores->primero;

    while (aux != NULL)
    {
        imprimirTJugador(aux->jugador);
        imprimirTFecha(aux->fecha);
        aux = aux->sig;
    }
}

nat cantidadTJugadoresLDE(TJugadoresLDE jugadores)
{
    return jugadores->tamanio;
}

void eliminarInicioTJugadoresLDE(TJugadoresLDE &jugadores)
{
}

void eliminarFinalTJugadoresLDE(TJugadoresLDE &jugadores)
{
}

bool estaEnTJugadoresLDE(TJugadoresLDE jugadores, nat id)
{
    return false;
}

TJugador obtenerTJugadorDeTJugadoresLDE(TJugadoresLDE jugadores, nat id)
{
    return NULL;
}

TFecha obtenerTFechaDeTJugadoresLDE(TJugadoresLDE jugadores, nat id)
{
    return NULL;
}

TJugadoresLDE obtenerSegunTFecha(TJugadoresLDE jugadores, TFecha fecha)
{
    return NULL;
}

TJugadoresLDE unirTJugadoresLDE(TJugadoresLDE &jugadores1, TJugadoresLDE &jugadores2)
{
    return NULL;
}