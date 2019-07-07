/* Mapping.cpp */
/* Estrategia de dispersion abierta */
#include "mapping.h"
#include <stdlib.h>

struct bucket {
	int clave;
	bucket* sig;
};

struct nodoMapping {
	bucket** tabla;
	int Tam;
};


mapping Crear(int Tam) {
	mapping m = new nodoMapping;
	m->Tam = Tam;
	m->tabla = new bucket*[Tam];
	for (int i = 0;i < Tam;i++)
		m->tabla[i] = NULL;
	return m;
}

void Insertar(mapping &m,int dom,int cod) {
	int lugar = (dom % m->Tam);
	bucket* nuevo = new bucket;
	nuevo->clave = cod;
	nuevo->sig = m->tabla[lugar];
	m->tabla[lugar] = nuevo;
}

bool Pertenece(mapping m,int dom) {
	int lugar = (dom % m->Tam);
	return (m->tabla[lugar] != NULL);
}


int Computar(mapping m,int dom) {
	int lugar = (dom % m->Tam);
	return (m->tabla[lugar]->clave);
}

