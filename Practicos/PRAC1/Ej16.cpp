#include <iostream>

using namespace std;

bool multiplo (int a,int b)
{
	int resto;
	resto = (a % b);
	if (resto == 0)
		return true;
	else
		return false;
}

bool perfecto(int n)
{
	int acum = 0;
	for (int i = 1;i <= (n / 2);i++)
	{
		if (multiplo(n,i))
			acum += i;
	}
	if (acum == n) 
		return true;
	else
		return false;
}

int main()
{
	cout << "Numeros perfectos entre 1 y 10000:\n";
	for (int i = 1;i <= 10000;i++)
	{
		if (perfecto(i))
		{
			cout << i << " = 1";
			for (int t = 2;t <= (i / 2);t++)
			{
				if (multiplo(i,t))
					cout << " + " << t;
			}
			cout << endl;
		}
	}
	system("PAUSE");
	return 0;
}
