/*dicvar.h*/

#ifndef DICVAR_H
#define DICVAR_H

#define MAX_VARIABLES 10

typedef struct DicVar DicVar;

/*Crea un DicVar vacio, con maximo MAX_VARIABLES*/
DicVar* crearDicVar();

//Pre: d es un diccionario valido
/*Agrega la variable al DicVar con el nombre "nombre", con valor "valor". 
En caso de que ya exista una variable con ese nombre, se actualiza el valor.*/
/*Si el nombre es el string vacio: "", no agrega la variable.*/
/*Si el DicVar esta lleno, no agrega la variable.*/
void agregarVariable(DicVar* d, const char* nombre, double valor);

//Pre: d es un diccionario valido
//Precondicion: existeVariable(d,nombre).
//Retorna el valor de la variable.
double buscarVariable(DicVar* d, const char* nombre);

//Pre: d es un diccionario valido
/*Retorna true si "d" contiene MAX_VARIABLES expresiones, false en cualquier otro caso.*/
bool llenoDicVar(DicVar* d);

//Pre: d es un diccionario valido
//Retorna true si hay una variable de nombre "nombre" en el DicVar "d".
bool existeVariable(DicVar* d, const char* nombre);

//Libera toda la memoria reservada por "d".
void destruirDicVar(DicVar* d);

//Pre: d es un diccionario valido
//Guarda las variables del DicVar "d" en el archivo de nombre "nom_arch" con el formato predefinido. Si existe se sobreescribe, sino se crea.
void guardarVariablesAArchivo(DicVar* d, const char* nom_arch);

//Precondicion: Existe un archivo de nombre "nom_arch" y tiene el formato correcto predefinido.
DicVar* cargarVariablesDeArchivo(const char* nom_arch);

#endif /*DICVAR_H*/

