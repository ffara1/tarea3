#include "../include/fecha.h"

///////////////////////////////////
////// PEGAR CÓDIGO TAREA 2 //////
///////////////////////////////////

struct rep_fecha
{
    /************ Parte 2.1 ************/
    /*Escriba el código a continuación */
    nat dia, mes, anio;
    /****** Fin de parte Parte 2.1 *****/
};

TFecha crearTFecha(nat dia, nat mes, nat anio)
{
    TFecha nuevaFecha = NULL;
    /************ Parte 3.1 ************/
    /*Escriba el código a continuación */
    nuevaFecha = new rep_fecha;
    nuevaFecha->dia = dia;
    nuevaFecha->mes = mes;
    nuevaFecha->anio = anio;

    /****** Fin de parte Parte 3.1 *****/
    return nuevaFecha;
}

void liberarTFecha(TFecha &fecha)
{
    /************ Parte 3.3 ************/
    /*Escriba el código a continuación */
    delete fecha;
    fecha = NULL;

    /****** Fin de parte Parte 3.3 *****/
}
void imprimirTFecha(TFecha fecha)
{
    /************ Parte 3.5 ************/
    /*Escriba el código a continuación */
    printf("%d/%d/%d\n", fecha->dia, fecha->mes, fecha->anio);

    /****** Fin de parte Parte 3.5 *****/
}

/************ Parte 3.9 ************/
/*Escriba el código a continuación */
/*Recuerde que las funciones auxiliares
  deben declararse antes de ser utilizadas*/
nat diasMes(nat mes, nat anio)
{
    nat cantDias = 0;
    switch (mes)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        cantDias = 31;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        cantDias = 30;
        break;
    case 2:
        if (anio % 4 == 0)
        {
            cantDias = 29;
        }
        else
        {
            cantDias = 28;
        }
        break;

    default:
        break;
    }

    return cantDias;
}

void aumentarTFecha(TFecha &fecha, nat dias)
{
    fecha->dia += dias;
    while (fecha->dia > diasMes(fecha->mes, fecha->anio))
    {
        fecha->dia -= diasMes(fecha->mes, fecha->anio);
        fecha->mes++;
        if (fecha->mes > 12)
        {
            fecha->mes = 1;
            fecha->anio++;
        }
    }
}

/****** Fin de parte Parte 3.9 *****/

int compararTFechas(TFecha fecha1, TFecha fecha2)
{
    int res = 0;
    /************ Parte 3.10 ************/
    /*Escriba el código a continuación */
    if ((fecha1->anio < fecha2->anio) or ((fecha1->anio == fecha2->anio) and (fecha1->mes < fecha2->mes)) or ((fecha1->anio == fecha2->anio) and (fecha1->mes == fecha2->mes) and (fecha1->dia < fecha2->dia)))
    {
        res = -1;
    }
    else
    {
        if ((fecha1->anio > fecha2->anio) or ((fecha1->anio == fecha2->anio) and (fecha1->mes > fecha2->mes)) or ((fecha1->anio == fecha2->anio) and (fecha1->mes == fecha2->mes) and (fecha1->dia > fecha2->dia)))
        {
            res = 1;
        }

        /****** Fin de parte Parte 3.10 *****/
    }
    return res;
}


// Retorna una copia de la fecha
TFecha copiarTFecha(TFecha fecha)
{
    TFecha copia = crearTFecha(fecha->dia, fecha->mes, fecha->anio);
    return copia;
}
/////////////////////////////////
////// FIN CÓDIGO TAREA 2 //////
/////////////////////////////////
