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
	a[0] = 9;
	a[1] = 9;
	a[2] = 9;
	a[3] = 9;
	a[4] = 9;
	a[5] = 9;
	a[6] = 9;
	a[7] = 9;

	// numero b
	b[0] = 9;
	b[1] = 9;
	b[2] = 9;
	b[3] = 9;
	b[4] = 9;
	b[5] = 9;
	b[6] = 9;
	b[7] = 9;

	
	int* c = multiplicar(a, b, n);
	
	// imprimo a
	imprimir(a, n); printf(" * "); imprimir(b, n); printf(" = ");
	
	// imprimo resultado
	imprimir(c, 2*n);
	
	printf("\n");

	liberarResultado(c);

	delete []a;
	delete []b;
	return EXIT_SUCCESS;
}
