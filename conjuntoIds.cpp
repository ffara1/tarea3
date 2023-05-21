#include "../include/conjuntoIds.h"

struct rep_conjuntoIds{
	nat cantMax;
	nat cant;
	nat *elementos;
};


TConjuntoIds crearTConjuntoIds(nat cantMax){
	TConjuntoIds nuevoConjunto = new rep_conjuntoIds;
	nuevoConjunto->cantMax = cantMax;
	nuevoConjunto->cant = 0;
	nuevoConjunto->elementos = new nat[cantMax];
	return nuevoConjunto;
};


bool esVacioTConjuntoIds(TConjuntoIds c){
	return (c->cant == 0);
};


void insertarTConjuntoIds(nat id, TConjuntoIds &c){
	if	(0 < id && id <= c->cantMax && c->cant < c->cantMax){
		c->cant++;
		c->elementos[c->cant] = id;
	}
}; 

void borrarTConjuntoIds(nat id, TConjuntoIds &c){
	if (perteneceTConjuntoIds(id, c) && c->elementos[id] == id){
		c->elementos[c->cant] = 0;
		c->cant--;
	}
};

bool perteneceTConjuntoIds(nat id, TConjuntoIds c){
	return (0 < id && id <= c->cant);
};


nat cardinalTConjuntoIds(TConjuntoIds c){
	return c->cant;
};

nat cantMaxTConjuntoIds(TConjuntoIds c){
	return c->cantMax;
};

void imprimirTConjuntoIds(TConjuntoIds c){
	printf("%d \n", c->elementos[0]);
	for (nat i = 1; i <= c->cant; i++){
		printf("%d \n", c->elementos[i]);
	}
};

void liberarTConjuntoIds(TConjuntoIds &c){
	delete[] c->elementos;
	delete c;
};




TConjuntoIds unionTConjuntoIds(TConjuntoIds c1, TConjuntoIds c2){
	TConjuntoIds nuevoConjunto = crearTConjuntoIds(c1->cantMax + c2->cantMax);
	if (c1 == NULL){
		nuevoConjunto = c2;
	} else if (c2 == NULL){
		nueviConjunto = c1;
	} else {
		for (nat i = 0; i <= c1->cant; i++){
			nuevoConjunto->elementos[i] = c1->elementos[i];
			nuevoConjunto->elementos[i + 1] = c2->elementos[i];
		}
		nuevoConjunto->cant = c1->cant + c2->cant;
	}
	return nuevoConjunto;
};

TConjuntoIds interseccionTConjuntoIds(TConjuntoIds c1, TConjuntoIds c2){
	return NULL;
};

TConjuntoIds diferenciaTConjuntoIds(TConjuntoIds c1, TConjuntoIds c2){
	return NULL;
};
