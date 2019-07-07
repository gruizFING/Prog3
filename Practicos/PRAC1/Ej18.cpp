#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

bool testPalindromo(int i,int j,char* str)
{
	if ((str == NULL) || (i > (strlen(str) / 2) + 1) || (j < (strlen(str) / 2) - 1))
		return true;
	else if (str[i] == str[j])
		return testPalindromo(i + 1,j - 1,str);
	else if (((str[i] < 'a') || (str[i] > 'z')) && ((str[i] < 'A') || (str[i] > 'Z')))
		return testPalindromo(i + 1,j,str);
	else if (((str[j] < 'a') || (str[j] > 'z')) && ((str[j] < 'A') || (str[j] > 'Z')))
		return testPalindromo(i,j - 1,str);
	else
		return false;
}

int main()
{
	char* s = new char[256];
	cout << "Ingrese una cadena de caracteres:\n";
	scanf("%[^\n]",s);    //Lee toda la linea y la mete en el string s
	if (testPalindromo(0,strlen(s) - 1,s))
		cout << "La cadena es un palindromo.\n";
	else
		cout << "La cadena no es un palindromo.\n";
	system("PAUSE");
	return 0;
}
