#include "../include/personasABB.h"
#include "../include/colaPersonasABB.h"

///////////////////////////////////
////// PEGAR CÓDIGO TAREA 2 //////
///////////////////////////////////

struct rep_personasAbb {
    TPersona persona;
    TPersonasABB izquierda;
    TPersonasABB derecha;
    
};

TPersonasABB crearTPersonasABB() {
    TPersonasABB arbol = new rep_personasAbb;
    arbol->persona = NULL;
    arbol->izquierda = NULL;
    arbol->derecha = NULL;
    return arbol;
}

bool esVacioTPersonasABB(TPersonasABB personasABB) {
    return (personasABB == NULL) || (personasABB->persona == NULL) ;
    

}

void insertarTPersonasABB(TPersonasABB &personasABB, TPersona p) {
    if (personasABB == NULL)
    {
        personasABB = crearTPersonasABB();
        personasABB->persona = p;
    }
    else
    {
        if (personasABB->persona != NULL)
        {
            if (idTPersona(p) < idTPersona(personasABB->persona))
            {
                insertarTPersonasABB(personasABB->izquierda, p);
            }
            else
            {
                if(idTPersona(p) > idTPersona(personasABB->persona))
                {
                insertarTPersonasABB(personasABB->derecha, p);
                }
            }
        }
        else 
        {
            personasABB->persona = p;
        }
    }


}

void liberarTPersonasABB(TPersonasABB &personasABB) {
    if (personasABB != NULL)
    {
        liberarTPersonasABB(personasABB->izquierda);
        liberarTPersonasABB(personasABB->derecha);
        if (personasABB->persona != NULL)
        {
            liberarTPersona(personasABB->persona);
        }
        delete personasABB;
        personasABB = NULL;
    
    }

}

void imprimirTPersonasABB(TPersonasABB personasABB) {
    if(personasABB != NULL)
    {
        imprimirTPersonasABB(personasABB->izquierda);
        if (personasABB->persona != NULL)
        {
        imprimirTPersona(personasABB->persona);
        }
        imprimirTPersonasABB(personasABB->derecha);
    }
   
}

nat cantidadTPersonasABB(TPersonasABB personasABB) {
    if (personasABB != NULL)
    {
        if (personasABB->persona != NULL)
        {
            return 1 + cantidadTPersonasABB(personasABB->izquierda) + cantidadTPersonasABB(personasABB->derecha);
        }
        else
        {
            return cantidadTPersonasABB(personasABB->izquierda) + cantidadTPersonasABB(personasABB->derecha);
        }

    }
    else
    {
        return 0;
    }
    
}

TPersona maxIdPersona(TPersonasABB personasABB) {
    if (personasABB->derecha != NULL)
    {
        return maxIdPersona(personasABB->derecha);
    }
    return personasABB->persona;
    
}

void removerTPersonasABB(TPersonasABB &personasABB, nat id) {
    if (personasABB != NULL)
    {
        if (id < idTPersona(personasABB->persona))
        {
            removerTPersonasABB(personasABB->izquierda, id);
        } else if (id > idTPersona(personasABB->persona)) {
            removerTPersonasABB(personasABB->derecha, id);
        } else {
            if (personasABB->derecha == NULL)
            {
                TPersonasABB aBorrar = personasABB;

                personasABB = personasABB->izquierda;

                liberarTPersona(aBorrar->persona);

                delete aBorrar;
            } else if (personasABB->izquierda == NULL) {
                TPersonasABB aBorrar = personasABB;

                personasABB = personasABB->derecha;

                liberarTPersona(aBorrar->persona);

                delete aBorrar;
            } else {
                liberarTPersona(personasABB->persona);

                personasABB->persona = copiarTPersona(maxIdPersona(personasABB->izquierda));

                removerTPersonasABB(personasABB->izquierda, idTPersona(personasABB->persona));
            }
        }
    }
}

