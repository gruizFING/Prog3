
#include <iostream>

using namespace std;

// 4a)
int funcion1()
{
	int a = 0;
	if (a++)                           // ????
		cout << "a es mayor que 0";
	else
		cout << "a es 0";
	return 0;
}

	
// Salida -> a es 0 	

// 4b)
int funcion2()	
{
	int a = 0;                              
	if (++a)							// ????
		cout << "a es mayor que 0";
	else
		cout << "a es 0";
	return 0;
}
// Salida -> a es mayor que 0  (a = 1)

int main()
{
	cout << endl << "Salida 1 -> ";
	funcion1();
	cout << endl << "Salida 2 -> ";
	funcion2();
	cout << "\n";
}
