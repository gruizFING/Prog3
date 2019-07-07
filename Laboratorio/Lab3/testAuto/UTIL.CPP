#include <stdio.h>
#include <stdlib.h>
#include "util.h"


void imprimirMaquinaCentral(RedInfelicidad* ri)
{
	printf("Maquina central:%d\n", maquinaCentral(ri));
}

void imprimirRutaMenorTiempo(RedInfelicidad* ri, int central)
{ Camino* res = rutaMenorTiempo(ri, central);

  if(res->tiempo > 0)
	{
      ListaSimpleConPrioridad* iterator = crearListaSimpleConPrioridad();
	  iterator = res->maquinasCamino;
	  printf("%d", *((int*)primeroListaSimpleConPrioridad(iterator)));
	  iterator = restoListaSimpleConPrioridad(iterator);
	  while (!esVaciaListaSimpleConPrioridad(iterator))
		{
			printf(" -> %d", *((int*)primeroListaSimpleConPrioridad(iterator)));
			iterator = restoListaSimpleConPrioridad(iterator);
		}
      printf("\n");
	}
	else if (res->tiempo == 0)
      printf("la maquina central no esta vigilada, yupi!! \n");
    else
      printf("todas las maquinas estan vigiladas, snif... \n");
}

void imprimirCariniositosEnAccion(RedInfelicidad* ri, int central, ListaSimpleConPrioridad* cariniositos)
{
    ListaSimpleConPrioridad* res = cariniositosEnAccion(ri, central, cariniositos);

    ListaSimpleConPrioridad* iterator = res;
    while (!esVaciaListaSimpleConPrioridad(iterator))
		{   CarinioAccion* nodo = (CarinioAccion*)primeroListaSimpleConPrioridad(iterator);
			printf("en punto %d  queda cariniosito \"%s\" \n",nodo->idmaquina, nodo->cariniosito);
			iterator = restoListaSimpleConPrioridad(iterator);
		};
}

