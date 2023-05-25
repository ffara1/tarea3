#include "../include/pilaPersona.h"
#include "../include/personasLDE.h"

struct rep_pilaPersona {
  TPersonasLDE personas;
  nat cantidad;

};

TPilaPersona crearTPilaPersona() {
  TPilaPersona p = new rep_pilaPersona;
  p->personas = NULL;
  p->cantidad = 0;
  return p;

}

void liberarTPilaPersona(TPilaPersona &p) {

  if (p->personas != NULL) {  
      liberarTPersonasLDE(p->personas);
  }
  delete p;
  p = NULL;
}

nat cantidadEnTPilaPersona(TPilaPersona p) { 
  return p->cantidad;
}

void apilarEnTPilaPersona(TPilaPersona &p, TPersona persona) {
  TPersona aux = copiarTPersona(persona);
  p->cantidad++;
  if (p != NULL){
    if (p->personas == NULL) {
      p->personas = crearTPersonasLDE();
    }
    insertarFinalDeTPersonasLDE(p->personas, aux);
  }

}

TPersona cimaDeTPilaPersona(TPilaPersona p) { 
  return obtenerFinalDeTPersonasLDE(p->personas);
  
}

void desapilarDeTPilaPersona(TPilaPersona &p) {
  if (p->personas != NULL){
    eliminarFinalTPersonasLDE(p->personas);
    p->cantidad--;
  }
}
