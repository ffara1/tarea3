#include "../include/aplicaciones.h"

TPilaPersona menoresQueElResto(TPersonasLDE lista) {
    TPilaPersona pila = crearTPilaPersona();
    while (cantidadTPersonasLDE(lista) > 0){
        TPersona p = obtenerInicioDeTPersonasLDE(lista);
        while (cantidadEnTPilaPersona(pila) > 0 && edadTPersona(p) < edadTPersona(cimaDeTPilaPersona(pila))){
            desapilarDeTPilaPersona(pila);
        }
        apilarEnTPilaPersona(pila, p);
        eliminarInicioTPersonasLDE(lista);
    }
}

bool sumaPares(nat k, TConjuntoIds c){
    return false;
}