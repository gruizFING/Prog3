#include "utils.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static int nrotest = 1;

void test(int L, int C, int B, int S, int *t1, int *c1, int resultado_esperado, bool debug) {
	printf("**** TEST %d ****\n", nrotest);
	nrotest++;
	Par* sol = new Par[L];

	int duracion = minimizar_tiempo_carrera(L,C,B,S,t1,c1,sol);

	if (debug) {
		/* Solo quiero saber el resultado */
		printf("Tiempo=%d\n",duracion);
	} else {
		/* Verifico que sea factible y si devuelve el resultado esperado */
		if (verificar_solucion (L, C, B, S, t1, c1, sol, duracion, resultado_esperado)) {
			printf("OK\n");
		} else {
			printf("ERROR\n");
			exit(1);
		}
	}

	delete []sol;
}

int solucion_factible (int L, int C, int S, int* c, Par* sol)
{
	/* Restriccion explicita */
	for (int i = 0; i < L; i++)
	{
		if (sol[i].velocidad < 1 || sol[i].velocidad > S)
			return 0;
	}

	/* No se consume mas combustible del disponible */
	int gasto = 0;
	for (int i=0; i<L; i++) {
		if (sol[i].boxes) {
			gasto = 0;
		}
		gasto += c[sol[i].velocidad-1];
		if (gasto > C) {
			return 0;
		}
	}

  return 1;
}

int calcular_duracion (int L, int B, int* t, Par* sol)
{
  int duracion = 0;
  for (int i = 0; i < L; i++)
    {
      duracion += t[sol[i].velocidad-1];
      if (sol[i].boxes) duracion += B;
    }

  return duracion;
}

int verificar_solucion (int L, int C, int B, int S, int *t, int *c,
                        Par *sol, int duracion, int esperado)
{
  if (esperado != duracion) {
	  /* La duracion es incorrecta */
	  return 0;
  }

  if (esperado == -1) {
	  return 1;
  }

  if (duracion < 0)
    {
	    /* No se encontro solucion */
      return 0;
    }

  if (duracion != calcular_duracion (L, B, t, sol))
    {
	    /* La solucion tiene una duracion distinta a la retornada */
      return 0;
    }


  if (solucion_factible (L, C, S, c, sol)) {
	  /* La solucion esta OK */
	  return 1;
  }

  return 0;
}

void imprimir_resultados (int L, Par *sol, int duracion)
{
  if (duracion < 1)
  {
	  printf ("No existe solucion\n");
	  return;
  }

  printf ("Velocidades = ");
  for (int i = 0; i < L; i++)
	  {
		  printf ("%d ", sol[i].velocidad);
	  }
  printf ("\n");

  printf ("Paradas = ");
  for (int i = 0; i < L; i++)
	  {
		  if (sol[i].boxes)
			  printf ("1 ");
		  else
			  printf( "0 " );
    }
  printf ("\n");

  printf ("Duracion = %d\n", duracion);
}
