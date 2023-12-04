#include <stdio.h>

struct nodoABB
{
    int dato;
    unsigned int altura; // altura del árbol que tiene al nodo como raíz
    nodoABB *izq, *der;
};

typedef nodoABB *ABB;

int altura(ABB t);
int max(int x, int y);
int abs(int x);

int max(int x, int y)
{
    if (x > y)
        return x;
    return y;
}

// pre: x no pertenece a t
bool insertar(ABB &t, int x);

// implementar insertar, de manera que:
// - actualizar el campo altura en los nodos que corresponda.
// - asumiendo que t cumple la condición de AVL, devuelva true si y solo si el árbol
// sigue cumpliendo esa condición después de la inserción. NO se pide balancear el árbol.

bool insertar(ABB &t, int x)
{
    if (t == NULL)
    {
        t = new nodoABB;
        t->dato = x;
        t->izq = t->der = NULL;
        return true;
    }
    bool res;
    if (x < t->dato)
        res = insertar(t->izq, x);
    else
        res = insertar(t->der, x);

    t->altura = max(altura(t->izq), altura(t->der));

    return res && (abs(altura(t->izq) - altura(t->der)) <= 1);
}

// parte b:
// Implementar un procedimiento iterativo imprimir que imprima los datos (de tipo int) de
// un ABB t por niveles, desde la raíz y en cada nivel de izquierda a derecha.
// El procedimiento debe recorrer el árbol una sola vez, utilizando una cola de árboles de
// tipo ABB, llamada ColaABB, que se asume implementada (NO debe implementar ColaABB).
// Utilice un procedimiento impInt, que se asume implementado, para imprimir valores (datos)
// de tipo int. No se permite usar otros TADs o estructuras de datos auxiliares.
void imprimir(ABB t);

void imprimir(ABB t)
{
    ColaABB c = crear();
    if (t != NULL)
        encolar(t, c);
    while (!esVacia(c))
    {
        t = desencolar(c);
        impInt(t->dato);
        if (t->izq != NULL)
            encolar(t->izq, c);
        if (t->der != NULL)
            encolar(t->der, c);
    }
}

int main() { return 0; }