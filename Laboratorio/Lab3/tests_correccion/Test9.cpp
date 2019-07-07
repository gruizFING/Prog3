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

  cout << "TEST 9.1" << endl;

  RedInfelicidad* ciudadCariniosa = crearRedInfelicidad(6);

  ListaSimpleConPrioridad*lcariniosos = listaCariniositos();

  unirMaquinasRedInfelicidad(ciudadCariniosa, 0, 3, 3);
  unirMaquinasRedInfelicidad(ciudadCariniosa, 2, 1, 3);
  unirMaquinasRedInfelicidad(ciudadCariniosa, 1, 3, 3);
  unirMaquinasRedInfelicidad(ciudadCariniosa, 1, 5, 3);
  unirMaquinasRedInfelicidad(ciudadCariniosa, 5, 3, 3);
  unirMaquinasRedInfelicidad(ciudadCariniosa, 3, 4, 3);

  imprimirMaquinaCentral(ciudadCariniosa);

  int central = maquinaCentral(ciudadCariniosa);

  imprimirRutaMenorTiempo(ciudadCariniosa, central);

  vigilarMaquina(ciudadCariniosa, central);

  imprimirRutaMenorTiempo(ciudadCariniosa, central);

  imprimirCariniositosEnAccion(ciudadCariniosa,central, lcariniosos);

  return 0;
}
