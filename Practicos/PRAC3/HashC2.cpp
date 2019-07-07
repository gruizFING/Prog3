/* HASHC.cpp */

#include "HashC2.h"
#include <stdlib.h>
#include <assert.h>
#include <math.h>

struct bucket {
	int clave;
	bool borrado;
};

struct nodoHash {
	bucket** tabla;
	int tam, cantElem;
};



hashC2 Crear(int Tam) {
	hashC2 h = new nodoHash;
	h->tam = Tam;
	h->cantElem = 0;
	h->tabla = new bucket*[Tam];
	for (int i = 0;i < Tam;i++)
		h->tabla[i] = NULL;
	return h;
}

void Insertar(hashC2 &h,int n) {
	int lugar = (n % h->tam);
	int iter = 0;
	int inicial = lugar;
	
	while ((h->tabla[lugar] != NULL) && (h->tabla[lugar]->borrado == false)) {
		iter++;
		//No se puede encontrar un lugar. El programa termina.
		assert(iter != h->tam);
		lugar = (lugar + (int)pow(iter,2)) % h->tam;
	}
	if (h->tabla[lugar] == NULL)
		h->tabla[lugar] = new bucket;
	h->tabla[lugar]->clave = n;
	h->tabla[lugar]->borrado = false;
	h->cantElem++;
}

bool Pertenece(hashC2 h,int n) {
	int lugar = (n % h->tam);
	int iter = 0;
	int inicial = lugar;
	bool encontre = false;
	
	while (!encontre && (h->tabla[lugar] != NULL) && (iter < h->tam)) {
		iter++;
		if ((h->tabla[lugar]->clave == n) && (h->tabla[lugar]->borrado == false))
			encontre = true;
		else
			lugar = (lugar + (int)pow(iter,2)) % h->tam;
	}
	return (encontre);
}
			

void Borrar(hashC2 &h,int n) {
	int lugar = (n % h->tam);
	int iter = 0;
	int inicial = lugar;
	bool borre = false;
	
	while (!borre && (h->tabla[lugar] != NULL) && (iter < h->tam)) {
		iter++;
		if ((h->tabla[lugar]->clave == n) && (h->tabla[lugar]->borrado == false)) {
			h->tabla[lugar]->borrado = true;
			h->cantElem--;
			borre = true;
		}
		else
			lugar = (lugar + (int)pow(iter,2)) % h->tam;
	}
}


