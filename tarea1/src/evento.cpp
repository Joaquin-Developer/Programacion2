#include "../include/evento.h"

struct rep_evento
{
    int id;
    char descripcion[MAX_DESCRIPCION];
    TFecha fecha;
};

TEvento crearTEvento(int id, const char descripcion[MAX_DESCRIPCION], TFecha fecha)
{
    TEvento nuevoEvento = new rep_evento;
    nuevoEvento->id = id;
    strcpy(nuevoEvento->descripcion, descripcion);
    nuevoEvento->fecha = fecha; // ojo con esto!
    return nuevoEvento;
}

void imprimirTEvento(TEvento evento)
{
    printf("Evento %d: ", evento->id);
    nat i = 0;
    while (i < MAX_DESCRIPCION && (*evento).descripcion[i] != 0)
    {
        printf("%c", (*evento).descripcion[i]);
        i++;
    }

    printf("\nFecha: ");
    imprimirTFecha(evento->fecha);
}

void liberarTEvento(TEvento &evento)
{
    /************ Parte 4.4 ************/
    /*Escriba el código a continuación */

    /****** Fin de parte Parte 4.4 *****/
    // delete evento->descripcion;
    liberarTFecha(evento->fecha);
    delete evento;
    evento = NULL;
}

int idTEvento(TEvento evento)
{
    int res = 0;
    res = evento->id;
    return res;
    // return evento->id;
}

TFecha fechaTEvento(TEvento evento)
{
    // TFecha fecha = NULL;
    // /************ Parte 4.4 ************/
    // /*Escriba el código a continuación */

    // /****** Fin de parte Parte 4.4 *****/
    // return fecha;
    return evento->fecha;
}

void posponerTEvento(TEvento &evento, int dias)
{
    aumentarTFecha(evento->fecha, dias);
}
