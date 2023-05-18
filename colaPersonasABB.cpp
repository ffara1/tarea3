#include "../include/colaPersonasABB.h"
#include "../include/personasLDE.h"

struct nodo_colaPersonasABB{
  TPersonasABB persona;
  nodo_colaPersonasABB *sig;
};

typedef struct nodo_colaPersonasABB *TNodoCola;

struct rep_colaPersonasABB{
  TNodoCola inicio;
  TNodoCola final;
  nat cantPersonas;
};

TNodoCola crearNodoCola(TPersonasABB persona, TNodoCola sig) {
  TNodoCola nodo = new nodo_colaPersonasABB;
  nodo->persona = persona;
  nodo->sig = sig;
  return nodo;
}

TColaPersonasABB crearTColaPersonasABB() {
  TColaPersonasABB cola = new rep_colaPersonasABB;
  cola->inicio = NULL;
  cola->final = NULL;
  cola->cantPersonas = 0;
  return cola;
}

void liberarTColaPersonasABB(TColaPersonasABB &c) {
  TNodoCola aux = c->inicio;
  while (aux != NULL){
    liberarTPersonasABB(aux->persona);
    TNodoCola aBorrar = aux;
    aux = aux->sig;
    delete aBorrar;
  }
  delete c;
  c = NULL;
}

nat cantidadEnTColaPersonasABB(TColaPersonasABB c) { 
  return c->cantPersonas;
}

void encolarEnTColaPersonasABB(TPersonasABB t, TColaPersonasABB &c){
  TNodoCola aEncolar = new nodo_colaPersonasABB;
  aEncolar->persona = t;
  aEncolar->sig = NULL;
  if (c->inicio != NULL){
    c->final->sig = aEncolar;
    c->final = aEncolar;
  } else{
    c->inicio = aEncolar;
    c->final = aEncolar;
  }
  c->cantPersonas++
}

TPersonasABB frenteDeTColaPersonasABB(TColaPersonasABB c){
  return c->inicio->persona;
}

void desencolarDeTColaPersonasABB(TColaPersonasABB &c) {
  TNodoCola aux = c->inicio;
  c->inicio = aux->sig;
  liberarTPersonasABB(aux->persona)
  delete aux;
  c->cantPersonas--;
}
