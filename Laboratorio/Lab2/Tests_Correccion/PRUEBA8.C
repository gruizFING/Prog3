 /*
 * =====================================================================================
 *
 *       Filename:  prueba8.c
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
#define CANT_MAX_CPU 8

int main() {

    struct SO *so = iniciar_SO(CANT_MAX_CPU);
    int i, error;
    char arreglo[][8] = {"1","2","3","4","5","6","7","8"};
    unsigned int pids[8];

	for (i = 0; i < 7 ; i++)
		crearPrograma_SO(so,arreglo[i],"_!A_a@");

    for (i = 0; i < 7 ; i++)
       pids[i] = ejecutar_SO(so,arreglo[i]);

    printf("Procesos Listos: \n");
    imprimirProcesosListos_SO(so);

    error= terminarProceso_SO(so, pids[0]);
    if (error!=SO_OK)
       printf("hubo error al matar al proceso\n");

    for (i = 0; i < 6 ; i++){
         ejecutarInstruccion_SO(so,i);
         ejecutarInstruccion_SO(so,i);
         };

    for (i = 2; i < 8 ; i++){
       error= terminarProceso_SO(so, i);
       if (error!=SO_OK)
          printf("hubo error al matar al proceso\n");
       };

    printf("-------------------------\n");

    for (i = 0; i < 7 ; i++)
		crearPrograma_SO(so,arreglo[i],"_!A_a@");

    for (i = 0; i < 7 ; i++)
       ejecutar_SO(so,arreglo[i]);

     for (i = 0; i < 8 ; i++){
         ejecutarInstruccion_SO(so,i);
         ejecutarInstruccion_SO(so,i);
         ejecutarInstruccion_SO(so,i);
         };

	liberar_SO(so);
	return EXIT_SUCCESS;
}
