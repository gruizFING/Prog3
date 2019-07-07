#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "ListaSimpleConPrioridad.h"
#include "CarinioEstrategia.h"

#include "ListaCariniosos.h"
#include "RedInfelicidad.h"
#include "ColaSimple.h"
#include "util.h"

int main(){

    ///ACA EMPIEZA
    printf("                   **********************************************\n");
    printf("                   *      PRUEBAS SOBRE MAQUINA CENTRAL         *\n");
    printf("                   **********************************************\n");
    printf("\n\n");
    printf("Prueba maquina central 1:\n");
    int c = 800;
    printf("\nCreando red de %d nodos...",c);
    RedInfelicidad* red = crearRedInfelicidad(c);
    printf("OK.\n");
    printf("\nUniendo maquinas...");
    unirMaquinasRedInfelicidad(red,0,1,1);
    for (int i=2;i<cantMaquinasRedInfelicidad(red);i++)
        unirMaquinasRedInfelicidad(red,i,1,cantMaquinasRedInfelicidad(red)-i);
    for (int j=2;j<cantMaquinasRedInfelicidad(red);j=j+2)
        unirMaquinasRedInfelicidad(red,j,j+1,1);
    printf("OK.\n");
    printf("\nBuscando maquina central...");
    int central = maquinaCentral(red);
    printf("OK.\n");
	printf("                              La maquina central es la %d\n",central);
	printf("\n");
	printf("Destruyendo red...");
	destruirRedInfelicidad(red);
	printf("OK.\n\n");
	printf("Prueba maquina central 2:\n");
	int b = 1000;
	printf("\nCreando red de %d nodos...",b);
    RedInfelicidad* red1 = crearRedInfelicidad(b);
    for (int i=1;i<cantMaquinasRedInfelicidad(red1);i++)
        unirMaquinasRedInfelicidad(red1,i,0,1);
    printf("OK\n");
    printf("\nUniendo maquinas...");
    for (int j=1;j<cantMaquinasRedInfelicidad(red1);j=j+2)
        unirMaquinasRedInfelicidad(red1,j,j+1,1);
    printf("OK.\n");
    printf("\nBuscando maquina central...");
    int central1 = maquinaCentral(red1);
    printf("OK.\n");
	printf("                              La maquina central es la %d\n",central1);
	//printf("\nDestruyendo red...");
	//destruirRedInfelicidad(red1);        <<<<<<<<<<<<<<<===============   ESTO ES LO QUE ESTABA AL PEDO
	//printf("OK.\n\n");


    printf("\n\n");

    printf("Prueba maquina central 3:\n");
    int a = 7;
    printf("\nCreando red de %d nodos...",a);
    RedInfelicidad* red2 = crearRedInfelicidad(a);
    printf("OK.\n");
    printf("\nUniendo maquinas...");
    unirMaquinasRedInfelicidad(red2,0,1,1);
    unirMaquinasRedInfelicidad(red2,0,5,1);
    unirMaquinasRedInfelicidad(red2,5,2,1);
    unirMaquinasRedInfelicidad(red2,5,3,1);
    unirMaquinasRedInfelicidad(red2,3,2,1);
    unirMaquinasRedInfelicidad(red2,2,6,1);
    unirMaquinasRedInfelicidad(red2,3,4,1);
    unirMaquinasRedInfelicidad(red2,6,4,1);
    unirMaquinasRedInfelicidad(red2,1,5,1);
    printf("OK.\n");
    printf("\nBuscando maquina central...");
    int central2 = maquinaCentral(red2);
    printf("OK.\n");
	printf("                              La maquina central es la %d\n",central2);
	printf("\nDestruyendo red...");
	destruirRedInfelicidad(red2);
	printf("OK.\n\n");

    printf("\n\n");
    printf("Prueba maquina central 3:\n");
    a = 13;
    printf("\nCreando red de %d nodos...",a);
    RedInfelicidad* arbol = crearRedInfelicidad(a);
    printf("OK.\n");
    printf("\nUniendo maquinas...");
    unirMaquinasRedInfelicidad(arbol,0,1,1);
    unirMaquinasRedInfelicidad(arbol,1,2,3);
    unirMaquinasRedInfelicidad(arbol,3,2,114);
    unirMaquinasRedInfelicidad(arbol,4,3,11);
    unirMaquinasRedInfelicidad(arbol,4,5,7);
    unirMaquinasRedInfelicidad(arbol,5,6,14);
    unirMaquinasRedInfelicidad(arbol,8,7,1);
    unirMaquinasRedInfelicidad(arbol,3,9,8);
    unirMaquinasRedInfelicidad(arbol,9,8,21);
    unirMaquinasRedInfelicidad(arbol,3,10,15);
    unirMaquinasRedInfelicidad(arbol,10,11,72);
    unirMaquinasRedInfelicidad(arbol,11,12,4);
    printf("OK.\n");
    printf("\nBuscando maquina central...");
    int central3 = maquinaCentral(arbol);
    printf("OK.\n");
	printf("                              La maquina central es la %d\n",central3);

    printf("\n");
    printf("                   **********************************************\n");
    printf("                   *      PRUEBAS SOBRE CAMINO MAS CORTO        *\n");
    printf("                   **********************************************\n");
    printf("\n\n");

    printf("Prueba camino mas corto 1:\n\n");
    printf("Creando red con 25 nodos...");
	RedInfelicidad* ciudadCariniosa = crearRedInfelicidad(25);
	printf("OK.\n\n");
	printf("Uniendo maquinas...");
	unirMaquinasRedInfelicidad(ciudadCariniosa, 0, 1, 5);
	unirMaquinasRedInfelicidad(ciudadCariniosa, 2, 1, 8);
	unirMaquinasRedInfelicidad(ciudadCariniosa, 1, 16, 70);
	unirMaquinasRedInfelicidad(ciudadCariniosa, 2, 3, 3);
	unirMaquinasRedInfelicidad(ciudadCariniosa, 1, 23, 500);
	unirMaquinasRedInfelicidad(ciudadCariniosa, 23, 24, 700);
	unirMaquinasRedInfelicidad(ciudadCariniosa, 16, 3, 20);
	unirMaquinasRedInfelicidad(ciudadCariniosa, 3, 4, 3);
	unirMaquinasRedInfelicidad(ciudadCariniosa, 4, 5, 1);
	unirMaquinasRedInfelicidad(ciudadCariniosa, 5, 6, 1);
	unirMaquinasRedInfelicidad(ciudadCariniosa, 6, 17, 300);
	unirMaquinasRedInfelicidad(ciudadCariniosa, 6, 7, 3);
    unirMaquinasRedInfelicidad(ciudadCariniosa, 7, 8, 9);
	unirMaquinasRedInfelicidad(ciudadCariniosa, 8, 9, 2);
	unirMaquinasRedInfelicidad(ciudadCariniosa, 8, 12, 3);
	unirMaquinasRedInfelicidad(ciudadCariniosa, 9, 10, 1);
	unirMaquinasRedInfelicidad(ciudadCariniosa, 9, 13, 12);
	unirMaquinasRedInfelicidad(ciudadCariniosa, 10, 11, 4);
    unirMaquinasRedInfelicidad(ciudadCariniosa, 11, 12, 1);
	unirMaquinasRedInfelicidad(ciudadCariniosa, 12, 15, 2);
	unirMaquinasRedInfelicidad(ciudadCariniosa, 12, 13, 1);
	unirMaquinasRedInfelicidad(ciudadCariniosa, 14, 15, 1);
	unirMaquinasRedInfelicidad(ciudadCariniosa, 15, 16, 42);
	unirMaquinasRedInfelicidad(ciudadCariniosa, 15, 20, 1);
    unirMaquinasRedInfelicidad(ciudadCariniosa, 16, 20, 50);
	unirMaquinasRedInfelicidad(ciudadCariniosa, 20, 21, 200);
	unirMaquinasRedInfelicidad(ciudadCariniosa, 20, 22, 200);
	unirMaquinasRedInfelicidad(ciudadCariniosa, 19, 20, 2);
	unirMaquinasRedInfelicidad(ciudadCariniosa, 19, 18, 7);
	unirMaquinasRedInfelicidad(ciudadCariniosa, 16, 17, 3);
	printf("OK.\n\n");
	printf("Buscando maquina central...");
	int cnt = maquinaCentral(ciudadCariniosa);
	printf("OK.\n\n");
	printf("                              La maquina central es: %d\n\n\n",cnt);
    printf("Vigilando maquinas...");
	vigilarMaquina(ciudadCariniosa,0);
	vigilarMaquina(ciudadCariniosa,2);
	vigilarMaquina(ciudadCariniosa,3);
	vigilarMaquina(ciudadCariniosa,4);
	vigilarMaquina(ciudadCariniosa,5);
	vigilarMaquina(ciudadCariniosa,6);
	vigilarMaquina(ciudadCariniosa,7);
	vigilarMaquina(ciudadCariniosa,8);
	vigilarMaquina(ciudadCariniosa,9);
	vigilarMaquina(ciudadCariniosa,10);
	vigilarMaquina(ciudadCariniosa,11);
	vigilarMaquina(ciudadCariniosa,12);
	vigilarMaquina(ciudadCariniosa,13);
	vigilarMaquina(ciudadCariniosa,14);
	vigilarMaquina(ciudadCariniosa,15);
	vigilarMaquina(ciudadCariniosa,16);
	vigilarMaquina(ciudadCariniosa,17);
	vigilarMaquina(ciudadCariniosa,18);
	vigilarMaquina(ciudadCariniosa,19);
	vigilarMaquina(ciudadCariniosa,20);
	vigilarMaquina(ciudadCariniosa,21);
	vigilarMaquina(ciudadCariniosa,22);
	printf("OK.\n\n");
	printf("La ruta mas corta hacia la central desde una maquina no vigilada es:\n\n");
	printf("                                        (Buscando ruta mas corta...)\n\n");
	imprimirRutaMenorTiempo(ciudadCariniosa,cnt);
	printf("\n\nOK.\n\n");

    printf("Prueba camino mas corto 2:\n\n");
	printf("\n\nPrueba sobre la red con %d nodos creada mas arriba\n\n",b);
	printf("                                        (Buscando ruta mas corta...)\n\n");
	imprimirRutaMenorTiempo(red1,central1);
	printf("\n\nOK.\n\n");



	vigilarMaquina(arbol,1);
	vigilarMaquina(arbol,2);
	vigilarMaquina(arbol,4);
	vigilarMaquina(arbol,5);
	vigilarMaquina(arbol,8);
	vigilarMaquina(arbol,9);
	vigilarMaquina(arbol,10);
	vigilarMaquina(arbol,11);
	printf("Prueba camino mas corto 3:\n\n");
	printf("\n\nPrueba sobre la red con %d nodos creada mas arriba\n",a);
	printf("Central no vigilada\n\n");
	printf("                                        (Buscando ruta mas corta...)\n\n");
	imprimirRutaMenorTiempo(arbol,3);
	printf("\n\nOK.\n\n");

	vigilarMaquina(arbol,3);
	printf("Prueba camino mas corto 4:\n\n");
	printf("\n\nPrueba sobre la red con %d nodos creada mas arriba\n",a);
	printf("Central vigilada, algunas no vigiladas\n\n");
	printf("                                        (Buscando ruta mas corta...)\n\n");
	imprimirRutaMenorTiempo(arbol,3);
	printf("\n\nOK.\n\n");

	vigilarMaquina(arbol,0);
	vigilarMaquina(arbol,12);
	vigilarMaquina(arbol,6);
	vigilarMaquina(arbol,7);
	printf("Prueba camino mas corto 3:\n\n");
	printf("\n\nPrueba sobre la red con %d nodos creada mas arriba\n",a);
	printf("Todas vigiladas\n\n");
	printf("                                        (Buscando ruta mas corta...)\n\n");
	imprimirRutaMenorTiempo(arbol,3);
	printf("\n\nOK.\n\n");
    printf("\nDestruyendo red...");
	destruirRedInfelicidad(arbol);
	printf("OK.\n\n");


	printf("\n");
    printf("                   **********************************************\n");
    printf("                   *     PRUEBAS SOBRE CARINIOSOS EN ACCION     *\n");
    printf("                   **********************************************\n");
    printf("\n\n");
    char* c1 = strdup("Alfa");
    char* c2 = strdup("Beta");
    char* c3 = strdup("Gamma");
    char* c4 = strdup("Delta");
    char* c5 = strdup("Epsilon");
    char* c6 = strdup("Kappa");
    char* c7 = strdup("Iota");
    char* c8 = strdup("Pi");
    char* c9 = strdup("Rho");
    char* c11 = strdup("Phi");
    char* c12 = strdup("Psi");
    char* c31 = strdup("Omega");
    char* c41 = strdup("Ypsilon");
    char* c51 = strdup("Marcelo se la come");
    char* c61 = strdup("Chuck");
    char* c71 = strdup("Otra vez epsilon");
    char* c81 = strdup("Epsilon capo");
    char* c91 = strdup("Sabelo que epsilon es grande");
    char* c311 = strdup("Marcelo se la come doblada");
    char* c411 = strdup("Epsilon grande!");
    char* c511 = strdup("Signo de exclamacion(!)");
    char* c611 = strdup("Signo de pregunta (?)");
    char* c711 = strdup("Signo de menos(-)");
    char* c811 = strdup("Signo de mas (+)");
    char* c911 = strdup("BANANERO ACM1PT");

    ListaSimpleConPrioridad* Cariniositos = crearListaSimpleConPrioridad();
    int prioridad = 0;

    agregarListaSimpleConPrioridad(Cariniositos,(char*)c1,prioridad);
    prioridad++;
    agregarListaSimpleConPrioridad(Cariniositos,(char*)c2,prioridad);
    prioridad++;
    agregarListaSimpleConPrioridad(Cariniositos,(char*)c3,prioridad);
    prioridad++;
    agregarListaSimpleConPrioridad(Cariniositos,(char*)c4,prioridad);
    prioridad++;
    agregarListaSimpleConPrioridad(Cariniositos,(char*)c5,prioridad);
    prioridad++;
    agregarListaSimpleConPrioridad(Cariniositos,(char*)c6,prioridad);
    prioridad++;
    agregarListaSimpleConPrioridad(Cariniositos,(char*)c7,prioridad);
    prioridad++;
    agregarListaSimpleConPrioridad(Cariniositos,(char*)c8,prioridad);
    prioridad++;
    agregarListaSimpleConPrioridad(Cariniositos,(char*)c9,prioridad);
    prioridad++;
    agregarListaSimpleConPrioridad(Cariniositos,(char*)c11,prioridad);
    prioridad++;
    agregarListaSimpleConPrioridad(Cariniositos,(char*)c12,prioridad);
    prioridad++;
    agregarListaSimpleConPrioridad(Cariniositos,(char*)c31,prioridad);
    prioridad++;
    agregarListaSimpleConPrioridad(Cariniositos,(char*)c41,prioridad);
    prioridad++;
    agregarListaSimpleConPrioridad(Cariniositos,(char*)c51,prioridad);
    prioridad++;
    agregarListaSimpleConPrioridad(Cariniositos,(char*)c61,prioridad);
    prioridad++;
    agregarListaSimpleConPrioridad(Cariniositos,(char*)c71,prioridad);
    prioridad++;
    agregarListaSimpleConPrioridad(Cariniositos,(char*)c81,prioridad);
    prioridad++;
    agregarListaSimpleConPrioridad(Cariniositos,(char*)c91,prioridad);
    prioridad++;
    agregarListaSimpleConPrioridad(Cariniositos,(char*)c311,prioridad);
    prioridad++;
    agregarListaSimpleConPrioridad(Cariniositos,(char*)c411,prioridad);
    prioridad++;
    agregarListaSimpleConPrioridad(Cariniositos,(char*)c511,prioridad);
    prioridad++;
    agregarListaSimpleConPrioridad(Cariniositos,(char*)c611,prioridad);
    prioridad++;
    agregarListaSimpleConPrioridad(Cariniositos,(char*)c711,prioridad);
    prioridad++;
    agregarListaSimpleConPrioridad(Cariniositos,(char*)c811,prioridad);
    prioridad++;
    agregarListaSimpleConPrioridad(Cariniositos,(char*)c911,prioridad);
    prioridad++;

    imprimirCariniositosEnAccion(ciudadCariniosa,20,Cariniositos);
    return 0;

///ACA TERMINA


}

