#include <iostream>

using namespace std;


int main()
{
	unsigned long n;
	float aprox_pi = 0.0;
	cout << "Ingrese el numero que corresponde a la reducida n-esima que quiera para aproximar PI: ";
	cin >> n;
	if ((n < 1) || (n > ULONG_MAX))
	{
		cout << "\007\007\007";
		cout << "El numero ingresado esta fuera del rango posible, es menor que 1 o es muy grande\n";
	}
	else
	{
		for (int i = 1, denominador = 1; i <= n; i++, denominador += 2)
		{	
			if ((i % 2) != 0) 
				aprox_pi += 4.0 / (float)denominador;
			else
				aprox_pi -= 4.0 / (float)denominador;
		}
		if (aprox_pi == 0) 
			cout << "El numero ingresado esta fuera de rango, inserte uno menor para la proxima.\n ";
		else
			cout << "El valor aproximado de PI = " << aprox_pi << endl;
	}
	system("PAUSE");
	return 0;
}
