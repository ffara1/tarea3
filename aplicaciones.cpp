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
    return pila;
}

bool sumaPares(nat k, TConjuntoIds c){
    nat i = 1;
    nat j = k - 1;
    while (i < j && (!perteneceTConjuntoIds(i, c) || !perteneceTConjuntoIds(j, c))){
        i++;
        j--;
    }
    return (i < j);
}