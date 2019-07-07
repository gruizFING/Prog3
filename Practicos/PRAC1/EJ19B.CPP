#include <iostream>

using namespace std;

double fibo (unsigned long n)
{
	unsigned long i = 1,j = 0,t;
	for (unsigned long k = 1;k <= n;k++)
	{
		t = i + j;
		i = j;
		j = t;
	}
	return j;
}

int main()
{
	unsigned int n;
	double res;
	cout << "Ingrese un natural: ";
	cin >> n;
	res = fibo(n);
	cout << "El " << n << "-esimo numero de fibonacci es: " << res << endl;
	system("PAUSE");
	return 0;
}
