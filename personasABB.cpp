lo#include "../include/personasABB.h"
#include "../include/colaPersonasABB.h"

///////////////////////////////////
////// PEGAR CÓDIGO TAREA 2 //////
///////////////////////////////////

struct rep_personasAbb
{
    TPersona persona;
    rep_personasAbb *izq;
    rep_personasAbb *der;
};

TPersonasABB crearTPersonasABB()
{
    TPersonasABB nuevoArbol = new rep_personasAbb;
    nuevoArbol->persona = NULL;
    nuevoArbol->izq = NULL;
    nuevoArbol->der = NULL;
    return nuevoArbol;
}

bool esVacioTPersonasABB(TPersonasABB personasABB)
{
    return ((personasABB == NULL) || (personasABB->persona == NULL));
}

void insertarTPersonasABB(TPersonasABB &personasABB, TPersona p)
{
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
                insertarTPersonasABB(personasABB->izq, p);
            }
            else
            {
                if (idTPersona(p) > idTPersona(personasABB->persona))
                {
                    insertarTPersonasABB(personasABB->der, p);
                }
            }
        }
        else
        {
            personasABB->persona = p;
        }
    }
}

void liberarTPersonasABB(TPersonasABB &personasABB)
{
    if (personasABB != NULL)
    {
        liberarTPersonasABB(personasABB->izq);
        liberarTPersonasABB(personasABB->der);
        if (personasABB->persona != NULL)
        {
            liberarTPersona(personasABB->persona);
        }
    }
    delete personasABB;
    personasABB = NULL;
}

void imprimirTPersonasABB(TPersonasABB personasABB)
{
    if ((personasABB != NULL) && (personasABB->persona != NULL))
    {
        imprimirTPersonasABB(personasABB->izq);
        imprimirTPersona(personasABB->persona);
        imprimirTPersonasABB(personasABB->der);
    }
}

nat cantidadTPersonasABB(TPersonasABB personasABB)
{
    if (personasABB == NULL)
    {
        return 0;
    }
    else
    {
        if (personasABB->persona == NULL)
        {
            return cantidadTPersonasABB(personasABB->izq) + cantidadTPersonasABB(personasABB->der);
        }
        else
        {
            return 1 + cantidadTPersonasABB(personasABB->izq) + cantidadTPersonasABB(personasABB->der);
        }
    }
}

TPersona maxIdPersona(TPersonasABB personasABB)
{
    if (personasABB->der != NULL)
    {
        return maxIdPersona(personasABB->der);
    }
    return personasABB->persona;
}

void removerTPersonasABB(TPersonasABB &personasABB, nat id)
{
    if (personasABB != NULL)
    {
        if (id < idTPersona(personasABB->persona))
        {
            removerTPersonasABB(personasABB->izq, id);
        }
        else
        {
            if (id > idTPersona(personasABB->persona))
            {
                removerTPersonasABB(personasABB->der, id);
            }
            else
            {
                if (personasABB->der == NULL)
                {
                    TPersonasABB aux = personasABB;
                    personasABB = personasABB->izq;
                    liberarTPersona(aux->persona);
                    delete aux;
                }
                else
                {
                    if (personasABB->izq == NULL)
                    {
                        TPersonasABB aux = personasABB;
                        personasABB = personasABB->der;
                        liberarTPersona(aux->persona);
                        delete aux;
                    }
                    else
                    {
                        liberarTPersona(personasABB->persona);
                        personasABB->persona = copiarTPersona(maxIdPersona(personasABB->izq));
                        removerTPersonasABB(personasABB->izq, idTPersona(personasABB->persona));
                    }
                }
            }
        }
    }
}

