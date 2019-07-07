/*
 * Tarea 4
 *
 * Programación 3
 * Instituto de Computación
 * Facultad de Ingeniería
 * Universidad de la República
 * 
 * $Rev: 317 $
 */

#include <stdio.h>
#include <stdlib.h>
#include "operaciones.h"
#include "utils.h"

int main() {
	int n = 4;
	int* a = new int[n];
	int* b = new int[n];
	// numero a
	a[0] = 1;
	a[1] = 0;
	a[2] = 0;
	a[3] = 0;

	// numero b
	b[0] = 1;
	b[1] = 0;
	b[2] = 0;
	b[3] = 0;

	// c := 1000 * 1000
	int* c = multiplicar(a, b, n);
	imprimir(a, n); printf(" * "); imprimir(b, n); printf(" = ");
	imprimir(c, 2*n);
	printf("\n");
	liberarResultado(c);

	// a_b := 1000 + 1000
	bool carry;
	int *a_b = sumar(a, b, n, carry);
	imprimir(a, n); printf(" + "); imprimir(b, n); printf(" = ");
	if (carry) printf ("C ");
	imprimir(a_b, n);
	printf("\n");
	

	// a_b_b := a_b + b
	int *a_b_b = sumar(a_b, b, n, carry);
	imprimir(a_b, n); printf(" + "); imprimir(b, n); printf(" = ");
	if (carry) printf ("C ");
	imprimir(a_b_b, n);
	printf("\n");
	liberarResultado(a_b);
	liberarResultado(a_b_b);

	delete []a;
	delete []b;
	return EXIT_SUCCESS;
}
