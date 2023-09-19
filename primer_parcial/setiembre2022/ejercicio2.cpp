#include <stdio.h>

typedef unsigned int nat;

struct nodoAB
{
    int dato;
    nodoAB *izq, *der;
};

typedef struct nodoAB *AB;

/*
Decimos que un árbol t de tipo AB está parcialmente ordenado si y solo si: o bien t es vacío (NULL) o si el valor
de cada nodo, que no sea el nodo raíz de t, es mayor o igual que el valor de su nodo padre.

Dado un árbol binario t de tipo AB retorna true si y solo si t es parcialmente ordenado. No defina operaciones
auxiliares para implementar parcialmenteOrdenado, función que no deberá recorrer el árbol t más de una vez.
*/
bool parcialmenteOrdenado(AB t)
{
    if (t == NULL)
        return true;

    bool res = true;

    if (t->izq != NULL)
        res = (t->dato <= t->izq->dato) && parcialmenteOrdenado(t->izq);

    if (t->der != NULL)
        res = (t->dato <= t->der->dato) && parcialmenteOrdenado(t->der);

    return res;
}

int main()
{
    return 0;
}