#include "carrera.h"
#include "utils.h"
#include <stdlib.h>

#include <stdio.h>
#include <string.h>

int main()
{
	int L, S, C, B;

	L = 10;
	C = 10;
	B = 15;
	S = 4;
	int t1[] = {40, 38, 35, 30};
	int c1[] = {1, 2, 3, 5};

	test(L,C,B,S,t1,c1,385,false);


	L = 10;
	C = 2;
	B = 15;
	S = 4;

	test(L,C,B,S,t1,c1,535,false);

	L = 10;
	C = 51;
	B = 15;
	S = 4;

    test(L,C,B,S,t1,c1,300,false);

	L = 10;
	C = 1;
	B = 15;
	S = 4;

	test(L,C,B,S,t1,c1,SIN_SOLUCION,false);

	return 0;
}
