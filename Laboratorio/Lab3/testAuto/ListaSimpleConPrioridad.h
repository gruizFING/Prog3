#ifndef LISTASIMPLECONPRIORIDAD_H
#define LISTASIMPLECONPROIRIDAD_H

struct ListaSimpleConPrioridad;

ListaSimpleConPrioridad* crearListaSimpleConPrioridad();
//crea una lista de nodos vacia.

bool esVaciaListaSimpleConPrioridad(ListaSimpleConPrioridad* l);
//devuelve true si la lista es vacia y false en caso contrario.
//Precondición: l fue previamente creada

ListaSimpleConPrioridad* agregarListaSimpleConPrioridad(ListaSimpleConPrioridad* &l, void* n, int prioridad);
//agrega el elemento n a la lista simple l según su prioridad.
//Precondición: l fue previamente creada

void* primeroListaSimpleConPrioridad(ListaSimpleConPrioridad* l);
//devuelve el primer elemento de la lista.
//Precondicion: !esVaciaListaSimpleConPrioridad(l).

int prioridadPrimeroListaSimpleConPrioridad(ListaSimpleConPrioridad* l);
//devuelve la prioridad del primer elemento de la lista.
//Precondicion: !esVaciaListaSimpleConPrioridad(l).

ListaSimpleConPrioridad* restoListaSimpleConPrioridad(ListaSimpleConPrioridad* l);
//devuelve un alias al resto de la lista.
//Precondicion: !esVaciaListaSimpleConPrioridad(l).

void destruirListaSimpleConPrioridad(ListaSimpleConPrioridad* &l);
//libera la memoria asociada a la lista.

#endif

