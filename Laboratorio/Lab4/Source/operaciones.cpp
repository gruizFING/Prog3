/* 4317743 */

#include "operaciones.h"
#include <stdlib.h>
#include <assert.h>


int* sumar(const int *a, const int *b, int n, bool &carry) {
	assert((a != NULL) && (b != NULL));
	int* res = new int[n];
	carry = false;
	for (int i = n-1;i >= 0;i--)
	{
		res[i] = a[i] + b[i];
		if (carry)
			res[i]++;
		if (res[i] > 9)
		{
			carry = true;
			res[i] = res[i] % 10;
		}
		else
			carry = false;
	}
	
	return res;
}


int* multiplicar(const int *a, const int *b, int n) {
	assert((a != NULL) && (b != NULL));
	int* res;
	if (n == 1) //Paso Base.
	{
		res = new int[2];
		res[1] = a[0] * b[0];
		if (res[1] > 9)
		{
			res[0] = res[1] / 10;
			res[1] = res[1] % 10;
		}
		else
			res[0] = 0;
	}
	else //Pasos Recursivo.
	{
		int* w = new int[n/2];
		int* x = new int[n/2];
		int* y = new int[n/2];
		int* z = new int[n/2];
		int i;
		for (i = 0;i < n/2;i++)
		{
			w[i] = a[i];
			x[i] = a[i + n/2];
			y[i] = b[i];
			z[i] = b[i + n/2];
		}
		//Calculo del primer Termino.
		int* primTerm = new int[2*n];
		int* prod = multiplicar(w,y,n/2);
		for (i = 0;i < 2*n;i++)
		{
			if (i < n)
				primTerm[i] = prod[i];
			else
				primTerm[i] = 0;
		}
		delete [] prod;
		//Calculo del segundo Termino.
		int* segTerm = new int[2*n];
		int* prod1 = multiplicar(w,z,n/2);
		delete [] w;
		int* prod2 = multiplicar(x,y,n/2);
		delete [] y;
		bool carry;
		int* suma = sumar(prod1,prod2,n,carry);
		delete [] prod1;
		delete [] prod2;
		for (i = 0;i < 2*n;i++)
		{
			if (i < n/2)
			{
				if ((carry) && (i == ((n/2) - 1)))
					segTerm[i] = 1;
				else
					segTerm[i] = 0;
			}
			else if (i < ((3*n)/2))
				segTerm[i] = suma[i - n/2];
			else
				segTerm[i] = 0;
		}
		delete [] suma;
		//Calculo del tercer termino.
		int* tercTerm = new int[2*n];
		prod = multiplicar(x,z,n/2);
		delete [] x;
		delete [] z;
		for (i = 0;i < 2*n;i++)
		{
			if (i < n)
				tercTerm[i] = 0;
			else
				tercTerm[i] = prod[i - n];
		}
		delete [] prod;
		//Suma de los terminos para obtener el resultado.
		int* Suma1y2 = sumar(primTerm,segTerm,2*n,carry);
		delete [] primTerm;
		delete [] segTerm;
		res = sumar(Suma1y2,tercTerm,2*n,carry);
		delete [] Suma1y2;
		delete [] tercTerm;
	}	
	
	return res;
}	


int* exponenciar(const int *base,int largo, int exponente, int &nLargo) {
	assert((base != NULL));
	int* res;
	if (exponente == 1)
	{
		res = new int[largo];
		for (int i = 0;i < largo;i++)
			res[i] = base[i];
		nLargo = largo;
	}
	else
	{
		int* exp = exponenciar(base,largo,exponente/2,nLargo);
		res = multiplicar(exp,exp,nLargo);
		delete [] exp;
		nLargo = 2 * nLargo;
	}
	
	return res;
}


void liberarResultado(int *resultado) {
	delete [] resultado;
	resultado = NULL;
}
