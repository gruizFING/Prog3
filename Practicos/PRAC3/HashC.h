#ifndef HASHC_H
#define HASHC_H

struct  nodoHashC;
typedef nodoHashC* hashC;


hashC Crear(int Tam);
//Crea el hash de enteros de tamanaño 'tam'.

void Insertar(hashC &h,int n);
//Inserta en el hash 'h' el entero 'n'.
//Si el  hash esta completo salgo del programa.
//Pre: 'h' fue previamente creado.
//Pre: !Pertenece(h,n).


bool Pertenece(hashC h,int n);
//Devuelve true si el entero n pertenece a h.
//Pre: 'h' fue previamente creado.


void Borrar(hashC &h,int n);
//Borrar el entero 'n' del hash 'h'.
//Si !Pertenece(h,n) no hace nada.
//Pre: 'h' fue previamente creado.

#endif  /*HASHC_H*/
