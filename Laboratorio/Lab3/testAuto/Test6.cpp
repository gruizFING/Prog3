#include <stdio.h>
#include <stdlib.h>

#include "RedInfelicidad.h"
#include "CarinioEstrategia.h"
#include "ListaCariniosos.h"
#include "util.h"

#include <iostream>

using namespace std;

int main()
{
	cout << "TEST 6.1" << endl;

	RedInfelicidad* ciudadCariniosa = crearRedInfelicidad(6);

	unirMaquinasRedInfelicidad(ciudadCariniosa, 0, 3, 4);
	unirMaquinasRedInfelicidad(ciudadCariniosa, 2, 1, 1);
	unirMaquinasRedInfelicidad(ciudadCariniosa, 1, 3, 2);
	unirMaquinasRedInfelicidad(ciudadCariniosa, 1, 5, 1);
	unirMaquinasRedInfelicidad(ciudadCariniosa, 5, 3, 6);
	unirMaquinasRedInfelicidad(ciudadCariniosa, 3, 4, 5);

	int central = 3;

	imprimirCariniositosEnAccion(ciudadCariniosa, central, listaPrimositos());

	cout << "TEST 6.2" << endl;

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

	central = 0;

	imprimirCariniositosEnAccion(ciudadCariniosa, central, listaCariniositos());

	destruirRedInfelicidad(ciudadCariniosa);

	cout << "TEST 6.3" << endl;

	ciudadCariniosa = crearRedInfelicidad(12);

	unirMaquinasRedInfelicidad(ciudadCariniosa, 0, 1, 1);
	unirMaquinasRedInfelicidad(ciudadCariniosa, 0, 2, 4);
	unirMaquinasRedInfelicidad(ciudadCariniosa, 0, 3, 4);
	unirMaquinasRedInfelicidad(ciudadCariniosa, 0, 4, 3);
	unirMaquinasRedInfelicidad(ciudadCariniosa, 1, 4, 1);
	unirMaquinasRedInfelicidad(ciudadCariniosa, 1, 5, 2);
	unirMaquinasRedInfelicidad(ciudadCariniosa, 0, 6, 1);
	unirMaquinasRedInfelicidad(ciudadCariniosa, 0, 7, 4);
	unirMaquinasRedInfelicidad(ciudadCariniosa, 0, 8, 4);
	unirMaquinasRedInfelicidad(ciudadCariniosa, 0, 9, 3);
	unirMaquinasRedInfelicidad(ciudadCariniosa, 1, 10, 1);
	unirMaquinasRedInfelicidad(ciudadCariniosa, 1, 11, 2);


	central = 0;

	imprimirCariniositosEnAccion(ciudadCariniosa, central, listaProfesositos());

	destruirRedInfelicidad(ciudadCariniosa);

	return 0;
}
