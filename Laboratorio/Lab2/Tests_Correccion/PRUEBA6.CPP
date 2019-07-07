   /*
 * =====================================================================================
 *
 *       Filename:  prueba6.c
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
#define CANT_MAX_CPU 1

int main() {

    struct SO *so = iniciar_SO(CANT_MAX_CPU);

    crearPrograma_SO(so,"programa1.exe","_A!aB!_@");
	crearPrograma_SO(so,"programa2.exe","ABC_a!c@");

	ejecutar_SO(so,"programa1.exe");

    printf("Procesos Bloqueados: \n");
	imprimirProcesosBloqueados_SO(so); //ninguno
	printf("Procesos Listos: \n");
    imprimirProcesosListos_SO(so); //programa1

    printf("\n");
    ejecutarInstruccion_SO(so,0); //_de prog1
    ejecutarInstruccion_SO(so,0); //A de prog1

    printf("Procesos Listos: \n");
    imprimirProcesosListos_SO(so); //ninguno

    printf("\n");
    ejecutarInstruccion_SO(so,0); // ! de prog1

    printf("Procesos Listos: \n");
    imprimirProcesosListos_SO(so); //programa1

    ejecutar_SO(so,"programa2.exe"); //pone en la lista de listos a prog2

    printf("Procesos Listos: \n");
    imprimirProcesosListos_SO(so); //los dos.

     printf("\n");
    ejecutarInstruccion_SO(so,0); //prog1 libera recurso a

    printf("Procesos Bloqueados: \n");
    imprimirProcesosBloqueados_SO(so); //ninguno
    printf("Procesos Listos: \n");
    imprimirProcesosListos_SO(so); //programa2

    printf("\n");
    ejecutarInstruccion_SO(so,0); //programa1 pide B
    ejecutarInstruccion_SO(so,0); //programa1 libera procesador

    printf("Procesos Listos: \n");
    imprimirProcesosListos_SO(so); //los dos programa2 primero

    printf("\n");
    ejecutarInstruccion_SO(so,0); //programa2 pide A
    ejecutarInstruccion_SO(so,0); //programa2 pide B, se queda trancado

    printf("Procesos Boloqueados: \n");
    imprimirProcesosBloqueados_SO(so); //programa2
    printf("Procesos Listos: \n");
    imprimirProcesosListos_SO(so); //programa1

    printf("\n");
    ejecutarInstruccion_SO(so,0); //programa1 no hace nada
    ejecutarInstruccion_SO(so,0); //programa1 termina, liberando recurso b

    printf("Procesos Listos: \n");
    imprimirProcesosListos_SO(so); //programa2

    printf("\n");
    for (int i=0; i<7; i++)
        ejecutarInstruccion_SO(so,0);

	liberar_SO(so);
	return EXIT_SUCCESS;
}
