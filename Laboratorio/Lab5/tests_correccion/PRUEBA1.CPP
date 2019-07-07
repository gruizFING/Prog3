#include "carrera.h"
#include "utils.h"
#include <stdlib.h>
#include <stdio.h>

int
main (int argc, char *argv[])
{
  int L, C, B, S;

  // Ejemplo 1:
  L = 11;
  C = 40;
  B = 12;
  S = 10;
  int t1[] = {150, 110, 90, 88, 30, 20, 18, 17, 15, 3};
  int c1[] = {4, 8, 17, 32, 64, 65, 70, 71, 100, 110};

  test(L,C,B,S,t1,c1,1048,false);

  return 0;
}
