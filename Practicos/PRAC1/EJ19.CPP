#include <iostream>

using namespace std;

unsigned long fibo(unsigned int n)
{
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else
		return (fibo(n - 1) + fibo(n - 2));
}

int main()
{
	unsigned int n;
	unsigned long res;
	cout << "Ingrese un natural: ";
	cin >> n;
	res = fibo(n);
	cout << "El " << n << "-esimo numero de fibonacci es: " << res << endl;
	system("PAUSE");
	return 0;
}
