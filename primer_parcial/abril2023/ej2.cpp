#include <stdio.h>

struct nodoABB
{
    float dato;
    nodoABB *izq, *der;
};
typedef nodoABB *ABB;

typedef unsigned int nat;

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

// calcula la altura de un arbol t
nat alturaABB(ABB t)
{
    if (t == NULL)
        return 0;

    nat alturaIzq = 1 + alturaABB(t->izq);
    nat alturaDer = 1 + alturaABB(t->der);
    // devuelvo la altura mayor entre la alturaIzq y alturaDer
    return alturaIzq >= alturaDer ? alturaIzq : alturaDer;
}

// crea una copia del arbol t
// retorna un nuevo arbol, que no comparte memoria con el arbol original
ABB copiar(ABB t)
{
    if (t == NULL)
        return NULL;

    ABB copia = new nodoABB;
    copia->dato = t->dato;
    copia->izq = copiar(t->izq);
    copia->der = copiar(t->der);
    return copia;
}

int main()
{
    return 0;
}