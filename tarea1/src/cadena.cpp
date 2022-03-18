/* 5124352 */

#include "../include/cadena.h"

// los elementos se mantienen entre 0 y cantidad - 1, incluidos
struct _rep_cadena
{
    // TInfo info;
    // _rep_cadena *siguiente;
    nat longitud;
    TInfo lista[L];
};

TCadena crearCadena()
{
    // TCadena cadena = new _rep_cadena;
    // cadena->info = NULL;
    // cadena->siguiente = NULL;
    // return cadena;
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
    // int cont = 0;
    // TCadena aux = cad;

    // while (aux != NULL)
    // {
    //     cont++; // incrementar en 1
    //     aux = aux->siguiente;
    // }

    // return cont;
}

bool estaEnCadena(nat natural, TCadena cad)
{
    bool estaEnCadena = false;
    nat i = 0;

    while (i < cantidadEnCadena(cad) || estaEnCadena)
        if (natInfo((*cad).lista[i]) == natural)
            estaEnCadena = true;
    return estaEnCadena;
    // bool estaEnCadena = false;
    // TCadena aux = cad;
    // while (aux != NULL || !estaEnCadena)
    // {
    //     if (natInfo(aux->info) == natural)
    //         estaEnCadena = true;
    //     aux = aux->siguiente;
    // }
    // return estaEnCadena;
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

    // // creo la nueva cadena:
    // TCadena cadena = crearCadena();
    // // creo el info, elemento de la cadena:
    // TInfo info = crearInfo(natural, real);
    // // asigno al campo info de cadena, el info que creé:
    // cadena->info = info;
    // // cadena auxiliar, con el primer elemento que había:
    // TCadena aux = cad;
    // // inserto:
    // cad = cadena;
    // cadena->siguiente = aux;
    // return cad;
}

TInfo infoCadena(nat natural, TCadena cad)
{
    // TCadena aux = cad;
    // TInfo info = NULL;

    // while (aux != NULL || info == NULL)
    // {
    //     if (natInfo(aux->info) == natural)
    //         info = aux->info;
    //     aux = aux->siguiente;
    // }

    // return info;

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
    // TCadena aux = cad;
    // TInfo info = NULL;

    // while (aux != NULL || info == NULL)
    // {
    //     if (natInfo(aux->info) == natural)
    //         info = aux->info;
    //     aux = aux->siguiente;
}

void imprimirCadena(TCadena cad)
{
    nat cantidad = cantidadEnCadena(cad);
    // TCadena aux = cad;

    // if (cantidadEnCadena(cad) != 0)
    // {
    //     while (aux != NULL)
    //     {
    //         printf("%s", infoATexto(cad->info));
    //         aux = aux->siguiente;
    //     }
    // }
    // printf("\n");

    if (cantidad != 0)
        for (nat i = 0; i < cantidad; i++)
            imprimirInfo((*cad).lista[i]);

    printf("\n");
}
