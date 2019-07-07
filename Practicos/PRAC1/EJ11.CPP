#include <iostream>

using namespace std;

void inicializar (int **a)
{
	*a = new int;
	**a = 4;
}

int main()
{
	int *p;
	inicializar(&p);
	cout << *p;
	return 0;
}

