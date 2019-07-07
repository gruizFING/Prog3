
/*
void printNota (int nota)
{
	if ((0 <= nota) && (nota < 3))
		cout << "Aplazado\n";
	else if ( (3 <= nota) && (nota < 7))
		cout << "Aceptable\n";
	else if ( (7 <= nota) && (nota < 13))
		cout << "Bien\n";
	else
		cout << "Fuera de rango\n";
}
*/
#include <iostream>

using namespace std;

void printNota (int nota)
{
	switch (nota) 
	{
		case 0: case 1: case 2:
			cout << "Aplazado\n";
			break;
		case 3: case 4: case 5: case 6:
			cout << "Aceptable\n";
			break;
		case 7: case 8: case 9: case 10: case 11: case 12:
			cout << "Bien\n";
			break;
		default:
			cout << "Fuera de rango\n";
	}
}

int main()
{
	cout << " Ingrese el valor de la nota: ";
	int nota;
	cin >> nota;
	cout << endl << "Observacion:  ";
	printNota(nota);
	return 0;
}



