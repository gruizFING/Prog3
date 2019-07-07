/* Ej5_Search2-Practico10 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <time.h>
#include <math.h>
#include <iostream>

using namespace std;
/********Uso el QuickSort para ordenar el arreglo antes del Search ************/
/******************************************************************************/
void swap(int &a,int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

int Particion(int *A,int ini,int fin)
{
	int Pivote = A[ini]; // elemento de la secuencia elegido como pivote inicial
	int i, pospiv = ini;
	for (i = ini + 1;i <= fin;i++)
	{
		if (A[i] < Pivote)
		{
			pospiv++; // se hace lugar en el arreglo para A[i]
			swap(A[i],A[pospiv]);
		}
	}
	swap(A[ini],A[pospiv]); // deja el pivote en su lugar final
	return (pospiv);
}


void QuickSort(int *A,int ini,int fin)
{
	if (ini < fin)
	{
		int PosPivote = Particion(A,ini,fin);
		QuickSort(A,ini,PosPivote - 1); //El pivote no lo incluyo ya que esta en la posicion correcta
		QuickSort(A,PosPivote + 1,fin);
	}
}

/***************************************************************************************/


int Search(int *A,int elem,int inicio,int fin)
{
	if (inicio < fin)
	{
		int pt = ((fin - inicio) / 3);
		int st = 2 * pt + 1 + inicio;
		pt += inicio;
		if ((A[pt] == elem) || (A[st] == elem))
			return 1;
		else if (elem < A[pt])
			return (Search(A,elem,inicio,pt));
		else if (elem > A[st])
			return (Search(A,elem,st+1,fin));
		else
			return (Search(A,elem,pt+1,st));
	}
	else
	{
		if (A[inicio] == elem)
			return 1;
		else
			return 0;
	}
}



int main ()
{
	const float MAX = 400;      
	const int N = (int)pow(3,5);  
	int a[N], i;
	srand (time(0));
	// asigna la semilla para la funcion que obtiene números aleatorios
	for (i = 0; i < N; i++)
	{
		a[i] = (int) ( (((double)rand() )/RAND_MAX) * MAX + 1.0);
		/*
		* se asigna a la posición i del vector a un valor aleatorio
		* entre 1 y MAX.
		*/
		cout << a[i] << ' ';
	}
	cout << endl << endl;
	QuickSort(a,0,N-1);
	for (i = 0; i < N; i++)
	{
		cout << a[i] << ' ';
	}
	cout << endl << endl;
	
	int res = Search(a,28,0,N-1);

	if (res)
		cout << "El numero 28 se encuentra en la secuencia" << endl;
	else
		cout << "El numero 28 no se encuentra en la secuencia" << endl;
	
	cout << endl << endl;
	cout << "Los numeros que faltan en la secuencia son:\n";
	for (int i = 1;i <= MAX;i++)
	{
		if (!Search(a,i,0,N-1))
			cout << i << " ";
	}
	cout << endl << endl;
	
	system("PAUSE");
	return EXIT_SUCCESS;
}

