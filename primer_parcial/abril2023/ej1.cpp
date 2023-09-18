/*
(1) - Dadas las struct de abajo, implemente insFinal(int x, Lista &l), en orden O(1) peor caso
*/

#include <stdio.h>

struct nodoLista
{
    int dato;
    nodoLista *sig;
    nodoLista *ant;
};

struct cabezal
{
    nodoLista *inicio;
    nodoLista *final;
};

typedef cabezal *Lista;

void insFinal(int x, Lista &l)
{
    nodoLista *insertar = new nodoLista;
    insertar->dato = x;
    insertar->sig = NULL;

    if (l->inicio == NULL)
    {
        insertar->ant = NULL;
        l->inicio = insertar;
        l->final = insertar;
        return;
    }
    l->final->sig = insertar;
    insertar->ant = l->final;
    l->final = insertar;
}

void insInicio(int, Lista &);

// PRE: cabezal l no nulo
void insInicio(int x, Lista &l)
{
    nodoLista *insertar = new nodoLista;
    insertar->dato = x;
    insertar->ant = insertar->sig = NULL;

    if (l->inicio == NULL)
    {
        l->inicio = insertar;
        l->final = insertar;
    }
    else
    {
        insertar->sig = l->inicio;
        l->inicio->ant = insertar;
        l->inicio = insertar;
    }
}

void imprimir(Lista l)
{
    nodoLista *aux = l->inicio;

    while (aux != NULL)
    {
        printf("%i", aux->dato);
        aux = aux->sig;
        if (aux != NULL)
            printf(", ");
    }
    printf("\n");
}

void liberarNodo(nodoLista *&nodo)
{
    delete nodo;
}

void liberar(Lista &lista)
{
    while (lista->inicio != NULL)
    {
        nodoLista *borrar = lista->inicio;
        lista->inicio = lista->inicio->sig;
        delete borrar;
    }
    delete lista;
    lista = NULL;
}

/**
 * (2)
 * Implemente una función iterativa pivote que, dados un entero x y una lista l de tipo Lista que no contie-
 ne a x, construya y devuelva una nueva lista (que no comparta memoria con l) que tenga a x y a todos los elementos
 de l, de tal manera que: todos los elementos de l menores a x, si existen, deben estar antes que x (entre el
inicio de la lista resultado y x, en cualquier orden) y todos los elementos mayores a x, si existen, deben estar
después de x (entre x y el final de la lista resultado, en cualquier orden). Para implementar pivote asuma implementados
correctamente los procedimientos insFinal (de la Parte 1) e insInicio (que inserta un entero al inicio de una
lista de tipo Lista), considerando que ambos insertan en O(1) peor caso. La única manera permitida de agregar
elementos a una lista de tipo Lista es a través de InsFinal y insInicio. La función pivote no debe modificar la lista
parámetro l ni usar estructuras de datos auxiliares (como arreglos u otro tipo de listas, por ejemplo).
 Lista pivote(int x, Lista l)
Ejemplo: Si x = 7 y l = [9, 3, 11, 9, 5, 2, 4], la lista resultado de pivote(x, l) podría ser: [4, 2, 5, 3, 7, 9, 11, 9].
 */
Lista pivote(int x, Lista l)
{
    Lista nuevaLista = new cabezal;
    nuevaLista->inicio = nuevaLista->final = NULL;

    insInicio(x, nuevaLista);

    nodoLista *aux = l->inicio;

    while (aux != NULL)
    {
        if (aux->dato <= x)
            insInicio(aux->dato, nuevaLista);
        else
            insFinal(aux->dato, nuevaLista);
        aux = aux->sig;
    }

    return nuevaLista;
}

int main()
{
    Lista lista = new cabezal;

    lista->inicio = NULL;
    lista->final = NULL;

    insFinal(1, lista);
    insInicio(9, lista);
    insFinal(2, lista);
    imprimir(lista);
    printf("Agrego 3, 4, imprimo denuevo toda la lista\n");
    insFinal(3, lista);
    insFinal(4, lista);
    imprimir(lista);

    Lista listaPivote = pivote(3, lista);
    imprimir(listaPivote);

    liberar(lista);
    liberar(listaPivote);

    return 0;
}
