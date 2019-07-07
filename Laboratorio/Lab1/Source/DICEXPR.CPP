/* 4317743 */

#include "dicexpr.h"
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

struct NodoExpr { //Informacion de la expresion
	char* nom;
	ABExp* expr;
};

struct DicExpr {
	NodoExpr** info; //Arrreglo de punteros a NodoExpr
	int tope; //Tamaño actual del diccionario
};

DicExpr* crearDicExpr() {
	DicExpr* dic = new DicExpr;
	dic->info = new NodoExpr*[MAX_EXPRESIONES]; //Reservo la memoria para la cantidad maxima de expresiones
	dic->tope = 0; //Inicializo el tope del diccionario en 0 como condicion de estar vacio
	return dic;
}

void agregarExpresion(DicExpr* d, const char* nombre, ABExp* abe) {
	if (!existeExpresion(d,nombre)) //Si la expresion no pertenece al diccionario
	{
		//Reservo la memoria necesaria para la informacion y luego le asigno el nombre y su expresion
		d->info[d->tope] = new NodoExpr;
		d->info[d->tope]->nom = new char[strlen(nombre) + 1];
		strcpy(d->info[d->tope]->nom,nombre);
		d->info[d->tope]->expr = abe;
		d->tope++; //Aumento el  tamaño del diccionario en 1
	}
	else
	{
		//Como la expresion ya esta en el diccionario la busco y la actualizo
		int i = 0;
		while (strcmp(nombre,d->info[i]->nom) != 0)
			i++;
		//Libero la memoria de la expresion anterior y luego le asigno la nueva
		destruirABExp(d->info[i]->expr); 
		d->info[i]->expr = abe;
	}
}

ABExp* buscarExpresion(DicExpr* d, const char* nombre) {
	assert(existeExpresion(d,nombre));
	int i = 0;
	while (strcmp(nombre,d->info[i]->nom) != 0) //Recorro el diccionario hasta que los nombres sean iguales
		++i;
	return (d->info[i]->expr); //Retorno la expresion encontrada
}

bool llenoDicExpr(DicExpr* d) {
	return (d->tope == MAX_EXPRESIONES); //Compara el tamaño actual del diccionario con el maximo de expresiones permitido 
}

bool existeExpresion(DicExpr* d, const char* nombre) {
	int i = 0;
	//Recorro el diccionario hasta el tamaño actual del mismo o hasta que los nombres sean iguales
	while ((i < d->tope) && (strcmp(nombre,d->info[i]->nom) != 0))
		++i;
	return (i < d->tope); //Retorna true si encontro la expresion antes de terminar de recorrer el diccionario
}

void destruirDicExpr(DicExpr* d) {
	for (int i = 0;i < d->tope;i++) //Libero la memoria ocupada por la informacion de cada expresion del diccionario
	{
		delete [] d->info[i]->nom;
		destruirABExp(d->info[i]->expr);
	}
	delete [] d->info; //Libero la memoria restante del diccionario
	delete d;
	d = NULL;
}


void guardarAux(FILE* &fp,ABExp* ab) { 
	fputs("<expr tipo=",fp);
	putc('"',fp);
	TipoNodo tnodo;
	tnodo = getTipoNodoABExp(ab);
	if (tnodo == VALOR)
		fputs("VAL",fp);
	else if (tnodo == VARIABLE)
		fputs("VAR",fp);
	else
	{
		Oper op;
		op = getOperABExp(ab);
		switch (op) {
		case MAS :{
			fputs("SUMA",fp);
			break;
		}
		case MENOS :{
			fputs("RESTA",fp);
			break;
		}
		case POR :{
			fputs("MULT",fp);
			break;
		}
		case DIV :{
			fputs("DIV",fp);
			break;
		}
		}
	}	
	putc('"',fp);
	putc('>',fp);
	if (tnodo == VALOR)
		fprintf(fp,"%.6lf</expr>",getValorABExp(ab));
	else if (tnodo == VARIABLE)
		fprintf(fp,"%s</expr>",getNombreVarABExp(ab));
	else
	{
		guardarAux(fp,getIzqABExp(ab));
		guardarAux(fp,getDerABExp(ab));
		fputs("</expr>",fp);
	}
}
	
