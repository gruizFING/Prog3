#include <stdio.h>
#include <stdlib.h>

#include "RedInfelicidad.h"
#include "CarinioEstrategia.h"
#include "util.h"
#include "ListaCariniosos.h"

#include <iostream>
using namespace std;

int main()
{

  cout << "TEST 1.1" << endl;

  RedInfelicidad* ciudadCariniosa = crearRedInfelicidad(6);

  ListaSimpleConPrioridad*lcariniosos = listaCariniositos();

  unirMaquinasRedInfelicidad(ciudadCariniosa, 0, 3, 4);
  unirMaquinasRedInfelicidad(ciudadCariniosa, 2, 1, 1);
  unirMaquinasRedInfelicidad(ciudadCariniosa, 1, 3, 2);
  unirMaquinasRedInfelicidad(ciudadCariniosa, 1, 5, 1);
  unirMaquinasRedInfelicidad(ciudadCariniosa, 5, 3, 3);
  unirMaquinasRedInfelicidad(ciudadCariniosa, 3, 4, 5);

  imprimirMaquinaCentral(ciudadCariniosa);

  int central = maquinaCentral(ciudadCariniosa);

  imprimirRutaMenorTiempo(ciudadCariniosa, central);

  vigilarMaquina(ciudadCariniosa, central);

  imprimirRutaMenorTiempo(ciudadCariniosa, central);

  vigilarMaquina(ciudadCariniosa, 1);
  vigilarMaquina(ciudadCariniosa, 5);

  imprimirRutaMenorTiempo(ciudadCariniosa, central);

  vigilarMaquina(ciudadCariniosa, 4);
  vigilarMaquina(ciudadCariniosa, 0);

  imprimirRutaMenorTiempo(ciudadCariniosa, central);

  vigilarMaquina(ciudadCariniosa, 2);

  imprimirRutaMenorTiempo(ciudadCariniosa, central);

  imprimirCariniositosEnAccion(ciudadCariniosa,central, lcariniosos);

  return 0;
}
