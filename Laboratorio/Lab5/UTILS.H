#ifndef UTILS_H
#define UTILS_H

#include "carrera.h"

#define SIN_SOLUCION -1

/**
* Descripcion de parametros:
* L = cantidad de vueltas.
* C = capacidad en litros.
* B = tiempo que demora en parar en boxes y cargar combustible.
* S = cantidad de velocidades.
* 
* t = Vector de tiempos/velocidades. t[i] es el tiempo que demora en dar
	una vuelta yendo a velocidad i.
* c = Vector donde c[i] representa el consumo por vuelta de la velocidad i.
* minimo = El resultado que debe retornar la ejecución de minimizar_tiempo_carrera
* debug = Si el booleano esta en 'true' solo imprime el tiempo de ejecutar la
* carrera, sino ejecuta el caso y realiza las verificaciones correspondientes.
*/
 
void test(int L, int C, int B, int S, int *t1, int *c1, int esperado, bool
debug);

int solucion_factible (int L, int C, int S, int* c, Par* sol);

int calcular_duracion (int L, int B, int* t, Par* sol);

int verificar_solucion (int L, int C, int B, int S, int *t, int *c,   Par *sol, int duracion, int esperado);

void imprimir_resultados (int L, Par *sol, int duracion);


#endif /* UTILS_H */
