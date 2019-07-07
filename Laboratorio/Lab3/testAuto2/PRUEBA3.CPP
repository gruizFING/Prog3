#include <stdio.h>
#include <stdlib.h>

#include "RedInfelicidad.h"
#include "CarinioEstrategia.h"
#include "util.h"
#include "ListaCariniosos.h"

#include <iostream>
using namespace std;

/*GRAFO RARO*/
int main()
{

  cout << "PRUEBA 1.1" << endl << endl;

  RedInfelicidad* ciudadCariniosa = crearRedInfelicidad(8);

  ListaSimpleConPrioridad*lcariniositos = listaCariniositos();
  ListaSimpleConPrioridad*lcariniosos = listaCariniosos();

  unirMaquinasRedInfelicidad(ciudadCariniosa, 0, 1, 1);
  unirMaquinasRedInfelicidad(ciudadCariniosa, 0, 2, 1);  
  unirMaquinasRedInfelicidad(ciudadCariniosa, 3, 1, 2);
  unirMaquinasRedInfelicidad(ciudadCariniosa, 2, 4, 2);  
  unirMaquinasRedInfelicidad(ciudadCariniosa, 3, 5, 1);
  unirMaquinasRedInfelicidad(ciudadCariniosa, 4, 5, 1);  
  unirMaquinasRedInfelicidad(ciudadCariniosa, 5, 6, 7);
  unirMaquinasRedInfelicidad(ciudadCariniosa, 5, 7, 7);   

  imprimirMaquinaCentral(ciudadCariniosa);

  int central = maquinaCentral(ciudadCariniosa); 
 
  vigilarMaquina(ciudadCariniosa, 5);
   imprimirRutaMenorTiempo(ciudadCariniosa, central);
  
  vigilarMaquina(ciudadCariniosa, 3);
  imprimirRutaMenorTiempo(ciudadCariniosa, central);
  
  vigilarMaquina(ciudadCariniosa, 4);
  vigilarMaquina(ciudadCariniosa, 1);
  vigilarMaquina(ciudadCariniosa, 2);
  imprimirRutaMenorTiempo(ciudadCariniosa, central);
    
  imprimirCariniositosEnAccion(ciudadCariniosa,central, lcariniositos);

  imprimirCariniositosEnAccion(ciudadCariniosa,5, lcariniosos );

  imprimirCariniositosEnAccion(ciudadCariniosa,7, lcariniosos );
    
  imprimirCariniositosEnAccion(ciudadCariniosa,0, lcariniosos );
  
  destruirRedInfelicidad(ciudadCariniosa);

   cout << "PRUEBA 1.2" << endl << endl;

  ciudadCariniosa = crearRedInfelicidad(7);
   
   unirMaquinasRedInfelicidad(ciudadCariniosa, 0, 1, 2);
  unirMaquinasRedInfelicidad(ciudadCariniosa, 0, 2, 1);  
  unirMaquinasRedInfelicidad(ciudadCariniosa, 2, 1, 4);
  unirMaquinasRedInfelicidad(ciudadCariniosa, 1, 3, 5);  
  unirMaquinasRedInfelicidad(ciudadCariniosa, 3, 2, 3);
  unirMaquinasRedInfelicidad(ciudadCariniosa, 4, 5, 1);  
  unirMaquinasRedInfelicidad(ciudadCariniosa, 5, 6, 2);
  unirMaquinasRedInfelicidad(ciudadCariniosa, 5, 3, 7);   
  unirMaquinasRedInfelicidad(ciudadCariniosa, 4, 3, 6);   
  unirMaquinasRedInfelicidad(ciudadCariniosa, 4, 6, 9);   

  imprimirMaquinaCentral(ciudadCariniosa);
  central = maquinaCentral(ciudadCariniosa); 
  central = maquinaCentral(ciudadCariniosa); 
  
  imprimirCariniositosEnAccion(ciudadCariniosa,central, lcariniositos);

  imprimirRutaMenorTiempo(ciudadCariniosa, central);
  
  vigilarMaquina(ciudadCariniosa, 5);
   imprimirRutaMenorTiempo(ciudadCariniosa, central);
   
  vigilarMaquina(ciudadCariniosa, 2);
  vigilarMaquina(ciudadCariniosa, 3);
  imprimirRutaMenorTiempo(ciudadCariniosa, central);
  imprimirRutaMenorTiempo(ciudadCariniosa, central);
  vigilarMaquina(ciudadCariniosa, 0);
 
  imprimirRutaMenorTiempo(ciudadCariniosa, central);
  
  vigilarMaquina(ciudadCariniosa, 4);
  vigilarMaquina(ciudadCariniosa, 1);
  
  imprimirRutaMenorTiempo(ciudadCariniosa, central);
  vigilarMaquina(ciudadCariniosa, 0);
  vigilarMaquina(ciudadCariniosa, 6);
   imprimirRutaMenorTiempo(ciudadCariniosa, central);
  imprimirCariniositosEnAccion(ciudadCariniosa,central, lcariniositos);

  central = maquinaCentral(ciudadCariniosa); 
  central = maquinaCentral(ciudadCariniosa); 
  central = maquinaCentral(ciudadCariniosa); 
  central = maquinaCentral(ciudadCariniosa); 
  central = maquinaCentral(ciudadCariniosa); 
  central = maquinaCentral(ciudadCariniosa); 
  central = maquinaCentral(ciudadCariniosa); 
  central = maquinaCentral(ciudadCariniosa); 
  central = maquinaCentral(ciudadCariniosa); 
  central = maquinaCentral(ciudadCariniosa); 
  central = maquinaCentral(ciudadCariniosa); 
  central = maquinaCentral(ciudadCariniosa); 
  central = maquinaCentral(ciudadCariniosa); 
  central = maquinaCentral(ciudadCariniosa); 
  central = maquinaCentral(ciudadCariniosa); 
  central = maquinaCentral(ciudadCariniosa); 
  imprimirMaquinaCentral(ciudadCariniosa);
  imprimirMaquinaCentral(ciudadCariniosa);
  imprimirMaquinaCentral(ciudadCariniosa);
  imprimirMaquinaCentral(ciudadCariniosa);
  imprimirMaquinaCentral(ciudadCariniosa);
  imprimirMaquinaCentral(ciudadCariniosa);
  imprimirMaquinaCentral(ciudadCariniosa);
  imprimirMaquinaCentral(ciudadCariniosa);
  imprimirMaquinaCentral(ciudadCariniosa);
  imprimirMaquinaCentral(ciudadCariniosa);
  imprimirMaquinaCentral(ciudadCariniosa);
  imprimirMaquinaCentral(ciudadCariniosa);
  imprimirMaquinaCentral(ciudadCariniosa);
  
  vigilarMaquina(ciudadCariniosa, 4);
  vigilarMaquina(ciudadCariniosa, 4);
  vigilarMaquina(ciudadCariniosa, 4);
  vigilarMaquina(ciudadCariniosa, 4);
  vigilarMaquina(ciudadCariniosa, 4);
  vigilarMaquina(ciudadCariniosa, 4);
  imprimirCariniositosEnAccion(ciudadCariniosa,central, lcariniositos);

  imprimirRutaMenorTiempo(ciudadCariniosa, central);
  
  imprimirRutaMenorTiempo(ciudadCariniosa, central);
  
  imprimirRutaMenorTiempo(ciudadCariniosa, central);
  
  imprimirCariniositosEnAccion(ciudadCariniosa,2, lcariniositos);

  destruirRedInfelicidad(ciudadCariniosa);
  
  return 0;
}
