/*
2 * Tarea 4: Ejemplo
3 *
4 * Programación 3
5 * Instituto de Computación
6 * Facultad de Ingeniería
7 * Universidad de la República
8 *
9 * $Rev: 289 $
10 */
#include <stdio.h>
#include <stdlib.h>
#include "operaciones.h"
#include "utils.h"
#include <iostream>
#include <math.h>

using namespace std;

int main() {
	bool acarreo;
	int n = 8;
	int* a = new int[n];
	int* b = new int[n];

	// numero a
	a[0] = 0;
	a[1] = 8;
	a[2] = 7;
	a[3] = 6;
	a[4] = 5;
	a[5] = 5;
	a[6] = 4;
	a[7] = 3;

	// numero b
	b[0] = 0;
	b[1] = 0;
	b[2] = 2;
	b[3] = 3;
	b[4] = 4;
	b[5] = 8;
	b[6] = 1;
	b[7] = 9;

	// Multiplico
	int * c = multiplicar(a, b, n);

	imprimir(a, n); printf(" * "); imprimir(b, n); printf(" = ");
	// imprimo resultado
	imprimir(c, 2*n);
	printf("\n");
	liberarResultado(c);

	// Sumo
	c = sumar(a, b, n, acarreo);

	imprimir(a, n); printf(" + "); imprimir(b, n); printf(" = ");

	// imprimo resultado
	if (acarreo) printf("C ");
	imprimir(c, n); printf("\n");
	liberarResultado(c);
	
	delete []a;
	delete []b;
	
	//Exponenciar
	a = new int[1];
	int largo = 1;
	int nLargo;
	int e = 1;
	a[0] = 2;
	//Potencias del 2.
	for (int m = 0;m <= 10;m++)
	{
		e = (int) pow(2,m);
		c = exponenciar(a,largo,e,nLargo);
		imprimir(a,largo); cout << " ^ " << e << " = "; imprimir(c,nLargo);
		cout << "   Largo = " << nLargo << endl;
		liberarResultado(c);
	}
	delete [] a;
	
	//Segunda prueba.
	cout << endl;
	largo = 4;
	a = new int[largo];
	a[0] = 1;a[1] = 4;a[2] = 5;a[3] = 2;
	imprimir(a,largo);cout << endl;
	c = multiplicar(a,a,largo);
	imprimir(c,largo*2);cout << endl;
	liberarResultado(c);
	
	for (int m = 0;m <= 3;m++)
	{
		e = (int) pow(2,m);
		c = exponenciar(a,largo,e,nLargo);
		imprimir(a,largo); cout << " ^ " << e << " = "; imprimir(c,nLargo);
		cout << "   Largo = " << nLargo << endl;
		liberarResultado(c);
	}
	
	//Tercer prueba.
	cout << endl;
	largo = 2;
	a = new int[largo];
	a[0] = 2;a[1] = 8;
	imprimir(a,largo);cout << endl;
	c = multiplicar(a,a,largo);
	imprimir(c,largo*2);cout << endl;
	liberarResultado(c);
	
	for (int m = 0;m <= 3;m++)
	{
		e = (int) pow(2,m);
		c = exponenciar(a,largo,e,nLargo);
		imprimir(a,largo); cout << " ^ " << e << " = "; imprimir(c,nLargo);
		cout << "   Largo = " << nLargo << endl;
		liberarResultado(c);
	}
	
	
	system("PAUSE");
	return EXIT_SUCCESS;
}
