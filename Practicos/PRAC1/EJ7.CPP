
#include <iostream>

using namespace std;

int main()
{
	int c[3] = {'1','2','3'};
	int *p = c;
	cout << *p;
	cout << p[0];
	cout << p[1];
	p++;
	cout << p[1];
	cout << endl;
	int *p3 = (int*) malloc (sizeof (int) * 4);
	for (int i = 0; i <= 3; i++)
	p3[i] = i;
	int *p2 = p3;
	p2 += 3;
	cout << *p2;
	cout << endl;
	int a = 1500;
	int b = 2000;
	int c2 = 3000;
	int **doble_puntero;
	doble_puntero = (int**) malloc (sizeof (int*) * 3);
	doble_puntero[0] = &a;
	doble_puntero[1] = &b;
	doble_puntero[2] = &c2;
	for(int i = 0; i <= 2; i++)
		cout << *(doble_puntero[i]);
	return 0;
}
