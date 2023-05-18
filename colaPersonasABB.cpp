#include "../include/colaPersonasABB.h"
#include "../include/personasLDE.h"

struct nodo_colaPersonasABB{
  TPersonasABB persona;
  nodo_colaPersonasABB *sig;
};

typedef struct nodo_colaPersonasABB *TNodoCola;

struct rep_colaPersonasABB{
  TColaPersonasABB inicio;
  TColaPersonasABB final;
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
  

}

void encolarEnTColaPersonasABB(TPersonasABB t, TColaPersonasABB &c) {

}

TPersonasABB frenteDeTColaPersonasABB(TColaPersonasABB c) { 
  return NULL;
}

void desencolarDeTColaPersonasABB(TColaPersonasABB &c) {

}
