#ifndef HASHC2_H
#define HASHC2_H

struct  nodoHash;
typedef nodoHash* hashC2;


hashC2 Crear(int Tam);
//Crea el hash de enteros de tamanaño 'tam'.

void Insertar(hashC2 &h,int n);
//Inserta en el hash 'h' el entero 'n'.
//Si el  hash esta completo termina el programa.
//Pre: 'h' fue previamente creado.
//Pre: !Pertenece(h,n).


bool Pertenece(hashC2 h,int n);
//Devuelve true si el entero 'n' pertenece a 'h'.
//Pre: 'h' fue previamente creado.


void Borrar(hashC2 &h,int n);
//Borrar el entero 'n' del hash 'h'.
//Si !Pertenece(h,n) no hace nada.
//Pre: 'h' fue previamente creado.

#endif  /*HASHC2_H*/
