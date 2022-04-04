/* 5124352 */

#include "../include/cadena.h"

// struct Nodo
// {
//     TInfo info;
//     Nodo *siguiente;
// };

struct _rep_cadena
{
    TInfo info;
    Nodo *siguiente;
    // Nodo primero;
    // Nodo ultimo;
};

TCadena crearCadena()
{
    // TCadena cadena = new _rep_cadena;
    // cadena->primero = NULL;
    // cadena->ultimo = NULL;
    TCadena cadena = NULL;
    return cadena;
}

void liberarCadena(TCadena cad)
{

    if (cad != NULL)
    {
        // TCadena primero = cad;
        // TCadena aux;

        // do
        // {
        //     aux = cad;
        //     cad = cad->siguiente;
        //     delete aux;

        // } while (aux->siguiente != primero);

        // delete cad;
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
    return false;
}

TCadena insertarAlInicio(nat natural, double real, TCadena cad)
{
    return NULL;
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
