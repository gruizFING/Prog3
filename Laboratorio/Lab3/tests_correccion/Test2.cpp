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

  cout << "TEST 2.1" << endl;

  RedInfelicidad* ciudadCariniosa = crearRedInfelicidad(9);
  unirMaquinasRedInfelicidad(ciudadCariniosa, 0, 2, 10);

  ListaSimpleConPrioridad*lcariniosos = listaProfesositos();

  unirMaquinasRedInfelicidad(ciudadCariniosa, 0, 2, 10);
  unirMaquinasRedInfelicidad(ciudadCariniosa, 1, 2, 11);
  unirMaquinasRedInfelicidad(ciudadCariniosa, 2, 5, 4);
  unirMaquinasRedInfelicidad(ciudadCariniosa, 3, 5, 2);
  unirMaquinasRedInfelicidad(ciudadCariniosa, 3, 4, 7);
  unirMaquinasRedInfelicidad(ciudadCariniosa, 5, 4, 3);

  unirMaquinasRedInfelicidad(ciudadCariniosa, 6, 4, 1);
  unirMaquinasRedInfelicidad(ciudadCariniosa, 4, 7, 1);

  unirMaquinasRedInfelicidad(ciudadCariniosa, 6, 7, 2);
  unirMaquinasRedInfelicidad(ciudadCariniosa, 6, 8, 1);
  unirMaquinasRedInfelicidad(ciudadCariniosa, 5, 8, 8);
  unirMaquinasRedInfelicidad(ciudadCariniosa, 8, 7, 9);

 int central = maquinaCentral(ciudadCariniosa); //central es la 2

  imprimirMaquinaCentral(ciudadCariniosa);

  vigilarMaquina(ciudadCariniosa, central);
  vigilarMaquina(ciudadCariniosa, 3);
  vigilarMaquina(ciudadCariniosa, 4);
  vigilarMaquina(ciudadCariniosa, 5);

  imprimirRutaMenorTiempo(ciudadCariniosa, central);

  imprimirCariniositosEnAccion(ciudadCariniosa,central, lcariniosos);

  return 0;
}
