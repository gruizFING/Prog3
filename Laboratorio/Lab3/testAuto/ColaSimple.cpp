/* 4317743 */

#include "ColaSimple.h"
#include <stdlib.h>
#include <assert.h>

struct NodoCola;
typedef NodoCola* NodoC;

struct NodoCola {
	void* v;
	NodoC sig;
};

struct ColaSimple {
	NodoC ppio;
	NodoC final;
};


ColaSimple* crearColaSimple() {
	ColaSimple* c = new ColaSimple;
	c->ppio = NULL;
	c->final = NULL;
	return c;
}

bool esVaciaColaSimple(ColaSimple* c) {
	return (c->ppio == NULL);
}

void encolarColaSimple(ColaSimple* &c, void* v) {
	NodoC nuevo = new NodoCola;
	nuevo->v = v;
	nuevo->sig = NULL;
	if (c->ppio == NULL)
	{
		c->ppio = nuevo;
		c->final = nuevo;
	}
	else
	{
		c->final->sig = nuevo;
		c->final = nuevo;
	}
}

void* desencolarColaSimple(ColaSimple* &c) {
	assert(c->ppio != NULL);
	NodoC aBorrar = c->ppio;
	c->ppio = c->ppio->sig;
	if (c->ppio == NULL)
		c->final = NULL;
	void* v = aBorrar->v;
	delete aBorrar;
	return v;
}

void destruirColaSimple(ColaSimple* &c) {
	while (c->ppio != NULL)
		desencolarColaSimple(c);
	delete c;
}


