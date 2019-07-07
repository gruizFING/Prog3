/*
 * vim: shiftwidth=3 tabstop=3 softtabstop=3
 * =====================================================================================
 *
 *       Filename:  main.c
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
	char n[][11] = {"060","045","030","018","039","036","090","054","042","120","051"};

	for (int i = 0; i < 11 ; i++) {
		if (i%2 == 0)
			crearPrograma_SO(so,n[i],"_@");
		else 
			crearPrograma_SO(so,n[i],"!@");
	}

	for (int i = 0; i < 11 ; i++) {
		ejecutar_SO(so,n[i]);
	}

	int i,cpu;
	int total = 0;
	for (i=0 ; i < 90 ; i++) {
		total = 0;
		for (cpu=0; cpu < CANT_MAX_CPU; cpu++)
			ejecutarInstruccion_SO(so,cpu);
	};

	liberar_SO(so);
	return EXIT_SUCCESS;
}

