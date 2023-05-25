#include "../include/conjuntoIds.h"

struct rep_conjuntoIds{
	nat cantMax;
	nat cantElem;
	bool *elem;
    
};


TConjuntoIds crearTConjuntoIds(nat cantMax){
	TConjuntoIds c = new rep_conjuntoIds;
	c->cantMax = cantMax;
	c->cantElem = 0;
	c->elem = new bool[cantMax];
	for (nat i = 0; i < cantMax; i++){
		c->elem[i] = false;
	}
	return c;
};


bool esVacioTConjuntoIds(TConjuntoIds c){
	return ((c != NULL) and (c->cantElem == 0));
};


void insertarTConjuntoIds(nat id, TConjuntoIds &c){
	if (c != NULL){
		if ((c->cantElem < c->cantMax) and (id > 0) and (id <= c->cantMax)){
			c->elem[id-1] = true;
			c->cantElem++;
		}
	}
    
}; 

void borrarTConjuntoIds(nat id, TConjuntoIds &c){
	if (perteneceTConjuntoIds(id, c)){
		c->elem[id-1] = false;
		c->cantElem--;
	}

     
};

bool perteneceTConjuntoIds(nat id, TConjuntoIds c){
	return ((c != NULL) and (id > 0) and (id <= c->cantMax) and (c->elem[id-1]));
};


nat cardinalTConjuntoIds(TConjuntoIds c){
	return c->cantElem;
};

nat cantMaxTConjuntoIds(TConjuntoIds c){
	return c->cantMax;
};

void imprimirTConjuntoIds(TConjuntoIds c){
	if (c != NULL){
		if (!esVacioTConjuntoIds(c)){
			for (nat i = 0; i < c->cantMax; i++){
				if (c->elem[i]){
					printf("%d ", i+1);
				}
			}
		}
	}
	printf("\n");
};

void liberarTConjuntoIds(TConjuntoIds &c){
	delete[] c->elem;
	delete c;
	c = NULL;
};




TConjuntoIds unionTConjuntoIds(TConjuntoIds c1, TConjuntoIds c2){
	TConjuntoIds c = crearTConjuntoIds(c1->cantMax + c2->cantMax);
	if (c1 == NULL){
		return c2;
	}
	if (c2 == NULL){
		return c1;
	}
	for (nat i = 0; i < c1->cantMax; i++){
		if (c1->elem[i]){
			c->elem[i] = true;
			c->cantElem++;
		}
	}
	for (nat i = 0; i < c2->cantMax; i++){
		if (c2->elem[i]){
			c->elem[i] = true;
			c->cantElem++;
		}
	}	
	return c;
};

TConjuntoIds interseccionTConjuntoIds(TConjuntoIds c1, TConjuntoIds c2){
	TConjuntoIds c = crearTConjuntoIds(c1->cantMax);
	if ((c1 == NULL) or (c2 == NULL)){
		return c;
	}
	for (nat i = 0; i < c1->cantMax; i++){
		if (c1->elem[i] and c2->elem[i]){
			c->elem[i] = true;
			c->cantElem++;
		}
	}
	return c;
};

TConjuntoIds diferenciaTConjuntoIds(TConjuntoIds c1, TConjuntoIds c2){
	TConjuntoIds c = crearTConjuntoIds(c1->cantMax);
	if (c1 == NULL){
		return c2;
	}
	if (c2 == NULL){
		return c1;
	}
	for (nat i = 0; i < c1->cantMax; i++){
		if (c1->elem[i] and !c2->elem[i]){
			c->elem[i] = true;
			c->cantElem++;
		}
	}
	return c;
};
