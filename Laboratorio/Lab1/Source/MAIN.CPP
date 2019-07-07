/* 4317743 */

#include "lectorExp.h"
#include "abexp.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


#define def_variable "VAR"
#define def_expresion "EXPR"
#define evaluar "EVAL"
#define persistir "SAVE"
#define cargar "LOAD"
#define salir "SALIR"


using namespace std;


int main() {
	cout << "Bienvenido a el mini-sistema:\n> ";
	//Creo el diccionario de variables y el de expresiones
	DicVar* dic_var = crearDicVar();
	DicExpr* dic_expr = crearDicExpr();
	char* linea = new char[257];
	char* com = new char[6];
	int i = 0;
	bool error_lect = false; //Es true cuando hay un error de lectura
	gets(linea); //Leo toda la linea hasta el salto de linea
	while ((linea[i] != '\0') && (!isspace(linea[i])) && (i < 5)) {
		com[i] = linea[i];
		i++;
	}
	com[i] = '\0';
	int j = i;
	if (strcmp(com,salir) == 0) {
		while ((linea[j] != '\0') && (isspace(linea[j])))
			j++;
		if (linea[j] != '\0')
			com[0] = 'a';
	}
	while (strcmp(com,salir) != 0) { //Se ejecuta mientras el comando no sea salir
		if (linea[i] != '\0') {
			if (strcmp(com,def_variable) == 0)
			{
				char* nom_var = new char[251];
				j = 0;
				while ((linea[i] != '\0') && ((linea[i]) != '=')) {
					if (!isspace(linea[i]))
						nom_var[j++] = linea[i];
					i++;
				}
				nom_var[j] = '\0';
				double val;
				if (linea[i++] != '\0') {
					while ((linea[i] != '\0') && (isspace(linea[i])))
						i++;
					if (linea[i] != '\0')
					{
						linea += i;
						sscanf(linea,"%lf",&val);
						linea -= i;
						i++;
						while ((linea[i] != '\0') && (isdigit(linea[i])))
							i++;
						if (linea[i] != '\0') {
							if (ispunct(linea[i])) {
								i++;
								if ((linea[i] != '\0') && (isdigit(linea[i]))) {
									while ((linea[i] != '\0') && (isdigit(linea[i])))
										i++;
									if (linea[i] != '\0') {
										while ((linea[i] != '\0') && (isspace(linea[i])))
											i++;
										if (linea[i] != '\0')
										error_lect = true;
									}
								}
								else
									error_lect = true;
							}
							else if (isspace(linea[i])) {
								while ((linea[i] != '\0') && (isspace(linea[i])))
									i++;
								if (linea[i] != '\0')
									error_lect = true;
							}
							else
								error_lect = true;
						}
					}
					else
						error_lect = true;
				}
				else
					error_lect = true;
				if (!error_lect) {
					if (strcmp(nom_var,"") == 0)
						cout << "ERROR: Nombre de variable vacio.\n";
					else
					{
						if (!existeVariable(dic_var,nom_var) && (llenoDicVar(dic_var)))
							cout << "ERROR: Se alcanzo la maxima cantidad de variables.\n";
						else
						{
							agregarVariable(dic_var,nom_var,val);
							cout << "OK. " << nom_var << " agregada.\n";
						}
					}
				}
				delete [] nom_var;
			}
			else if (strcmp(com,def_expresion) == 0)
			{
				char* nom_expr = new char[250];
				j = 0;
				while ((linea[i] != '\0') && ((linea[i]) != '=')) {
					if (!isspace(linea[i]))
						nom_expr[j++] = linea[i];
					i++;
				}
				nom_expr[j] = '\0';
				char* expr = new char[250];
				if (linea[i++] != '\0') {
					j = 0;
					while (linea[i] != '\0') {
						if (!isspace(linea[i]))
							expr[j++] = linea[i];
						i++;
					}
					expr[j] = '\0';
					if (j == 0)
						error_lect = true;
				}
				else
					error_lect = true;
				if (!error_lect) {
					ABExp* abe;
					bool error;
					abe = leerExpr(expr,error);
					if (error)
						cout << "ERROR: La expresion no es valida.\n";
					else if (strcmp(nom_expr,"") == 0)
						cout << "ERROR: Nombre de expresion vacio.\n";
					else
					{
						if (!existeExpresion(dic_expr,nom_expr) && (llenoDicExpr(dic_expr)))
							cout << "ERROR: Se alcanzo la maxima cantidad de expresiones.\n";
						else
						{
							agregarExpresion(dic_expr,nom_expr,abe);
							cout << "OK. " << nom_expr << " agregada.\n";
						}
					}
				}
				delete [] expr;
				delete [] nom_expr;
			}
			else if (strcmp(com,evaluar) == 0)
			{
				char* expr = new char[252];
				j = 0;
				while (linea[i] != '\0') {
					if (!isspace(linea[i]))
						expr[j++] = linea[i];
					i++;
				}
				expr[j] = '\0';
				if (j == 0)
					error_lect = true;
				else
				{
					ABExp* abe;
					bool error;
					abe = leerExpr(expr,error);
					if (error)
						cout << "ERROR: La expresion no es valida.\n";
					else
					{
						bool error_mat = false;
						bool err_faltavar = false;
						double res;
						res = evaluarABExp(dic_var,dic_expr,abe,error_mat,err_faltavar);
						if (error_mat)
							cout << "ERROR: Division por cero.\n";
						else if (err_faltavar)
							cout << "ERROR: Falta definir variable o expresion.\n";
						else
							printf("OK. %.2lf\n",res);
						destruirABExp(abe);
					}
				}
				delete [] expr;
			}
			else if (strcmp(com,persistir) == 0)
			{
				char* filename = new char[252];
				while ((linea[i] != '\0') && (isspace(linea[i])))
						i++;
				if (linea[i] != '\0')
				{
					linea += i;
					sscanf(linea,"%s",filename);
					linea -= i;
					while ((linea[i] != '\0') && (!isspace(linea[i])))
						i++;
					if (linea[i] != '\0') {
						while ((linea[i] != '\0') && (isspace(linea[i])))
							i++;
						if (linea[i] != '\0')
							error_lect = true;
					}
				}
				else
					error_lect = true;
				if (!error_lect) {
					guardarVariablesAArchivo(dic_var,filename);
					guardarExpresionesAArchivo(dic_expr,filename);
					cout << "OK. Datos guardados.\n";
				}
				delete [] filename;
			}
			else if (strcmp(com,cargar) == 0)
			{
				char* filename = new char[252];
				while ((linea[i] != '\0') && (isspace(linea[i])))
						i++;
				if (linea[i] != '\0')
				{
					linea += i;
					sscanf(linea,"%s",filename);
					linea -= i;
					while ((linea[i] != '\0') && (!isspace(linea[i])))
						i++;
					if (linea[i] != '\0') {
						while ((linea[i] != '\0') && (isspace(linea[i])))
							i++;
						if (linea[i] != '\0')
							error_lect = true;
					}
				}
				else
					error_lect = true;
				if (!error_lect) {
					//Libero la memoria reservada por los diccionarios actuales
					destruirDicVar(dic_var);
					destruirDicExpr(dic_expr);
					//Cargo la informacion de los archivos a los nuevos diccionarios
					dic_var = cargarVariablesDeArchivo(filename);
					dic_expr = cargarExpresionesDeArchivo(filename);
					cout << "OK. Datos cargados.\n";
				}
				delete [] filename;
			}
			else
				error_lect = true;
		}
		else
			error_lect = true;
		if (error_lect)
			cout << "Comando no reconocido.\n";
		delete [] com;
		delete [] linea;
		linea = new char[257];
		com = new char[6];
		i = 0;
		error_lect = false;
		cout << "> ";
		gets(linea);
		while ((linea[i] != '\0') && (!isspace(linea[i])) && (i < 5)) {
			com[i] = linea[i];
			i++;
		}
		com[i] = '\0';
		j = i;
		if (strcmp(com,salir) == 0) {
			while ((linea[j] != '\0') && (isspace(linea[j])))
				j++;
			if (linea[j] != '\0')
				com[0] = 'a';
		}
	} //while
	delete [] com;
	delete [] linea;
	//Libero toda la memoria
	destruirDicVar(dic_var);
	destruirDicExpr(dic_expr);
	return 0;
}



