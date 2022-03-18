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
    if ((cantidadEnCadena(cad) < L))
    {
        (*cad).longitud++;
        for (nat i = 0; i < cantidadEnCadena(cad); i++)
        {
            (*cad).lista[i + 1] = (*cad).lista[i];
        }
        // Tinfo a insertar:
        TInfo info = crearInfo(natural, real);
        (*cad).lista[0] = info;
    }
    return cad;
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
    int indiceBorrar = -1;
    nat cantidad = cantidadEnCadena(cad);

    nat i = 0;
    while (i < cantidad || indiceBorrar != -1)
    {
        if (natInfo((*cad).lista[i]) == natural)
            indiceBorrar = i;
        i++;
    }

    // 1 2 3 4 5 6
    // i = 2
    // 1 2 4 5 6

    if (indiceBorrar != -1)
    {
        for (i = indiceBorrar; i < cantidad - 1; i++)
        {
            (*cad).lista[i] = (*cad).lista[i + 1];
        }
    }
    (*cad).longitud--;
    return cad;
}

void imprimirCadena(TCadena cad)
{
    nat cantidad = cantidadEnCadena(cad);

    if (cantidad != 0)
        for (nat i = 0; i < cantidad; i++)
            imprimirInfo((*cad).lista[i]);

    printf("\n");
}
