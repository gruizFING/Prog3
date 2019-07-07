#include <stdio.h>

#include "RedInfelicidad.h"
#include "CarinioEstrategia.h"
#include "ListaCariniosos.h"
#include "util.h"

#include <iostream>
using namespace std;

int main()
{
	cout << "TEST 3" << endl;
	RedInfelicidad* ri = crearRedInfelicidad(9);
	unirMaquinasRedInfelicidad(ri, 0, 1, 1);
	unirMaquinasRedInfelicidad(ri, 0, 2, 1);
	unirMaquinasRedInfelicidad(ri, 0, 7, 1);
	unirMaquinasRedInfelicidad(ri, 1, 2, 1);
	unirMaquinasRedInfelicidad(ri, 1, 3, 1);

	unirMaquinasRedInfelicidad(ri, 3, 4, 1);
	unirMaquinasRedInfelicidad(ri, 3, 5, 1);
	unirMaquinasRedInfelicidad(ri, 5, 6, 1);
	unirMaquinasRedInfelicidad(ri, 7, 8, 1);

	imprimirMaquinaCentral(ri);

	int mc = maquinaCentral(ri);

	vigilarMaquina(ri, mc);
	vigilarMaquina(ri, 0);
	vigilarMaquina(ri, 1);
	vigilarMaquina(ri, 2);
	vigilarMaquina(ri, 4);
	vigilarMaquina(ri, 5);
	vigilarMaquina(ri, 7);

	imprimirRutaMenorTiempo(ri, mc);

	imprimirCariniositosEnAccion(ri, mc, listaPrimositos());

	return 0;
}
