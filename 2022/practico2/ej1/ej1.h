#ifndef _EJ_1
#define _EJ_1

typedef unsigned int uint;

/* Ordena A [1.. n] de manera creciente . */
void ordenar(float *, uint);

/* Inserta e en A [1.. n+1] de manera ordenada .
Precondici ón: n >=0. Si n >=1 = > A [1.. n] est á ordenado de manera ←-
creciente . A[n+1] es indeterminado .
Postcondici ón: A [1.. n +1] queda ordenado de manera creciente . */
void insertarOrdenado(float *, uint, float);

#endif
