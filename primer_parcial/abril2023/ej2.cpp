#include <stdio.h>

struct nodoABB
{
    float dato;
    nodoABB *izq, *der;
};
typedef nodoABB *ABB;

// dados un real x y un arbol binario de busqueda (ABB) t, elimine de t todos los
// elementos > x y retorne la cantidad de elementos borrados.
// El árbol resultante debe ser también binario de búsqueda. Si no hay elementos mayores que
// x en t (en particular si t es el árbol vacío, NULL), borrarMayores no tendrá efecto en t y el retorno será 0. La
// operación deberá evitar recorrer nodos innecesarios de t. No defina operaciones auxiliares para implementar borrarMayores
int borrarMayores(float, ABB &);

int borrarMayores(float x, ABB &t)
{
    if (t == NULL)
        return 0;
    int resultado = 0;

    if (t->dato > x)
    {
        resultado = 1 + borrarMayores(x, t->izq) + borrarMayores(x, t->der);
        ABB borrar = t;
        t = t->izq;
        delete borrar;
    }
    else
        resultado = borrarMayores(x, t->der);

    return resultado;
}

int main()
{
    return 0;
}