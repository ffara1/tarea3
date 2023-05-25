#include "../include/agendaLS.h"

///////////////////////////////////
////// PEGAR CÓDIGO TAREA 2 //////
///////////////////////////////////

struct rep_agendaLS {
    TEvento  evento;
    TAgendaLS sig; 
    
};

TAgendaLS crearAgendaLS() {
    TAgendaLS nuevaAgenda = new rep_agendaLS;
    nuevaAgenda->evento = NULL;
    nuevaAgenda->sig = NULL;
    return nuevaAgenda;
}

void agregarEnAgendaLS(TAgendaLS &agenda, TEvento evento) {
    if (agenda->evento != NULL)
    {
        TAgendaLS aux = crearAgendaLS();
        TAgendaLS alias = aux;
        alias->sig = agenda;
        while ((alias->sig != NULL) and (compararTFechas(fechaTEvento(evento),fechaTEvento(alias->sig->evento))==1))
        {
            alias = alias->sig;
        }
        aux->evento = evento;
        aux->sig = alias->sig;
        if (alias->evento == evento)
        {
            agenda = aux;
        }
        else
        {
            alias->sig = aux;
        }
    }
    else
    {
        agenda->evento = evento;
    }
   
}


void imprimirAgendaLS(TAgendaLS agenda) {
    while ((agenda != NULL) and (agenda->evento != NULL))
    {
       imprimirTEvento(agenda->evento);
       agenda = agenda->sig;
    }
    
    
}

void liberarAgendaLS(TAgendaLS &agenda) {
  TAgendaLS alias = agenda;
  while ((agenda!= NULL) and (agenda->evento != NULL))
  {
        liberarTEvento(agenda->evento);
        alias = agenda->sig;
        delete agenda;
        agenda = alias;
  }
  delete agenda;
  agenda = NULL;
   
}

bool esVaciaAgendaLS(TAgendaLS agenda){
    if ((agenda->evento == NULL) and (agenda->sig == NULL))
    {
        return true;
    }
    else
    { 
    return false;
    }
}

TAgendaLS copiarAgendaLS(TAgendaLS agenda)
{
    TAgendaLS copia = crearAgendaLS();
    while ((agenda != NULL) and (agenda->evento != NULL))
    {
    agregarEnAgendaLS(copia, copiarTEvento(agenda->evento));
    agenda = agenda->sig;
    }
    return copia;
}

bool estaEnAgendaLS(TAgendaLS agenda, int id) {
    bool esta = false;
    while ((agenda != NULL) and (agenda->evento != NULL))
    {
        if (idTEvento(agenda->evento) == id)
        {
            esta = true;
        }
        agenda = agenda->sig;
    }

    return esta ;
}

TEvento obtenerDeAgendaLS(TAgendaLS agenda, int id) {
    while (idTEvento(agenda->evento) != id)
        {
            agenda = agenda->sig;    
        }
    return agenda->evento;
}


void posponerEnAgendaLS(TAgendaLS &agenda, int id, nat n) {
    int m = n;
    if ( agenda->sig == NULL)
    {
        posponerTEvento(agenda->evento,m);
    }
    else
    {
    TAgendaLS alias = agenda;
    TAgendaLS aux = NULL;
    while (idTEvento(alias->evento) != id)
    {
        aux = alias;
        alias = alias->sig;
    }
    if (aux == NULL)
    {
        agenda = agenda->sig;
        aux = agenda;
    }
    else
    {
        aux->sig = alias->sig;
    }
    posponerTEvento(alias->evento,m);
    while (aux->sig != NULL and compararTFechas(fechaTEvento(alias->evento), fechaTEvento(aux->sig->evento)) == 1 )
    {
        aux = aux->sig;
    }
    alias->sig = aux->sig;
    if (aux != NULL)
    {
        aux->sig = alias;
    }
    else
    {
        agenda = alias;
    }
    }
    
    
}

void imprimirEventosFechaLS(TAgendaLS agenda, TFecha fecha) {
    while ((agenda != NULL) and (agenda->evento != NULL))
    {
        if (compararTFechas(fechaTEvento(agenda->evento),fecha) == 0)
        {
            imprimirTEvento(agenda->evento);
        }
        agenda = agenda->sig;
    }
}

bool hayEventosFechaLS(TAgendaLS agenda, TFecha fecha) {
    while ((agenda!= NULL) and (agenda->evento != NULL) and (compararTFechas(fechaTEvento(agenda->evento),fecha) != 0)) 
    {
        agenda = agenda->sig;
    }
    return (agenda != NULL);
}

void removerDeAgendaLS(TAgendaLS &agenda, int id) {
    TAgendaLS alias = agenda;
    TAgendaLS aux = NULL;
    while (idTEvento(alias->evento) != id)
    {
        aux = alias;
        alias = alias->sig;
    }
    if (aux != NULL)
    {
        aux->sig = alias->sig;
    }
    else
    {
        agenda = agenda->sig;
    }
    alias->sig = NULL;
    liberarAgendaLS(alias);
    
}



///////////////////////////////////
////// FIN CÓDIGO TAREA 2 //////
///////////////////////////////////
