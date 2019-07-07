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
	S = 6;
	int t1[] = {40, 38, 35, 30, 29, 25};
	int c1[] = {1, 2, 3, 5, 7, 8 };

	test(L,C,B,S,t1,c1,385,false);


	L = 10;
	C = 10;
	B = 10;
	S = 6;

	test(L,C,B,S,t1,c1,340,false);

	L = 10;
	C = 10;
	B = 20;
	S = 6;

    test(L,C,B,S,t1,c1,398,false);

	L = 10;
	C = 10;
	B = 2;
	S = 6;

	test(L,C,B,S,t1,c1,268,false);

	return 0;
}
