#include "../include/pilaPersona.h"
#include "../include/personasLDE.h"

struct rep_pilaPersona{
  TPersonasLDE personas;
  int tope;
};

TPilaPersona crearTPilaPersona(){
  TPilaPersona pila = new rep_pilaPersona;
  pila->personas = NULL;
  pila->tope = 0;
  return pila;
}

void liberarTPilaPersona(TPilaPersona &p){
    if (p->personas != NULL){
      liberarTPersonasLDE(p->personas);
    }
    delete p;
    p = NULL;
}

nat cantidadEnTPilaPersona(TPilaPersona p){
  return p->tope;
}

void apilarEnTPilaPersona(TPilaPersona &p, TPersona persona){
  TPersona nuevo = copiarTPersona(persona);
  p->tope++;
  if (p != NULL){
    if (p->personas == NULL){
      p->personas = crearTPersonasLDE();
    }
    insertarFinalDeTPersonasLDE(p->personas, nuevo);
  }
}

TPersona cimaDeTPilaPersona(TPilaPersona p){
  return obtenerFinalDeTPersonasLDE(p->personas);
}

void desapilarDeTPilaPersona(TPilaPersona &p){
  if (p->personas != NULL){
    eliminarFinalTPersonasLDE(p->personas);
    p->tope--;
  } 
}
