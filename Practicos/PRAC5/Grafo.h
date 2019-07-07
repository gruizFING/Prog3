/* TAD:GrafoEnteros_Grafo.h */
#ifndef Grafo_H
#define Grafo_H

struct TipoGrafo;
typedef TipoGrafo* Grafo;

typedef struct Vertice {
	int id;
} Vertice;

typedef struct Arista {
	int id1,id2;
} Arista;

typedef struct NodoVert {
	Vertice v;
	int ref;
	NodoVert* sig;
} NodoVert;

typedef NodoVert* ConjVert;

Grafo CrearGrafo();
//Crea el Grafo vacio.

void AgregarVertice(Grafo &g,Vertice v);
//Agrega el vertice 'v' al grafo 'g'.
//Se asume que no hay repetidos.

void QuitarVertice(Grafo &g,Vertice v);
//Saca el vertice 'v' del grafo 'g'. Si no existe no hace nada.

void AgregarArista(Grafo &g,Arista a);
//Agrega la arista 'a' al grafo 'g'.
//Si no existe alguno de los vertices de 'a' no hace nada.

void QuitarArista(Grafo &g,Arista a);
//Saca la arista 'a' del grafo 'g'.
//Si no existe alguno de los vertices de 'a' no hace nada.

ConjVert Vertices(Grafo g);
//Devuelve el conjunto de vertices del grafo 'g'.

ConjVert Adyacentes(Grafo g,Vertice v);
//Devuelve el conjunto de vertices adyacentes del vertice 'v' en el grafo 'g'.
//Pre: El vertice 'v' debe existir en el grafo 'g'.



#endif /* Grafo_H */

