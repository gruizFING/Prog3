#include <iostream>

using namespace std;

double factorial (unsigned int n)
{
	if (n == 0)
		return 1;
	else 
		return (n * factorial(n - 1));
}



int main()
{
	unsigned int i;
	double fact;
	cout << "Ingrese un natural: ";
	cin >> i;
	fact = factorial(i);
	cout << "El factorial de " << i << " es = " << fact << endl;
	system("Pause");
	return 0;
}	
