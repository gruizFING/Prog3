#ifndef Lista_Enteros
#define Lista_Enteros

struct ListaInt;

/* CONSTRUCTORAS */
ListaInt* NullL ();
// Crea la lista de enteros vacia

ListaInt* ConsL (int i,ListaInt* l);
// Devuelve la lista resultado de insertar el entero i en el principio de la lista l

ListaInt* SnocL (int i,ListaInt* l);
// Devuelve la lista resultado de insertar el entero i al final de la lista l

/* PREDICADO */
bool IsEmptyL (ListaInt* l);
// Retorna true si la lista l esta vacia

/* SELECTORAS/DESTRUCTORAS */
int HeadL (ListaInt* l);
// Precondicion: NOT IsEmptyL(l)
// Devuelve el primer elemento en la lista l

ListaInt* TailL (ListaInt* l);
// Precondicion: NOT IsEmptyL(l)
// Devuelve el resto de la lista l

void DestroyL (ListaInt* &l);
// Libera la memoria reservada por la lista l

#endif
