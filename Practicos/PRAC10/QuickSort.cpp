/* QuickSort */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <time.h>
#include <math.h>
#include <iostream>

using namespace std;

void swap(int &a,int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

int Particion(int *A,int ini,int fin)
{
	int Pivote = A[ini]; // elemento de la secuencia elegido como pivote
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


/******************* Solucion implementada por el InCo **************************/
int elegirPivote(int *a, int izq, int der){
	int medio = (der + izq) / 2;
	if (a[izq] > a[medio])
		swap (a[izq], a[medio]);
	if (a[izq] > a[der])
		swap (a[izq], a[der]);
	if (a[medio] > a[der])
		swap (a[medio], a[der]);
	return medio;
}

/* Procedimiento recursivo de ordenacion */
void Q_Sort (int *a, int izq, int der)
{
	if (izq + 1 < der)
	{
		int posPiv = elegirPivote(a, izq, der);
		int p = a[posPiv];
		swap (a[posPiv], a[der - 1]);
		int i = izq + 1;
		int j = der - 2;
		do
		{
			while (a[i] < p)
				i++;
			while (a[j] > p)
				j--;
			swap (a[i], a[j]);
		}
		while (i < j);
		
		swap (a[i], a[j]);
		swap (a[i], a[der - 1]); // Restaura el Pivote
		Q_Sort (a, izq, i-1);
		Q_Sort (a, i+1, der);
	}
	else if (a[izq] > a[der])
		swap (a[izq], a[der]);
}

/* Programa principal, recibe el vector a con los datos y su tope
* el arreglo a ordenar va desde 1 hasta tope, la casilla 0 es auxiliar */
void QuickSort2 (int *a, int tope)
{
	Q_Sort (a, 1, tope);
}

//Ej6 o 7
int K_esimo_QuickSort( arreglo &A, int ini, int fin, int k){
	int PosPivote;
	if (ini<fin){// si hay más de un elemento
		PosPivote = Particion(A, ini, fin);
		if (k<PosPivote) {
			return K_esimo_QuickSort (A, ini, PosPivote-1, k);
		}
		else if (k>PosPivote) {
			return K_esimo_QuickSort (A, PosPivote+1, fin, k);
		}
			else return A[PosPivote];
	} // if
} // fin K_esimo_QuickSort



/**********************************************************************************/

/* Rutina de Prueba */
int main ()
{
	const float MAX = 20000;
	const int N = 256;
	int a[N], i, a2[N+1], valor = INT_MIN;
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
		assert (valor <= a[i]);
		valor = a[i];
		cout << a[i] << ' ';
	}
	cout << endl << endl;
	
	for (i = 1; i <= N; i++)
	{
		a2[i] = (int) ( (((double)rand() )/RAND_MAX) * MAX + 1.0);
		/*
		* se asigna a la posición i del vector a un valor aleatorio
		* entre 1 y MAX.
		*/
		cout << a2[i] << ' ';
	}
	cout << endl << endl;
	
	QuickSort2(a2,N);
	valor = INT_MIN;
	
	for (i = 1; i <= N; i++)
	{
		assert (valor <= a2[i]);
		valor = a2[i];
		cout << a2[i] << ' ';
	}
	cout << endl << endl;
	
	system("PAUSE");
	return 0;
}
