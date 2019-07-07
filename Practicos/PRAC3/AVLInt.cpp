/*AVLInt.cpp*/

#include "AVLInt.h"
#include <stdlib.h>

typedef struct AVLInt {
	int clave;
	short int fb;
	AVLInt* izq;
	AVLInt* der;
} AVLInt;


AVLInt* Crear() {
	AVLInt* a = NULL;
	return a;
}


/*********************Operaciones de Rebalanceo***********************/
void ROTLL(AVLInt* &a) {
	AVLInt* nuevo = a->izq;
	a->izq = nuevo->der;
	nuevo->der = a;
	a->fb -= 1;
	nuevo->fb -= 1;
	a = nuevo;
}

void ROTRR(AVLInt* &a) {
	AVLInt* nuevo = a->der;
	a->der = nuevo->izq;
	nuevo->izq = a;
	a->fb += 1;
	nuevo->fb += 1;
	a = nuevo;
}

void ROTLR(AVLInt* &a) {
	AVLInt* nuevo = a->izq->der;
	AVLInt* aux = nuevo->izq;
	nuevo->izq = a->izq;
	a->izq->der = aux;
	aux = nuevo->der;
	nuevo->der = a;
	a->izq = aux;
	if (nuevo->fb == 1) {
		nuevo->izq->fb = 0;
		a->fb = -1;
	}
	else if (nuevo->fb == -1) {
		nuevo->izq->fb = 1;
		a->fb = 0;
	}
	else {
		nuevo->izq->fb = 0;
		a->fb = 0;
	}
	a = nuevo;
}

void ROTRL(AVLInt* a) {
	AVLInt* nuevo = a->der->izq;
	AVLInt* aux = a->der;
	nuevo->der = a->der;
	a->der->izq = aux;
	aux = nuevo->izq;
	nuevo->izq = a;
	a->der = aux;
	if (nuevo->fb == -1) {
		nuevo->der->fb = 0;
		a->fb = 1;
	}
	else if (nuevo->fb == 1) {
		nuevo->der->fb = -1;
		a->fb = 0;
	}
	else {
		nuevo->der->fb = 0;
		a->fb = 0;
	}
	a = nuevo;
}

/*********************************************************************/

AVLInt* Insertar(AVLInt* &a,int n,bool &inserto) {
	if (a == NULL) {
		a = new AVLInt;
		a->clave = n;
		a->fb = 0;
		a->izq = NULL;
		a->der = NULL;
		inserto = true;
	}
	else if (n < a->clave) {
		a = Insertar(a->izq,n,inserto);
		if (inserto) {
			switch (a->fb) {
				case -1 :{  //No es necesario rebalancear.
					a->fb = 0;
					inserto = false;
					break;
				}
				case 0 :{ //Hay que ver los ancestros.
					a->fb = 1;
					break;
				}
				case 1 :{ //Es necesario rebalancear.
					if (a->izq->fb == 1)
						ROTLL(a);
					else
						ROTLR(a);
					inserto = false;
					break;
				}
			}
		}
	}
	else if (n > a->clave) {
		a = Insertar(a->der,n,inserto);
		if (inserto) {
			switch (a->fb) {
				case 1 :{
					a->fb = 0;
					inserto = false;
					break;
				}
				case 0 :{
					a->fb = -1;
					break;
				}
				case -1 :{
					if (a->der->fb == -1)
						ROTRR(a);
					else
						ROTRL(a);
					inserto = false;
					break;
				}
			}
		}
	}
}


bool EsVacio(AVLInt* a) {
	return (a == NULL);
}

bool Pertenece(AVLInt* a,int n) {
	if (a == NULL)
		return false;
	else if (a->clave == n)
		return true;
	else if (a->clave > n)
		return Pertenece(a->izq,n);
	else
		return Pertenece(a->der,n);
}