bool estaTPersonasABB(TPersonasABB personasABB, nat id) {
if (personasABB == NULL)
    {
        return false;
    } else {
        if (id == idTPersona(personasABB->persona))
        {
            return true;
        } else {
            return (estaTPersonasABB(personasABB->izquierda, id) or estaTPersonasABB(personasABB->derecha, id));
        }
    }
}

TPersona obtenerDeTPersonasABB(TPersonasABB personasABB, nat id) {
    if (idTPersona(personasABB->persona)<id)
    {
        return obtenerDeTPersonasABB(personasABB->derecha, id);
    }
    else
    {
        if (idTPersona(personasABB->persona)>id)
        {
            return obtenerDeTPersonasABB(personasABB->izquierda, id);
        }
        return personasABB->persona;
    }
}

nat alturaTPersonasABB(TPersonasABB personasABB) {
    if ((personasABB != NULL) and (personasABB->persona != NULL))
    {
        nat alturaIzquierda = alturaTPersonasABB(personasABB->izquierda);
        nat alturaDerecha = alturaTPersonasABB(personasABB->derecha);
        if (alturaIzquierda > alturaDerecha)
        {
            return alturaIzquierda + 1;
        }
        else
        {
            return alturaDerecha + 1;
        }
    }
    else
    {
        return 0;
    }
}

bool esPerfectoTPersonasABB(TPersonasABB personasABB) {
    if ((personasABB != NULL) and (personasABB->persona != NULL))
    {
        if (personasABB->izquierda == NULL and personasABB->derecha == NULL)
        {
            return true;
        }
        else
        {
            if (personasABB->izquierda != NULL and personasABB->derecha != NULL)
            {
                return ((esPerfectoTPersonasABB(personasABB->izquierda)) and (esPerfectoTPersonasABB(personasABB->derecha))and (alturaTPersonasABB(personasABB->izquierda) == alturaTPersonasABB(personasABB->derecha)));
            }
            else
            {
                return false;
            }
        }
    }
    else
    {
        return true;
    }

}
TPersonasABB mayoresTPersonasABB(TPersonasABB personasABB, nat edad) {
if (personasABB == NULL) {
        return NULL;
    }
    TPersonasABB mayores = NULL;
    if (edadTPersona(personasABB->persona) > edad) 
    {
        mayores = crearTPersonasABB();
        mayores->persona = copiarTPersona(personasABB->persona);
        mayores->izquierda = mayoresTPersonasABB(personasABB->izquierda, edad);
        mayores->derecha = mayoresTPersonasABB(personasABB->derecha, edad);
    } 
    else
    {
        mayores = mayoresTPersonasABB(personasABB->izquierda, edad);        
        mayores = mayoresTPersonasABB(personasABB->derecha, edad);
    }
    
    return mayores;
}

void aplanarEnLista(TPersonasABB t, TPersonasLDE &l){
    if (t != NULL)
    {
        aplanarEnLista(t->derecha, l);
        insertarTPersonasLDE(l, copiarTPersona(t->persona), 1);
        aplanarEnLista(t->izquierda, l);
    }
}

TPersonasLDE aTPersonasLDE(TPersonasABB personasABB) {
    TPersonasLDE l = crearTPersonasLDE();
    if (esVacioTPersonasABB(personasABB) == false)
    {
        aplanarEnLista(personasABB, l);
    }
    return l;
}

///////////////////////////////////
////// FIN CÓDIGO TAREA 2 //////
///////////////////////////////////

///////////////////////////////////////////////////////////////////////////
/////////////  NUEVAS FUNCIONES  //////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////

