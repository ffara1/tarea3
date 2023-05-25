#include "../include/personasLDE.h"

///////////////////////////////////
////// PEGAR CÓDIGO TAREA 2 //////
///////////////////////////////////

typedef struct aux_personaLDE *TListaPersonasLDE;
struct aux_personaLDE
{
    TPersona persona;
    TListaPersonasLDE ant;
    TListaPersonasLDE sig;
};

struct rep_personasLDE
{
    TListaPersonasLDE primero;
    TListaPersonasLDE ultimo;
    nat cantidad;
};

TListaPersonasLDE crearTListaPersonasLDE(TPersona persona, TListaPersonasLDE ant, TListaPersonasLDE sig)
{
    TListaPersonasLDE aux = new aux_personaLDE;
    aux->persona = persona;
    aux->sig = sig;
    aux->ant = ant;
    return aux;
}

TPersonasLDE crearTPersonasLDE()
{
    TPersonasLDE personas = new rep_personasLDE;
    personas->primero = NULL;
    personas->ultimo = NULL;
    personas->cantidad = 0;
    return personas;
}

void insertarTPersonasLDE(TPersonasLDE &personas, TPersona persona, nat pos)
{
    if (personas->cantidad == 0)
    {
        personas->primero = crearTListaPersonasLDE(persona, NULL, NULL);
        personas->ultimo = personas->primero;
    }
    else
    {
        if (pos == 1)
        {
            personas->primero = crearTListaPersonasLDE(persona, NULL, personas->primero);
            personas->primero->sig->ant = personas->primero;
        }
        else if (pos > personas->cantidad)
        {
            personas->ultimo = crearTListaPersonasLDE(persona, personas->ultimo, NULL);
            personas->ultimo->ant->sig = personas->ultimo;
        }
        else
        {
            TListaPersonasLDE aux2 = personas->primero;
            while (pos > 1)
            {
                aux2 = aux2->sig;
                pos = pos - 1;
            }
            aux2->ant = crearTListaPersonasLDE(persona, aux2->ant, aux2);
            aux2->ant->ant->sig = aux2->ant;
        }
    }
    personas->cantidad = personas->cantidad + 1;
}

void liberarTListaPersonasLDE(TListaPersonasLDE &lista)
{

    liberarTPersona(lista->persona);
    delete lista;
    lista = NULL;

}

void liberarTPersonasLDE(TPersonasLDE &personasLDE)
{
    TListaPersonasLDE aux2 = NULL;
    while (personasLDE->primero != NULL)
    {
        aux2 = personasLDE->primero->sig;
        liberarTListaPersonasLDE(personasLDE->primero);
        personasLDE->primero = aux2;
    }
    delete personasLDE;
    personasLDE = NULL;
}
void imprimirTPersonasLDE(TPersonasLDE personas)
{
    TListaPersonasLDE aux = personas->primero;
    while (aux != NULL and aux->persona != NULL)
    {
        imprimirTPersona(aux->persona);
        aux = aux->sig;
    }
}
nat cantidadTPersonasLDE(TPersonasLDE personas)
{
    return personas->cantidad ;
}
void eliminarInicioTPersonasLDE(TPersonasLDE &personas)
{
    nat i = personas->cantidad;
    if (personas->primero != NULL)
    {
        if (personas->primero != personas->ultimo)
        {
            TListaPersonasLDE aux = personas->primero->sig;
            liberarTListaPersonasLDE(personas->primero);
            personas->primero = aux;
            personas->primero->ant = NULL;
            personas->cantidad = i - 1;
        }
        else
        {
            liberarTListaPersonasLDE(personas->primero);
            personas->primero = NULL;
            personas->ultimo = NULL;
            personas->cantidad = 0;
        }
    }
}

void eliminarFinalTPersonasLDE(TPersonasLDE & personas)
{
    nat i = personas->cantidad;
    if (personas->ultimo != NULL ){
        if (personas->ultimo != personas->primero)
        {
            TListaPersonasLDE aux = personas->ultimo->ant;
            liberarTListaPersonasLDE(personas->ultimo);
            personas->ultimo = aux;
            personas->ultimo->sig = NULL;
            personas->cantidad = i - 1;
        }
        else
        {
            liberarTListaPersonasLDE(personas->ultimo);
            personas->primero = NULL;
            personas->ultimo = NULL;
            personas->cantidad = 0;
        }
    }
    
}

bool estaEnTPersonasLDE(TPersonasLDE personas, nat id){
    TListaPersonasLDE aux = personas->primero;
    while ((aux != NULL) and (idTPersona(aux->persona)) != id)
    {
        aux = aux->sig;
    }
    return (aux != NULL);
}

TPersona obtenerDeTPersonasLDE(TPersonasLDE personas, nat id)
{
    TListaPersonasLDE aux = personas->primero;
    while ((aux != NULL) && (idTPersona(aux->persona) != id))
    {
        aux = aux->sig;
    }
    return aux->persona;
}

TPersonasLDE concatenarTPersonasLDE(TPersonasLDE personas1, TPersonasLDE personas2){
    TPersonasLDE aux = crearTPersonasLDE();

    if (personas1->primero == NULL)
    {
        aux->primero = personas2->primero;
        aux->ultimo = personas2->ultimo;
    } else if (personas2->primero == NULL)
    {
        aux->primero = personas1->primero;

        aux->ultimo = personas1->ultimo;
    } else {
        aux->primero = personas1->primero;

        personas1->ultimo->sig = personas2->primero;

        personas2->primero->ant = personas1->ultimo;

        aux->ultimo = personas2->ultimo;
    }

    aux->cantidad = personas1->cantidad + personas2->cantidad;

    delete personas1;

    personas1 = NULL;

    delete personas2;

    personas2 = NULL;

    return aux;
}

///////////////////////////////////
////// FIN CÓDIGO TAREA 2 //////
///////////////////////////////////

///////////////////////////////////////////////////////////////////////////
/////////////  NUEVAS FUNCIONES  //////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////

void insertarInicioDeTPersonasLDE(TPersonasLDE &personas, TPersona persona){
    TListaPersonasLDE aux = personas->primero;
    if (aux != NULL)
    {
        personas->primero = crearTListaPersonasLDE(persona, NULL, personas->primero);
        personas->primero->sig = aux;
        aux->ant = personas->primero;
    } else {
        personas->primero = crearTListaPersonasLDE(persona, NULL, NULL);
        personas->ultimo = personas->primero;

    }
    personas->cantidad = personas->cantidad + 1;
    
}

void insertarFinalDeTPersonasLDE(TPersonasLDE &personas, TPersona persona){
    TListaPersonasLDE aux = personas->ultimo;
    if (aux != NULL)
    {
        personas->ultimo = crearTListaPersonasLDE(persona, personas->ultimo, NULL);
        personas->ultimo->ant = aux;
        aux->sig = personas->ultimo;
    } else {
        personas->primero = crearTListaPersonasLDE(persona, NULL, NULL);
        personas->ultimo = personas->primero;

    }
    personas->cantidad = personas->cantidad + 1;

}

TPersona obtenerInicioDeTPersonasLDE(TPersonasLDE personas){
    return personas->primero->persona;

}

TPersona obtenerFinalDeTPersonasLDE(TPersonasLDE personas){
    return personas->ultimo->persona;

}

///////////////////////////////////////////////////////////////////////////
/////////////  FIN NUEVAS FUNCIONES  //////////////////////////////////////
///////////////////////////////////////////////////////////////////////////

