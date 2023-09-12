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
};

TJugadoresLDE crearTJugadoresLDE()
{
    TJugadoresLDE lista = new rep_jugadoresLDE;
    lista->primero = lista->ultimo = NULL;
    return lista;
}

void insertarTJugadoresLDE(TJugadoresLDE &jugadores, TJugador &jugador, TFecha &fecha)
{
    NDJugador insertar = new rep_nodo_jugadores;
    insertar->fecha = fecha;
    insertar->jugador = jugador;

    // caso 1 - LDE vacia
    if (jugadores->primero == NULL && jugadores->ultimo == NULL)
    {
        insertar->ant = NULL;
        insertar->sig = NULL;
        jugadores->primero = insertar;
        jugadores->ultimo = insertar;
        return;
    }

    // caso 2 - LDE con 1 elemento
    if (jugadores->primero == jugadores->ultimo)
    {
        // fecha insertar >= fecha primer elemento => inserto al comienzo de la lista
        if (compararTFechas(insertar->fecha, jugadores->primero->fecha) >= 0)
        {
            jugadores->primero = insertar;
            insertar->ant = NULL;
            insertar->sig = jugadores->ultimo;
            jugadores->ultimo->ant = insertar;
        }
        else
        {
            // si no, inserto al final de la lista
            jugadores->ultimo = insertar;
            insertar->sig = NULL;
            insertar->ant = jugadores->primero;
            jugadores->primero->sig = insertar;
        }
        return;
    }

    // caso 3 - Genérico (len(lista) > 1)

    NDJugador aux = jugadores->primero;

    while (aux->sig != NULL)
    {
    }
}

void liberarTJugadoresLDE(TJugadoresLDE &jugadoresLDE)
{
    NDJugador borrar;
    while (jugadoresLDE->primero != NULL)
    {
        borrar = jugadoresLDE->primero;
        jugadoresLDE->primero = jugadoresLDE->primero->sig;
        liberarTFecha(borrar->fecha);
        liberarTJugador(borrar->jugador);
        delete borrar;
    }
    delete jugadoresLDE;
    jugadoresLDE = NULL;
}

void imprimirMayorAMenorTJugadoresLDE(TJugadoresLDE jugadores)
{
    // recorro lista de fin a principio
    NDJugador aux = jugadores->primero;

    while (aux != NULL)
    {
        imprimirTJugador(aux->jugador);
        aux = aux->sig;
    }
}

void imprimirMenorAMayorTJugadoresLDE(TJugadoresLDE jugadores)
{
    // recorro lista de principio a fin
    NDJugador aux = jugadores->primero;

    while (aux != NULL)
    {
        imprimirTJugador(aux->jugador);
        aux = aux->ant;
    }
}

nat cantidadTJugadoresLDE(TJugadoresLDE jugadores)
{
    return 0;
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