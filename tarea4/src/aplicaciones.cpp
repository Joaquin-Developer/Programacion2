#include "../include/aplicaciones.h"
#include "../include/colaDePrioridadJugador.h"

/*
  Dada una tabla de jugadores 't' y un arreglo de nombres 'nombres' de
  longitud 'n', imprime en pantalla los datos de los jugadores en 'nombres'
  que están en 't', en orden ascendente según su edad (de menor a mayor).
  Se  asume que los IDs de los jugadores están acotados entre 1 y MAX_ID.
  El tiempo de ejecución en promedio es O(n*log n+ n*m), siendo 'n' la cantidad de nombres de los jugadores de la tabla
  y 'm' la maxima cantidad de jugadas que posea un jugador.
  Se debe utilizar una cola de prioridad auxiliar para resolver el problema.
 */
void listarEnOrden(TTablaJugadores t, char **nombres, nat n)
{
    TColaDePrioridadJugador cp = crearCP(MAX_ID);

    for (nat i = 0; i < n; i++)
    {
        char *nombre = nombres[i];
        if (perteneceATTablaJugadores(t, nombre))
            insertarEnCP(copiarTJugador(obtenerJugadorDeTTablaJugadores(t, nombre)), cp);
    }

    while (!estaVaciaCP(cp))
    {
        imprimirTJugador(prioritario(cp));
        eliminarPrioritario(cp);
    }
    liberarCP(cp);
}