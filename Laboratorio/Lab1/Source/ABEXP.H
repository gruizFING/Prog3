/*ABExp.h*/
#ifndef ABEXP_H
#define ABEXP_H

typedef struct ABExp ABExp;
#include "dicvar.h"
#include "dicexpr.h"

typedef enum Oper {MAS, MENOS, POR, DIV} Oper;

typedef enum TipoNodo {VALOR, VARIABLE, OPER} TipoNodo;

union Contenido_Nodo {
  Oper tipo_op;
  char* nombre_var;
  double val;
};

typedef struct Nodo {
  TipoNodo tipo;
	union Contenido_Nodo* contenido;
} Nodo;

typedef struct ABExp{
	Nodo* node;
	ABExp* izq;
	ABExp* der;
} ABExp;

/*Crea un ABExp de tipo OPER con el operador "op", con hijos izquierdo y derecho, izq y der respectivamente.*/
ABExp* crearABExpOper( Oper op, ABExp* izq, ABExp* der);

/*Crea un ABExp de tipo VALOR*/
ABExp* crearABExpValor( double valor );

/*Crea un ABExp de tipo VARIABLE cuyo contenido es "nombrevar"*/
ABExp* crearABExpVariable( const char* nombrevar );

/*Retorna el tipo de Nodo de "ab"*/
TipoNodo getTipoNodoABExp(ABExp* ab);

//precondicion: ab_var es un nodo de tipo VARIABLE
/*se retorna una copia del nombre_var, que no comparte memoria con el nombre de la variable.*/
char* getNombreVarABExp(ABExp* ab_var);

//precondicion: ab_val es un nodo de tipo VALOR
/*se retorna el valor contenido en el nodo ab_val*/
double getValorABExp(ABExp* ab_val);

//precondicion: ab_op es un nodo interno de tipo OPER.
/*se retorna el operador Op del nodo ab_op*/
Oper getOperABExp(ABExp* ab_op);

//precondicion: ab_op es un nodo interno de tipo OPER.
/*Retorna el operando izquierdo de ab*/
ABExp* getIzqABExp(ABExp* ab);

//precondicion: ab_op es un nodo interno de tipo OPER.
/*Retorna el operando derecho de ab*/
ABExp* getDerABExp(ABExp* ab);

//error_mat es true si ocurre división por cero.
//err_faltavar es true si hay algun nodo de tipo VARIABLE tal que no existe ninguna variable o expresion con ese nombre.
/*Retorna el resultado de evaluar la expresion del arbol ab*/
/*En caso que sea VARIABLE, retorna el valor de la variable con ese nombre, o si hay una expresion con ese nombre retorna el resultado de evaluar esa expresion*/
/*En caso que sea VALOR, retorna el valor contenido en el nodo.*/
/*En caso que sea OPER, retorna el resultado de aplicar el operador a el resultado de evaluar las expresiones de sus operandos izq y der*/
double evaluarABExp(DicVar* d, DicExpr* dic_exp, ABExp* ab, bool &error_mat, bool &err_faltavar);

/*Libera toda la memoria reservada por ab.*/
void destruirABExp(ABExp* ab);

#endif /*ABEXP_H*/

