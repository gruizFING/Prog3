/*
 * Tarea 4
 *
 * Programación 3
 * Instituto de Computación
 * Facultad de Ingeniería
 * Universidad de la República
 *
 * $Rev: 297 $
 */

#include "utils.h"
#include <stdio.h>

void imprimir(const int* a, int n){
	int i = 0;
	while ((i < n-1) && (a[i] == 0))
		i++;

	for(int j = i; j < n; j++)
		printf("%d", a[j]);
}

