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

#include "so.h"
#define CANT_MAX_CPU 2

int main() {
	struct SO *so = iniciar_SO(CANT_MAX_CPU);
	char code1[] = "!___A__a@";
	char code2[] = "_A_!______a@";
	char code3[] = "_!_A__!__!__@";

	char prog[] = "0";
	crearPrograma_SO(so,prog,code1);
	prog[0] = '1';
	crearPrograma_SO(so,prog,code2);
	prog[0] = '2';
	crearPrograma_SO(so,prog,code3);

	for (int i = 0; i < 90; i++) {
		prog[0] = '0';
		ejecutar_SO(so,prog);
		prog[0] = '1';
		ejecutar_SO(so,prog);
		prog[0] = '2';
		ejecutar_SO(so,prog);
	}
	int i,cpu;
	for (i=0 ; i < 20000 ; i++) {
		for (cpu=0; cpu < CANT_MAX_CPU; cpu++)
			ejecutarInstruccion_SO(so,cpu);
		if ((i % 1000) == 0) {
			printf("i=%d\n",i);
			//imprimirProcesosBloqueados_SO(so);
			//imprimirProcesosListos_SO(so);
			//printf("--------\n");
		}
	};

	liberar_SO(so);
	return EXIT_SUCCESS;
}

