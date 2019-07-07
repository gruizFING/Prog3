/*
 * Tarea 3
 *
 * Programación 3
 * Instituto de Computación
 * Facultad de Ingeniería
 * Universidad de la República
 *
 * $Rev: 260 $
 *
 */
#ifndef CARINIOESTRATEGIA_H
#define CARINIOESTRATEGIA_H

#include "RedInfelicidad.h"
#include "ListaSimpleConPrioridad.h"

#define INFINITO 1000000

/*
 * Estructura para almacenar el par (Cariñosito, idMaquina)
 */
struct CarinioAccion
{
	char* cariniosito;
	int idmaquina;
};

/*
 * Estructura que representa un camino
 */
struct Camino
{
  ListaSimpleConPrioridad* maquinasCamino;
  int tiempo;
};


/*
 * Retorna el identificador de la máquina central
 */
int maquinaCentral(RedInfelicidad* ri);

/* Si la máquina central no está vigilada tiempo =0 y maquinasCamino tiene a la máquina central.
 * si todas las máquinas están vigiladas, timepo = -1 y máquinasCamino = NULL
 * sino, tiempo es el tiempo que lleva recorrer el camino más corto y máquinasCamino tiene una lista con los ids de las máquinas del camino,
 *      comenzando por la máquina no vigilada y terminando por la máquina central.
 */
Camino* rutaMenorTiempo(RedInfelicidad* ri, int central);

/*
 *  Devuelve una lista de nodos de tipo CarinioAccion, según la descripción de la letra.
 */
ListaSimpleConPrioridad* cariniositosEnAccion(RedInfelicidad* ri, int central, ListaSimpleConPrioridad* lc);

#endif /* CARINIOESTRATEGIA_H */
