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
    liberarTFecha(evento->fecha);
    delete evento;
    evento = NULL;
}

int idTEvento(TEvento evento)
{
    return evento->id;
}

TFecha fechaTEvento(TEvento evento)
{
    return evento->fecha;
}

void posponerTEvento(TEvento &evento, int dias)
{
    aumentarTFecha(evento->fecha, dias);
}
