/* 4317743 */
#include "carrera.h"
#include <stdlib.h>
#include <assert.h>

void armarTuplaSolucion(int CD,int &mejorTiempo,int tiempo,int vuelta,Par* tupla,Par* &sol);
int tiempoMin,CapTanque,CantLaps,TimeBoxes,CantVel;	
int* tiempos;
int* consumo;								
			
int minimizar_tiempo_carrera (int L, int C, int B, int S,int *t, int *c, Par* &sol) {
	assert((L > 0) && (C > 0) && (B > 0) && (S > 0));
	Par* tupla = new Par[L];
	int mejorTiempo = -1;
	tiempoMin = t[0];
	for (int i = 1;i < S;i++)
	{
		if (t[i] < tiempoMin)
			tiempoMin = t[i];
	}
	CapTanque = C;
	CantLaps = L;
	TimeBoxes = B;
	CantVel = S;
	tiempos = t;
	consumo = c;
	armarTuplaSolucion(C,mejorTiempo,0,0,tupla,sol);
	delete [] tupla;
	return mejorTiempo;
}


void armarTuplaSolucion(int CD,int &mejorTiempo,int tiempo,int vuelta,Par* tupla,Par* &sol) {
	if (vuelta == CantLaps) //Es una posible solucion.
	//Cambio la solucion por la tupla encontrada.
	{
			for (int i = 0;i < CantLaps;i++)
			{
				sol[i].velocidad = tupla[i].velocidad;
				sol[i].boxes = tupla[i].boxes;
			}
			mejorTiempo = tiempo;
	}
	else
	{
		for (int s = CantVel-1;s > -1;s--) //Restricción Explicita.
		{
			if (CD > consumo[s]) //Restricción Implicita. No entra a boxes.
			{
				tiempo += tiempos[s];
				int tiempoMinimoRest = tiempo + tiempoMin * (CantLaps - (vuelta + 1));
				if ((mejorTiempo == -1) || (tiempoMinimoRest < mejorTiempo)) //Predicado de Poda.
				{
					tupla[vuelta].velocidad = s + 1;
					tupla[vuelta].boxes = false;
					armarTuplaSolucion(CD-consumo[s],mejorTiempo,tiempo,vuelta+1,tupla,sol);
				}
				tiempo -= tiempos[s];
			}
			else if (CapTanque > consumo[s]) //Restriccion Implicita. Entra a boxes.
			{
				tiempo += TimeBoxes + tiempos[s];
				int tiempoMinimoRest = tiempo + tiempoMin * (CantLaps - (vuelta + 1));
				if ((mejorTiempo == -1) || (tiempoMinimoRest < mejorTiempo)) //Predicado de Poda.
				{
					tupla[vuelta].velocidad = s + 1;
					tupla[vuelta].boxes = true;
					armarTuplaSolucion(CapTanque-consumo[s],mejorTiempo,tiempo,vuelta+1,tupla,sol);
				}
				tiempo -= TimeBoxes + tiempos[s];
			}
		}
	}
}
