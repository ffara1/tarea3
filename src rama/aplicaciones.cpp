#include "../include/aplicaciones.h"

TPilaPersona menoresQueElResto(TPersonasLDE lista) {
    TPilaPersona res = crearTPilaPersona();
    while (cantidadTPersonasLDE(lista)>0){
        TPersona p = obtenerInicioDeTPersonasLDE(lista);
        while ((cantidadEnTPilaPersona(res)>0) and edadTPersona(p) < edadTPersona(cimaDeTPilaPersona(res))){
            desapilarDeTPilaPersona(res);
        }
         apilarEnTPilaPersona(res, p);
         eliminarInicioTPersonasLDE(lista);   
    }
    return res;    
}

bool sumaPares(nat k, TConjuntoIds c){
    nat i = 1;
    nat j = k-1;
    while (i < j and (!perteneceTConjuntoIds(i, c) or !perteneceTConjuntoIds(j, c))){
        i++;
        j--;
    }
    return i < j;
}