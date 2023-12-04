#include <stdio.h>

struct representacionCP;
typedef representacionCP *CP;

typedef unsigned int T; // tipo Genérico, se asigna int como ejemplo.

// Devuelve la cola de prioridad vacía
CP crear();

// Agrega x con prioridad p a cp
void agregar(T x, unsigned int p, CP &cp);

// Retorna true si y solo si cp es vacía
bool esVacia(CP cp);

/* Retorna el elemento con mayor prioridad (valor más
grade) ingresado en cp. Ante igual prioridad retorna el
primero en ingresar */
// Precondición: !esVacia(cp)
T prioritario(CP cp);

/* Remueve el elemento con mayor prioridad (valor más
grade) ingresado en cp. Ante igual prioridad elimina el
primero en ingresar */
// Precondición: !esVacia(cp)
void eliminar(CP &cp);

// implementaciones:

struct nodoLista
{
    T dato;
    unsigned int prioridad;
    nodoLista *sig;
};

struct representacionCP
{
    nodoLista *colaPrioridad;
    nodoLista *prioritario;
};
// de esta forma se puede implementar las operaciones crear, agregar, esVacia, prioritario en O(1)
// ACOTADO -> Usar arrays
// NO ACOTADO -> Usar estructuras dinámicas como Listas Enlazadas (o sus variantes: Pilas, Colas)

CP crear()
{
    CP cp = new representacionCP;
    cp->colaPrioridad = NULL;
    cp->prioritario = NULL;
    return cp;
}

void agregar(T x, unsigned int p, CP &cp)
{
    nodoLista *nodo = new nodoLista;
    nodo->dato = x;
    nodo->prioridad = p;
    nodo->sig = cp->colaPrioridad;
    cp->colaPrioridad = nodo;

    if (cp->prioritario == NULL || p > cp->prioritario->prioridad)
        cp->prioritario = nodo;
}

int main()
{
    return 0;
}