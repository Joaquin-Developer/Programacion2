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

    while (i < cantidadEnCadena(cad) && !estaEnCadena)
    {
        if (natInfo((*cad).lista[i]) == natural)
            estaEnCadena = true;
        i++;
    }
    return estaEnCadena;
}

TCadena insertarAlInicio(nat natural, double real, TCadena cad)
{
    // creo el Tinfo a insertar:
    TInfo infoInsertar = crearInfo(natural, real);
    // aumento tamaño:
    (*cad).longitud++;

    for (nat i = cantidadEnCadena(cad); i > 0; i--)
        (*cad).lista[i] = (*cad).lista[i - 1];

    (*cad).lista[0] = infoInsertar;

    return cad;
}

TInfo infoCadena(nat natural, TCadena cad)
{
    TInfo tinfo = NULL;
    nat i = 0;

    while (i < cantidadEnCadena(cad) && tinfo == NULL)
    {
        if (natInfo((*cad).lista[i]) == natural)
            tinfo = (*cad).lista[i];
        i++;
    }

    return tinfo;
}

TCadena removerDeCadena(nat natural, TCadena cad)
{
    int indiceBorrar = -1;
    nat cantidad = cantidadEnCadena(cad);

    nat i = 0;
    while (i < cantidad && indiceBorrar != -1)
    {
        if (natInfo((*cad).lista[i]) == natural)
            indiceBorrar = i;
        i++;
    }

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
