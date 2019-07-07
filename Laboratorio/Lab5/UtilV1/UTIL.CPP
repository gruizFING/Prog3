/* 4257602 */
/*
 * Tarea 5 - Backtracking
 */

#include "util.h"
#include "carrera.h"
#include <stdio.h>

bool esPosibleSolucion(Par* race, int* c, int* t, int B, int C, int S, int laps)
{
	bool error = false;
	int fuel = C;
	int i = 0;
	int time = 0;
	while (i < laps)
	{
		//Chequeo que las velocidades no esten fuera de rango
		if (race[i].velocidad > S || race[i].velocidad < 0)
		{			
			printf("Error en vuelta %d: velocidad fuera de rango\n", i + 1);
			return false;
		};
		//Chequeo vuelta a vuelta si no me quedo sin combustible
		if (race[i].boxes)
			fuel = C - c[race[i].velocidad];
		else
			fuel = fuel - c[race[i].velocidad];
		if (fuel < 1)
		{
			printf("Error en vuelta %d: me quedo sin combustible\n", i + 1);
			return false;
		}
		//Calculo tiempo parcial de carrera
		time = time + t[race[i].velocidad];
		if (race[i].boxes)
			time = time + B;
		//Paso a la proxima vuelta
		i++;
	};	
	printf("Es una solucion posible con tiempo de carrera == %d\n", time);
	for (int i=0; i<laps; i++)
		printf("Vuelta-> %d Velocidad-> %d\n ", i + 1, race[i].velocidad);
	return true;
}