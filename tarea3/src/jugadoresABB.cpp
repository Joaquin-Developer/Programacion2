#include "../include/jugadoresABB.h"
#include "../include/colaJugadoresABB.h"
#include "../include/pilaJugador.h"

struct rep_jugadoresABB
{
    TJugador jugador;
    TJugadoresABB izq;
    TJugadoresABB der;
};

TJugadoresABB crearTJugadoresABB()
{
    return NULL;
}

bool esVacioTJugadoresABB(TJugadoresABB jugadoresABB)
{
    return jugadoresABB == NULL;
}

void insertarTJugadoresABB(TJugadoresABB &jugadoresABB, TJugador jugador)
{
    // caso base - jugadoresABB es null, creo un rep_jugadoresABB
    if (jugadoresABB == NULL)
    {
        jugadoresABB = new rep_jugadoresABB;
        jugadoresABB->jugador = jugador;
        jugadoresABB->der = jugadoresABB->izq = NULL;
        return;
    }
    // recursivamente voy iterando el arbol binario:

    if (idTJugador(jugador) >= idTJugador(jugadoresABB->jugador))
    {
        // si el id del jugador a insertar es mayor al del nodo, inserto sobre la derecha
        insertarTJugadoresABB(jugadoresABB->der, jugador);
    }
    else
    {
        // si no, inserto sobre la izquierda
        insertarTJugadoresABB(jugadoresABB->izq, jugador);
    }
}

void liberarNodoABB(TJugadoresABB &jugadores)
{
    liberarTJugador(jugadores->jugador);
    delete jugadores;
    jugadores = NULL;
}

void liberarTJugadoresABB(TJugadoresABB &jugadoresABB)
{
    if (jugadoresABB == NULL)
        return;

    liberarTJugadoresABB(jugadoresABB->izq);
    liberarTJugadoresABB(jugadoresABB->der);
    liberarNodoABB(jugadoresABB);
}

void imprimirTJugadoresABB(TJugadoresABB jugadoresABB)
{
    if (jugadoresABB == NULL)
        return;

    imprimirTJugadoresABB(jugadoresABB->izq);
    imprimirTJugador(jugadoresABB->jugador);
    imprimirTJugadoresABB(jugadoresABB->der);
}

nat cantidadTJugadoresABB(TJugadoresABB jugadoresABB)
{
    if (jugadoresABB == NULL)
        return 0;
    return 1 + cantidadTJugadoresABB(jugadoresABB->izq) + cantidadTJugadoresABB(jugadoresABB->der);
}

TJugador maxIdJugador(TJugadoresABB jugadoresABB)
{
    if (jugadoresABB == NULL)
        return NULL;

    while (jugadoresABB->der != NULL)
        jugadoresABB = jugadoresABB->der;

    return jugadoresABB->jugador;
}

void removerTJugadoresABB(TJugadoresABB &jugadoresABB, nat id)
{
    if (jugadoresABB != NULL)
    {
        if (id < idTJugador(jugadoresABB->jugador))
        {
            // El id a remover es menor, buscar en el subárbol izquierdo
            removerTJugadoresABB(jugadoresABB->izq, id);
        }
        else
        {
            if (id > idTJugador(jugadoresABB->jugador))
            {
                // El id a remover es mayor, buscar en el subárbol derecho
                removerTJugadoresABB(jugadoresABB->der, id);
            }
            else
            {
                // Se encontró el jugador a eliminar
                if (jugadoresABB->izq == NULL && jugadoresABB->der == NULL)
                {
                    // caso 1: el nodo es una hoja, se elimina
                    liberarNodoABB(jugadoresABB);
                    // liberarTJugador(jugadoresABB->jugador);
                    // delete jugadoresABB;
                }
                else
                {
                    if (jugadoresABB->izq == NULL)
                    {
                        // caso 2: el nodo tiene solo un hijo derecho
                        TJugadoresABB aux = jugadoresABB;
                        jugadoresABB = jugadoresABB->der;
                        liberarNodoABB(aux);
                    }
                    else
                    {
                        if (jugadoresABB->der == NULL)
                        {
                            // caso 3: el nodo tiene solo un hijo izquierdo
                            TJugadoresABB aux = jugadoresABB;
                            jugadoresABB = jugadoresABB->izq;
                            liberarNodoABB(aux);
                        }
                        else
                        {
                            // caso 4
                            // encontrar el nodo con el ID máximo en el subárbol izquierdo
                            // y reemplazar el contenido del nodo actual con el contenido del nodo máximo encontrado
                            liberarTJugador(jugadoresABB->jugador);
                            jugadoresABB->jugador = copiarTJugador(maxIdJugador(jugadoresABB->izq));
                            // eliminar el nodo máximo del subárbol izquierdo
                            removerTJugadoresABB(jugadoresABB->izq, idTJugador(jugadoresABB->jugador));
                        }
                    }
                }
            }
        }
    }
}

