/*
 * vim: shiftwidth=3 tabstop=3 softtabstop=3
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  Tarea de multiestructura
 *
 *        Version:  1.0
 *        Created:  13/06/10 10:55:03
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Mario A. del Riego (delriego@fing.edu.uy),
 *        Company: FING
 *
 * =====================================================================================
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Esto es un cambio, estoy jugando!

#include "so.h"
#define CANT_MAX_CPU 3

int main() {
	struct SO *so = iniciar_SO(CANT_MAX_CPU);

	crearPrograma_SO(so,"1","AA!___AA_aaaa@");
	crearPrograma_SO(so,"2","_A_!______a__B__@");
	crearPrograma_SO(so,"3","_!_AB_@__!__@");
	crearPrograma_SO(so,"4","_!_AB_@__!_b@");

	for (int i = 0; i < 2; i++) {
		if (!ejecutar_SO(so,"1")) exit(1);
		if (!ejecutar_SO(so,"2")) exit(1);
		if (!ejecutar_SO(so,"3")) exit(1);
		if (!ejecutar_SO(so,"4")) exit(1);
		if (ejecutar_SO(so,"0")) exit(1);
	}
	int i,cpu;
	for (i=0 ; i < 20 ; i++) {
		for (cpu=0; cpu < CANT_MAX_CPU; cpu++)
			ejecutarInstruccion_SO(so,cpu);
		if ((i % 5) == 0) {
			printf("i=%d\n",i);
			imprimirProcesosBloqueados_SO(so);
//			imprimirProcesosListos_SO(so);
			printf("--------\n");
		}
	};

	liberar_SO(so);
	return EXIT_SUCCESS;
}

