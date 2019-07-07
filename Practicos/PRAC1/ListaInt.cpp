#include "ListaInt.h"
#include <stdlib.h>

struct ListaInt
{
	int elem;
	ListaInt* sig;
};


ListaInt* NullL ()
{
	return NULL;
}

ListaInt* ConsL (int i,ListaInt* l)
{
	ListaInt* nuevo = new ListaInt;
	nuevo -> elem = i;
	nuevo -> sig  = l;
	return nuevo;
}

ListaInt* SnocL (int i,ListaInt* l)
{
	ListaInt* nuevo = new ListaInt;
	nuevo -> elem = i;
	nuevo -> sig  = NULL;
	if (l == NULL)
		l = nuevo;
	else
	{
		ListaInt* lpos = l;
		while (lpos->sig != NULL)
			lpos = lpos->sig;
		lpos->sig = nuevo; 		
	}
	return l;
}

bool IsEmptyL (ListaInt* l)
{
	return (l == NULL);
}

int HeadL (ListaInt* l)
{
	return (l->elem);
}

ListaInt* TailL (ListaInt* l)
{
	return (l->sig);
}

void DestroyL (ListaInt* &l)
{
	ListaInt* aBorrar;
	while (l != NULL)
	{
		aBorrar = l;
		l = l->sig;
		delete aBorrar;
	}
}
