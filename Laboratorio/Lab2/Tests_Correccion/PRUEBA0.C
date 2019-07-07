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
	char code1[] = "!___A_Aa@";
	char code2[] = "_A_!______a@";
	char code3[] = "_!_A__!__!__@";

	char prog[] = "archivo1";
	crearPrograma_SO(so,prog,code1);
	prog[7] = '2';
	crearPrograma_SO(so,prog,code2);
	prog[7] = '3';
	crearPrograma_SO(so,prog,code3);

	prog[7] = '1';
	unsigned int pid1 = ejecutar_SO(so,prog);
	prog[7] = '2';
	ejecutar_SO(so,prog);
	prog[7] = '3';
	ejecutar_SO(so,prog);
 
	int i,cpu;
	for (i=0 ; i < 30 ; i++) {
		printf("i=%d\n",i);
		for (cpu=0; cpu < CANT_MAX_CPU; cpu++)
			ejecutarInstruccion_SO(so,cpu);
		imprimirProcesosBloqueados_SO(so);
		imprimirProcesosListos_SO(so);
		printf("--------\n");
	};

	/* 
	 * Termino el proceso bloqueado
	 **/
	terminarProceso_SO(so,pid1);

	/*
	 * No hay procesos listos.
	 * No debe pasar nada.
	 */
	for (cpu=0; cpu < CANT_MAX_CPU; cpu++)
		ejecutarInstruccion_SO(so,cpu);

	/*
	 * No me lista nada.
	 */
	imprimirProcesosBloqueados_SO(so);
	imprimirProcesosListos_SO(so);

	/*
	 * No hay procesos listos.
	 * No debe pasar nada.
	 */
	for (i=0 ; i < 10 ; i++) {
		for (cpu=0; cpu < CANT_MAX_CPU; cpu++)
			ejecutarInstruccion_SO(so,cpu);
	}

	/*
	 * En el sistema no hay nada, ejecuto un proceso
	 * y lo ejecuto completamente.
	 */ 
	ejecutar_SO(so,prog);
	for (pid1=0; pid1 < strlen(code3); pid1++) 
		ejecutarInstruccion_SO(so,0);

	imprimirProgramas_SO(so);

	liberar_SO(so);
	return EXIT_SUCCESS;
}

