#ifndef Lista_Enteros
#define Lista_Enteros
#define MaxTamLista = 10

struct ListaInt;

/* CONSTRUCTORAS */
void NullL (ListaInt &l);
// Crea la lista de enteros vacia

ListaInt SnocL (int i,ListaInt l);
// Precondicion: !IsFullL(l)
// Devuelve la lista resultado de insertar el entero i al principio de la lista l

/* PREDICADOS */
bool IsEmptyL (ListaInt l);
// Retorna true si la lista l esta vacia

bool IsFullL (ListaInt l);
// Retorna true si la lista l esta llena

/* SELECTORAS/DESTRUCTORAS */
int HeadL (ListaInt l);
// Precondicion: !IsEmptyL(l)
// Devuelve el primer elemento en la lista l

ListaInt TailL (ListaInt l);
// Precondicion: !IsEmptyL(l)
// Devuelve el resto de la lista l

void DestroyL (ListaInt &l);
// Borra todos los enteros de la lista l dejandola vacia

#endif
