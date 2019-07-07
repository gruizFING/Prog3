#include <stdio.h>
#include <stdlib.h>

#include "RedInfelicidad.h"
#include "CarinioEstrategia.h"
#include "util.h"

#include <iostream>

using namespace std;

int main()
{
	cout << "TEST 4.1" << endl;

	RedInfelicidad* ciudadCariniosa = crearRedInfelicidad(6);

	unirMaquinasRedInfelicidad(ciudadCariniosa, 0, 3, 4);
	unirMaquinasRedInfelicidad(ciudadCariniosa, 2, 1, 1);
	unirMaquinasRedInfelicidad(ciudadCariniosa, 1, 3, 2);
	unirMaquinasRedInfelicidad(ciudadCariniosa, 1, 5, 1);
	unirMaquinasRedInfelicidad(ciudadCariniosa, 5, 3, 6);
	unirMaquinasRedInfelicidad(ciudadCariniosa, 3, 4, 5);

	vigilarMaquina(ciudadCariniosa, 0);

	vigilarMaquina(ciudadCariniosa, 1);
	vigilarMaquina(ciudadCariniosa, 3);
	imprimirRutaMenorTiempo(ciudadCariniosa, 0);

	vigilarMaquina(ciudadCariniosa, 2);
	imprimirRutaMenorTiempo(ciudadCariniosa, 0);

	vigilarMaquina(ciudadCariniosa, 5);
	imprimirRutaMenorTiempo(ciudadCariniosa, 0);

	destruirRedInfelicidad(ciudadCariniosa);

	cout << "TEST 4.2" << endl;

	ciudadCariniosa = crearRedInfelicidad(16);

	int can = 3;
	int gor = 5;
	for(int i = 0; i < can; i++)
	for(int j = 1; j <= gor; j++)
	{
		if(i > 0)
			unirMaquinasRedInfelicidad(ciudadCariniosa, j+(i-1)*gor, j+i*gor, j+i*gor);
		else unirMaquinasRedInfelicidad(ciudadCariniosa, 0, j, j);
	}

	for(int i = 0; i < can*gor; i++)
	{
		imprimirRutaMenorTiempo(ciudadCariniosa,0);
		vigilarMaquina(ciudadCariniosa, i);
	}

	destruirRedInfelicidad(ciudadCariniosa);

	cout << "TEST 4.3" << endl;

	ciudadCariniosa = crearRedInfelicidad(6);

	unirMaquinasRedInfelicidad(ciudadCariniosa, 0, 1, 1);
	unirMaquinasRedInfelicidad(ciudadCariniosa, 0, 2, 4);
	unirMaquinasRedInfelicidad(ciudadCariniosa, 0, 3, 4);
	unirMaquinasRedInfelicidad(ciudadCariniosa, 0, 4, 3);
	unirMaquinasRedInfelicidad(ciudadCariniosa, 1, 4, 1);
	unirMaquinasRedInfelicidad(ciudadCariniosa, 1, 5, 2);

	vigilarMaquina(ciudadCariniosa, 0);
	imprimirRutaMenorTiempo(ciudadCariniosa, 0);
	vigilarMaquina(ciudadCariniosa, 1);
	imprimirRutaMenorTiempo(ciudadCariniosa, 0);
	vigilarMaquina(ciudadCariniosa, 4);
	imprimirRutaMenorTiempo(ciudadCariniosa, 0);

	destruirRedInfelicidad(ciudadCariniosa);

	cout << "TEST 4.4" << endl;

	int cantM = 50;
	ciudadCariniosa = crearRedInfelicidad(cantM);

	for(int i = 0; i < cantM-1; i++)
	{
		unirMaquinasRedInfelicidad(ciudadCariniosa, i, i+1, 1);
	}

	for(int i = 0; i < cantM; i++)
	{
		imprimirRutaMenorTiempo(ciudadCariniosa, 0);
		vigilarMaquina(ciudadCariniosa, i);
	}

	imprimirRutaMenorTiempo(ciudadCariniosa, 0);

	destruirRedInfelicidad(ciudadCariniosa);

	return 0;
}
