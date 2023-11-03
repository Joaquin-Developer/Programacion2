#include "../include/tablaJugadores.h"

struct rep_tablaJugadores
{
    TJugadoresLDE *tabla;
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
    tablaJugadores->tabla = new TJugadoresLDE[max];
    for (int i = 0; i < max; i++)
        tablaJugadores->tabla[i] = crearTJugadoresLDE();
    return tablaJugadores;
}

void liberarTTablaJugadores(TTablaJugadores &tabla)
{
    for (int i = 0; i < tabla->tope; i++)
        liberarTJugadoresLDE(tabla->tabla[i]);

    delete[] tabla->tabla;
    delete tabla;
    tabla = NULL;
}

void insertarJugadorEnTabla(TTablaJugadores &tabla, TJugador jugador, TFecha fecha)
{
    int indice = funcionDeDispersion(nombreTJugador(jugador)) % tabla->tope;
    insertarTJugadoresLDE(tabla->tabla[indice], jugador, fecha);
}

void eliminarJugadorDeTTablaJugadores(TTablaJugadores &tabla, const char nombre[100])
{
    int indice = funcionDeDispersion(nombre) % tabla->tope;
    eliminarJugadorConNombreTJugadoresLDE(tabla->tabla[indice], nombre);
}

bool perteneceATTablaJugadores(TTablaJugadores tabla, const char nombre[100])
{
    int indice = funcionDeDispersion(nombre) % tabla->tope;
    return estaJugadorConNombreEnTJugadoresLDE(tabla->tabla[indice], nombre);
}

TJugador obtenerJugadorDeTTablaJugadores(TTablaJugadores tabla, const char nombre[100])
{
    int indice = funcionDeDispersion(nombre) % tabla->tope;
    return obtenerJugadorConNombreTJugadoresLDE(tabla->tabla[indice], nombre);
}

void imprimirTTablaJugadores(TTablaJugadores tabla)
{
    for (int i = 0; i < tabla->tope; i++)
        imprimirMayorAMenorTJugadoresLDE(tabla->tabla[i]);
}