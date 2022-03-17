#include <stdio.h>

// (c) y (d)

typedef struct rep_fecha *TFecha;

/* Devuelve un ' TFecha ' con dia d, mes m y año a */
TFecha crear_fecha(unsigned int d, unsigned int m, unsigned int a);

/* Devuelve true si f1 es anterior a f2 , false en otro caso */
bool comparar_fechas(TFecha f1, TFecha f2);

/* Devuelve el día correspondiente a fecha */
unsigned int dia(TFecha fecha);

/* Devuelve el mes correspondiente a fecha */
unsigned int mes(TFecha fecha);

/* Devuelve el año correspondiente a fecha */
unsigned int anio(TFecha fecha);

// (a)

//  unsigned int: 0 - 4 000 000 000
// int:           - 2 000 000 000  ---- + 2 000 000 0000

/*
struct rep_fecha {
  unsigned int d;
  unsigned int m;
  unsigned int a;
};
*/

/*
int main () {
  const unsigned int n = 4;
  rep_fecha fechas[n];
  fechas[0] = {13, 1, 2022};
  fechas[1] = {1, 10, 2002};
  fechas[2] = {22, 5, 2001};
  fechas[3] = {18, 3, 2005};


  // ordenar

  // imprimir

  for (unsigned int i = 0 ; i < n ; i++ ) {
    printf("%u/%u/%u ", fechas[i].d, fechas[i].m, fechas[i].a);
    printf("\n");
  }



  return 0;
}
*/

// (b)

struct rep_fecha
{
  unsigned int f; // AAAAMMDD
};

/*
int main() {
  const int n = 4;
  rep_fecha fechas[n];
  fechas[0].f = 20220113;
  fechas[1].f = 20021001;
  fechas[2].f = 20010522;
  fechas[3].f = 20050318;

  // ordenar

  // imprimir

  for (unsigned int i = 0 ; i < n ; i++ ) {
    printf("%u/%u/%u ", fechas[i].f % 100, (fechas[i].f / 100) % 100 , fechas[i].f / 10000);
    printf("\n");
  }



  return 0;
}
*/

// (c)

/*
TFecha crear_fecha (unsigned int d, unsigned int m, unsigned int a) {
  TFecha nueva = new rep_fecha;

  (*nueva).d = d;  // nueva->d = d
  (*nueva).m = m;  // nueva->d = d
  (*nueva).a = a;  // nueva->d = d


  return nueva;
}

bool comparar_fechas (TFecha f1, TFecha f2) {
  return ( ( (*f1).a < (*f2).a) ) ||
       ( ((*f1).a == (*f2).a))  && ((*f1).m < (*f2).m)  ||
       ( ((*f1).a == (*f2).a))  && ((*f1).m == (*f2).m  && (*f1).d < (*f2).d   )
  ;
}

unsigned int dia (TFecha fecha) {
  return (*fecha).d;
}


unsigned int mes (TFecha fecha) {
  return (*fecha).m;
}


unsigned int anio (TFecha fecha) {
  return fecha->a;
}
*/

TFecha crear_fecha(unsigned int d, unsigned int m, unsigned int a)
{
  TFecha nueva = new rep_fecha;

  (*nueva).f = a * 10000 + m * 100 + d;

  return nueva;
}

/* Devuelve true si f1 es anterior a f2 , false en otro caso */
bool comparar_fechas(TFecha f1, TFecha f2)
{
  return (*f1).f < (*f2).f;
}

/* Devuelve el día correspondiente a fecha */
unsigned int dia(TFecha fecha)
{
  return (*fecha).f % 100;
}

/* Devuelve el mes correspondiente a fecha */
unsigned int mes(TFecha fecha)
{
  return (fecha->f / 100) % 100;
}

/* Devuelve el año correspondiente a fecha */
unsigned int anio(TFecha fecha)
{
  return (*fecha).f / 10000;
}

int main()
{
  const unsigned int n = 4;
  TFecha fechas[n];
  fechas[0] = crear_fecha(13, 1, 2022);
  fechas[1] = crear_fecha(1, 10, 2002);
  fechas[2] = crear_fecha(22, 5, 2001);
  fechas[3] = crear_fecha(18, 3, 2005);

  // ordenar

  // imprimir

  for (unsigned int i = 0; i < n; i++)
  {
    printf("%u/%u/%u ", dia(fechas[i]), mes(fechas[i]), anio(fechas[i]));
    printf("\n");
  }
}
