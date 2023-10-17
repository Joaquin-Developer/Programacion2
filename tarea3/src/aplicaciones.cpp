#include "../include/aplicaciones.h"

TPilaJugador menoresQueElResto(TJugadoresLDE lista)
{
    return NULL;
}

bool sumaPares(nat k, TConjuntoIds c)
{
    for (nat i = 1; i <= cantMaxTConjuntoIds(c); i++)
    {
        nat id1 = i;
        nat id2 = k - id1;

        if (id1 == id2)
            continue;

        if (perteneceTConjuntoIds(id1, c) && perteneceTConjuntoIds(id2, c))
            return true;
    }
    return false;
}