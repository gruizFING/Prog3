/*dicexpr.h*/


#ifndef DICEXPR_H
#define DICEXPR_H

typedef struct DicExpr DicExpr;
#include "abexp.h"

#define MAX_EXPRESIONES 10


/*Crea un diccionario de expresiones vacío con maximo MAX_EXPRESIONES.*/
DicExpr* crearDicExpr();

//Precondicion: d es un diccionario valido
/*Agrega la expresion abe al diccionario con el nombre "nombre", en caso que la expresion
 ya exista, se libera la memoria de la expresion anterior, y se le asigna la expresion "abe"*/
/*Si el nombre es el string vacio: "", no agrega la expresion.*/
/*Si el diccionario esta lleno, no agrega la expresion.*/
void agregarExpresion(DicExpr* d, const char* nombre, ABExp* abe);

//Precondicion: d es un diccionario valido
//Precondicion: existeExpresion(d, nombre);
ABExp* buscarExpresion(DicExpr* d, const char* nombre);

//Precondicion: d es un diccionario valido
/*Retorna true si "d" contiene MAX_EXPRESIONES expresiones, false en cualquier otro caso.*/
bool llenoDicExpr(DicExpr* d);

//Precondicion: d es un diccionario valido
/*Retorna true si existe una expresion de nombre "nombre" en el diccionario "d".*/
bool existeExpresion(DicExpr* d, const char* nombre);

/*Libera toda la memoria reservada por "d".*/
void destruirDicExpr(DicExpr* d);

//Precondicion: d es un diccionario valido
/*Guarda las expresiones en un archivo de nombre "nom_arch" en el formato preestablecido.
 En caso de existir un archivo con ese nombre, lo sobreescribe, si no existe lo crea.*/
void guardarExpresionesAArchivo(DicExpr* d, const char* nom_arch);

/*Precondicion: Existe el archivo de nombre "nom_arch"*/
/*Precondicion: El archivo de nombre "nom_arch" tiene el formato correcto de guardado de expresiones.*/
/*Lee las expresiones de el archivo nom_arch.*/
DicExpr* cargarExpresionesDeArchivo(const char* nom_arch);


#endif /*DICEXPR_H*/
