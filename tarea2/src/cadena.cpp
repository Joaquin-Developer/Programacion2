/* 5124352 */

#include "../include/cadena.h"

struct Nodo
{
    TInfo info;
    Nodo *siguiente;
};

typedef struct Nodo *TNodo;

struct _rep_cadena
{
    Nodo *primero;
    Nodo *ultimo;
};

TCadena crearCadena()
{
    TCadena cadena = new _rep_cadena;
    cadena->primero = NULL;
    cadena->ultimo = NULL;
    return cadena;
}

void liberarCadena(TCadena cad)
{
    TNodo nodo;
    while (cad->primero != NULL)
    {
        nodo = cad->primero;
        cad->primero = cad->primero->siguiente;
        liberarInfo(nodo->info);
        delete nodo;
    }
    cad->primero = NULL; // esto es al pedo (?
    cad->ultimo = NULL;
    delete cad;
}

nat cantidadEnCadena(TCadena cad)
{
    nat cant = 0;
    TNodo aux = cad->primero;

    if (aux == NULL)
        cant = 0;
    else
    {
        do
        {
            cant++;
            aux = aux->siguiente;
        } while (aux != cad->ultimo);
    }

    return cant;
}

bool estaEnCadena(nat natural, TCadena cad)
{
    bool estaEnCadena = false;
    TNodo aux = cad->primero;

    do
    {
        if (natInfo(aux->info) == natural)
            estaEnCadena = true;
        aux = aux->siguiente;
    } while (aux != cad->ultimo && !estaEnCadena);

    return estaEnCadena;
}

TCadena insertarAlInicio(nat natural, double real, TCadena cad)
{
    TInfo nuevo = crearInfo(natural, real);
    TNodo nodo = new Nodo;
    nodo->info = nuevo;
    // nodo->siguiente = nodo;

    if (cad->primero == NULL)
    {
        cad->primero = nodo;
        cad->ultimo = nodo;
        nodo->siguiente = nodo;
    }
    else
    {
        // TNodo aux = cad->primero;
        nodo->siguiente = cad->primero;
        cad->primero = nodo;
        cad->ultimo->siguiente = nodo;
    }

    return cad;
}

TInfo infoCadena(nat natural, TCadena cad)
{
    TInfo info = NULL;
    TNodo aux = cad->primero;

    do
    {
        if (natInfo(aux->info) == natural)
            info = aux->info;
        aux = aux->siguiente;
    } while (aux != cad->ultimo && info == NULL);

    return info;
}

TInfo primeroEnCadena(TCadena cad)
{
    return cad->primero->info;
}

TCadena cadenaSiguiente(TCadena cad)
{
    TNodo prim = cad->primero;

    cad->primero = cad->primero->siguiente;
    cad->ultimo = prim;

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
        TNodo aux = cad->primero;
        do
        {
            imprimirInfo(aux->info);
            aux = aux->siguiente;
        } while (aux != cad->primero);
    }
    printf("\n");
}
