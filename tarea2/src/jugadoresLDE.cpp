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
        if (compararTFechas(insertar->fecha, jugadores->primero->fecha) == -1)
        {
            // si fecha_insertar es menor que fecha de elemento, inserto al comienzo de la lista.
            insertar->sig = jugadores->primero;
            jugadores->primero->ant = insertar;
            jugadores->primero = insertar;
        }
        else
        {
            // si fecha_insertar es mayor o igual, inserto al final de la lista.
            jugadores->ultimo->sig = insertar;
            insertar->ant = jugadores->ultimo;
            jugadores->ultimo = insertar;
        }
        jugadores->tamanio = 2;
        return;
    }

    // Caso 3 - Lista con más de un elemento
    NDJugador aux = jugadores->primero;

    // Comparar la fecha de insertar con la fecha del primer elemento:
    if (compararTFechas(insertar->fecha, aux->fecha) < 0)
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

// void eliminarInicioTJugadoresLDE(TJugadoresLDE &jugadores)
// {
//     if (jugadores->primero == NULL && jugadores->ultimo == NULL)
//         return;
//     NDJugador p = jugadores->primero;
//     jugadores->primero = p->sig;
//     jugadores->primero->ant = NULL;
//     liberarNDJugador(p);
//     jugadores->tamanio--;
// }

void eliminarFinalTJugadoresLDE(TJugadoresLDE &jugadores)
{
    if (jugadores->primero == NULL)
        return;

    NDJugador borrar = jugadores->primero;
    jugadores->primero = borrar->sig;
    if (jugadores->primero != NULL)
    {
        // Si todavía hay elementos en la lista, actualiza el puntero 'ant' del nuevo primero.
        jugadores->primero->ant = NULL;
    }

    // Libera la memoria del jugador y su partida
    liberarNDJugador(borrar);
    jugadores->tamanio--;

    if (jugadores->primero == NULL)
    {
        // La lista está vacía después de la eliminación, actualiza el último puntero.
        jugadores->ultimo = NULL;
    }
}

void eliminarInicioTJugadoresLDE(TJugadoresLDE &jugadores)
{
    if (jugadores->ultimo == NULL)
        return;

    NDJugador borrar = jugadores->ultimo;
    jugadores->ultimo = borrar->ant;
    if (jugadores->ultimo != NULL)
    {
        // Si todavía hay elementos en la lista, actualiza el puntero 'sig' del nuevo último.
        jugadores->ultimo->sig = NULL;
    }

    // Libera la memoria del jugador y su partida
    liberarNDJugador(borrar);
    jugadores->tamanio--;

    if (jugadores->ultimo == NULL)
    {
        // La lista está vacía después de la eliminación, actualiza el primer puntero.
        jugadores->primero = NULL;
    }
}

// void eliminarFinalTJugadoresLDE(TJugadoresLDE &jugadores)
// {
//     if (jugadores->primero == NULL && jugadores->ultimo == NULL)
//         return;
//     NDJugador p = jugadores->ultimo;
//     jugadores->ultimo = p->ant;
//     jugadores->ultimo->sig = NULL;
//     liberarNDJugador(p);
//     jugadores->tamanio--;
// }

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