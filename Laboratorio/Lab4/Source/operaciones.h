/*
 * Tarea 4: Divide and Conquer
 *
 * Programación 3
 * Instituto de Computación
 * Facultad de Ingeniería
 * Universidad de la República
 *
 * $Rev: 292 $
 *
 */
#ifndef OPERACIONES_H
#define OPERACIONES_H


/*
 * El dígito en la posición a[0] es el más significativo.
 * El dígito en la posición b[0] es el más significativo.
 * El resultado debe respetar este orden.
 *
 * @Pre: a != NULL
 * @Pre: El vector 'a' tiene largo 'n'
 * @Pre: b != NULL
 * @Pre: El vector 'b' tiene largo 'n'
 */
int* sumar(const int *a, const int *b, int n, bool &carry);

/*
 * El dígito en la posición a[0] es el más significativo.
 * El dígito en la posición b[0] es el más significativo.
 * El resultado debe respetar este orden.
 *
 * @Pre: a != NULL
 * @Pre: El vector 'a' tiene largo 'n'
 * @Pre: b != NULL
 * @Pre: El vector 'b' tiene largo 'n'
 */
int* multiplicar(const int *a, const int *b, int n);

/*
 * Exponenciación de base^exponente.
 * @Pre: El exponente debe ser potencia de 2
 * @Pre:Largo debe ser potencia de 2
 * @Pre: El largo del vector 'base' debe ser igual a largo
 * @Post: nLargo indica el largo del vector resultado devuelto
 */
int* exponenciar(const int *base,int largo, int exponente, int &nLargo);

/*
 * Libera la memoria de 'resultado'
 */
void liberarResultado(int *resultado);

#endif