void guardarExpresionesAArchivo(DicExpr* d, const char* nom_arch) {
	//Copio el nombre del archivo y luego le agrego la extension -Exprs.txt
	char* copia_nom = new char[strlen(nom_arch) + 11]; 
	strcpy(copia_nom,nom_arch);
	strcat(copia_nom,"-Exprs.txt");
	FILE* fp = fopen(copia_nom,"w"); //Abro el canal para modo escritura
	delete [] copia_nom; //Libero la memoria ocupada por la copia del nombre del archivo
	//Recorro todo el diccionario y voy escribiendo al archivo la informacion
	for (int i = 0;i < d->tope;i++) {
		fprintf(fp,"<def exp=\"%s\">",d->info[i]->nom);
		guardarAux(fp,d->info[i]->expr); //Recorro el arbol de la expresion y guardo la informacion en el archivo
		fputs("</def>\n",fp);
	}
	fclose(fp); //Cierro el canal hacia el archivo
}


ABExp* armarExpresion(FILE* &fp) {
	ABExp* ab;
	char c;
	while((c = getc(fp)) != '"');
	c = getc(fp);
	if (c == 'V')
	{
		getc(fp);
		c = getc(fp);
		getc(fp);getc(fp);
		if (c == 'L')
		{
			double val;
			fscanf(fp,"%lf",&val);
			ab = crearABExpValor(val);
		}
		else
		{
			char* nom_var = new char[256];
			fscanf(fp,"%[^<]",nom_var);
			ab = crearABExpVariable(nom_var);
			delete [] nom_var;
		}
	}
	else
	{
		Oper op = MAS;
		switch (c) {
		case 'S' :{
			op = MAS;
			break;
		}
		case 'R' :{
			op = MENOS;
			break;
		}
		case 'M' :{
			op = POR;
			break;
		}
		case 'D' :{
			op = DIV;
			break;
		}
		}
		while((c = getc(fp)) != '"');
		ABExp* ramaIzq;
		ramaIzq = armarExpresion(fp);
		ABExp* ramaDer;
		ramaDer = armarExpresion(fp);
		ab = crearABExpOper(op,ramaIzq,ramaDer);
	}
	return ab;
}
		
		
DicExpr* cargarExpresionesDeArchivo(const char* nom_arch) {
	char* copia_nom = new char[strlen(nom_arch) + 11]; 
	strcpy(copia_nom,nom_arch);
	strcat(copia_nom,"-Exprs.txt");
	FILE* fp = fopen(copia_nom,"r");  //Abro el canal para modo lectura
	assert(fp != NULL);
	delete [] copia_nom;
	DicExpr* dic;
	dic = crearDicExpr(); //Creo el diccionario de expresiones
	getc(fp);
	while (!feof(fp)) //Se ejecuta mientras no sea el fin de el archivo
	{
		char c;
		while((c = getc(fp)) != '"');
		char* nom_expr = new char[256];
		fscanf(fp,"%[^\"]",nom_expr);
		while((c = getc(fp)) != '>');
		ABExp* ab;
		ab = armarExpresion(fp); //Arma el arbol de la expresion leyendo la informacion del archivo
		agregarExpresion(dic,nom_expr,ab); //Agrego la expresion de nombre "nom_expr" y arbol "ab" al diccionario
		delete [] nom_expr;
		while((c = getc(fp)) != 'd');
		while((c = getc(fp)) != '>');
		getc(fp);getc(fp);
	}
	fclose(fp); //Cierro el canal hacia el archivo
	return dic; //Retorno el diccionario creado luego de leer la informacion del archivo
}

