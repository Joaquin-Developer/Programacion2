/* 5124352 */

#include "../include/cadena.h"

// los elementos se mantienen entre 0 y cantidad - 1, incluidos
struct _rep_cadena
{
    nat longitud;
    TInfo lista[L];
};

TCadena crearCadena()
{
    TCadena cadena = new _rep_cadena;
    (*cadena).longitud = 0;
    return cadena;
}

/* en siguientes tareas
void liberarCadena(TCadena cad) {
}
*/

nat cantidadEnCadena(TCadena cad)
{
    return (*cad).longitud;
}

bool estaEnCadena(nat natural, TCadena cad)
{
    bool estaEnCadena = false;
    nat i = 0;

    while (i < cantidadEnCadena(cad) || estaEnCadena)
        if (natInfo((*cad).lista[i]) == natural)
            estaEnCadena = true;

    return estaEnCadena;
}

TCadena insertarAlInicio(nat natural, double real, TCadena cad)
{
    return NULL;
}

TInfo infoCadena(nat natural, TCadena cad)
{
    TInfo tinfo = NULL;
    nat i = 0;

    while (i < cantidadEnCadena(cad) || tinfo != NULL)
        if (natInfo((*cad).lista[i]) == natural)
            tinfo = (*cad).lista[i];

    return tinfo;
}

TCadena removerDeCadena(nat natural, TCadena cad)
{
    return NULL;
}

void imprimirCadena(TCadena cad)
{
    int cantidad = cantidadEnCadena(cad);

    if (cantidad != 0)
        for (int i = 0; i < cantidad; i++)
            printf(infoATexto((*cad).lista[i]));

    printf("\n");
}
