/* 5124352 */

#include "../include/colCadenas.h"
#include "../include/cadena.h"

struct _rep_colCadenas
{
    TCadena lista[CANT_CADS];
};

TColCadenas crearColCadenas()
{
    TColCadenas col = new _rep_colCadenas;

    for (int i = 0; i < CANT_CADS; i++)
        (*col).lista[i] = crearCadena();

    return col;
}

/* en siguientes tareas
void liberarColCadenas(TColCadenas col) {
}
*/
nat cantidadColCadenas(nat pos, TColCadenas col)
{
    return cantidadEnCadena((*col).lista[pos]);
}

bool estaEnColCadenas(nat natural, nat pos, TColCadenas col)
{
    return estaEnCadena(natural, (*col).lista[pos]);
}

TColCadenas insertarEnColCadenas(nat natural, double real, nat pos, TColCadenas col)
{
    insertarAlInicio(natural, real, (*col).lista[pos]);
    return col;
}

TInfo infoEnColCadenas(nat natural, nat pos, TColCadenas col)
{
    return infoCadena(natural, (*col).lista[pos]);
}

TColCadenas removerDeColCadenas(nat natural, nat pos, TColCadenas col)
{
    removerDeCadena(natural, (*col).lista[pos]);
    return col;
}
