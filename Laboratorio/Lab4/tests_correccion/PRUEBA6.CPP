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
	int n = 16;
	int* a = new int[n];
	int* b = new int[n];

	// numero a
	a[0] = 2;
	a[1] = 5;
	a[2] = 3;
	a[3] = 0;
	a[4] = 9;
	a[5] = 0;
	a[6] = 0;
	a[7] = 4;
	a[8] = 7;
	a[9] = 9;
	a[10] = 3;
	a[11] = 5;
	a[12] = 9;
	a[13] = 2;
	a[14] = 1;
	a[15] = 1;

	// numero b
	b[0] = 4;
	b[1] = 1;
	b[2] = 3;
	b[3] = 8;
	b[4] = 7;
	b[5] = 2;
	b[6] = 9;
	b[7] = 9;
	b[8] = 4;
	b[9] = 5;
	b[10] = 6;
	b[11] = 1;
	b[12] = 4;
	b[13] = 0;
	b[14] = 9;
	b[15] = 9;


	/// prueba 5.1
	// c:= a * b
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
	// e := a ^ 8
	int* e = exponenciar(a,n, 8, nlargo);
	imprimir(a, n); printf(" ^ 8 = ");
	imprimir(e, nlargo);
	printf("\n");
	liberarResultado(e);

	delete []a;
	delete []b;
	return EXIT_SUCCESS;
}
