#include "Pila_Enteros.h"
#include <stdlib.h>

typedef StackNodo* Stack;
struct StackNodo
{
	int info;
	Stack sig;
};

StackNodo* NullS ()
{
	return NULL;
}

StackNodo* Push (int i,StackNodo* s)
{
	Stack nuevo = new StackNodo;
	nuevo->info = i;
	nuevo->sig  = s;
	return nuevo;
}

bool IsEmptyS (StackNodo* s)
{
	return (s == NULL);
}

int Top (StackNodo* s)
{
	return (s->info);
}

StackNodo* Pop (StackNodo* s)
{
	return (s->sig);
}

void DestroyS (StackNodo* &s)
{
	Stack aBorrar;
	while (s != NULL)
	{
		aBorrar = s;
		s = s->sig;
		delete aBorrar;
	}
}
