#include <math.h>
#include <iostream>

using namespace std;


void Criba(bool* criba,long int n) {
	for (int i = 2;i < sqrt(n) + 1;i++) {
		if (criba[i] == false)
			for (int j = 2;j*i < n;j++)
				criba[j*i] = true;
	}
}


int main() {
	long int n = 0;
	while (n < 3) {
		cout << "Ingrese un numero entero mayor que 2: ";
		cin >> n;
	}
	bool* criba = new bool[n];
	for (long int i = 2;i < n;i++) 
		criba[i] = false;
	Criba(criba,n);
	cout << "Los numeros primos menores que " << n << " son:\n";
	for (long int i = 2;i < n;i++) 
		if (criba[i] == false)
			cout << i << " ";
	cout << endl;
	delete [] criba;
	system("PAUSE");
	return 0;
}