bool estaTJugadoresABB(TJugadoresABB jugadoresABB, nat id)
{
    if (jugadoresABB == NULL)
        return false;

    if (idTJugador(jugadoresABB->jugador) == id)
        return true;

    if (idTJugador(jugadoresABB->jugador) > id)
        return estaTJugadoresABB(jugadoresABB->izq, id);
    else
        return estaTJugadoresABB(jugadoresABB->der, id);
}

TJugador obtenerDeTJugadoresABB(TJugadoresABB jugadoresABB, nat id)
{
    if (jugadoresABB == NULL)
        return NULL;

    if (idTJugador(jugadoresABB->jugador) == id)
        return jugadoresABB->jugador;

    if (idTJugador(jugadoresABB->jugador) > id)
        return obtenerDeTJugadoresABB(jugadoresABB->izq, id);
    else
        return obtenerDeTJugadoresABB(jugadoresABB->der, id);
}

nat alturaTJugadoresABB(TJugadoresABB jugadoresABB)
{
    if (jugadoresABB == NULL)
        return 0;

    nat alturaIzq = alturaTJugadoresABB(jugadoresABB->izq);
    nat alturaDer = alturaTJugadoresABB(jugadoresABB->der);
    nat maximaAlturaSubarboles;

    if (alturaIzq > alturaDer)
        maximaAlturaSubarboles = alturaIzq;
    else
        maximaAlturaSubarboles = alturaDer;

    return 1 + maximaAlturaSubarboles;
}

bool esPerfectoTJugadoresABB(TJugadoresABB jugadoresABB)
{
    if (jugadoresABB == NULL)
        return true; // arbol vacio se considera perfecto

    // altura de los subarboles izquierdo y derecho
    nat alturaIzq = alturaTJugadoresABB(jugadoresABB->izq);
    nat alturaDer = alturaTJugadoresABB(jugadoresABB->der);

    if (alturaIzq != alturaDer)
        return false;

    // verifica si los subarboles izquierdo y derecho tambien son perfectos:
    return esPerfectoTJugadoresABB(jugadoresABB->izq) && esPerfectoTJugadoresABB(jugadoresABB->der);
}

TJugadoresABB mayoresTJugadoresABB(TJugadoresABB jugadoresABB, nat edad)
{
    TJugadoresABB resultado;

    if (esVacioTJugadoresABB(jugadoresABB))
        resultado = crearTJugadoresABB();
    else
    {
        TJugadoresABB mayoresIzq = mayoresTJugadoresABB(jugadoresABB->izq, edad);
        TJugadoresABB mayoresDer = mayoresTJugadoresABB(jugadoresABB->der, edad);

        if (edadTJugador(jugadoresABB->jugador) > edad)
        {
            resultado = new rep_jugadoresABB;
            resultado->jugador = copiarTJugador(jugadoresABB->jugador);
            resultado->izq = mayoresIzq;
            resultado->der = mayoresDer;
        }
        else if (esVacioTJugadoresABB(mayoresIzq))
            resultado = mayoresDer;

        else if (esVacioTJugadoresABB(mayoresDer))
            resultado = mayoresIzq;

        else
        {
            resultado = new rep_jugadoresABB;
            resultado->der = mayoresDer;
            resultado->jugador = copiarTJugador(maxIdJugador(mayoresIzq));
            removerTJugadoresABB(mayoresIzq, idTJugador(resultado->jugador));
            resultado->izq = mayoresIzq;
        }
    }

    return resultado;
}

