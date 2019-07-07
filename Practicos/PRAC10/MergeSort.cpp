/* MergeSort */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <time.h>
#include <math.h>
#include <iostream>

using namespace std;

/* ini_a y fin_a son los limites de un array, ini_b y fin_b son los limites del otro */
/* Intercala ordenadamente los arrays (ya ordenados), dejando el resultado en el mismo a */
void Merge(int *a,int ini_a,int fin_a,int ini_b,int fin_b) 
{
	int *tmp = new int[fin_b - ini_a + 1];
	int pos = 0;
	int princ = ini_a;
	while ((ini_a <= fin_a) && (ini_b <= fin_b))
	{
		if (a[ini_a] < a[ini_b])
		{
			tmp[pos] = a[ini_a];
			ini_a++;
		}
		else
		{
			tmp[pos] = a[ini_b];
			ini_b++;
		}
		pos++;
	}
	
	while (ini_a <= fin_a)
		tmp[pos++] = a[ini_a++];
	
	while (ini_b <= fin_b)
		tmp[pos++] = a[ini_b++];
		
	for(int i = fin_b;i >= princ;i--)
		a[i] = tmp[--pos];
	
	delete [] tmp;
}


void MergeSort(int *a,int p,int f)
{
	if (p < f)
	{
		int medio = (p + f) / 2;
		MergeSort(a,p,medio);
		MergeSort(a,medio + 1,f);
		Merge(a,p,medio,medio + 1,f);
	}
}



/* Rutina de Prueba */
int main ()
{
	const float MAX = 20000;
	const int N = 256;
	int a[N], i, valor = INT_MIN;
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
	MergeSort(a,0,N-1);
	
	for (i = 0; i < N; i++)
	{
		assert (valor <= a[i]);
		valor = a[i];
		cout << a[i] << ' ';
	}
	cout << endl << endl;
	system("PAUSE");
	return 0;
}

