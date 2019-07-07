// Ejercicio 1 "Rangos de tipos de variables" 
// int con 16 bits y float con 32 bits

// char = (-128,127)
// short = (-32768,32677)
// unsigned short = (0,65535)
/* int = (-32768,32677) */
// unsigned int = (0,65535)
// long = (-2147483648,2147483647)
// unsigned long = (0,4294967295)
// float = ? 
// double = ?


// Parte b)

#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
	int bits;
	bits = 8 * (int) sizeof(char);
	printf(" La cantidad de bits de char es: %d\n",bits);
	bits = 8 * (int) sizeof(short);
	printf(" La cantidad de bits de short es: %d\n",bits);
	bits = 8 * (int) sizeof(int);
	printf(" La cantidad de bits de int es: %d\n",bits);
	bits = 8 * (int) sizeof(unsigned short);
	printf(" La cantidad de bits de unsigned short es: %d\n",bits);
	bits = 8 * (int) sizeof(unsigned int);
	cout << " La cantidad de bits de unsigned int es: " << bits << endl;
	bits = 8 * (int) sizeof(long);
	cout << " La cantidad de bits de long es: " << bits << endl;
	bits = 8 * (int) sizeof(unsigned long);
	cout << " La cantidad de bits de unsigned long es: " << bits << endl;
	bits = 8 * (int) sizeof(float);
	cout << " La cantidad de bits de float es: " << bits << "\n";
	bits = 8 * (int) sizeof(double);
	cout << " La cantidad de bits de double es: " << bits << "\n";
	cout << " End!!! " << "\n";
	return 0;
}