bool estaTPersonasABB(TPersonasABB personasABB, nat id)
{
    if ((personasABB != NULL) and (idTPersona(personasABB->persona) != id))
    {
        return estaTPersonasABB(personasABB->izq, id) || estaTPersonasABB(personasABB->der, id);
    }
    else
    {
        if (personasABB != NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

TPersona obtenerDeTPersonasABB(TPersonasABB personasABB, nat id)
{
    if (idTPersona(personasABB->persona) == id)
    {
        return personasABB->persona;
    }
    else
    {
        if (id < idTPersona(personasABB->persona))
        {
            return obtenerDeTPersonasABB(personasABB->izq, id);
        }
        else
        {
            return obtenerDeTPersonasABB(personasABB->der, id);
        }
    }
}

nat alturaTPersonasABB(TPersonasABB personasABB)
{
    nat totalDer, totalIzq;
    if (personasABB != NULL && personasABB->persona != NULL)
    {
        totalIzq = alturaTPersonasABB(personasABB->izq);
        totalDer = alturaTPersonasABB(personasABB->der);
        if (totalIzq < totalDer)
        {
            return (1 + totalDer);
        }
        else
        {
            return (1 + totalIzq);
        }
    }
    else
    {
        return 0;
    }
}

bool estaLlenoABB(TPersonasABB personasABB)
{
    if (personasABB == NULL)
    {
        return true;
    }
    else
    {
        if (personasABB->izq == NULL && personasABB->der == NULL)
        {
            return true;
        }
        else
        {
            if (personasABB->izq != NULL && personasABB->der != NULL)
            {
                return estaLlenoABB(personasABB->izq) && estaLlenoABB(personasABB->der);
            }
            else
            {
                return false;
            }
        }
    }
}

bool esPerfectoTPersonasABB(TPersonasABB personasABB)
{
    if (personasABB != NULL)
    {
        return estaLlenoABB(personasABB) && (alturaTPersonasABB(personasABB->izq)) == (alturaTPersonasABB(personasABB->der));
    }
    else
    {
        return (personasABB->persona == NULL);
    }
}

TPersonasABB mayoresTPersonasABB(TPersonasABB personasABB, nat edad)
{
    TPersonasABB mayores = NULL;
    if (personasABB != NULL)
    {
        if (edadTPersona(personasABB->persona) > edad)
        {
            mayores = crearTPersonasABB();
            mayores->persona = copiarTPersona(personasABB->persona);
            mayores->izq = mayoresTPersonasABB(personasABB->izq, edad);
            mayores->der = mayoresTPersonasABB(personasABB->der, edad);
        }
        else
        {
            mayores = mayoresTPersonasABB(personasABB->izq, edad);
            mayores = mayoresTPersonasABB(personasABB->der, edad);
        }
    }
    return mayores;
}

void aplanarArbol(TPersonasABB arbol, TPersonasLDE &auxPersonas)
{
    if (arbol != NULL)
    {
        aplanarArbol(arbol->der, auxPersonas);
        insertarTPersonasLDE(auxPersonas, copiarTPersona(arbol->persona), 1);
        aplanarArbol(arbol->izq, auxPersonas);
    }
}

TPersonasLDE aTPersonasLDE(TPersonasABB personasABB)
{
    TPersonasLDE nuevaLista = crearTPersonasLDE();
    if (!esVacioTPersonasABB(personasABB))
    {
        aplanarArbol(personasABB, nuevaLista);
    }
    return nuevaLista;
}

///////////////////////////////////
////// FIN CÓDIGO TAREA 2 //////
///////////////////////////////////

///////////////////////////////////////////////////////////////////////////
/////////////  NUEVAS FUNCIONES  //////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////

nat amplitudTPersonasABB(TPersonasABB t){
    if (t != NULL){
        
        TColaPersonasABB cola = crearColaABB();
        encolarABB(cola, t);
        nat cantEnCola = cantidadEnTColaPersonasABB(cola);
        nat amplitud = cantEnCola;
        while (cantEnCola > 0){
            TPersonasABB aux = frenteDeTColaPersonasABB(cola);
            desencolarDeTColaPersonasABB(cola);
            if (aux->izq != NULL){
                encolarEnTColaPersonasABB(cola, aux->izq);
            }
            if (aux->der != NULL){
                encolarEnTColaPersonasABB(cola, aux->der);
            }
            cantEnCola--;
            if (cantEnCola == 0){
                cantEnCola = cantidadEnTColaPersonasABB(cola);
                if (cantEnCola > amplitud){
                    amplitud = cantEnCola;
                }
            }
        }
        liberarTColaPersonasABB(cola);
        return amplitud;
    }
}

TPilaPersona serializarTPersonasABB(TPersonasABB &personasABB) {
    TPilaPersona pilaPersonas = crearTPilaPersona();
    if (personasABB != NULL) {
        TPilaPersona pilaIzq = serializarTPersonasABB(personasABB->izq);
        TPilaPersona pilaDer = serializarTPersonasABB(personasABB->der);
        if (personasABB->persona != NULL){
            apilarTPilaPersona(pilaPersonas, copiarTPersona(personasABB->persona));
        }
        liberarTPersonasABB(personasABB);
    }  
    return pilaPersonas;
}

TPersonasABB deserializarTPersonasABB(TPilaPersona &pilaPersonas) {
    TPersonasABB personasABB = crearTPersonasABB();
    if (pilaPersonas != NULL) {
        if (pilaPersonas->persona != NULL){
            personasABB->persona = copiarTPersona(cimaTPilaPersona(pilaPersonas));
        }
        desapilarTPilaPersona(pilaPersonas);
        personasABB->izq = deserializarTPersonasABB(pilaPersonas);
        personasABB->der = deserializarTPersonasABB(pilaPersonas);
        liberarTPilaPersona(pilaPersonas);
    }
    return personasABB;
}

///////////////////////////////////////////////////////////////////////////
/////////////  FIN NUEVAS FUNCIONES  //////////////////////////////////////
///////////////////////////////////////////////////////////////////////////

