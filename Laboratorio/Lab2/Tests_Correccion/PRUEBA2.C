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
 
	crearPrograma_SO(so,"1","!___A__a@");
	crearPrograma_SO(so,"2","_A_!______a@");
	crearPrograma_SO(so,"3","_!_A__!__!__@");


	ejecutar_SO(so,"1");
	ejecutar_SO(so,"2");
	ejecutar_SO(so,"3");
 
	int i,cpu;
	for (i=0 ; i < 90 ; i++) {
		printf("i=%d\n",i);
		for (cpu=0; cpu < CANT_MAX_CPU; cpu++)
			ejecutarInstruccion_SO(so,cpu);
		imprimirProcesosBloqueados_SO(so);
		imprimirProcesosListos_SO(so);
		printf("--------\n");
	};

	liberar_SO(so);
	return EXIT_SUCCESS;
}

