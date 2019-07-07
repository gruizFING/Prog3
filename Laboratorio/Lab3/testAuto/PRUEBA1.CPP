
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

/** Se imprimen en este orden, y si, son re cariñosos **/
char* c1 = strdup("Batman");
char* c2 = strdup("Harry Potter");
char* c3 = strdup("Pocahontas");
char* c4 = strdup("Asterix");
char* c5 = strdup("Satanas");
char* c6 = strdup("Astor Piazzola");
char* c7 = strdup("Beethoven");
char* c8 = strdup("Superman");
char* c9 = strdup("SLAYERRRR");

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


RedInfelicidad* ri = crearRedInfelicidad(9);

unirMaquinasRedInfelicidad(ri,0,1,1);
unirMaquinasRedInfelicidad(ri,1,2,1);
unirMaquinasRedInfelicidad(ri,1,4,5);
unirMaquinasRedInfelicidad(ri,2,3,1);
unirMaquinasRedInfelicidad(ri,3,4,1);
unirMaquinasRedInfelicidad(ri,4,5,4);
unirMaquinasRedInfelicidad(ri,4,7,3);
unirMaquinasRedInfelicidad(ri,5,6,2);
unirMaquinasRedInfelicidad(ri,7,8,3);

vigilarMaquina(ri,1);
vigilarMaquina(ri,2);
vigilarMaquina(ri,3);
vigilarMaquina(ri,4);
vigilarMaquina(ri,5);
vigilarMaquina(ri,7);

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

