/*
 * Tarea 5 - Backtracking
 *
 * Programacion 3
 * Instituto de Computacion
 * Facultad de Ingenieria
 * Universidad de la Republica
 * 
 * Version $Rev: 313 $
*/
#ifndef CARRERA_H
#define CARRERA_H
struct Par{
	int velocidad;
	bool boxes;
};
typedef struct Par Par;
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
* 
* sol = Vector solucion donde cada elemento sol[i], representa la velocidad
*       en cada vuelta i, y si el auto paro o no en la vuelta i.
* Precondiciones y postcondiciones:
* @Pre: L es mayor a 0.
* @Pre: C es mayor a 0.
* @Pre: B es mayor a 0.
* @Pre: S es mayor a 0.
* @Pre: t fue previamente creado y tiene largo S. 
	t[i] es mayor a 0 para todo i,  0 <= i < L
* @Pre: c fue previamente creado y tiene largo S. 
	c[i] es mayor a 0 para todo i, 0 <= i < L
* @Pre: el arreglo sol tiene largo L. La memoria para dicho arreglo fue 
*  previamente reservada.
* @Post: Retorna el tiempo minimo de la carrera. Si no hay solucion retorna -1.
* @Post: Retorna en sol[i].velocidad la velocidad a la que debe ir en la vuelta i
y en sol[i].boxes retorna true si se detiene en boxes antes de la vuelta i.
**/
int minimizar_tiempo_carrera (int L, int C, int B, int S,
       		       	        int *t, int *c, Par* &sol);
#endif /* CARRERA_H */
