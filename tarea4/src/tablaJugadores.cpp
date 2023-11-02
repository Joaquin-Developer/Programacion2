#include "../include/tablaJugadores.h"

struct rep_nodo_jugador;
typedef struct rep_nodo_jugador *NDJugador;

struct rep_nodo_jugador
{
    TFecha fecha;
    TJugador jugador;
    NDJugador sig;
};

struct rep_tablaJugadores
{
    NDJugador *tabla;
    int tope;
};

nat funcionDeDispersion(const char nombre[100])
{
    nat res = 0;
    int i = 0;
    while (i < 100 && nombre[i] != '\0')
    {
        res += int(nombre[i]);
        i++;
    }
    return res;
}

TTablaJugadores crearTTablaJugadores(int max)
{
    TTablaJugadores tablaJugadores = new rep_tablaJugadores;
    tablaJugadores->tope = max;
    tablaJugadores->tabla = new NDJugador[max];
    for (int i = 0; i < max; i++)
        tablaJugadores->tabla[i] = NULL;
    return tablaJugadores;
}

void liberarTTablaJugadores(TTablaJugadores &tabla)
{
    for (int i = 0; i < tabla->tope; i++)
    {
        while (tabla->tabla[i] != NULL)
        {
            NDJugador borrar = tabla->tabla[i];
            liberarTFecha(borrar->fecha);
            liberarTJugador(borrar->jugador);
            tabla->tabla[i] = borrar->sig;
            delete borrar;
        }
    }
    delete[] tabla->tabla;
    delete tabla;
    tabla = NULL;
}

void insertarJugadorEnTabla(TTablaJugadores &tabla, TJugador jugador, TFecha fecha)
{
    int indice = funcionDeDispersion(nombreTJugador(jugador)) % tabla->tope;

    // nodo a insertar:
    NDJugador insertar = new rep_nodo_jugador;
    insertar->jugador = jugador;
    insertar->fecha = fecha;

    // si la lista es nula, inserto al comienzo.
    if (tabla->tabla[indice] == NULL)
    {
        insertar->sig = NULL;
        tabla->tabla[indice] = insertar;
    }
    else
    {
        // sis no, inserto ordenado por fecha
    }
}

void eliminarJugadorDeTTablaJugadores(TTablaJugadores &tabla, const char nombre[100])
{
}

bool perteneceATTablaJugadores(TTablaJugadores tabla, const char nombre[100])
{
    return false;
}

TJugador obtenerJugadorDeTTablaJugadores(TTablaJugadores tabla, const char nombre[100])
{
    return NULL;
}

void imprimirTTablaJugadores(TTablaJugadores tabla)
{
}