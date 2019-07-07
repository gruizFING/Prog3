/* 4317743 */

#include "abexp.h"
#include <stdlib.h>
#include <assert.h>
#include <string.h>


ABExp* crearABExpOper( Oper op, ABExp* izq, ABExp* der) {
	ABExp* ab = new ABExp;
	ab->izq = izq;
	ab->der = der;
	ab->node = new Nodo;
	ab->node->tipo = OPER;
	ab->node->contenido = new Contenido_Nodo;
	ab->node->contenido->tipo_op = op;
	return ab;
}

ABExp* crearABExpValor( double valor ) {
	ABExp* ab = new ABExp;
	ab->izq = NULL;
	ab->der = NULL;
	ab->node = new Nodo;
	ab->node->tipo = VALOR;
	ab->node->contenido = new Contenido_Nodo;
	ab->node->contenido->val = valor;
	return ab;
}

ABExp* crearABExpVariable( const char* nombrevar ) {
	ABExp* ab = new ABExp;
	ab->izq = NULL;
	ab->der = NULL;
	ab->node = new Nodo;
	ab->node->tipo = VARIABLE;
	ab->node->contenido = new Contenido_Nodo;
	ab->node->contenido->nombre_var = new char[strlen(nombrevar) + 1];
	strcpy(ab->node->contenido->nombre_var,nombrevar);
	return ab;
}

TipoNodo getTipoNodoABExp(ABExp* ab) {
	return ab->node->tipo;
}

char* getNombreVarABExp(ABExp* ab_var) {
	assert(getTipoNodoABExp(ab_var) == VARIABLE);
	//Hago una copia limpia del nombre de la expresion
	char* copiaNom = new char[strlen(ab_var->node->contenido->nombre_var) + 1];
	strcpy(copiaNom,ab_var->node->contenido->nombre_var);
	return copiaNom;
}

double getValorABExp(ABExp* ab_val) {
	assert(getTipoNodoABExp(ab_val) == VALOR);
	return ab_val->node->contenido->val;
}

Oper getOperABExp(ABExp* ab_op) {
	assert((ab_op->izq != NULL) && (ab_op->der != NULL));
	assert(getTipoNodoABExp(ab_op) == OPER);
	return ab_op->node->contenido->tipo_op;
}

ABExp* getIzqABExp(ABExp* ab) {
	assert((ab->izq != NULL) && (ab->der != NULL));
	assert(getTipoNodoABExp(ab) == OPER);
	return ab->izq;
}

ABExp* getDerABExp(ABExp* ab) {
	assert((ab->izq != NULL) && (ab->der != NULL));
	assert(getTipoNodoABExp(ab) == OPER);
	return ab->der;
}


double evaluarABExp(DicVar* d, DicExpr* dic_exp, ABExp* ab, bool &error_mat, bool &err_faltavar) {
	double res = 1.0;	
	if (getTipoNodoABExp(ab) == VARIABLE)
	{
		if (existeVariable(d,getNombreVarABExp(ab)))
			res = (buscarVariable(d,getNombreVarABExp(ab)));
		else if (existeExpresion(dic_exp,getNombreVarABExp(ab)))
			res = (evaluarABExp(d,dic_exp,buscarExpresion(dic_exp,getNombreVarABExp(ab)),error_mat,err_faltavar));
		else
			err_faltavar = true;
	}
	else if (getTipoNodoABExp(ab) == VALOR)
		res = (getValorABExp(ab));
	else
	{
		Oper op;
		op = getOperABExp(ab);
		switch (op) {
		case MAS :{
			res = ((evaluarABExp(d,dic_exp,getIzqABExp(ab),error_mat,err_faltavar))
				   + (evaluarABExp(d,dic_exp,getDerABExp(ab),error_mat,err_faltavar)));
			break;
		}
		case MENOS :{
			res = ((evaluarABExp(d,dic_exp,getIzqABExp(ab),error_mat,err_faltavar))
				   - (evaluarABExp(d,dic_exp,getDerABExp(ab),error_mat,err_faltavar)));
			break;
		}
		case POR :{
			res = ((evaluarABExp(d,dic_exp,getIzqABExp(ab),error_mat,err_faltavar))
				   * (evaluarABExp(d,dic_exp,getDerABExp(ab),error_mat,err_faltavar)));
			break;
		}
		case DIV :{
			if ((evaluarABExp(d,dic_exp,getDerABExp(ab),error_mat,err_faltavar)) == 0)
				error_mat = true;
			else
				res = ((evaluarABExp(d,dic_exp,getIzqABExp(ab),error_mat,err_faltavar))
				       / (evaluarABExp(d,dic_exp,getDerABExp(ab),error_mat,err_faltavar)));
			break;
		}
		}
	}
	return res;
}

void destruirNodo(Nodo* nodo) {
	Contenido_Nodo* aBorrar;
	aBorrar = nodo->contenido;
	if (nodo->tipo == VARIABLE)
		delete [] aBorrar->nombre_var;
	delete aBorrar;
	delete nodo;
}
	
void destruirABExp(ABExp* ab) {
	if (getTipoNodoABExp(ab) == OPER) //Si es de tipo operador entonces libero la memoria de las ramas izquierda y derecha
	{
		destruirABExp(ab->izq);
		destruirABExp(ab->der);
	}
	destruirNodo(ab->node); //Libera la memoria de el nodo con la informacion de la expresion
	delete ab;
	ab = NULL;
}

