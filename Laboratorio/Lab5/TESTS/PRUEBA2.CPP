#include "carrera.h"
#include "utils.h"
#include <stdlib.h>

#define DEBUG false

int main() {
	int L,S,C,B;
	int *t1, *c1;

	L = 1;
	C = 5;
	B = 5;
	S = 1;
	t1 = new int[S];
	c1 = new int[S];
	t1[0] = 3;
	c1[0] = 3;
	test(L,C,B,S,t1,c1,3,DEBUG);

	/* -------------------- */
	L = 1;
	C = 5;
	B = 5;
	S = 1;
	t1 = new int[S];
	c1 = new int[S];
	t1[0] = 3;
	c1[0] = 6;
	test(L,C,B,S,t1,c1,SIN_SOLUCION,DEBUG);

	/* -------------------- */
	L = 1;
	C = 5;
	B = 5;
	S = 2;
	t1 = new int[S];
	c1 = new int[S];
	t1[0] = 3;
	t1[1] = 2;
	c1[0] = 3;
	c1[1] = 4;
	test(L,C,B,S,t1,c1,2,DEBUG);

	/* -------------------- */
	C = 5;
	B = 5;
	L = 1;
	S = 2;
	t1 = new int[S];
	c1 = new int[S];
	t1[0] = 3;
	t1[1] = 2;
	c1[0] = 6;
	c1[1] = 7;
	test(L,C,B,S,t1,c1,SIN_SOLUCION,DEBUG);

	/* -------------------- */
	C = 5;
	B = 5;
	t1 = new int[S];
	c1 = new int[S];
	t1[0] = 3;
	c1[0] = 4;
	t1[1] = 2;
	c1[1] = 6;
	test(L,C,B,S,t1,c1, 3,DEBUG);

	/* -------------------- */
	L = 2;
	S = 2;
	t1 = new int[S];
	c1 = new int[S];
	C = 5;
	B = 5;
	t1[0] = 2;
	c1[0] = 2;
	t1[1] = 1;
	c1[1] = 3;
	test(L,C,B,S,t1,c1, 4,DEBUG);

	/* -------------------- */
	L = 10;
	S = 10;
	C = 10;
	B = 5;
	t1 = new int[S];
	c1 = new int[S];
	t1[0] = 40;
	t1[1] = 35;
	t1[2] = 27;
	t1[3] = 24;
	t1[4] = 20;
	t1[5] = 14;
	t1[6] = 13;
	t1[7] = 12;
	t1[8] = 11;
	t1[9] = 10;
	c1[0] = 15;
	c1[1] = 16;
	c1[2] = 17;
	c1[3] = 18;
	c1[4] = 19;
	c1[5] = 20;
	c1[6] = 21;
	c1[7] = 23;
	c1[8] = 25;
	c1[9] = 27;
	test(L,C,B,S,t1,c1,SIN_SOLUCION,DEBUG);

	return EXIT_SUCCESS;
}
