#include <iostream>
#include <limits.h>
#include <assert.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;


void SelectionSort (int* a, int n) {
	int min, tmp;
	for (int i = 0; i < n-1; i++){
		min = i;
		for (int j = i + 1; j < n; j++){
			if (a[j] < a[min])
				min = j;
		}
		// Intercambio de elementos
		tmp = a[i];
		a[i] = a[min];
		a[min] = tmp;
	}
}




int main ()	{
	const int N = 100;
	const float MAX = 1000;
	int *a = new int[N];
	int valor = INT_MIN;
	srand (time(0));
	// asigna la semilla para la funcion que obtiene numeros aleatorios
	int i;
	for (i = 0; i < N; i++){
		a[i] = (MAX * rand ()) / (RAND_MAX + 1.0);
		/*
		* se asigna a la posicion i del vector a un valor aleatorio
		* entre 1 y MAX. Por mas informacion sobre la funcion rand
		* ejecutar "man rand" en la consola de cygwin
		*/
		cout << a[i] << " ";
	}
	cout << "\n\n";
	SelectionSort (a, N);
	for (i = 0; i < N; i++){
		assert (valor <= a[i]);
		valor = a[i];
		cout << a[i] << " ";
	}
	cout << "\n\n";
	delete [] a;
	system("PAUSE");
	return 0;
}
