#include <stdio.h>

typedef unsigned int nat;

struct EstInfo
{
    nat nota;
    int ci;
};

struct nodoABB
{
    EstInfo info;
    nodoABB *izq, *der;
};

typedef nodoABB *ABB;

ABB maxAbb(ABB);
ABB minAbb(ABB);

void removerMaxABB(ABB &);

// devuelve un nuevo arbol
// solo con los estudiantes que poseen cierta nota
ABB filtrado(ABB a, nat nota)
{
    if (a == NULL)
        return NULL;

    ABB result;
    ABB filtradoIzq = filtrado(a->izq, nota);
    ABB filtradoDer = filtrado(a->der, nota);

    EstInfo raiz = a->info;
    if (raiz.nota > nota)
    {
        result = new nodoABB;
        result->info = raiz;
        result->izq = filtradoIzq;
        result->der = filtradoDer;
    }
    else if (filtradoIzq == NULL)
        result = filtradoDer;
    else if (filtradoDer == NULL)
        result = filtradoIzq;
    else
    {
        ABB mayor = maxAbb(filtradoIzq);
        result = new nodoABB;
        result->info = mayor->info;
        result->izq = filtradoIzq;
        result->der = filtradoDer;
        removerMaxABB(filtradoIzq);
    }

    return result;
}

int main()
{
    return 0;
}