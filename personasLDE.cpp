#include "../include/personasLDE.h"

///////////////////////////////////
////// PEGAR CÓDIGO TAREA 2 //////
///////////////////////////////////

struct rep_lista{
    TPersona persona;
    rep_lista *sig;
    rep_lista *ant;
};

typedef struct rep_lista *TLista;

struct rep_personasLDE{
    TLista inicio;
    TLista final;
    nat cantPersonas;
};

TLista crearTLista(TLista ant, TPersona persona, TLista sig){
    TLista nuevaPersona = new rep_lista;
    nuevaPersona->persona = persona;
    nuevaPersona->sig = sig;
    nuevaPersona->ant = ant;
    return nuevaPersona;
}

TPersonasLDE crearTPersonasLDE(){
    TPersonasLDE personas = new rep_personasLDE;
    personas->inicio = NULL;
    personas->final = NULL;
    personas->cantPersonas = 0;
    return personas;
}

void insertarTPersonasLDE(TPersonasLDE &personas, TPersona persona, nat pos){
    if (personas->cantPersonas == 0)
    {
        personas->inicio = crearTLista(NULL, persona, NULL);
        personas->final = personas->inicio;
    }
    else if (pos == 1)
    {
        personas->inicio = crearTLista(NULL, persona, personas->inicio);
        personas->inicio->sig->ant = personas->inicio;
    }
    else if (pos > personas->cantPersonas)
    {
        personas->final = crearTLista(personas->final, persona, NULL);
        personas->final->ant->sig = personas->final;
    }
    else
    {
        TLista aux = personas->inicio;
        while (pos > 1)
        {
            aux = aux->sig;
            pos--;
        }
        aux->ant = crearTLista(aux->ant, persona, aux);
        aux->ant->ant->sig = aux->ant;
    }
    personas->cantPersonas++;
}

void liberarTLista(TLista &lista){
    if (lista != NULL && lista->persona != NULL)
    {
        liberarTPersona(lista->persona);
        delete lista;
        lista = NULL;
    }
}

void liberarTPersonasLDE(TPersonasLDE &personasLDE){
    TLista aux = NULL;
    while (personasLDE->inicio != NULL)
    {
        aux = personasLDE->inicio->sig;
        liberarTLista(personasLDE->inicio);
        personasLDE->inicio = aux;
    }
    delete personasLDE;
    personasLDE = NULL;
}

void imprimirTPersonasLDE(TPersonasLDE personas){
    TLista aux = personas->inicio;
    while ((aux != NULL) && (aux->persona != NULL))
    {
        imprimirTPersona(aux->persona);
        aux = aux->sig;
    }
}

nat cantidadTPersonasLDE(TPersonasLDE personas){
    return personas->cantPersonas;
}

void eliminarInicioTPersonasLDE(TPersonasLDE &personas){
    if (personas->inicio != NULL)
    {
        if (personas->inicio == personas->final)
        {
            liberarTLista(personas->inicio);
            personas->inicio = NULL;
            personas->final = NULL;
        }
        else
        {
            TLista siguiente = personas->inicio->sig;
            liberarTLista(personas->inicio);
            personas->inicio = siguiente;
            personas->inicio->ant = NULL;
        }
        personas->cantPersonas--;
    }
}

void eliminarFinalTPersonasLDE(TPersonasLDE &personas){
    if (personas->final != NULL){
        if (personas->inicio == personas->final){
            liberarTLista(personas->final);
            personas->inicio = NULL;
            personas->final = NULL;
        }
        else{
            TLista anterior = personas->final->ant;
            liberarTLista(personas->final);
            personas->final = anterior;
            personas->final->sig = NULL;
        }
        personas->cantPersonas--;
    }
}

bool estaEnTPersonasLDE(TPersonasLDE personas, nat id){
    TLista aux = personas->inicio;
    while ((aux != NULL) && (idTPersona(aux->persona) != id)){
        aux = aux->sig;
    }
    return (aux != NULL);
}

TPersona obtenerDeTPersonasLDE(TPersonasLDE personas, nat id){
    TLista aux = personas->inicio;
    while ((aux != NULL) && (idTPersona(aux->persona) != id)){
        aux = aux->sig;
    }
    return aux->persona;
}

TPersonasLDE concatenarTPersonasLDE(TPersonasLDE personas1, TPersonasLDE personas2){
    TPersonasLDE nuevaLista = crearTPersonasLDE();
    if (personas1->inicio == NULL){
        nuevaLista->inicio = personas2->inicio;
        nuevaLista->final = personas2->final;
        nuevaLista->cantPersonas = personas1->cantPersonas + personas2->cantPersonas;
    }
    else{
        if (personas2->inicio == NULL){
            nuevaLista->inicio = personas1->inicio;
            nuevaLista->final = personas1->final;
            nuevaLista->cantPersonas = personas1->cantPersonas + personas2->cantPersonas;
        }
        else{
            TLista aux = NULL;
            TLista aux2 = NULL;
            aux = personas1->final;
            aux2 = personas2->inicio;
            nuevaLista->inicio = personas1->inicio;
            nuevaLista->final = personas2->final;
            aux->sig = aux2;
            aux2->ant = aux;
            nuevaLista->cantPersonas = personas1->cantPersonas + personas2->cantPersonas;
        }
    }
    delete personas1;
    personas1 = NULL;
    delete personas2;
    personas2 = NULL;
    return nuevaLista;
}

///////////////////////////////////
////// FIN CÓDIGO TAREA 2 //////
///////////////////////////////////

///////////////////////////////////////////////////////////////////////////
/////////////  NUEVAS FUNCIONES  //////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////

void insertarInicioDeTPersonasLDE(TPersonasLDE &personas, TPersona persona){
    if (personas->inicio != NULL){
        TLista nuevo = crearTLista(NULL, persona, personas->inicio);
        personas->inicio->ant = nuevo;
        personas->inicio = nuevo;
    } else {
        personas->inicio = crearTLista(NULL, persona, NULL);
        personas->final = personas->inicio;
    }
    personas->cantPersonas++;
}

void insertarFinalDeTPersonasLDE(TPersonasLDE &personas, TPersona persona){
    if (personas->final == NULL){
        insertarInicioDeTPersonasLDE(personas, persona);
    } else {
        TLista nuevo = crearTLista(personas->final, persona, NULL);
        personas->final->sig = nuevo;
        personas->final = nuevo;
        personas->cantPersonas++;
    }
}

TPersona obtenerInicioDeTPersonasLDE(TPersonasLDE personas){
    if (personas->inicio != NULL){
        return personas->inicio->persona;
    } else {
        return NULL;
    }
}

TPersona obtenerFinalDeTPersonasLDE(TPersonasLDE personas){
    if (personas->final != NULL){
        return personas->final->persona;
    } else {
        return NULL;
    }
}

///////////////////////////////////////////////////////////////////////////
/////////////  FIN NUEVAS FUNCIONES  //////////////////////////////////////
///////////////////////////////////////////////////////////////////////////

