/* 5124352 */

#include "../include/cadena.h"

struct Nodo
{
    TInfo info;
    _rep_cadena *siguiente;
};

struct _rep_cadena
{
    // TInfo info;
    // _rep_cadena *siguiente;
    Nodo *primero;
    Nodo *ultimo;
};

TCadena crearCadena()
{
    // TCadena cadena = NULL;
    // return cadena;
    TCadena cadena = new _rep_cadena;
    cadena->primero = NULL;
    cadena->ultimo = NULL;
    return cadena;
}

void liberarCadena(TCadena cad)
{
    if (cad != NULL)
    {
        TCadena aux;
        do
        {
            aux = cad;
            cad = cad->siguiente;
            delete aux;
        } while (cad->siguiente != cad);
    }
}

nat cantidadEnCadena(TCadena cad)
{
    TCadena aux = cad;
    nat cant = 0;

    do
    {
        cant++;
        aux = aux->siguiente;

    } while (aux != cad);

    return cant;
}

bool estaEnCadena(nat natural, TCadena cad)
{
    bool estaEnCadena = false;
    do
    {
        if (natInfo(cad->info) == natural)
            estaEnCadena = true;
    } while (cad->siguiente != cad && !estaEnCadena);

    return estaEnCadena;
}

TCadena insertarAlInicio(nat natural, double real, TCadena cad)
{
    TInfo nuevo = crearInfo(natural, real);
    TCadena nuevoCadena = crearCadena();
    nuevoCadena->info = nuevo;
    nuevoCadena->siguiente = cad;

    return cad;
}

TInfo infoCadena(nat natural, TCadena cad)
{
    return NULL;
}

TInfo primeroEnCadena(TCadena cad)
{
    return NULL;
}

TCadena cadenaSiguiente(TCadena cad)
{
    return NULL;
}

TCadena removerDeCadena(nat natural, TCadena cad)
{
    return NULL;
}

void imprimirCadena(TCadena cad)
{
}
