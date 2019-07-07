#include "carrera.h"
#include "utils.h"
#include <stdlib.h>
#include <stdio.h>

int
main (int argc, char *argv[])
{
	int L, C, B, S;

	L = 7;
	C = 37;
	B = 10;
	S = 10;
	int t1[] = {120, 70, 34, 27, 25, 20, 19, 17, 15, 10};
	int c1[] = {1, 2, 3, 4, 5, 6, 7, 9, 14, 38};
	test(L,C,B,S,t1,c1,127,false);

	L = 9;
	C = 20;
	B = 1;
	S = 10;
	int t2[] = {1, 5, 9, 15, 20, 21, 22, 23, 24, 25};
	int c2[] = {1, 3, 5,  9, 12, 15, 18, 20, 22, 28};
	test(L,S,C,B, t2, c2, 9, false);

	L = 10;
	C = 10; //la capacidad no alcanza para dar una vuelta a ninguna velocidad
	B = 5;
	S = 10;

	int t3[] = {120, 70, 34, 27, 25, 20, 19, 17, 15, 10};
	int c3[] = {11, 12, 13, 14, 15, 16, 17, 19, 20, 21};

	test(L,C,B,S,t3,c3,-1,false);

	///////////////////////////////////////////////////////////////////////

	return 0;
}
