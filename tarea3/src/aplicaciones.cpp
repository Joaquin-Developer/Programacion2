#include "../include/aplicaciones.h"

TPilaJugador menoresQueElResto(TJugadoresLDE lista)
{
    if (lista == NULL || cantidadTJugadoresLDE(lista) == 0)
        return NULL;

    TPilaJugador pila = crearTPilaJugador();
    TJugador inicio = obtenerInicioDeTJugadoresLDE(lista);
    apilarEnTPilaJugador(pila, inicio);
    eliminarInicioTJugadoresLDE(lista);

    while (cantidadTJugadoresLDE(lista) > 0)
    {
        TJugador cimaPila = cimaDeTPilaJugador(pila);
        TJugador inicioLDE = obtenerInicioDeTJugadoresLDE(lista);

        if (edadTJugador(inicioLDE) < edadTJugador(cimaPila)) // desapilo
            desapilarDeTPilaJugador(pila);
        else
        {
            // apilo y borro primer elemento de LDE
            apilarEnTPilaJugador(pila, inicioLDE);
            eliminarInicioTJugadoresLDE(lista);
        }

        // si la pila quedo vacia, apilo y borro primer elem de LDE
        if (cantidadEnTPilaJugador(pila) == 0)
        {
            apilarEnTPilaJugador(pila, inicioLDE);
            eliminarInicioTJugadoresLDE(lista);
        }
    }
    // liberarTJugadoresLDE(lista);

    return pila;
}

bool sumaPares(nat k, TConjuntoIds c)
{
    for (nat i = 1; i <= cantMaxTConjuntoIds(c); i++)
    {
        nat id1 = i;
        nat id2 = k - id1;

        if (id1 != id2 && (perteneceTConjuntoIds(id1, c) && perteneceTConjuntoIds(id2, c)))
            return true;
    }
    return false;
}