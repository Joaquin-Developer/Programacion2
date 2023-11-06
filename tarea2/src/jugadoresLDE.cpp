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

    NDJugador aux = jugadores->primero;

    if (aux == NULL)
    {
        jugadores->primero = insertar;
        jugadores->ultimo = insertar;
        jugadores->tamanio = 1;
        return;
    }

    while (aux->sig != NULL && compararTFechas(fecha, aux->fecha) == -1)
        aux = aux->sig;

    if (aux->sig == NULL && compararTFechas(fecha, aux->fecha) == -1)
    {
        aux->sig = insertar;
        insertar->ant = aux;
        jugadores->ultimo = insertar;
    }
    else if (aux->ant == NULL)
    {
        insertar->sig = aux;
        aux->ant = insertar;
        jugadores->primero = insertar;
    }
    else
    {
        insertar->sig = aux;
        insertar->ant = aux->ant;
        aux->ant->sig = insertar;
        aux->ant = insertar;
    }
    jugadores->tamanio = jugadores->tamanio + 1;
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
    // recorro lista de principio a fin
    NDJugador aux = jugadores->primero;

    while (aux != NULL)
    {
        imprimirTJugador(aux->jugador);
        imprimirTFecha(aux->fecha);
        aux = aux->sig;
    }
}

void imprimirMenorAMayorTJugadoresLDE(TJugadoresLDE jugadores)
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

nat cantidadTJugadoresLDE(TJugadoresLDE jugadores)
{
    return jugadores->tamanio;
}

void eliminarInicioTJugadoresLDE(TJugadoresLDE &jugadores)
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

void eliminarFinalTJugadoresLDE(TJugadoresLDE &jugadores)
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

bool estaEnTJugadoresLDE(TJugadoresLDE jugadores, nat id)
{
    NDJugador aux = jugadores->primero;
    bool encontrado = false;

    while (!encontrado && aux != NULL)
    {
        if (idTJugador(aux->jugador) == id)
            encontrado = true;
        aux = aux->sig;
    }
    return encontrado;
}

TJugador obtenerTJugadorDeTJugadoresLDE(TJugadoresLDE jugadores, nat id)
{
    TJugador jugador = NULL;
    NDJugador aux = jugadores->primero;

    while (jugador == NULL && aux != NULL)
    {
        if (idTJugador(aux->jugador) == id)
            jugador = aux->jugador;
        aux = aux->sig;
    }
    return jugador;
}

TFecha obtenerTFechaDeTJugadoresLDE(TJugadoresLDE jugadores, nat id)
{
    TFecha fecha = NULL;
    NDJugador aux = jugadores->primero;

    while (fecha == NULL && aux != NULL)
    {
        if (idTJugador(aux->jugador) == id)
            fecha = aux->fecha;
        aux = aux->sig;
    }
    return fecha;
}

// Función para obtener los jugadores en la lista de jugadores que tienen fecha igual al parametro "fecha"
// La lista resultado debe de respetar el orden de la lista original
// La lista resultado NO comparte memoria con la lista parametro
// Si no hay ningun jugador con esa fecha, se devuelve la lista vacia.
// La función es O(n*m) peor caso, donde n es la cantidad de jugadores en la lista y m es la cantidad de jugadas de la partida con mas jugadas entre todas las jugadores de la lista.

TJugadoresLDE obtenerSegunTFecha(TJugadoresLDE jugadores, TFecha fecha)
{
    TJugadoresLDE nuevaLista = crearTJugadoresLDE();
    NDJugador actual = jugadores->primero;

    while (actual != NULL)
    {
        if (compararTFechas(actual->fecha, fecha) == 0)
        {
            TJugador copiaJugador = copiarTJugador(actual->jugador);
            TFecha copiaFecha = copiarTFecha(fecha);
            insertarTJugadoresLDE(nuevaLista, copiaJugador, copiaFecha);
        }
        actual = actual->sig;
    }

    return nuevaLista;
}

TJugadoresLDE unirTJugadoresLDE(TJugadoresLDE &jugadores1, TJugadoresLDE &jugadores2)
{
    TJugadoresLDE nuevaLista = crearTJugadoresLDE();

    // se conectan los nodos de jugadores1 en la nueva lista
    nuevaLista->primero = jugadores1->primero;
    if (jugadores1->ultimo != NULL)
    {
        nuevaLista->ultimo = jugadores1->ultimo;
        jugadores1->ultimo->sig = NULL; // Desconecta jugadores1 de su último nodo
    }

    // Actualiza el tamaño de nuevaLista
    nuevaLista->tamanio = jugadores1->tamanio;

    // Libera la memoria de la lista jugadores1 sin duplicar el recorrido
    jugadores1->primero = NULL;
    jugadores1->ultimo = NULL;
    liberarTJugadoresLDE(jugadores1);

    // Combina los nodos de jugadores2 en la nueva lista resultado
    if (nuevaLista->ultimo != NULL)
    {
        nuevaLista->ultimo->sig = jugadores2->primero;
    }
    else
    {
        nuevaLista->primero = jugadores2->primero;
    }
    if (jugadores2->ultimo != NULL)
    {
        nuevaLista->ultimo = jugadores2->ultimo;
    }

    // Actualiza el tamaño de resultado
    nuevaLista->tamanio += jugadores2->tamanio;

    // Libera la memoria de la lista jugadores2 sin duplicar el recorrido
    jugadores2->primero = NULL;
    jugadores2->ultimo = NULL;
    liberarTJugadoresLDE(jugadores2);
    return nuevaLista;
}