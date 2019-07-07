#include "ListaIntA.h"
#include <stdlib.h>


struct ListaInt
{
	int info[9];
	int tope;
};

void NullL (ListaInt &l)
{
	for (int i = 0;i < 10;i++)
		l.info[i] = 0;
	l.tope = 0;
}

ListaInt SnocL (int i,ListaInt l)
{
	l.info[++l.tope] = i;
	return l;
}

bool IsEmptyL (ListaInt l)
{
	return (l.tope == 0);
}

bool IsFullL (ListaInt l)
{
	return (l.tope == 10);
}

int HeadL (ListaInt l)
{
	return (l.info[l.tope]);
}

ListaInt TailL (ListaInt l)
{
	l.tope -= 1;
	return l;
}

void DestroyL (ListaInt &l)
{
	l.tope = 0;
}
