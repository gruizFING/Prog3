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

  cout << "TEST 10.1" << endl;

  RedInfelicidad* ciudadCariniosa = crearRedInfelicidad(10);

  ListaSimpleConPrioridad*lprimosos = listaPrimositos();
  ListaSimpleConPrioridad*lprofesorsitos = listaProfesositos();

  unirMaquinasRedInfelicidad(ciudadCariniosa, 0, 4, 3);
  unirMaquinasRedInfelicidad(ciudadCariniosa, 0, 2, 3);
  unirMaquinasRedInfelicidad(ciudadCariniosa, 0, 6, 3);
  unirMaquinasRedInfelicidad(ciudadCariniosa, 1, 9, 3);
  unirMaquinasRedInfelicidad(ciudadCariniosa, 3, 4, 3);
  unirMaquinasRedInfelicidad(ciudadCariniosa, 5, 7, 3);
  unirMaquinasRedInfelicidad(ciudadCariniosa, 6, 7, 3);
  unirMaquinasRedInfelicidad(ciudadCariniosa, 6, 9, 3);
  unirMaquinasRedInfelicidad(ciudadCariniosa, 7, 8, 3);
  unirMaquinasRedInfelicidad(ciudadCariniosa, 7, 9, 3);
  unirMaquinasRedInfelicidad(ciudadCariniosa, 6, 8, 6);

  imprimirMaquinaCentral(ciudadCariniosa);

  int central = maquinaCentral(ciudadCariniosa);

  vigilarMaquina(ciudadCariniosa, 4);
  vigilarMaquina(ciudadCariniosa, 2);
  vigilarMaquina(ciudadCariniosa, 0);
  vigilarMaquina(ciudadCariniosa, 3);
  vigilarMaquina(ciudadCariniosa, 6);
  vigilarMaquina(ciudadCariniosa, 7);
  vigilarMaquina(ciudadCariniosa, 9);

  imprimirRutaMenorTiempo(ciudadCariniosa, central);

  imprimirCariniositosEnAccion(ciudadCariniosa,central, lprimosos);

  imprimirCariniositosEnAccion(ciudadCariniosa,central, lprofesorsitos);

  return 0;
}
