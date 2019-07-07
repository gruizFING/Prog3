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
	int n = 8;
	int* a = new int[n];
	int* b = new int[n];
	// numero a
	a[0] = 5;
	a[1] = 9;
	a[2] = 2;
	a[3] = 1;
	a[4] = 5;
	a[5] = 9;
	a[6] = 0;
	a[7] = 8;

	// numero b
	b[0] = 9;
	b[1] = 8;
	b[2] = 7;
	b[3] = 6;
	b[4] = 5;
	b[5] = 4;
	b[6] = 3;
	b[7] = 2;


	int* c = multiplicar(a, b, n);

	// imprimo a y b
	imprimir(a, n); printf(" * "); imprimir(b, n); printf(" = "); 
	imprimir(c, 2*n);
	printf("\n");
	liberarResultado(c);

	bool carry;
	c = sumar(a, b, n, carry);
	// imprimo a y b
	imprimir(a, n); printf(" + "); imprimir(b, n); printf(" = ");
	if (carry) printf("C ");
	imprimir(c, n);

	printf("\n");
	liberarResultado(c);

	int nLargo;
	int exponente = 1 << 5;
	c = exponenciar(a, n ,exponente, nLargo);
	imprimir(a, n); printf (" ^ %d = ",exponente); imprimir(c,nLargo);
	printf("\n");
	liberarResultado(c);

	delete []a;
	delete []b;

	return EXIT_SUCCESS;
}
