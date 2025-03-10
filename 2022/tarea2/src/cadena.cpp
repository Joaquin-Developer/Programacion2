/* 5124352 */

#include "../include/cadena.h"

struct _rep_cadena
{
    TInfo info;
    _rep_cadena *anterior;
    _rep_cadena *siguiente;
};

TCadena crearCadena()
{
    return NULL;
}

void liberarCadena(TCadena cad)
{
    while (cad != NULL)
    {
        TCadena aux = cad;
        cad = cad->siguiente;
        liberarInfo(aux->info);
        delete aux;
    }
}

nat cantidadEnCadena(TCadena cad)
{
    if (cad == NULL)
        return 0;
    else
    {
        nat cant = 0;
        TCadena aux = cad;
        do
        {
            cant++;
            aux = aux->siguiente;
        } while (aux != cad);

        return cant;
    }
}

bool estaEnCadena(nat natural, TCadena cad)
{
    if (cad == NULL)
        return false;

    bool estaEnCadena = false;
    TCadena aux = cad;

    do
    {
        if (natInfo(aux->info) == natural)
            estaEnCadena = true;
        aux = aux->siguiente;
    } while (aux != cad && !estaEnCadena);

    return estaEnCadena;
}

TCadena insertarAlInicio(nat natural, double real, TCadena cad)
{
    TCadena cadenaNueva = new _rep_cadena;
    cadenaNueva->info = crearInfo(natural, real);

    if (cad == NULL)
    {
        cad = cadenaNueva;
        cadenaNueva->anterior = cadenaNueva;
        cadenaNueva->siguiente = cadenaNueva;
    }
    else
    {
        cadenaNueva->siguiente = cad;
        cadenaNueva->anterior = cad->anterior;
        cadenaNueva->siguiente->anterior = cadenaNueva;
        cadenaNueva->anterior->siguiente = cadenaNueva;
        *cad = *cadenaNueva;
    }

    return cad;
}

TInfo infoCadena(nat natural, TCadena cad)
{
    TInfo info = NULL;
    TCadena aux = cad;

    do
    {
        if (natInfo(aux->info) == natural)
            info = aux->info;
        aux = aux->siguiente;
    } while (aux != cad && info == NULL);

    return info;
}

TInfo primeroEnCadena(TCadena cad)
{
    return cad->info;
}

TCadena cadenaSiguiente(TCadena cad)
{
    cad = cad->siguiente;
    return cad;
}

TCadena removerDeCadena(nat natural, TCadena cad)
{
    // TNodo aux = cad->primero;
    // TNodo remover;
    // bool remover = false;
    // do
    // {
    //     if (natInfo(aux->info) == natural)
    //     {
    //         remover = aux;
    //         remover = true;
    //     }
    //     aux = aux->siguiente;
    // } while (aux->siguiente != cad->primero && !remover);

    return cad;
}

void imprimirCadena(TCadena cad)
{
    if (cantidadEnCadena(cad) > 0)
    {
        TCadena aux = cad;
        do
        {
            imprimirInfo((*aux).info);
            aux = aux->siguiente;
        } while (aux != cad);
    }
    printf("\n");
}
