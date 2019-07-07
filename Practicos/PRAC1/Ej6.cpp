#include <stdio.h>
#include <iostream>
#define MAXIMO_DE_LINEA 80

using namespace std;

char* func (char* s)    // Pasa todas las letras minusculas del string "s" a mayusculas
{
	int i;
	for (i = strlen(s) - 1; i >= 0; i--)
		if ((s[i] <= 'z') && (s[i] >= 'a'))  
			s[i] -= 'a' - 'A';
		return s;
}

int main ()            // Restricción: Ingresar al menos un caracter y ¿ no más de 80 ?.
{
	char* s = (char*) malloc (sizeof (char) * MAXIMO_DE_LINEA);
	scanf ("%[^\n]", s);
	s = func(s);
	cout << s << endl;
	return 0;
}
