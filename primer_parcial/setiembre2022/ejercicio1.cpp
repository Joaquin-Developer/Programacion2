#include <stdio.h>

typedef unsigned int nat;

struct nodoLista
{
    int dato;
    nodoLista *sig;
};

typedef nodoLista *Lista;

/*
dadas dos listas ordenadas en forma ascendente (de menor a mayor) de enteros, C1 y C2, y sin elementos
repetidos que representan a dos conjuntos, retorne una nueva lista ordenada en forma descendente (de mayor a
menor) y sin elementos repetidos que represente al conjunto C1_Interseccion_C2. Esto es, el conjunto formado por los
elementos que están en C1 y en C2. Notar que que si C1 o C2 son vacías (NULL), el resultado debe ser NULL.
Tener en cuenta que:
- La nueva lista no deberá compartir registros de memoria con las listas parámetros.
- Se requiere que esta función recorra a lo sumo una vez cada lista parámetro y que en la lista resultante
los elementos se vayan agregando eficientemente, sin recorrerla cada vez.
- No se permite definir funciones o procedimientos auxiliares, ni otras estructuras de datos diferentes
(como arreglos/vectores) para implementar interseccion.
*/
Lista interseccion(Lista c1, Lista c2)
{
    if (c1 == NULL || c2 == NULL)
        return NULL;

    Lista result = NULL;

    while (c1 != NULL && c2 != NULL)
    {
        if (c1->dato == c2->dato)
        {
            Lista nodo = new nodoLista;
            nodo->dato = c1->dato;
            // inserto al comienzo, para que quede ordenado descendiente.
            nodo->sig = result;
            result = nodo;
            c1 = c1->sig;
            c2 = c2->sig;
        }
        else if (c1->dato < c2->dato)
            c1 = c1->sig;
        else
            c2 = c2->sig;
    }
    return result;
}

int main()
{
    return 0;
}