/* TAD:GrafoEnteros_Grafo.cpp */

#include "Grafo.h"
#include <stdlib.h>


struct TipoGrafo {
	bool** Matrix;
	int cantVert;
	ConjVert cv;
};


Grafo CrearGrafo() {
	Grafo g = new TipoGrafo;
	g->Matrix = NULL;
	g->cantVert = 0;
	g->cv = NULL;
	return g;
}

void AgregarVertice(Grafo &g,Vertice v) {
	NodoVert* nuevo = new NodoVert;
	nuevo->v = v;
	nuevo->sig = g->cv;
	nuevo->ref = g->cantVert;
	g->cv = nuevo;
	g->cantVert++;
	for (int i = 0;i < g->cantVert;i++) {
		g->Matrix[i][g->cantVert] = new bool;
		g->Matrix[i][g->cantVert] = false;
		g->Matrix[g->cantVert][i] = new bool;
		g->Matrix[g->cantVert][i] = false;
	}
}

NodoVert* buscarConjVert(ConjVert c,int id);

void AgregarArista(Grafo &g,Arista a) {
	NodoVert* v1 = buscarConjVert(g->cv,a.id1);
	NodoVert* v2 = buscarConjVert(g->cv,a.id2);
	if ((v1 != NULL) && (v2 != NULL))
		g->Matrix[v1->ref][v2->ref] = true;
}

void QuitarArista(Grafo &g,Arista a) {
	NodoVert* v1 = buscarConjVert(g->cv,a.id1);
	NodoVert* v2 = buscarConjVert(g->cv,a.id2);
	if ((v1 != NULL) && (v2 != NULL))
		g->Matrix[v1->ref][v2->ref] = false;
}
	

ConjVert Vertices(Grafo g) {
	return (g->cv);
}

