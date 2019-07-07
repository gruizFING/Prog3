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

int main ()
{
	int num1,num2;
	cout << "Ingrese dos enteros, el primero mayor o igual al segundo: ";
	cin >> num1 >> num2;
	while (num1 < num2)
	{
		cout << "\007El primer entero ingresado debe ser mayor que el segundo.\n";
		cout << "Ingrese dos enteros, el primero mayor o igual al segundo: ";
		cin >> num1 >> num2;
	}	
	if (multiplo(num1,num2))
		cout << "El segundo es multiplo del primero.\n";
	else
		cout << "El segundo no es multiplo del primero.\n";
	system("PAUSE");
	return 0;
}
