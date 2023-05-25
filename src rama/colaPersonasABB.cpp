#include "../include/colaPersonasABB.h"
#include "../include/personasLDE.h"

struct nodo_colaPersonasABB {
  TPersonasABB dato;
  nodo_colaPersonasABB *sig;
};

typedef nodo_colaPersonasABB *TNodo;

struct rep_colaPersonasABB {
  nodo_colaPersonasABB *inicio;
  nodo_colaPersonasABB *ultimo;
  nat cantidad;

};

TNodo crearNodo(TPersonasABB t, TNodo sig) {
  TNodo n = new nodo_colaPersonasABB;
  n->dato = t;
  n->sig = sig;
  return n;
}

TColaPersonasABB crearTColaPersonasABB() {
  TColaPersonasABB c = new rep_colaPersonasABB;
  c->inicio = NULL;
  c->ultimo = NULL;
  c->cantidad = 0;
  return c;
}

void liberarTColaPersonasABB(TColaPersonasABB &c) {
  if (c != NULL) {
    nodo_colaPersonasABB *aux = c->inicio;
    while (aux != NULL) {
      nodo_colaPersonasABB *aBorrar = aux;
      aux = aux->sig;
      delete aBorrar;
      c->cantidad--;
    }
    delete c;
    c = NULL;
  }

}

nat cantidadEnTColaPersonasABB(TColaPersonasABB c) { 
  return c->cantidad;
 }

void encolarEnTColaPersonasABB(TPersonasABB t, TColaPersonasABB &c) {
  
nodo_colaPersonasABB *nuevo = crearNodo(t, NULL) ;
if (c->cantidad == 0) {
  c->inicio = nuevo;
  c->ultimo = nuevo;
  c->cantidad++;
} else {
  c->ultimo->sig = nuevo;
  c->ultimo = nuevo;
  c->cantidad++;
}
}

TPersonasABB frenteDeTColaPersonasABB(TColaPersonasABB c) { 
  return c->inicio->dato;
}

void desencolarDeTColaPersonasABB(TColaPersonasABB &c) {
  nodo_colaPersonasABB *aux = c->inicio;
  c->inicio = c->inicio->sig;
  delete aux;
  aux = NULL;
  c->cantidad--;

}
