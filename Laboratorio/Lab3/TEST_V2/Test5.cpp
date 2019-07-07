#include <stdio.h>
#include <stdlib.h>

#include "RedInfelicidad.h"
#include "CarinioEstrategia.h"
#include "util.h"

#include <iostream>

using namespace std;

int main()
{
	cout << "TEST 5.1" << endl;

	RedInfelicidad* ciudadCariniosa = crearRedInfelicidad(6);

	unirMaquinasRedInfelicidad(ciudadCariniosa, 0, 3, 4);
	unirMaquinasRedInfelicidad(ciudadCariniosa, 2, 1, 1);
	unirMaquinasRedInfelicidad(ciudadCariniosa, 1, 3, 2);
	unirMaquinasRedInfelicidad(ciudadCariniosa, 1, 5, 1);
	unirMaquinasRedInfelicidad(ciudadCariniosa, 5, 3, 3);
	unirMaquinasRedInfelicidad(ciudadCariniosa, 3, 4, 5);

	int central = maquinaCentral(ciudadCariniosa);

	imprimirMaquinaCentral(ciudadCariniosa);

	destruirRedInfelicidad(ciudadCariniosa);

	cout << "TEST 5.2" << endl;

	ciudadCariniosa = crearRedInfelicidad(6);

	unirMaquinasRedInfelicidad(ciudadCariniosa, 1, 0, 4);
	unirMaquinasRedInfelicidad(ciudadCariniosa, 1, 2, 1);
	unirMaquinasRedInfelicidad(ciudadCariniosa, 1, 3, 2);
	unirMaquinasRedInfelicidad(ciudadCariniosa, 1, 4, 1);
	unirMaquinasRedInfelicidad(ciudadCariniosa, 1, 5, 3);

	central = maquinaCentral(ciudadCariniosa);

	imprimirMaquinaCentral(ciudadCariniosa);

	destruirRedInfelicidad(ciudadCariniosa);

	cout << "TEST 5.3" << endl;

	ciudadCariniosa = crearRedInfelicidad(6);

	unirMaquinasRedInfelicidad(ciudadCariniosa, 0, 1, 4);
	unirMaquinasRedInfelicidad(ciudadCariniosa, 0, 2, 1);
	unirMaquinasRedInfelicidad(ciudadCariniosa, 0, 3, 2);
	unirMaquinasRedInfelicidad(ciudadCariniosa, 0, 4, 3);
	unirMaquinasRedInfelicidad(ciudadCariniosa, 1, 4, 1);
	unirMaquinasRedInfelicidad(ciudadCariniosa, 1, 5, 3);

	central = maquinaCentral(ciudadCariniosa);

	imprimirMaquinaCentral(ciudadCariniosa);

	destruirRedInfelicidad(ciudadCariniosa);

	cout << "TEST 5.4" << endl;

	ciudadCariniosa = crearRedInfelicidad(3);

	unirMaquinasRedInfelicidad(ciudadCariniosa, 0, 1, 1);
	unirMaquinasRedInfelicidad(ciudadCariniosa, 0, 2, 1);

	central = maquinaCentral(ciudadCariniosa);

	imprimirMaquinaCentral(ciudadCariniosa);

	destruirRedInfelicidad(ciudadCariniosa);

	return 0;
}
