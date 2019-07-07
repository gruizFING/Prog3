#ifndef COLASIMPLE_H
#define	COLASIMPLE_H

struct ColaSimple;

ColaSimple* crearColaSimple();
//devuelve la cola vacia

bool esVaciaColaSimple(ColaSimple* c);
//devuelve true si c es vacia
//Precondición: c fue previamente creada

void encolarColaSimple(ColaSimple* &c, void* v);
//agrega el elemento i en c
//Precondición: c fue previamente creada

void* desencolarColaSimple(ColaSimple* &c);
//devuelve el primer elemento de c
//Precondición: c fue previamente creada
//Precondicion: !esVaciaColaSimple(c);

void destruirColaSimple(ColaSimple* &c);
//libera toda la memoria ocupada por c
//Precondicion: c fue previamente creada.


#endif	/*COLASIMPLE_H */
