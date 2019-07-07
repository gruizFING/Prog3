#include <iostream>

using namespace std;

unsigned int mcd(unsigned int x,unsigned int y)
{
	if (y == 0)
		return x;
	else
		return (mcd(y,x % y));
}

int main()
{
	cout << "Ingrese dos numeros naturales: ";
	unsigned int x,y,res;
	cin >> x >> y;
/*	if (x >= y)
		res = mcd(x,y);
	else
		res = mcd(y,x);*/
	if (mcd(x,y) == 1)
		cout << x << " y " << y << " son primos entre si.\n";
	else
		cout << x << " y " << y << " no son primos entre si.\n";
	system("PAUSE");
	return 0;
}
