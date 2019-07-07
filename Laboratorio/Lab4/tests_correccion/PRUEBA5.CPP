/*
 * Tarea 4
 *
 * Programación 3
 * Instituto de Computación
 * Facultad de Ingeniería
 * Universidad de la República
 *
 * $Rev: 302 $
 */

#include <stdio.h>
#include <stdlib.h>
#include "operaciones.h"
#include "utils.h"

int main() {
	bool carry;
	int nlargo;
	int n = 1024;
	int* a = new int[n];
	int* b = new int[n];

	for (int i = 0; i < n; i++) a[i] = 7;
	for (int i = 0; i < n; i++) b[i] = 8;

	// numero a
	a[0] = 7;
	a[1] = 9;
	a[2] = 3;
	a[3] = 0;
	a[4] = 9;
	a[5] = 0;
	a[6] = 0;
	a[7] = 0;

	// numero b
	b[0] = 4;
	b[1] = 9;
	b[2] = 3;
	b[3] = 1;
	b[4] = 9;
	b[5] = 4;
	b[6] = 9;
	b[7] = 0;


	/// prueba 5.1
	//  c := a * b
	int* c = multiplicar(a, b, n);
	imprimir(a, n); printf(" * "); imprimir(b, n); printf(" = ");
	imprimir(c, 2*n);
	printf("\n");
	liberarResultado(c);

	/// prueba 5.2
	// d := a + b
	int* d = sumar(a, b, n, carry);
	imprimir(a, n); printf(" + "); imprimir(b, n); printf(" = ");
	if (carry) printf("C ");
	imprimir(d, n);
	printf("\n");
	liberarResultado(d);

	/// prueba 5.3
	// e := a ^ 4
	int* e = exponenciar(a,n, 4, nlargo);
	imprimir(a, n); printf(" ^ 4 = ");
	imprimir(e, nlargo);
	printf("\n");
	liberarResultado(e);

	delete []a;
	delete []b;

	return EXIT_SUCCESS;
}
