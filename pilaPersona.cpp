#include "../include/pilaPersona.h"
#include "../include/personasLDE.h"

struct rep_pilaPersona{
  TPersonasLDE personas;
  int tope;
};

TPilaPersona crearTPilaPersona(){
  TPilaPersona pila = new rep_pilaPersona;
  pila->personas = crearTPersonasLDE();
  pila->tope = 0;
  return pila;
}

void liberarTPilaPersona(TPilaPersona &p){
  int i = 0;
  while (i <= p->tope)
  {
    liberarTPersonasLDE(p->personas);
    i++;
  }
  delete p;
}

nat cantidadEnTPilaPersona(TPilaPersona p){
  return p->tope;
}

void apilarEnTPilaPersona(TPilaPersona &p, TPersona persona){
  TPersona nuevo = copiaTPersona(persona);
  p->tope++;
  insertarTPersonasLDE(p->personas, nuevo, p->tope);
}

TPersona cimaDeTPilaPersona(TPilaPersona p){
  return obtenerInicioDeTPersonasLDE(p->personas);
}

void desapilarDeTPilaPersona(TPilaPersona &p){
  eliminarFinalDeTPersonasLDE(p->personas);
  p->tope--;
}
