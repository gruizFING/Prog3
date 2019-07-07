 /*
 * =====================================================================================
 *
 *       Filename:  prueba9.c
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
#define CANT_PROGS 19/*CANT_PROGS debe entrar en 10 caracteres*/

int main() {

	int i;
    char noms[CANT_PROGS][10];
	for(i = 0; i < CANT_PROGS; i++)
	{
		sprintf(noms[i],"%d",i);
	}

	struct SO *so = iniciar_SO(CANT_MAX_CPU);
	for (i = 0; i < CANT_PROGS ; i++)
		crearPrograma_SO(so,noms[i],"_!A_a@");

    imprimirProgramas_SO(so);
	liberar_SO(so);
	
	so = iniciar_SO(CANT_MAX_CPU);
	for (i = CANT_PROGS-1; i >= 0 ; i--)
		crearPrograma_SO(so,noms[i],"_!A_a@");
    imprimirProgramas_SO(so);
	liberar_SO(so);
	
	so = iniciar_SO(CANT_MAX_CPU);
	for (i = 0; i < 4 ; i++)
		crearPrograma_SO(so,noms[i],"_!A_a@");
	for (i = CANT_PROGS-1; i >= 4 ; i--)
		crearPrograma_SO(so,noms[i],"_!A_a@");
    imprimirProgramas_SO(so);
	liberar_SO(so);
	
	so = iniciar_SO(CANT_MAX_CPU);
	for (i = 0; i < CANT_PROGS ; i+=2)
		crearPrograma_SO(so,noms[i],"_!A_a@");
	for (i = 1; i < CANT_PROGS ; i+=2)
		crearPrograma_SO(so,noms[i],"_!A_a@");
    imprimirProgramas_SO(so);
	liberar_SO(so);
	
	return EXIT_SUCCESS;
}
