#include "RedInfelicidad.h"
#include "ListaSimpleConPrioridad.h"
#include "CarinioEstrategia.h"
#include "util.h"
#include <stdio.h>
// ************ CAMINO MAS CORTO ************* //

void ImprimirRI(RedInfelicidad* ri){
	printf("Maquina Central      = %i\n",maquinaCentral(ri));
	printf("Cantidad de Maquinas = %i\n",cantMaquinasRedInfelicidad(ri));
	int i;
	for (i=0;i<cantMaquinasRedInfelicidad(ri);i++){
		printf("--Maquina->%i\n",i);
		ListaSimpleConPrioridad* l = obtenerConexionesRedInfelicidad(ri,i);
		printf("Conexiones: ");		
		while (!esVaciaListaSimpleConPrioridad(l)){
			struct Conexion* con = (struct Conexion*) primeroListaSimpleConPrioridad(l);
			printf("ID:%i-C:%i ",con->idmaquina,con->costo);	
			l = restoListaSimpleConPrioridad(l);
		}			
		printf("\n***********************\n");
	}
}

int main(){
	printf("----------------------------Red 1---------------------------\n");
	RedInfelicidad* ri = crearRedInfelicidad(13);
	unirMaquinasRedInfelicidad(ri,0,1,10);
	unirMaquinasRedInfelicidad(ri,1,3,5);
	unirMaquinasRedInfelicidad(ri,1,4,6);
	unirMaquinasRedInfelicidad(ri,1,6,9);	
	unirMaquinasRedInfelicidad(ri,1,7,1);
	unirMaquinasRedInfelicidad(ri,2,7,2);
	unirMaquinasRedInfelicidad(ri,2,10,3);
	unirMaquinasRedInfelicidad(ri,3,11,3);
	unirMaquinasRedInfelicidad(ri,4,5,1);
	unirMaquinasRedInfelicidad(ri,4,12,2);	
	unirMaquinasRedInfelicidad(ri,6,8,3);
	unirMaquinasRedInfelicidad(ri,6,9,1);
	unirMaquinasRedInfelicidad(ri,7,10,2);
	unirMaquinasRedInfelicidad(ri,8,9,5);
	int central = maquinaCentral(ri);
	
	Camino* res = rutaMenorTiempo(ri, central);
	imprimirRutaMenorTiempo(ri,central);
	while (res->tiempo >= 0){
		ListaSimpleConPrioridad* iterator = crearListaSimpleConPrioridad();
		iterator = res->maquinasCamino;
		printf("Vigilo %d.\n", *((int*)primeroListaSimpleConPrioridad(iterator)));
		vigilarMaquina(ri,*((int*)primeroListaSimpleConPrioridad(iterator)));
		res = rutaMenorTiempo(ri, central);
		printf("El nuevo camino es \n");
		imprimirRutaMenorTiempo(ri,central);
	}
}
