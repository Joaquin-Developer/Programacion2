## PRACTICO 1: Introducción a TADs y modularización

### Ejercicio 1
A) Dada la siguiente representación de fecha:
```c++
// Registro con dia d, mes m y año a
struct rep_fecha {
    unsigned int d;
    unsigned int m;
    unsigned int a;
};
```
Implemente una función `main()` que inicialice un arreglo de fechas (por ejemplo, con las fechas 10/10/2022,
15/5/2022 y 20/11/1992), lo ordene e imprima el resultado.

B) Considere ahora la siguiente representación de fecha:
```c++
struct rep_fecha {
    unsigned int f; // AAAAMMDD
}
```
Modifique el `main()` implementado en la parte (a) de manera que se adecúe a la nueva representación.

C) Considere ahora que cuenta con la siguiente interfaz del tipo de datos TFecha:
```c++
typedef struct rep_fecha *TFecha;

/* Devuelve un 'TFecha' con dia d, mes m y año a */
TFecha crear_fecha(unsigned int d , unsigned int m, unsigned int a);

/* Devuelve true si f1 es anterior a f2, false en otro caso */
bool comparar_fechas(TFecha f1, TFecha f2);

/* Devuelve el día correspondiente a fecha */
unsigned int dia(TFecha fecha);

/* Devuelve el mes correspondiente a fecha */
unsigned int mes(TFecha fecha);

/* Devuelve el año correspondiente a fecha */
unsigned int anio(TFecha fecha);
```
Implemente la interfaz utilizando la representación de fecha dada en la parte (a). Reescriba la función `main()` haciendo uso de las operaciones implementadas en la interfaz y sin acceder a la representación.

D) Vuelva a implementar la interfaz pero con la representación de fecha dada en la parte (b). Realice los cambios necesarios en la función `main()` escrita en la parte (c).

### Ejercicio 2
La siguiente es la especificación del módulo TInfo
```c++
// info .h
# ifndef _INFO_H
# define _INFO_H

/* Representación de TInfo */
typedef struct _rep_info *TInfo ;

/* Operaciones de TInfo */

/*
Devuelve un 'TInfo' compuesto por 'natural' y 'real'.
*/
TInfo crearInfo(uint natural , double real);

/*
Devuelve el componente natural de 'info'.
*/
uint natInfo(TInfo info);

/*
Devuelve el componente real de 'info'.
*/
double realInfo(TInfo info);

# endif
```

A) Implemente el módulo de implementación de TInfo.  
B) Implemente otro módulo que use el tipo TInfo, por ejemplo, para almacenar pares (edad, altura) de un registro pediátrico. En particular, cree 3 variables de tipo TInfo que contengan los valores (3,67.1), (5,98.3) y (7,103.5) y luego imprima el contenido de cada una de ellas
