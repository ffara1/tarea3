#include "../include/conjuntoIds.h"

struct rep_conjuntoIds{
	nat cantMax;
	nat cant;
	bool *elementos;
};


TConjuntoIds crearTConjuntoIds(nat cantMax){
	TConjuntoIds nuevoConjunto = new rep_conjuntoIds;
	nuevoConjunto->cantMax = cantMax;
	nuevoConjunto->cant = 0;
	nuevoConjunto->elementos = new bool[cantMax];
	for (nat i = 0; i < cantMax; i++){
		nuevoConjunto->elementos[i] = false;
	}
	return nuevoConjunto;
};


bool esVacioTConjuntoIds(TConjuntoIds c){
	return (c != NULL && c->cant == 0);
};


void insertarTConjuntoIds(nat id, TConjuntoIds &c){
	if (0 < id && id <= c->cantMax && c->cant < c->cantMax){
		c->cant++;
		c->elementos[id - 1] = true;	
	}
}; 

bool perteneceTConjuntoIds(nat id, TConjuntoIds c);

void borrarTConjuntoIds(nat id, TConjuntoIds &c){
	if (perteneceTConjuntoIds(id, c)){
		c->elementos[id - 1] = false;
		c->cant--;
	}
};

bool perteneceTConjuntoIds(nat id, TConjuntoIds c){
	return	(0 < id && id <= c->cantMax && c->elementos[id - 1]);
};

nat cardinalTConjuntoIds(TConjuntoIds c){
	return c->cant;
};

nat cantMaxTConjuntoIds(TConjuntoIds c){
	return c->cantMax;
};

void imprimirTConjuntoIds(TConjuntoIds c){
	if (c != NULL && c->cant > 0){
		for (nat i = 0; i < c->cantMax; i++){
			if (c->elementos[i]){
				printf("%d ", i + 1);
			}
		}
	}
	printf("\n");
};

void liberarTConjuntoIds(TConjuntoIds &c){
	delete[] c->elementos;
	delete c;
	c = NULL;
};


TConjuntoIds unionTConjuntoIds(TConjuntoIds c1, TConjuntoIds c2){
	TConjuntoIds nuevoConjunto = crearTConjuntoIds(c1->cantMax + c2->cantMax);
	if (c1 == NULL){
		nuevoConjunto = c2;
	} else if (c2 == NULL){
		nuevoConjunto = c1;
	} else {
		nuevoConjunto->cant = c1->cant + c2->cant;
		for (nat i = 0; i < c1->cantMax; i++){
			if (c1->elementos[i]){
				nuevoConjunto->elementos[i] = true;
			}
		}
		for (nat i = 0; i < c2->cantMax; i++){
			if (c2->elementos[i]){
				nuevoConjunto->elementos[i] = true;
			}
		}
	}
	return nuevoConjunto;
};

TConjuntoIds interseccionTConjuntoIds(TConjuntoIds c1, TConjuntoIds c2){
	TConjuntoIds interseccion = crearTConjuntoIds(c1->cantMax);
	if (c1 == NULL || c2 == NULL){
		return interseccion;
	} else {
		for (nat i = 0; i < c1->cant; i++){
			if (c1->elementos[i] && c2->elementos[i]){
				interseccion->cant++;
				interseccion->elementos[i] = true;
			}
		}
	}
	return interseccion;
};

TConjuntoIds diferenciaTConjuntoIds(TConjuntoIds c1, TConjuntoIds c2){
	TConjuntoIds diferencia = crearTConjuntoIds(c1->cantMax);
	if (c1 == NULL){
		diferencia = c2;
	} else if (c2 == NULL){
		diferencia = c1;
	} else {
		for (nat i = 0; i < c2->cantMax; i++){
			if (c1->elementos[i] && !c2->elementos[i]){
				diferencia->cant++;
				diferencia->elementos[i] = true;
			}
		}
	}
	return diferencia;
};

