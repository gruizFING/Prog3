/* 4317743 */

#include "ListaSimpleConPrioridad.h"
#include <stdlib.h>
#include <assert.h>

struct ListaSimpleConPrioridad {
	void* info;
	int   prio;
	ListaSimpleConPrioridad* sig;
};


ListaSimpleConPrioridad* crearListaSimpleConPrioridad() {
	return NULL;
}


bool esVaciaListaSimpleConPrioridad(ListaSimpleConPrioridad* l) {
	return (l == NULL);
}


ListaSimpleConPrioridad* agregarListaSimpleConPrioridad(ListaSimpleConPrioridad* &l, void* n, int prioridad) {
	ListaSimpleConPrioridad* nuevo = new ListaSimpleConPrioridad;
	nuevo->info = n;
	nuevo->prio = prioridad;
	if ((l == NULL) || (l->prio >= prioridad))
	{
		nuevo->sig  = l;
		l = nuevo;
	}
	else
	{
		ListaSimpleConPrioridad* pos = l;
		while ((pos->sig != NULL) && (pos->sig->prio < prioridad))
			pos = pos->sig;
		nuevo->sig = pos->sig;
		pos->sig = nuevo;
	}
	return l;
}


void* primeroListaSimpleConPrioridad(ListaSimpleConPrioridad* l) {
	assert(l != NULL);
	return (l->info);
}


int prioridadPrimeroListaSimpleConPrioridad(ListaSimpleConPrioridad* l) {
	assert(l != NULL);
	return (l->prio);
}


ListaSimpleConPrioridad* restoListaSimpleConPrioridad(ListaSimpleConPrioridad* l) {
	assert(l != NULL);
	return (l->sig);
}


void destruirListaSimpleConPrioridad(ListaSimpleConPrioridad* &l) {
	while (l != NULL)
	{
		ListaSimpleConPrioridad* aBorrar = l;
		l = l->sig; 
		delete aBorrar;
	}
}


