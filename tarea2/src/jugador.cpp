#include "../include/jugador.h"

struct rep_jugador
{
    nat id;
    nat edad;
    char pais[100];
    char nombre[100];
    TPartida partida;
};

TJugador crearTJugador(nat id, nat edad, const char pais[100], const char nombre[100], TPartida partida)
{
    TJugador jugador = new rep_jugador;
    jugador->id = id;
    jugador->edad = edad;
    strcpy(jugador->pais, pais);
    strcpy(jugador->nombre, nombre);
    jugador->partida = partida;
    return jugador;
}

void liberarTJugador(TJugador &jugador)
{
    liberarTPartida(jugador->partida);
    delete jugador;
    jugador = NULL;
}

void imprimirTJugador(TJugador jugador)
{
    printf("Jugador %i: %s, %s, %i años\n", jugador->id, jugador->nombre, jugador->pais, jugador->edad);
    imprimirTPartida(jugador->partida);
}

nat idTJugador(TJugador jugador)
{
    return 0;
}

nat edadTJugador(TJugador jugador)
{
    return 0;
}

char *nombreTJugador(TJugador jugador)
{
    return NULL;
}

char *paisTJugador(TJugador jugador)
{
    return NULL;
}

TPartida partidaTJugador(TJugador jugador)
{
    return NULL;
}

void agregarJugadaATJugador(TJugador &jugador, TJugada jugada)
{
}

void removerJugadaDeTJugador(TJugador &jugador, int numeroDeJugada)
{
}

bool estaEnPartidaDeTJugador(TJugador jugador, int numeroDeJugada)
{
    return false;
}

TJugada obtenerDePartidaDeTJugador(TJugador jugador, int numeroDeJugada)
{
    return NULL;
}

TJugador copiarTJugador(TJugador jugador)
{
    return NULL;
}
