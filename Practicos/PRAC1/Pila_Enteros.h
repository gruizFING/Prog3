#ifndef Pila_Enteros
#define Pila_Enteros

struct StackNodo;

/* CONSTRUCTORAS */
StackNodo* NullS ();
// Retorna la pila de enteros vacia

StackNodo* Push (int i,StackNodo* s);
// Inserta el entero i en el tope de la pila s y luego la retorna

/* PREDICADO */
bool IsEmptyS (StackNodo* s);
// Retorna true si la pila s esta vacia

/* SELECTORAS/DESTRUCTORAS */
int Top (StackNodo* s);
// Precondicion: !IsEmptyS(s)
// Retorna el entero del tope de la pila

StackNodo* Pop (StackNodo* s);
// Precondicion: !IsEmptyS(s)
// Retorna la pila s sin el entero en el tope de la misma

void DestroyS (StackNodo* &s);
// Libera la memoria reservada por s

#endif
