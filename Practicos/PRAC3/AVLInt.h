#ifndef AVLInt_H
#define AVLInt_H

struct AVLInt;

AVLInt* Crear();
//Devuelve el AVL de enteros vacio.

AVLInt* Insertar(AVLInt* &a,int n,bool &inserto);
//Inserta el entero 'n' en el AVL 'a' y lo devuelve.
//Pre: 'a' fue previamente creado.

bool EsVacio(AVLInt* a);
//Devuelve true si el avl 'a' esta vacio.
//Pre: 'a' fue previamente creado.

bool Pertenece(AVLInt* a,int n);
//Devuelve true si el entero 'n' pertenece al AVL 'a'.
//Pre: 'a' fue previamente creado.

AVLInt* Borrar(AVLInt* &a,int n);
//Borra el entero 'n' del AVL 'a'. Si !Pertenece(a,n) entonces no hace nada.
//Pre: 'a' fue previamente creado.

#endif  /*AVLInt_H*/
