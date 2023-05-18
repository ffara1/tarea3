#include "../include/agendaLS.h"

///////////////////////////////////
////// PEGAR CÓDIGO TAREA 2 //////
///////////////////////////////////

struct rep_agendaLS
{
    TEvento evento;
    rep_agendaLS *sig;
};

TAgendaLS crearAgendaLS()
{
    TAgendaLS nuevaAgenda = new rep_agendaLS;
    nuevaAgenda->evento = NULL;
    nuevaAgenda->sig = NULL;
    return nuevaAgenda;
}

void agregarEnAgendaLS(TAgendaLS &agenda, TEvento evento)
{
    if (agenda->evento != NULL)
    {
        TAgendaLS nuevo = crearAgendaLS();
        TAgendaLS agendaAux = nuevo;
        agendaAux->sig = agenda;
        while ((agendaAux->sig != NULL) && (compararTFechas(fechaTEvento(evento), fechaTEvento(agendaAux->sig->evento)) > 0))
        {
            agendaAux = agendaAux->sig;
        }
        nuevo->evento = evento;
        nuevo->sig = agendaAux->sig;
        if (agendaAux->evento == evento)
        {
            agenda = nuevo;
        }
        else
        {
            agendaAux->sig = nuevo;
        }
    }
    else
    {
        agenda->evento = evento;
    }
}

void imprimirAgendaLS(TAgendaLS agenda)
{
    while ((agenda != NULL) && (agenda->evento != NULL))
    {
        imprimirTEvento(agenda->evento);
        agenda = agenda->sig;
    }
}

void liberarAgendaLS(TAgendaLS &agenda)
{
    TAgendaLS aux = NULL;
    while ((agenda != NULL) && (agenda->evento != NULL))
    {
        liberarTEvento(agenda->evento);
        aux = agenda->sig;
        delete agenda;
        agenda = aux;
    }
    delete agenda;
    agenda = NULL;
}

bool esVaciaAgendaLS(TAgendaLS agenda)
{
    return !((agenda->evento != NULL) && (agenda->sig != NULL));
}

TAgendaLS copiarAgendaLS(TAgendaLS agenda)
{
    TAgendaLS copiaAgenda = crearAgendaLS();
    while ((agenda != NULL) && (agenda->evento != NULL))
    {
        agregarEnAgendaLS(copiaAgenda, copiarTEvento(agenda->evento));
        agenda = agenda->sig;
    }
    return copiaAgenda;
}

bool estaEnAgendaLS(TAgendaLS agenda, int id)
{
    TAgendaLS aux = agenda;
    if (aux->evento != NULL)
    {
        while ((aux != NULL) && (idTEvento(aux->evento) != id))
        {
            aux = aux->sig;
        }
        return (aux != NULL);
    }
    else
    {
        return false;
    }
}

TEvento obtenerDeAgendaLS(TAgendaLS agenda, int id)
{
    TAgendaLS aux = agenda;
    while (idTEvento(aux->evento) != id)
    {
        aux = aux->sig;
    }
    return aux->evento;
}

void posponerEnAgendaLS(TAgendaLS &agenda, int id, nat n)
{
    TAgendaLS aux = agenda;
    TAgendaLS anterior = NULL;
    int valor_n = n;
    if (agenda->sig != NULL)
    {
        while (idTEvento(aux->evento) != id)
        {
            anterior = aux;
            aux = aux->sig;
        }
        if (anterior != NULL)
        {
            anterior->sig = aux->sig;
        }
        else
        {
            agenda = agenda->sig;
            anterior = agenda;
        }
        posponerTEvento(aux->evento, valor_n);
        while ((anterior->sig != NULL) && (compararTFechas(fechaTEvento(aux->evento), fechaTEvento(anterior->sig->evento)) > 0))
        {
            anterior = anterior->sig;
        }
        aux->sig = anterior->sig;
        if (anterior != NULL)
        {
            anterior->sig = aux;
        }
        else
        {
            agenda = aux;
        }
    }
    else
    {
        posponerTEvento(aux->evento, valor_n);
    }
}

void imprimirEventosFechaLS(TAgendaLS agenda, TFecha fecha)
{
    TAgendaLS aux = agenda;
    while (aux != NULL)
    {
        if (compararTFechas(fecha, fechaTEvento(aux->evento)) == 0)
        {
            imprimirTEvento(aux->evento);
        }
        aux = aux->sig;
    }
}

bool hayEventosFechaLS(TAgendaLS agenda, TFecha fecha)
{
    TAgendaLS aux = agenda;
    bool hayEventos = false;
    while ((aux != NULL) && (hayEventos == false))
    {
        if (compararTFechas(fecha, fechaTEvento(aux->evento)) == 0)
        {
            hayEventos = true;
        }
        aux = aux->sig;
    }
    return hayEventos;
}

void removerDeAgendaLS(TAgendaLS &agenda, int id)
{
    TAgendaLS aux = agenda;
    TAgendaLS anterior = NULL;
    while ((aux != NULL) && (idTEvento(aux->evento) != id))
    {
        anterior = aux;
        aux = aux->sig;
    }
    if (aux != NULL)
    {
        if (anterior != NULL)
        {
            anterior->sig = aux->sig;
        }
        else
        {
            agenda = agenda->sig;
        }
        liberarTEvento(aux->evento);
        delete aux;
    }
}
///////////////////////////////////
////// FIN CÓDIGO TAREA 2 //////
///////////////////////////////////