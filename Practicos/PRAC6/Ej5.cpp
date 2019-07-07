/* Ej5_Practico6(D&C) */

#include <stdlib.h>
#include <iostream>

using namespace std;

void crearTabla(int cant,int** &Tabla) {
	Tabla = new int*[cant];
	int i;
	for (i = 0;i < cant;i++)
		Tabla[i] = new int[cant-1];
		
	for (i = 0;i < cant;i++)
		for (int j = 0;j < cant-1;j++)
			Tabla[i][j] = 0;
}

void destruirTabla(int cant,int** &Tabla) {
	for (int i = 0;i < cant;i++)
		delete [] Tabla[i];
	delete [] Tabla;
}

void imprimirTabla(int cant,int** Tabla) {
	cout << "                Organizacion del Torneo" << endl;
	cout << "| Jugador/Dia |";
	for (int i = 1;i < cant;i++)
		cout << " Dia " << i << " |";
	cout << endl;
	
	for (int i = 0;i < cant;i++)
	{
		for (int j = 0;j < cant-1;j++)
		{
			if (j == 0)
			{
				cout << "|      " << i << "      |";
				cout << "   " << Tabla[i][j] << "   |";
			}
			else
				cout << "   " << Tabla[i][j] << "   |";
		}
		cout << "\n";
	}
}


// dentro de la matriz tabla se copian los elementos que conforman
// una matriz con origen en (origen, 0) y tamaño [cant, cant-1]
// en otra matriz de origen (destino, cant).
void completar(int origen, int destino, int cant, int ** & tabla){
	for(int i = 0; i < cant; i++)
		for(int j = 0; j < (cant-1); j++)
			tabla[destino+i][cant+j] = tabla[origen+i][j];
}
	

// genera los cruzamientos del torneo y los coloca en la
// tabla a partir de la posición [ini][0].
void generarCruzamientos(int ini,int cant, int ** &tabla){
	if(cant == 2){ // caso base, solo dos competidores
		tabla[ini][0] = ini+1;
		tabla[ini+1][0] = ini;
	}
	else
	{
		// generar cruzamientos de los dos sub-torneos
		generarCruzamientos(ini, cant/2, tabla);
		generarCruzamientos(ini+cant/2, cant/2, tabla);
		// asignar al primer jugador del sub-torneo 1 el
		// primer jugador del sub-torneo 2 (y viceversa)
		// y así sucesivamente
		for(int i = ini; i < (ini+cant/2); i++)
		{
			tabla[i][(cant/2)-1] = i+cant/2;
			tabla[i+cant/2][(cant/2)-1] = i;
		}
		// completar los cruzamientos de cada jugador con
		// los del jugador asignado en la parte anterior
		completar(ini, ini+cant/2, cant/2, tabla);
		completar(ini+cant/2, ini, cant/2, tabla);
	}
}

// imprime los cruzamientos de un torneo de cant participantes
void torneo(int cant){
	int** tabla;
	crearTabla(cant, tabla);
	generarCruzamientos(0, cant, tabla);
	imprimirTabla(cant, tabla);
	destruirTabla(cant, tabla);
}


int main () {
	cout << "Torneo1 --> 2 jugadores\n";
	torneo(2);
	cout << "\n\nTorneo2 --> 4 jugadores\n";
	torneo(4);
	cout << "\n\nTorneo3 --> 8 jugadores\n";
	torneo(8);
		
	system("PAUSE");
	return EXIT_SUCCESS;
}
