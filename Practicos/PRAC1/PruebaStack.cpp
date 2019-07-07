#include "Pila_Enteros.h"
#include <stdio.h>
#include <iostream>

using namespace std;

int main ()
{
	cout << "--- Prueba de la pila de enteros ---\n";
	cout << "Ingrese una serie de enteros terminandola en 666:\n";
	StackNodo* s = NullS();
	int i;
	cin >> i;
	while (i != 666)
	{
		s = Push(i,s);
		cin >> i;
	}
	cout << "¿La  pila esta vacia? -> ";
	if (IsEmptyS(s))
		cout << "SI.\n";
	else
	{
		cout << "NO.\n";
		i = Top(s);
		cout << "El elemento del tope de la pila es: " << i << endl;
		i = Top(Pop(s));
		cout << "El que le sigue es: " << i << endl;
	}
	DestroyS(s);
	if (IsEmptyS(s))
		cout << "La pila ha sido destruida exitosamente.\n";
	else
		cout << "\007\007\007La pila no se destruyo correctamente.\n";
	system("PAUSE");
	return 0;
}
