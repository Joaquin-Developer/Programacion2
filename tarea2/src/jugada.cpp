#include "../include/jugada.h"

// Define la estructura Jugada
struct rep_jugada
{
    int numero;
    Movimiento *movimientos;
};

// Crea una jugada con los valores dados
TJugada crearTJugada(int numero, Movimiento mov1, Movimiento mov2, Movimiento mov3, Movimiento mov4)
{
    TJugada jugada = new rep_jugada;
    jugada->numero = numero;
    jugada->movimientos = new Movimiento[4];
    jugada->movimientos[0] = mov1;
    jugada->movimientos[1] = mov2;
    jugada->movimientos[2] = mov3;
    jugada->movimientos[3] = mov4;
    return jugada;
}

// Función que retorna el numero de la jugada
int numeroTJugada(TJugada jugada)
{
    return jugada->numero;
}

// Función que retorna los movimientos de una jugada
Movimiento *movimientoTJugada(TJugada jugada)
{
    return jugada->movimientos;
}

// Devuelve true si y solo si la jugada tiene el movimiento mov en la posicion pos
bool tieneMovimientoEnPosTJugada(TJugada jugada, int pos, Movimiento mov)
{
    return jugada->movimientos[pos] == mov;
}

// Imprime la jugada
void imprimirTJugada(TJugada jugada)
{
    printf("Jugada: %i \n", numeroTJugada(jugada));
    Movimiento *movimientos = movimientoTJugada(jugada);

    printf("Movimientos: ");
    for (int i = 0; i < 4; i++)
        switch (movimientos[i])
        {
        case Derecha:
            printf("Derecha ");
            break;
        case Izquierda:
            printf("Izquierda ");
            break;
        case Abajo:
            printf("Abajo ");
            break;
        case Arriba:
            printf("Arriba ");
            break;
        }
    printf("\n");
}

// Libera la memoria asignada para un jugada
void liberarTJugada(TJugada &jugada)
{
    if (jugada != NULL)
    {
        delete[] jugada->movimientos;
        delete jugada;
        jugada = NULL;
    }
}

// Retorna una copia de la jugada
TJugada copiarTJugada(TJugada jugada)
{
    if (jugada == NULL)
        return NULL;

    Movimiento *movs = movimientoTJugada(jugada);
    return crearTJugada(numeroTJugada(jugada), movs[0], movs[1], movs[2], movs[3]);
}