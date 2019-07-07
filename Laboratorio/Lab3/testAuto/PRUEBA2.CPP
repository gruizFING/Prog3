
#include "CarinioEstrategia.h"
#include "ColaSimple.h"
#include "RedInfelicidad.h"
#include "ListaSimpleConPrioridad.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{

ListaSimpleConPrioridad* Cariniositos = crearListaSimpleConPrioridad();
int prioridad = 0;

char* c1 = strdup("Dani Umpi");
char* c2 = strdup("Frodo");
char* c3 = strdup("J.S Bach");
char* c4 = strdup("Deicide");
char* c5 = strdup("Diego Forlan");
char* c6 = strdup("Jenna Jameson (esta es cariniosa en serio)");
char* c7 = strdup("Dios");
char* c8 = strdup("alguno del INCO");
char* c9 = strdup("Queca Gada");
char* c10 = strdup("Che QueVara");
char* c11 = strdup("LUIS XIV");
char* c12 = strdup("Terminator");
char* c13 = strdup("Wanda Nara");
char* c14 = strdup("Akinator");
char* c15 = strdup("Gandalf");

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
    agregarListaSimpleConPrioridad(Cariniositos,(char*)c10,prioridad);
    prioridad++;
    agregarListaSimpleConPrioridad(Cariniositos,(char*)c11,prioridad);
    prioridad++;
    agregarListaSimpleConPrioridad(Cariniositos,(char*)c12,prioridad);
    prioridad++;
    agregarListaSimpleConPrioridad(Cariniositos,(char*)c13,prioridad);
    prioridad++;
    agregarListaSimpleConPrioridad(Cariniositos,(char*)c14,prioridad);
    prioridad++;
    agregarListaSimpleConPrioridad(Cariniositos,(char*)c15,prioridad);



RedInfelicidad* ri = crearRedInfelicidad(15);

unirMaquinasRedInfelicidad(ri,0,14,2);
unirMaquinasRedInfelicidad(ri,0,10,1);
unirMaquinasRedInfelicidad(ri,0,12,5);
unirMaquinasRedInfelicidad(ri,0,2,1);
unirMaquinasRedInfelicidad(ri,0,3,3);
unirMaquinasRedInfelicidad(ri,10,9,2);
unirMaquinasRedInfelicidad(ri,10,11,1);
unirMaquinasRedInfelicidad(ri,14,13,2);
unirMaquinasRedInfelicidad(ri,2,7,2);
unirMaquinasRedInfelicidad(ri,2,5,6);
unirMaquinasRedInfelicidad(ri,7,8,4);
unirMaquinasRedInfelicidad(ri,5,8,5);
unirMaquinasRedInfelicidad(ri,3,5,2);
unirMaquinasRedInfelicidad(ri,1,3,1);
unirMaquinasRedInfelicidad(ri,1,4,1);
unirMaquinasRedInfelicidad(ri,4,6,3);
unirMaquinasRedInfelicidad(ri,6,5,3);

vigilarMaquina(ri,0);
vigilarMaquina(ri,10);
vigilarMaquina(ri,14);
vigilarMaquina(ri,12);
vigilarMaquina(ri,2);
vigilarMaquina(ri,3);
vigilarMaquina(ri,5);
vigilarMaquina(ri,8);

printf("Red Infelicidad:\n");
printf("\n");

for (int i = 0; i < cantMaquinasRedInfelicidad(ri); i++)
{
    printf("Maquina %d:\n",i);
    printf("Estado: ");

    if (maquinaEstaVigilada(ri,i))
       printf("Vigilada\n");
    else
       printf("No vigilada\n");

    printf("Conexiones:\n");
    for (int j = 0; j < cantMaquinasRedInfelicidad(ri); j++)
    {
        if (estanConectadasMaquinasRedInfelicidad(ri,i,j))
           printf("   Maq. %d\n",j);
    }
    printf("\n");
}

int maq_central = maquinaCentral(ri);

printf ("La maquina central es: %d\n",maq_central);
printf("\n");

Camino* rutaMenor = rutaMenorTiempo(ri,maq_central);

printf("La ruta mas corta a la central desde una no vigilada y su tiempo son:\n");

printf("Tiempo: %d\n",rutaMenor->tiempo);
ListaSimpleConPrioridad* maqs = rutaMenor->maquinasCamino;
while (!esVaciaListaSimpleConPrioridad(maqs))
{
    Conexion* primera = (Conexion*)primeroListaSimpleConPrioridad(maqs);
    printf("maquina: %d\n",primera->idmaquina);
    maqs = restoListaSimpleConPrioridad(maqs);
}

printf("\n");

printf("Recorrido de la felicidad:\n");

printf("\n");

ListaSimpleConPrioridad* Carinios = cariniositosEnAccion(ri,maq_central,Cariniositos);
while (!esVaciaListaSimpleConPrioridad(Carinios))
{
    CarinioAccion* pri = (CarinioAccion*)primeroListaSimpleConPrioridad(Carinios);
    printf("Cariniosito: %s, maquina: %d\n",pri->cariniosito,pri->idmaquina);

    Carinios = restoListaSimpleConPrioridad(Carinios);
}

destruirRedInfelicidad(ri);

return 0;
}

