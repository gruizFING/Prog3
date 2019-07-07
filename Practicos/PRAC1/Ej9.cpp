#include <stdio.h>
#include <iostream>

using namespace std;

int main1()
{
	int i = 0, j = 0;
	for (i += 2; j < 6; j++, i += 2)
		cout << i << " " << j++ << " ";   // Error: En vez de I es i
	cout << endl;
	return 0;
}

// Salida -> 2 0 4 2 6 4 | y salto de linea.

int main2()
{
	int a = 1, b = 0;
	int *p = &a;
	cout << " a = "<< a << endl;
	cout << " p = "<< p << endl;   // Fruta!!!
	cout << " *p = "<< *p << endl;
	a = 2;
	cout << " a = " << a << endl;
	cout << " p = " << p << endl;  // Fruta!!!
	cout << " *p = " << *p << endl;
	*p += 2;
	cout << " a = " << a << endl;
	cout << " p = " << p << endl;  
	cout << " *p = " << *p << endl;
	p = &b;
	cout << " a = " << a << endl;
	cout << " p = " << p << endl;
	cout << " *p = " << *p << endl;
	return 0;
}

//***********************************
//Salida --->   a = 1               *
//			    *p = 1              *
//              a = 2               *
//			    *p = 2              *
//              a = 4               *
// 	            *p = 4              *
//              a = 4               *
//              *p = 0              *
//***********************************

int main3()
{
	int a[10], i;
	int *p = a, *q = &(a[0]);
	for (i = 0; i < 10; i++) 
		a[i] = i;
	cout << "p = " << p << endl;
	cout << "q = " << q << endl;
	for (i = 0; i < 10; i++, p++)
		printf("a[%d] = %d\n", i, *p);
	return 0;
}
//**********************************
//Salida -->  p = "algo"           *
//            q = "mismo algo"     *
//            a[0] = 0             *
//            a[1] = 1             *
//            a[2] = 2             *
//              ....               *
//            a[9] = 9             *
//**********************************


int main()
{
	int i;
	char *s;
	s = new char[26];
	for (i = 0; i < 26; i++)
		s[i] = 'a' + i;
	for (i = 0; i < 26; i++)
		printf(" s[%02d] = %c\n", i, s[i]);
	return 0;
}

//*********************************
//Salida --> s[00] = a            *
//           s[01] = b            *
//           s[02] = c            *
//             ....               *
//           s[25] = z            *
//*********************************

