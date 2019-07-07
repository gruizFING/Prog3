#include <iostream>
#include <cmath>

using namespace std;

bool multiplo (int a,int b)  //Precondicion: a >= b
{
	int resto;
	resto = (a % b);
	if (resto == 0)
		return true;
	else
		return false;
}

int main()
{
	int n_ini;
	cout << "Ingrese el numero: ";
	cin >> n_ini;
	cout << "Descomposicion en factores primos de " << n_ini << ":\n ";
	int i = 2,exp = 0,n = n_ini;
	while ((i <= n_ini) && (n > 1))
	{
		while ((i <= n) && (multiplo(n,i)))
		{
			exp += 1;
			n = n / i;
		}
		if (exp > 0)
		{
			cout << i << "exp(" << exp << ")";
			if (n > 1)
			{
				cout << " * ";
				i = 1;
				exp = 0;
			}
		}
		i++;
	}
	cout << endl;
	system("PAUSE");
	return 0;
}
