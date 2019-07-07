 /*
 * =====================================================================================
 *
 *       Filename:  prueba7.c
 *
 *    Description:  Tarea de multiestructura
 *
 *        Version:  1.0
 *       Compiler:  g++
 *
 *         Author: Curso de Programación 3
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

	crearPrograma_SO(so,"winamp.exe","@");
	crearPrograma_SO(so,"ares.exe","A_!_a@");
	crearPrograma_SO(so,"Sosimon.exe","_C!_c@");

	unsigned int sosimon = ejecutar_SO(so,"Sosimon.exe");
	ejecutar_SO(so,"ares.exe");

	printf("Procesos Listos: \n");
	imprimirProcesosListos_SO(so);

	int error= terminarProceso_SO(so, sosimon); //mato a Sosimon.exe
	if (error!=SO_OK)
		printf("Hubo error al matar proceso %d\n",sosimon);

	printf("Procesos Listos: \n");
	imprimirProcesosListos_SO(so);

	crearPrograma_SO(so,"RedSocial.exe","_!_C@");

	ejecutarInstruccion_SO(so,0);
	ejecutarInstruccion_SO(so,1); //no hace nada
	printf("...........................\n");

	ejecutar_SO(so,"RedSocial.exe");

	for (int i=0; i<6; i++) {
		ejecutarInstruccion_SO(so,1);
		ejecutarInstruccion_SO(so,0);
	}

	printf("Procesos Listos: \n");
	imprimirProcesosListos_SO(so);
	unsigned int winamp = ejecutar_SO(so,"winamp.exe");

	ejecutarInstruccion_SO(so,1); // Se ejecutó @ de 'winamp.exe' y se murió

	error= terminarProceso_SO(so, winamp); // No debería matar a winamp.exe porque no existe
	if (error==SO_OK)
		printf("Hubo error al matar al proceso\n");

	liberar_SO(so);
	return EXIT_SUCCESS;
}
