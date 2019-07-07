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
#define CANT_MAX_CPU 1
#define CANT_PROG 5

int main() {
	struct SO *so = iniciar_SO(CANT_MAX_CPU);
	char nombres[][CANT_PROG] = {"060","045","030","090","120"};
   char prog_cortoA[]   = "A@";
   char prog_cortoB[]   = "B@";
   char prog_cortoC[]   = "C@";
   char prog_largo[]    = "____________________________________!___________________@";
   char prog_pidotodo[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZZ@";
	unsigned int pid;

	for (int i = 0; i < CANT_PROG ; i++) {
		if (i%2 == 0)
			crearPrograma_SO(so,nombres[i],"_@");
		else 
			crearPrograma_SO(so,nombres[i],"!@");
	}

	for (int i = 0; i < CANT_PROG ; i++) {
		ejecutar_SO(so,nombres[i]);
	}

	crearPrograma_SO(so,"tooshortA.exe",prog_cortoA);
	crearPrograma_SO(so,"tooshortB.exe",prog_cortoB);
	crearPrograma_SO(so,"tooshortC.exe",prog_cortoC);
	crearPrograma_SO(so,"toolong.exe",prog_largo);
	crearPrograma_SO(so,"takeall.exe",prog_pidotodo);

	ejecutar_SO(so,"tooshortA.exe");
	pid = ejecutar_SO(so,"toolong.exe");
	printf("%d=ejecutar_SO(toolong.exe)\n",pid);
	unsigned int takeall = ejecutar_SO(so,"takeall.exe");
	printf("%d=ejecutar_SO(takeall.exe)\n",takeall);

	int i,cpu;
	int total = 0;
	for (i=0 ; i < 100 ; i++) {
		printf("i=%d\n",i);
		total = 0;
		for (cpu=0; cpu < CANT_MAX_CPU; cpu++)
			ejecutarInstruccion_SO(so,cpu);
		imprimirProcesosBloqueados_SO(so);
		imprimirProcesosListos_SO(so);
		printf("--------\n");
	};

	/*
	 * Tengo un proceso (takeall) con todos los recursos en deadlock
	 */
	imprimirProcesosListos_SO(so);
	imprimirProcesosBloqueados_SO(so);
	ejecutar_SO(so,"tooshortA.exe");
	ejecutar_SO(so,"tooshortA.exe");
	ejecutar_SO(so,"tooshortA.exe");
	ejecutar_SO(so,"tooshortA.exe");
	for (i=0; i < 4; i++) ejecutarInstruccion_SO(so,0);
	ejecutar_SO(so,"tooshortB.exe");
	ejecutar_SO(so,"tooshortB.exe");
	ejecutar_SO(so,"tooshortC.exe");
	ejecutar_SO(so,"tooshortC.exe");
	for (i=0; i < 4; i++) ejecutarInstruccion_SO(so,0);
	imprimirProcesosListos_SO(so);
	imprimirProcesosBloqueados_SO(so);
	terminarProceso_SO(so,takeall); // Libero todos los recursos
	imprimirProcesosListos_SO(so);
	imprimirProcesosBloqueados_SO(so);
	printf("+++++++\n");

	for (i=0 ; i < 10; i++) {
		printf("j=%d\n",i);
		total = 0;
		for (cpu=0; cpu < CANT_MAX_CPU; cpu++)
			ejecutarInstruccion_SO(so,cpu);
		imprimirProcesosBloqueados_SO(so);
		imprimirProcesosListos_SO(so);
		printf("--------\n");
	};

	/*
	 * ¿Existe?
	 */
	terminarProceso_SO(so,pid); 
	imprimirProgramas_SO(so);
	liberar_SO(so);
	return EXIT_SUCCESS;
}

