#include <iostream>

using namespace std;

void swap (int *a, int *b)
{
	int z = *a;
	*a = *b;
	*b = z;
}

int main ()
{
	int a = 3, b = 5;
	int *p = &a, *q = &b;
	swap(p, q);
	cout << a << " " << b;
	return 0;
}