nat amplitudTPersonasABB(TPersonasABB personasABB) {

    TColaPersonasABB nivel = crearTColaPersonasABB();
    if (personasABB != NULL && personasABB->persona != NULL){
        encolarEnTColaPersonasABB(personasABB, nivel);
    }
    nat cant = cantidadEnTColaPersonasABB(nivel); 
    nat max = cant;
    while (cant > 0){
        while (cant > 0){
            TPersonasABB nodo = frenteDeTColaPersonasABB(nivel);
            desencolarDeTColaPersonasABB(nivel);
            if (nodo->izquierda != NULL){
                encolarEnTColaPersonasABB(nodo->izquierda, nivel);
            }
            if (nodo->derecha != NULL){
                encolarEnTColaPersonasABB(nodo->derecha, nivel);
            }
            cant--;
        }
        cant = cantidadEnTColaPersonasABB(nivel);
        if (cant > max){
        max = cant; 
        }
    }
    liberarTColaPersonasABB(nivel);
    return max;
}

TPilaPersona serializarTPersonasABB(TPersonasABB t)
{
    TPilaPersona aux = crearTPilaPersona();
    TColaPersonasABB nivel = crearTColaPersonasABB();
    if (t != NULL)
    {
        encolarEnTColaPersonasABB(t, nivel);
        nat cant = cantidadEnTColaPersonasABB(nivel);
        while (cant > 0)
        {
        nat cantNivel = cant; 
        while (cantNivel > 0)
        {
                TPersonasABB nodo = frenteDeTColaPersonasABB(nivel);
                desencolarDeTColaPersonasABB(nivel);
                if (nodo->izquierda != NULL)
                {
                encolarEnTColaPersonasABB(nodo->izquierda, nivel);
                }
                if (nodo->derecha != NULL)
                {
                encolarEnTColaPersonasABB(nodo->derecha, nivel);
                }
                if (nodo->persona != NULL)
                {
                apilarEnTPilaPersona(aux, nodo->persona);
                }
                cantNivel--;
        }
        cant = cantidadEnTColaPersonasABB(nivel); 
        }
    }
    TPilaPersona nuevo = crearTPilaPersona();
    while (cantidadEnTPilaPersona(aux) > 0)
    {
        apilarEnTPilaPersona(nuevo, cimaDeTPilaPersona(aux));
        desapilarDeTPilaPersona(aux);
    }
    liberarTPilaPersona(aux);
    liberarTColaPersonasABB(nivel);
    return nuevo;
}

TPersonasABB deserializarTPersonasABB(TPilaPersona &t) {
    if (cantidadEnTPilaPersona(t) != 0){
        TPersonasABB nuevoArbol = crearTPersonasABB();
        nuevoArbol->persona = copiarTPersona(cimaDeTPilaPersona(t));
        desapilarDeTPilaPersona(t);
        TColaPersonasABB nivel = crearTColaPersonasABB();
        encolarEnTColaPersonasABB(nuevoArbol, nivel);
        while (cantidadEnTPilaPersona(t) > 0){
            while (cantidadEnTColaPersonasABB(nivel) > 0){
                TPersonasABB frente = frenteDeTColaPersonasABB(nivel);
                desencolarDeTColaPersonasABB(nivel);
                if (cantidadEnTPilaPersona(t) > 0){
                    frente->izquierda = crearTPersonasABB();
                    frente->izquierda->persona = copiarTPersona(cimaDeTPilaPersona(t));
                    desapilarDeTPilaPersona(t);
                    encolarEnTColaPersonasABB(frente->izquierda, nivel);
                }
                if (cantidadEnTPilaPersona(t) > 0){
                    frente->derecha = crearTPersonasABB();
                    frente->derecha->persona = copiarTPersona(cimaDeTPilaPersona(t));
                    desapilarDeTPilaPersona(t);
                    encolarEnTColaPersonasABB(frente->derecha, nivel);
                }
            }
        }
        liberarTColaPersonasABB(nivel);
        liberarTPilaPersona(t);
        return nuevoArbol; 
    }
    else
    {
        return NULL;
    }    
}
///////////////////////////////////////////////////////////////////////////
/////////////  FIN NUEVAS FUNCIONES  //////////////////////////////////////
///////////////////////////////////////////////////////////////////////////

