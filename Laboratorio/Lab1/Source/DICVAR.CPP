/* 4317743 */

#include "dicvar.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>

struct NodoVar { //Informacion de la variable
	char* nom;
	double val;
};

struct DicVar {
	NodoVar** info; //Arrreglo de punteros a NodoVar
	int tope; //Tamaño actual del diccionario
};

DicVar* crearDicVar() {
	DicVar* dic = new DicVar;
	dic->info = new NodoVar*[MAX_VARIABLES]; //Reservo la memoria para la cantidad maxima de variables
	dic->tope = 0; //Inicializo el tope del diccionario en 0 como condicion de estar vacio
	return dic;
}

void agregarVariable(DicVar* d, const char* nombre, double valor) {
	if (!existeVariable(d,nombre)) //Si la variable no pertenece al diccionario
	{
		//Reservo la memoria necesaria para la informacion de la variable y luego le asigno el nombre y su valor
		d->info[d->tope] = new NodoVar;
		d->info[d->tope]->nom = new char[strlen(nombre) + 1];
		strcpy(d->info[d->tope]->nom,nombre);
		d->info[d->tope]->val = valor;
		d->tope++; //Aumento el  tamaño del diccionario en 1
	}
	else
	{
		//Como la variable ya esta en el diccionario la busco y le actualizo su valor
		int i = 0;
		while (strcmp(nombre,d->info[i]->nom) != 0)
			i++;
		d->info[i]->val = valor;
	}
}

double buscarVariable(DicVar* d, const char* nombre) {
	assert(existeVariable(d,nombre));
	int i = 0;
	while (strcmp(nombre,d->info[i]->nom) != 0) //Recorro el diccionario hasta que los nombres sean iguales
		++i;
	return (d->info[i]->val); //Retorno el valor de la variable encontrada
}

bool llenoDicVar(DicVar* d) {
	return (d->tope == MAX_VARIABLES); //Compara el tamaño actual del diccionario con el maximo de variables permitido 
}

bool existeVariable(DicVar* d, const char* nombre) {
	int i = 0;
	//Recorro el diccionario hasta el tamaño actual del mismo o hasta que los nombres sean iguales
	while ((i < d->tope) && (strcmp(nombre,d->info[i]->nom) != 0))
		++i;
	return (i < d->tope); //Retorna true si encontro la variable antes de terminar de recorrer el diccionario
}

void destruirDicVar(DicVar* d) {
	for (int i = 0;i < d->tope;i++) //Libero la memoria ocupada por los nombres de las variables en el diccionario
		delete [] d->info[i]->nom;
	delete [] d->info; //Libero la memoria restante del diccionario
	delete d;
	d = NULL;
}


void guardarVariablesAArchivo(DicVar* d, const char* nom_arch) {
	//Copio el nombre del archivo y luego le agrego la extension -Vars.txt
	char* copia_nom = new char[strlen(nom_arch) + 10]; 
	strcpy(copia_nom,nom_arch);
	strcat(copia_nom,"-Vars.txt");
	FILE* fp = fopen(copia_nom,"w"); //Abro el canal para modo escritura
	delete [] copia_nom; //Libero la memoria ocupada por la copia del nombre del archivo
	//Recorro todo el diccionario y voy escribiendo al archivo la informacion
	for (int i = 0;i < d->tope;i++) {
		fputs("<def var=",fp);
		putc('"',fp);
		fprintf(fp,"%s",d->info[i]->nom);
		putc('"',fp);
		fprintf(fp,">%.6lf</def>\n",d->info[i]->val);
	}
	fclose(fp); //Cierro el canal hacia el archivo
}

DicVar* cargarVariablesDeArchivo(const char* nom_arch) {
	char* copia_nom = new char[strlen(nom_arch) + 10]; 
	strcpy(copia_nom,nom_arch);
	strcat(copia_nom,"-Vars.txt");
	FILE* fp = fopen(copia_nom,"r"); //Abro el canal para modo lectura
	assert(fp != NULL);
	delete [] copia_nom;
	DicVar* dic;
	dic = crearDicVar(); //Creo el diccionario de variables
	getc(fp);
	while (!feof(fp)) //Se ejecuta mientras no sea el fin de el archivo
	{
		char c;
		while((c = getc(fp)) != '"');
		char* nom = new char[256];
		int i = 0;
		while((c = getc(fp)) != '"') 
			nom[i++] = c;
		nom[i] = '\0';
		getc(fp);
		double val;
		fscanf(fp,"%lf",&val);
		agregarVariable(dic,nom,val); //Agrego la variable de nombre "nom" y valor "val" al diccionario
		delete [] nom;
		while((c = getc(fp)) != '>');
		getc(fp);getc(fp);
	}
	fclose(fp); //Cierro el canal hacia el archivo
	return dic; //Retorno el diccionario creado luego de leer la informacion del archivo
}

