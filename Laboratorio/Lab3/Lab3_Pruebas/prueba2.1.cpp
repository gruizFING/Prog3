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
	RedInfelicidad* ri = crearRedInfelicidad(21);
	unirMaquinasRedInfelicidad(ri,0,18,1);
	unirMaquinasRedInfelicidad(ri,0,11,1);
	unirMaquinasRedInfelicidad(ri,1,3,6);
	unirMaquinasRedInfelicidad(ri,1,2,2);
	unirMaquinasRedInfelicidad(ri,1,19,3);
	// unirMaquinasRedInfelicidad(ri,1,6,9);	
	unirMaquinasRedInfelicidad(ri,2,16,1);
	unirMaquinasRedInfelicidad(ri,3,4,10);
	unirMaquinasRedInfelicidad(ri,3,13,7);
	unirMaquinasRedInfelicidad(ri,3,11,1);
	unirMaquinasRedInfelicidad(ri,3,6,5);
	unirMaquinasRedInfelicidad(ri,4,15,10);
	unirMaquinasRedInfelicidad(ri,5,14,1);
	unirMaquinasRedInfelicidad(ri,5,19,5);
	unirMaquinasRedInfelicidad(ri,6,16,3);
	unirMaquinasRedInfelicidad(ri,6,7,1);
	unirMaquinasRedInfelicidad(ri,7,8,1);
	unirMaquinasRedInfelicidad(ri,8,9,1);
	unirMaquinasRedInfelicidad(ri,9,10,2);
	unirMaquinasRedInfelicidad(ri,10,20,3);
	unirMaquinasRedInfelicidad(ri,11,17,9);
	unirMaquinasRedInfelicidad(ri,12,15,9);
	unirMaquinasRedInfelicidad(ri,12,19,2);
		
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
