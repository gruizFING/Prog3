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

  cout << "TEST 8.1" << endl;

  RedInfelicidad* ciudadCariniosa = crearRedInfelicidad(10);

  ListaSimpleConPrioridad*lcariniosos = listaCariniositos();
  ListaSimpleConPrioridad*lprimosos = listaPrimositos();
  ListaSimpleConPrioridad*lprofesorsitos = listaProfesositos();

  unirMaquinasRedInfelicidad(ciudadCariniosa, 0, 4, 4);
  unirMaquinasRedInfelicidad(ciudadCariniosa, 0, 2, 1);
  unirMaquinasRedInfelicidad(ciudadCariniosa, 0, 6, 2);
  unirMaquinasRedInfelicidad(ciudadCariniosa, 1, 9, 1);
  unirMaquinasRedInfelicidad(ciudadCariniosa, 3, 4, 3);
  unirMaquinasRedInfelicidad(ciudadCariniosa, 5, 7, 3);
  unirMaquinasRedInfelicidad(ciudadCariniosa, 6, 7, 1);
  unirMaquinasRedInfelicidad(ciudadCariniosa, 6, 9, 3);
  unirMaquinasRedInfelicidad(ciudadCariniosa, 7, 8, 5);
  unirMaquinasRedInfelicidad(ciudadCariniosa, 7, 9, 12);

  imprimirMaquinaCentral(ciudadCariniosa);

  int central = maquinaCentral(ciudadCariniosa);

  imprimirRutaMenorTiempo(ciudadCariniosa, central);

  imprimirCariniositosEnAccion(ciudadCariniosa,central, lcariniosos);

  cout << "TEST 8.2" << endl;

  vigilarMaquina(ciudadCariniosa, central);

  imprimirRutaMenorTiempo(ciudadCariniosa, central);

  vigilarMaquina(ciudadCariniosa, 4);
  vigilarMaquina(ciudadCariniosa, 7);
  vigilarMaquina(ciudadCariniosa, 0);
  vigilarMaquina(ciudadCariniosa, 9);

  imprimirRutaMenorTiempo(ciudadCariniosa, central);

  imprimirCariniositosEnAccion(ciudadCariniosa,central, lprimosos);

  cout << "TEST 8.3" << endl;

  vigilarMaquina(ciudadCariniosa, 2);
  vigilarMaquina(ciudadCariniosa, 6);


  imprimirRutaMenorTiempo(ciudadCariniosa, central);

  imprimirCariniositosEnAccion(ciudadCariniosa,central, lprofesorsitos);

  return 0;
}
