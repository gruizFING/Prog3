#include <stdio.h>
#include <stdlib.h>

#include "RedInfelicidad.h"
#include "CarinioEstrategia.h"
#include "util.h"
#include "ListaCariniosos.h"

#include <iostream>
using namespace std;

/*...en este main se prueban las mismas cosas variando la complejidad del grafo...*/

int main()
{

 cout << "PRUEBA 0.0" << endl << endl;

  RedInfelicidad* ciudadCariniosa = crearRedInfelicidad(1);
  ListaSimpleConPrioridad*lprimosos = listaPrimositos();
  
  unirMaquinasRedInfelicidad(ciudadCariniosa, 0, 1, 3);
  unirMaquinasRedInfelicidad(ciudadCariniosa, 1, 2, 3);  
  unirMaquinasRedInfelicidad(ciudadCariniosa, 0, 6, 3);
  unirMaquinasRedInfelicidad(ciudadCariniosa, 1, 6, 3);
  unirMaquinasRedInfelicidad(ciudadCariniosa, 2, 6, 3);
  unirMaquinasRedInfelicidad(ciudadCariniosa, 3, 6, 3);
  unirMaquinasRedInfelicidad(ciudadCariniosa, 6, 4, 3);
  unirMaquinasRedInfelicidad(ciudadCariniosa, 5, 6, 3);
  
   int central = maquinaCentral(ciudadCariniosa); 
   imprimirMaquinaCentral(ciudadCariniosa);
   
   vigilarMaquina(ciudadCariniosa, 2);
   imprimirRutaMenorTiempo(ciudadCariniosa, central);
   
   vigilarMaquina(ciudadCariniosa, 0);
	imprimirRutaMenorTiempo(ciudadCariniosa, central);
	
  imprimirCariniositosEnAccion(ciudadCariniosa,central, lprimosos);

  
  cout << "PRUEBA 0.1" << endl << endl;

  ciudadCariniosa = crearRedInfelicidad(3);

  
  ListaSimpleConPrioridad*lprofesorsitos = listaProfesositos();

  unirMaquinasRedInfelicidad(ciudadCariniosa, 0, 1, 3);
  unirMaquinasRedInfelicidad(ciudadCariniosa, 1, 2, 3);  

  imprimirMaquinaCentral(ciudadCariniosa);

 central = maquinaCentral(ciudadCariniosa); 
  imprimirRutaMenorTiempo(ciudadCariniosa, central);
  
  vigilarMaquina(ciudadCariniosa, 1);
   imprimirRutaMenorTiempo(ciudadCariniosa, central);
  
  vigilarMaquina(ciudadCariniosa, 0);
  imprimirRutaMenorTiempo(ciudadCariniosa, central);
  
  vigilarMaquina(ciudadCariniosa, 2);
  imprimirRutaMenorTiempo(ciudadCariniosa, central);
  
  imprimirCariniositosEnAccion(ciudadCariniosa,central, lprimosos);

  imprimirCariniositosEnAccion(ciudadCariniosa,central, lprofesorsitos);

  destruirRedInfelicidad(ciudadCariniosa);

   cout << "PRUEBA 0.2" << endl << endl;

  ciudadCariniosa = crearRedInfelicidad(7);

  unirMaquinasRedInfelicidad(ciudadCariniosa, 0, 6, 3);
  unirMaquinasRedInfelicidad(ciudadCariniosa, 1, 6, 3);
  unirMaquinasRedInfelicidad(ciudadCariniosa, 2, 6, 3);
  unirMaquinasRedInfelicidad(ciudadCariniosa, 3, 6, 3);
  unirMaquinasRedInfelicidad(ciudadCariniosa, 6, 4, 3);
  unirMaquinasRedInfelicidad(ciudadCariniosa, 5, 6, 3);
  
  imprimirMaquinaCentral(ciudadCariniosa);
  
  central = maquinaCentral(ciudadCariniosa); 
  imprimirRutaMenorTiempo(ciudadCariniosa, central);
  
  vigilarMaquina(ciudadCariniosa, 6);
   imprimirRutaMenorTiempo(ciudadCariniosa, central);
   
   vigilarMaquina(ciudadCariniosa, 0);
   imprimirRutaMenorTiempo(ciudadCariniosa, central);
   
   vigilarMaquina(ciudadCariniosa, 1);
   imprimirRutaMenorTiempo(ciudadCariniosa, central);
   
   vigilarMaquina(ciudadCariniosa, 2);
   imprimirRutaMenorTiempo(ciudadCariniosa, central);
   
   vigilarMaquina(ciudadCariniosa, 3);
   imprimirRutaMenorTiempo(ciudadCariniosa, central);
   
   vigilarMaquina(ciudadCariniosa, 4);
   imprimirRutaMenorTiempo(ciudadCariniosa, central);
   
   vigilarMaquina(ciudadCariniosa, 5);
   imprimirRutaMenorTiempo(ciudadCariniosa, central);
   
   imprimirCariniositosEnAccion(ciudadCariniosa,central, lprofesorsitos);

   destruirRedInfelicidad(ciudadCariniosa);

   cout << "PRUEBA 0.3" << endl << endl;

  ciudadCariniosa = crearRedInfelicidad(7);

  unirMaquinasRedInfelicidad(ciudadCariniosa, 0, 6, 1);
  unirMaquinasRedInfelicidad(ciudadCariniosa, 1, 6, 2);
  unirMaquinasRedInfelicidad(ciudadCariniosa, 2, 6, 3);
  unirMaquinasRedInfelicidad(ciudadCariniosa, 3, 6, 4);
  unirMaquinasRedInfelicidad(ciudadCariniosa, 6, 4, 5);
  unirMaquinasRedInfelicidad(ciudadCariniosa, 5, 6, 6);
 
  
  imprimirMaquinaCentral(ciudadCariniosa);
  
  central = maquinaCentral(ciudadCariniosa); 
  imprimirRutaMenorTiempo(ciudadCariniosa, central);
  
  vigilarMaquina(ciudadCariniosa, 6);
   imprimirRutaMenorTiempo(ciudadCariniosa, central);
   
   vigilarMaquina(ciudadCariniosa, 0);
   imprimirRutaMenorTiempo(ciudadCariniosa, central);
   
   vigilarMaquina(ciudadCariniosa, 1);
   imprimirRutaMenorTiempo(ciudadCariniosa, central);
   
   vigilarMaquina(ciudadCariniosa, 2);
   imprimirRutaMenorTiempo(ciudadCariniosa, central);
   
   vigilarMaquina(ciudadCariniosa, 3);
   imprimirRutaMenorTiempo(ciudadCariniosa, central);
   
   vigilarMaquina(ciudadCariniosa, 4);
   imprimirRutaMenorTiempo(ciudadCariniosa, central);
   
   vigilarMaquina(ciudadCariniosa, 5);
   imprimirRutaMenorTiempo(ciudadCariniosa, central);
   
   imprimirCariniositosEnAccion(ciudadCariniosa,central, lprofesorsitos);

   destruirRedInfelicidad(ciudadCariniosa);
  return 0;
}
