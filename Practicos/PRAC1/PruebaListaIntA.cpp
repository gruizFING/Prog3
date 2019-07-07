#include "ListaIntA.h"
#include <stdio.h>
#include <iostream>

using namespace std;
typedef ListaInt L;

int main ()
{
	cout << "Ingrese una lista de enteros terminandola en 666:\n";
	L l;
	NullL(l); 
	int i;
	cin >> i;
	while ((i != 666) && (!IsFullL(l)))
	{
		l = SnocL(i,l);
		cin >> i;
	}
	if (IsEmptyL(l))
		cout << "La lista esta vacia.\n";
	else
	{
		cout << "La lista no esta vacia.\n";
		if (IsFullL(l))
			cout << "La lista esta llena.\n";
		i = HeadL(l);
		cout << "El primer elemento de la lista es " << i << endl;
	}
	l = TailL(l);
	if (!IsEmptyL(l))
	{
		i = HeadL(l);
		cout << "El segundo elemento de la lista es " << i << endl;
		if (!IsEmptyL(l))
		{	
			i = HeadL(TailL(l));
			cout << "El tercer elemento de la lista es " << i << endl;
		}
	}
	DestroyL(l);
	if (IsEmptyL(l))
		cout << "La lista ha sido destruida exitosamente.\n";
	else
		cout << "\007\007\007La lista no se destruyo correctamente.\n";
	system("PAUSE");
	return 0;
}
