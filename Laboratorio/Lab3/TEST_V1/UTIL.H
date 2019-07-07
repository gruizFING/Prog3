#ifndef UTIL_H
#define UTIL_H

#include "CarinioEstrategia.h"

void imprimirMaquinaCentral(RedInfelicidad* ri);

void imprimirRutaMenorTiempo(RedInfelicidad* ri, int central);

void imprimirCariniositosEnAccion(RedInfelicidad* ri, int central, ListaSimpleConPrioridad* cariniositos);

#endif
