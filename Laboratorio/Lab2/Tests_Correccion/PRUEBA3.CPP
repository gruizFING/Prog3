/*
 * vim: shiftwidth=3 tabstop=3 softtabstop=3
 */

/* 
 * Tarea 2: Caso de prueba v2
 *
 * Programación 3
 * Instituto de Computación
 * Facultad de Ingeniería
 * Universidad de la República
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "so.h"
#define CANT_MAX_CPU 2

int main() {
	struct SO *so = iniciar_SO(CANT_MAX_CPU);
	imprimirProgramas_SO(so);
	terminarProceso_SO(so,12345); 

	crearPrograma_SO(so,"1","ABC___D____bcd@");
	crearPrograma_SO(so,"2","___D______d@");


	ejecutar_SO(so,"1");
	ejecutar_SO(so,"2");
 
	int i,cpu;
	for (i=0 ; i < 30 ; i++) {
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

