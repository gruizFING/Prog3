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
	int n = 8;
	int* cero = new int[n];
	int* b = new int[n];
	int* uno = new int[n];

	// numero uno
	uno[0] = 0;
	uno[1] = 0;
	uno[2] = 0;
	uno[3] = 0;
	uno[4] = 0;
	uno[5] = 0;
	uno[6] = 0;
	uno[7] = 1;

	// numero cero
	cero[0] = 0;
	cero[1] = 0;
	cero[2] = 0;
	cero[3] = 0;
	cero[4] = 0;
	cero[5] = 0;
	cero[6] = 0;
	cero[7] = 0;

	// numero b
	b[0] = 9;
	b[1] = 9;
	b[2] = 9;
	b[3] = 9;
	b[4] = 9;
	b[5] = 9;
	b[6] = 9;
	b[7] = 9;


	// 0 * 99999999
	int* c = multiplicar(cero, b, n);
	imprimir(cero, n); printf(" * "); imprimir(b, n); printf(" = ");
	imprimir(c, 2*n);
	printf("\n");
	liberarResultado(c);

	// 0 + 99999999
	int* d = sumar(cero, b, n, carry);
	imprimir(cero, n); printf(" + "); imprimir(b, n); printf(" = ");
	if (carry) printf("C ");
	imprimir(d, n);
	printf("\n");
	liberarResultado(d);

	// 0 ^ 16
	int* e = exponenciar(cero, n, 16, nlargo);
	imprimir(cero, n); printf(" ^ 16 = ");
	imprimir(e, nlargo);
	printf("\n");
	liberarResultado(e);

	// 1 ^ 32
	int* f = exponenciar(uno, n, 32, nlargo);
	imprimir(uno, n); printf(" ^ 32 = "); imprimir(f, nlargo);
	printf("\n");
	liberarResultado(f);

	delete []cero;
	delete []uno;
	delete []b;

	return EXIT_SUCCESS;
}
