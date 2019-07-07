/*
 * Tarea 3
 *
 * Programaci�n 3
 * Instituto de Computaci�n
 * Facultad de Ingenier�a
 * Universidad de la Rep�blica
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
 * Estructura para almacenar el par (Cari�osito, idMaquina)
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
 * Retorna el identificador de la m�quina central
 */
int maquinaCentral(RedInfelicidad* ri);

/* Si la m�quina central no est� vigilada tiempo =0 y maquinasCamino tiene a la m�quina central.
 * si todas las m�quinas est�n vigiladas, timepo = -1 y m�quinasCamino = NULL
 * sino, tiempo es el tiempo que lleva recorrer el camino m�s corto y m�quinasCamino tiene una lista con los ids de las m�quinas del camino,
 *      comenzando por la m�quina no vigilada y terminando por la m�quina central.
 */
Camino* rutaMenorTiempo(RedInfelicidad* ri, int central);

/*
 *  Devuelve una lista de nodos de tipo CarinioAccion, seg�n la descripci�n de la letra.
 */
ListaSimpleConPrioridad* cariniositosEnAccion(RedInfelicidad* ri, int central, ListaSimpleConPrioridad* lc);

#endif /* CARINIOESTRATEGIA_H */
