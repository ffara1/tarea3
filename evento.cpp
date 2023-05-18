#include "../include/evento.h"

///////////////////////////////////
////// PEGAR CÓDIGO TAREA 2 //////
///////////////////////////////////

struct rep_evento
{
    /************ Parte 4.1 ************/
    /*Escriba el código a continuación */
    int id;
    TFecha fecha;
    char des[MAX_DESCRIPCION];
    /****** Fin de parte Parte 4.1 *****/
};

TEvento crearTEvento(int id, const char descripcion[MAX_DESCRIPCION], TFecha fecha)
{
    TEvento nuevoEvento = new rep_evento;
    /************ Parte 4.2 ************/
    /*Escriba el código a continuación */

    nuevoEvento->id = id;
    nuevoEvento->fecha = fecha;
    strcpy(nuevoEvento->des, descripcion);
    /****** Fin de parte Parte 4.2 *****/
    return nuevoEvento;
}

void imprimirTEvento(TEvento evento)
{
    /************ Parte 4.3 ************/
    /*Escriba el código a continuación */

    printf("Evento %d: %s\n", evento->id, evento->des);
    printf("Fecha: ");
    imprimirTFecha(evento->fecha);

    /****** Fin de parte Parte 4.3 *****/
}

void liberarTEvento(TEvento &evento)
{
    /************ Parte 4.4 ************/
    /*Escriba el código a continuación */
    liberarTFecha(evento->fecha);
    delete evento;
    evento = NULL;
    /****** Fin de parte Parte 4.4 *****/
}

int idTEvento(TEvento evento)
{
    int res = 0;
    /************ Parte 4.4 ************/
    /*Escriba el código a continuación */
    res = evento->id;
    /****** Fin de parte Parte 4.4 *****/
    return res;
}

TFecha fechaTEvento(TEvento evento)
{
    TFecha fecha = evento->fecha;
    /************ Parte 4.4 ************/
    /*Escriba el código a continuación */

    /****** Fin de parte Parte 4.4 *****/
    return fecha;
}

void posponerTEvento(TEvento &evento, int dias)
{
    /************ Parte 4.5 ************/
    /*Escriba el código a continuación */
    nat cant = dias;
    aumentarTFecha(evento->fecha, cant);
    /****** Fin de parte Parte 4.5 *****/
}


TEvento copiarTEvento(TEvento evento)
{

    TEvento copia = new rep_evento;
    copia->id = evento->id;
    copia->fecha = copiarTFecha(evento->fecha);
    strcpy(copia->des, evento->des);

    return copia;
}

/////////////////////////////////
////// FIN CÓDIGO TAREA 2 //////
/////////////////////////////////
