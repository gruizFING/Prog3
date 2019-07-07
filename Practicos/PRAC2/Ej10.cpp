#include <stdio.h>
#include <stdlib.h>
#include <iostream>

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


int main () {
	int* arr = new int[500];
	cout << "Ingrese un arreglo de enteros terminandolo con 666:\n";
	int num;
	cin >> num;
	int n = 0;
	while (num != 666) {
		arr[n] = num;
		n++;
		cin >> num;
	}
	for (int i = 0;i < 5;i++) //jojo!!
		cout << "\a";
	SelectionSort(arr,n);
	cout << "El arreglo ordenado es:\n";
	for (int j = 0;j < n;j++)
		cout << arr[j] << " ";
	delete [] arr;
	system("PAUSE");
	return 0;
}