///////////////////////////////////
////// FIN CÓDIGO TAREA 2 //////
///////////////////////////////////

///////////////////////////////////////////////////////////////////////////
/////////////  NUEVAS FUNCIONES  //////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////

nat amplitudTJugadoresABB(TJugadoresABB t)
{
    if (t == NULL)
        return 0;

    nat amplitud = 1;

    TColaJugadoresABB cola = crearTColaJugadoresABB();
    encolarEnTColaJugadoresABB(t, cola);

    while (cantidadEnTColaJugadoresABB(cola) > 0)
    {
        nat amplitudNivelActual = cantidadEnTColaJugadoresABB(cola);

        if (amplitudNivelActual > amplitud)
            amplitud = amplitudNivelActual;

        // desencolo y encolo sub-nodos tantas veces como elementos tenga en la queue
        for (nat i = 1; i <= amplitudNivelActual; i++)
        {
            TJugadoresABB nodo = frenteDeTColaJugadoresABB(cola);

            if (nodo->izq != NULL)
                encolarEnTColaJugadoresABB(nodo->izq, cola);

            if (nodo->der != NULL)
                encolarEnTColaJugadoresABB(nodo->der, cola);

            desencolarDeTColaJugadoresABB(cola);
        }
    }

    liberarTColaJugadoresABB(cola);

    return amplitud;
}

// Función que transforma el árbol en una pila de jugadores de tipo TJugador, donde los jugadores están ordenadas como
// en una recorrida por niveles del árbol.
// Es decir, en la lista primero deben estar los nodos del nivel 1 (la raiz), luego los del nivel 2, etc.
// El árbol no se debe modificar y los elementos de la pila no comparten memoria con el árbol original.
// *REV* La funcion es O(n*m) peor caso, siendo n la cantidad de jugadores en el árbol binario y m la cantidad de
// eventos de la agenda con mas eventos entre todas las personas del árbol.

TPilaJugador serializarTJugadoresABB(TJugadoresABB t)
{
    TPilaJugador pila = crearTPilaJugador();

    if (t == NULL)
        return pila;

    TColaJugadoresABB cola = crearTColaJugadoresABB();
    encolarEnTColaJugadoresABB(t, cola);

    while (cantidadEnTColaJugadoresABB(cola) > 0)
    {
        nat amplitudNivelActual = cantidadEnTColaJugadoresABB(cola);

        // desencolo y encolo sub-nodos tantas veces como elementos tenga en la queue
        for (nat i = 1; i <= amplitudNivelActual; i++)
        {
            TJugadoresABB nodo = frenteDeTColaJugadoresABB(cola);
            apilarEnTPilaJugador(pila, nodo->jugador);

            if (nodo->izq != NULL)
                encolarEnTColaJugadoresABB(nodo->izq, cola);

            if (nodo->der != NULL)
                encolarEnTColaJugadoresABB(nodo->der, cola);

            desencolarDeTColaJugadoresABB(cola);
        }
    }

    liberarTColaJugadoresABB(cola);

    // invierto la pila
    TPilaJugador pilaInvertida = crearTPilaJugador();

    while (cantidadEnTPilaJugador(pila) > 0)
    {
        TJugador nodo = cimaDeTPilaJugador(pila);
        apilarEnTPilaJugador(pilaInvertida, nodo);
        desapilarDeTPilaJugador(pila);
    }

    liberarTPilaJugador(pila);
    return pilaInvertida;
}

TJugadoresABB deserializarTJugadoresABB(TPilaJugador &p)
{
    return NULL;
}

///////////////////////////////////////////////////////////////////////////
/////////////  FIN NUEVAS FUNCIONES  //////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
