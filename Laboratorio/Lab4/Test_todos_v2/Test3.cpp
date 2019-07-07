#include <stdio.h>
#include <strings.h>
#include <iostream>
#include "operaciones.h"
#include "utils.h"
using namespace std;

int main()
{
    printf("***********************************************************************\n");
    printf("***********************************************************************\n");
    printf("                 CASO DE PRUEBA NO OFICIAL Nro.3- Version 1.0            \n");
    printf("***********************************************************************\n");
    printf("***********************************************************************\n");
    ///CONSTRUCCIONES
    int* a = new int[1];
    int* b = new int[2];
    int* c = new int[4];
    int* d = new int[8];
    int* e = new int[16];
    int* e1 = new int[16];
    int* f = new int[32];
    int* f1 = new int[32];
    int* g = new int[64];
    int* h = new int[128];
    int* i = new int[256];
    int* j = new int[512];
    int* k = new int[1024];

    ///INICIALIZACIONES DE LOS GRANDES
    for (int p=0; p<1024; p++){
        if (p<16){
            e[p]=((p*(p+p*p*147+6) % 601) + p+661) % 10;
            e1[p]= ((9943+ 146 * (p + 77))%987) % 10;
            f[p]= (p*p) % 10;
            f1[p]= (p*(2*p+9)*(p+11) + 6581) % 10;
            g[p]= (6 + p*(p %10)*e1[p] ) % 10;
            h[p]= ((p + 88) % 10);
            i[p]= (8484*(p+5)*23 + 45*p+g[p]*f[p]) % 10;
            j[p]= ((3849 + 614*(p^2)*23 + 345*p +e[p]*e[p])%661) % 10;
            k[p]= (i[p]*p + 9*i[p] + p*(p %10)) % 10;
        }
        else if (p<32){
                f[p]= (p*p*p*p) % 10;
                f1[p]= (p*(p+554) + 98) % 10;
                g[p]= (8 + p*(p %10) ) % 10;
                h[p]= ((p + 7) % 10);
                i[p]= (6523*(p)*3 + 345*p) % 10;
                j[p]= (666 + f[p%10] + 614*23 + 345*p ) % 10;
                k[p]= (i[p%10] + f[p%10] + 5533 + p*(p %10)) % 10;
             }
             else if (p<64){
                    g[p]= (15 + 9*(p %10) ) % 10;
                    h[p]= ((p+9887 + 4) % 797)%10;
                    i[p]= (7134*23+g[p] + 245*p) % 10;
                    j[p]= (664 + g[p%10] + 623*53 + 345*p ) % 10;
                    k[p]= (j[p%10] + j[p%10]+ p*(p %10)) % 10;
                  }
                  else if (p<128){
                        h[p]= ((p*p) % 15)%10;
                        i[p]= (686*(p+998)*11 + 345*p) % 10;
                        j[p]= ((666 + i[p%10] + 6124*23 + 345*p )%601) % 10;
                        k[p]= ((j[p%10] + i[p%10] +568 + p*(p %10))%601) % 10;
                        }
                        else if (p<256){
                                i[p]= (6774*253 + 345*p) % 10;
                                j[p]= (7666 + h[p%10] + 64*23 + 345*p ) % 10;
                                k[p]= ((i[p%10] + i[p%10] + 8 + p*(p %10)+9899)%991) % 10;
                             }
                             else if (p<512){
                                    j[p]= (123 + h[p%10] + 64*89 + 345*p ) % 10;
                                    k[p]= (k[p-1] + i[p%10] + 8 + p*(p %10)) % 10;
                                  }
                                  else
                                        k[p]= (i[p%10] + 2*i[p%10] + 899 + p*(p %10)) % 10;


    }
    d[0]=8; d[1]=3; d[2]=3; d[3]=8; d[4]=9; d[5]=6; d[6]=5; d[7]=4;

    printf("**** PRUEBAS DE LA SUMA ****");

    printf("\n\nPrueba 1) 9999 + 0001 = ");
    c[0]=9; c[1]=9; c[2]=9; c[3]=9;
    int* l = new int[4];
    l[0]=0; l[1]=0; l[2]=0; l[3]=1;
    bool carry;
    int* suma = sumar(c,l,4,carry);
    if (carry)
        printf("C ");
    imprimir(suma,4);
    liberarResultado(suma);

    printf("\n\nPrueba 2) 9807 + 1404 = ");
    c[0]=9; c[1]=8; c[2]=0; c[3]=7;
    l[0]=1; l[1]=4; l[2]=0; l[3]=4;
    suma = sumar(c,l,4,carry);
    if (carry)
        printf("C ");
    imprimir(suma,4);
    liberarResultado(suma);

    printf("\n\nPrueba 3) 0000 + 0000 = ");
    c[0]=0; c[1]=0; c[2]=0; c[3]=0;
    l[0]=0; l[1]=0; l[2]=0; l[3]=0;
    suma = sumar(c,l,4,carry);
    if (carry)
        printf("C ");
    imprimir(suma,4);
    liberarResultado(suma);

    printf("\n\nPrueba 4) 0000 + 6475 = ");
    c[0]=0; c[1]=0; c[2]=0; c[3]=0;
    l[0]=6; l[1]=4; l[2]=7; l[3]=5;
    suma = sumar(c,l,4,carry);
    if (carry)
        printf("C ");
    imprimir(suma,4);
    liberarResultado(suma);

    printf("\n\nPrueba 5) 7999 + 0011 = ");
    c[0]=7; c[1]=9; c[2]=9; c[3]=9;
    l = new int[4];
    l[0]=0; l[1]=0; l[2]=1; l[3]=1;
    suma = sumar(c,l,4,carry);
    if (carry)
        printf("C ");
    imprimir(suma,4);
    liberarResultado(suma);

    printf("\n\nPrueba 6) 9999 + 9999 = ");
    c[0]=9; c[1]=9; c[2]=9; c[3]=9;
    l[0]=9; l[1]=9; l[2]=9; l[3]=9;
    suma = sumar(c,l,4,carry);
    if (carry)
        printf("C ");
    imprimir(suma,4);
    liberarResultado(suma);

    printf("\n\nPrueba 7) 1 + 1 = ");
    a[0]=1;
    int* m = new int[1];
    m[0]=1;
    suma = sumar(a,m,1,carry);
    if (carry)
        printf("C ");
    imprimir(suma,1);
    liberarResultado(suma);

    printf("\n\nPrueba 8) 7 + 1 = ");
    a[0]=7;
    m[0]=1;
    suma = sumar(a,m,1,carry);
    if (carry)
        printf("C ");
    imprimir(suma,1);
    liberarResultado(suma);

    printf("\n\nPrueba 9) e + e1 = ");
    suma = sumar(e,e1,16,carry);
    if (carry)
        printf("C ");
    imprimir(suma,16);
    liberarResultado(suma);

    printf("\n\nPrueba 10) f + f1 = ");
    suma = sumar(f,f1,32,carry);
    if (carry)
        printf("C ");
    imprimir(suma,32);
    liberarResultado(suma);

    printf("\n\nPrueba 11) e + e = ");
    suma = sumar(e,e,16,carry);
    if (carry)
        printf("C ");
    imprimir(suma,16);
    liberarResultado(suma);

    printf("\n\nPrueba 12) k + k ");
    suma = sumar(k,k,1024,carry);
    if (carry)
        printf("C ");
    imprimir(suma,1024);
    liberarResultado(suma);

    printf("\n\n**** PRUEBAS DE LA MULTIPLICACION ****");

    printf("\n\nPrueba 1) 9999 * 9999 = ");
    c[0]=9; c[1]=9; c[2]=9; c[3]=9;
    l[0]=9; l[1]=9; l[2]=9; l[3]=9;
    int* multi = multiplicar(c,l,4);
    imprimir(multi,8);
    liberarResultado(multi);

    printf("\n\nPrueba 2) 51 * 13 = ");
    b[0]=5; b[1]=1;
    int* n = new int[2];
    n[0]=1; n[1]=3;
    multi = multiplicar(b,n,2);
    imprimir(multi,4);
    liberarResultado(multi);

    printf("\n\nPrueba 3) f * f1 = ");
    multi = multiplicar(f,f1,32);
    imprimir(multi,64);
    liberarResultado(multi);

    printf("\n\nPrueba 4) e * e1 = ");
    multi = multiplicar(e,e1,16);
    imprimir(multi,32);
    liberarResultado(multi);

    printf("\n\nPrueba 5) h * h = ");
    multi = multiplicar(h,h,128);
    imprimir(multi,256);
    liberarResultado(multi);

    printf("\n\nPrueba 6) i * i = ");
    multi = multiplicar(i,i,256);
    imprimir(multi,512);
    liberarResultado(multi);

    printf("\n\nPrueba 7) k * k = ");
    multi = multiplicar(k,k,1024);
    imprimir(multi,2048);

    printf("\n\nPrueba 8) multi * multi = ");
    multi = multiplicar(multi,multi,2048);
    imprimir(multi,4096);

    liberarResultado(multi);

    printf("**** PRUEBAS DE LA EXPONENCIACION ****\n\n");


    /*
     * Exponenciación de base^exponente.
     * @Pre: El exponente debe ser potencia de 2
     * @Pre:Largo debe ser potencia de 2
     * @Pre: El largo del vector 'base' debe ser igual a largo
     * @Post: nLargo indica el largo del vector resultado devuelto
    */
    int length;
    int exp;
    exp = 1;

    printf("\n\nExponente = 1:");

    printf("\n\nPrueba 1) 0 ^ 1 = ");
    a[0]=0;
    int* res = exponenciar(a,1,exp,length);
    imprimir(res,length);
    liberarResultado(res);

    printf("\n\nPrueba 2) 1 ^ 1 = ");
    a[0]=1;
    res = exponenciar(a,1,exp,length);
    imprimir(res,length);
    liberarResultado(res);

    printf("\n\nPrueba 3) 9 ^ 1 = ");
    a[0]=9;
    res = exponenciar(a,1,exp,length);
    imprimir(res,length);
    liberarResultado(res);

    printf("\n\nPrueba 4) 95 ^ 1 = ");
    b[0]=9; b[1]=5;
    res = exponenciar(b,2,exp,length);
    imprimir(res,length);
    liberarResultado(res);

    printf("\n\nPrueba 5) 7685 ^ 1 = ");
    c[0]=7; c[1]=6; c[2]=8; c[3]=5;
    res = exponenciar(c,4,exp,length);
    imprimir(res,length);
    liberarResultado(res);

    printf("\n\nPrueba 6) d ^ 1 = ");
    res = exponenciar(d,8,exp,length);
    imprimir(res,length);
    liberarResultado(res);

    printf("\n\nPrueba 7) 10293758 ^ 1 = ");
    d[0]=1; d[1]=0; d[2]=2; d[3]=9; d[4]=3; d[5]=7; d[6]=5; d[7]=8;
    res = exponenciar(d,8,exp,length);
    imprimir(res,length);
    liberarResultado(res);

    printf("\n\nPrueba 8) e ^ 1 = ");
    res = exponenciar(e,16,exp,length);
    imprimir(res,length);
    liberarResultado(res);

    printf("\n\nPrueba 9) f ^ 1 = ");
    res = exponenciar(f,32,exp,length);
    imprimir(res,length);
    liberarResultado(res);

    printf("\n\nPrueba 10) g ^ 1 = ");
    res = exponenciar(g,64,exp,length);
    imprimir(res,length);
    liberarResultado(res);

    printf("\n\nPrueba 11) h ^ 1 = ");
    res = exponenciar(h,128,exp,length);
    imprimir(res,length);
    liberarResultado(res);

    printf("\n\nPrueba 12) i ^ 1 = ");
    res = exponenciar(i,256,exp,length);
    imprimir(res,length);
    liberarResultado(res);

    printf("\n\nPrueba 13) j ^ 1 = ");
    res = exponenciar(j,512,exp,length);
    imprimir(res,length);
    liberarResultado(res);

    printf("\n\nPrueba 14) k ^ 1 = ");
    res = exponenciar(k,1024,exp,length);
    imprimir(res,length);
    liberarResultado(res);


    printf("\n\nExponente = 2:\n\n");
    exp = 2;

    printf("\n\nPrueba 1) 0 ^ 2 = ");
    a[0]=0;
    res = exponenciar(a,1,exp,length);
    imprimir(res,length);
    liberarResultado(res);

    printf("\n\nPrueba 2) 1 ^ 2 = ");
    a[0]=1;
    res = exponenciar(a,1,exp,length);
    imprimir(res,length);
    liberarResultado(res);

    printf("\n\nPrueba 3) 9 ^ 2 = ");
    a[0]=9;
    res = exponenciar(a,1,exp,length);
    imprimir(res,length);
    liberarResultado(res);

    printf("\n\nPrueba 4) 89 ^ 2 = ");
    b[0]=8; b[1]=9;
    res = exponenciar(b,2,exp,length);
    imprimir(res,length);
    liberarResultado(res);

    printf("\n\nPrueba 5) 9635 ^ 2 = ");
    c[0]=9; c[1]=6; c[2]=3; c[3]=5;
    res = exponenciar(c,4,exp,length);
    imprimir(res,length);
    liberarResultado(res);

    printf("\n\nPrueba 6) d ^ 2 = ");
    res = exponenciar(d,8,exp,length);
    imprimir(res,length);
    liberarResultado(res);

    printf("\n\nPrueba 7) 11293753 ^ 2 = ");
    d[0]=1; d[1]=1; d[2]=2; d[3]=9; d[4]=3; d[5]=7; d[6]=5; d[7]=3;
    res = exponenciar(d,8,exp,length);
    imprimir(res,length);
    liberarResultado(res);

    printf("\n\nPrueba 8) e ^ 2 = ");
    res = exponenciar(e,16,exp,length);
    imprimir(res,length);
    liberarResultado(res);

    printf("\n\nPrueba 9) f ^ 2 = ");
    res = exponenciar(f,32,exp,length);
    imprimir(res,length);
    liberarResultado(res);

    printf("\n\nPrueba 10) g ^ 2 = ");
    res = exponenciar(g,64,exp,length);
    imprimir(res,length);
    liberarResultado(res);

    printf("\n\nPrueba 11) h ^ 2 = ");
    res = exponenciar(h,128,exp,length);
    imprimir(res,length);
    liberarResultado(res);

    printf("\n\nPrueba 12) i ^ 2 = ");
    res = exponenciar(i,256,exp,length);
    imprimir(res,length);
    liberarResultado(res);

    printf("\n\nPrueba 13) j ^ 2 = ");
    res = exponenciar(j,512,exp,length);
    imprimir(res,length);
    liberarResultado(res);

    printf("\n\nPrueba 14) k ^ 2 = ");
    res = exponenciar(k,1024,exp,length);
    imprimir(res,length);
    liberarResultado(res);

    printf("\n\nPrueba 15) e1 ^ 2 = ");
    res = exponenciar(e1,16,exp,length);
    imprimir(res,length);
    liberarResultado(res);


    printf("\n\nExponente = 4:\n\n");
    exp = 4;

    printf("\n\nPrueba 1) 0 ^ 4 = ");
    a[0]=0;
    res = exponenciar(a,1,exp,length);
    imprimir(res,length);
    liberarResultado(res);

    printf("\n\nPrueba 2) 1 ^ 4 = ");
    a[0]=1;
    res = exponenciar(a,1,exp,length);
    imprimir(res,length);
    liberarResultado(res);

    printf("\n\nPrueba 3) 8 ^ 4 = ");
    a[0]=8;
    res = exponenciar(a,1,exp,length);
    imprimir(res,length);
    liberarResultado(res);

    printf("\n\nPrueba 4) 45 ^ 4 = ");
    b[0]=4; b[1]=5;
    res = exponenciar(b,2,exp,length);
    imprimir(res,length);
    liberarResultado(res);

    printf("\n\nPrueba 5) 5585 ^ 4 = ");
    c[0]=5; c[1]=5; c[2]=8; c[3]=5;
    res = exponenciar(c,4,exp,length);
    imprimir(res,length);
    liberarResultado(res);

    printf("\n\nPrueba 6) d ^ 4 = ");
    res = exponenciar(d,8,exp,length);
    imprimir(res,length);
    liberarResultado(res);

    printf("\n\nPrueba 7) 23693755 ^ 4 = ");
    d[0]=2; d[1]=3; d[2]=6; d[3]=9; d[4]=3; d[5]=7; d[6]=5; d[7]=5;
    res = exponenciar(d,8,exp,length);
    imprimir(res,length);
    liberarResultado(res);

    printf("\n\nPrueba 8) e ^ 4 = ");
    res = exponenciar(e,16,exp,length);
    imprimir(res,length);
    liberarResultado(res);

    printf("\n\nPrueba 9) f ^ 4 = ");
    res = exponenciar(f,32,exp,length);
    imprimir(res,length);
    liberarResultado(res);

    printf("\n\nPrueba 10) g ^ 4 = ");
    res = exponenciar(g,64,exp,length);
    imprimir(res,length);
    liberarResultado(res);

    printf("\n\nPrueba 11) h ^ 4 = ");
    res = exponenciar(h,128,exp,length);
    imprimir(res,length);
    liberarResultado(res);

    printf("\n\nPrueba 12) i ^ 4 = ");
    res = exponenciar(i,256,exp,length);
    imprimir(res,length);
    liberarResultado(res);

    printf("\n\nPrueba 13) j ^ 4 = ");
    res = exponenciar(j,512,exp,length);
    imprimir(res,length);
    liberarResultado(res);

    printf("\n\nPrueba 14) k ^ 4 = ");
    res = exponenciar(k,1024,exp,length);
    imprimir(res,length);
    liberarResultado(res);

    printf("\n\nPrueba 15) e1 ^ 4 = ");
    res = exponenciar(e,16,exp,length);
    imprimir(res,length);
    liberarResultado(res);

    printf("\n\nPrueba 16) f1 ^ 4 = ");
    res = exponenciar(f,32,exp,length);
    imprimir(res,length);
    liberarResultado(res);


    printf("\n\nExponente = 8:\n\n");
    exp = 8;

    printf("\n\nPrueba 1) 0 ^ 8 = ");
    a[0]=0;
    res = exponenciar(a,1,exp,length);
    imprimir(res,length);
    liberarResultado(res);

    printf("\n\nPrueba 2) 1 ^ 8 = ");
    a[0]=1;
    res = exponenciar(a,1,exp,length);
    imprimir(res,length);

    printf("\n\nPrueba 3) 7 ^ 8 = ");
    a[0]=7;
    res = exponenciar(a,1,exp,length);
    imprimir(res,length);
    liberarResultado(res);

    printf("\n\nPrueba 4) 85 ^ 8 = ");
    b[0]=8; b[1]=5;
    res = exponenciar(b,2,exp,length);
    imprimir(res,length);
    liberarResultado(res);

    printf("\n\nPrueba 5) 9000 ^ 8 = ");
    c[0]=9; c[1]=0; c[2]=0; c[3]=0;
    res = exponenciar(c,4,exp,length);
    imprimir(res,length);
    liberarResultado(res);

    printf("\n\nPrueba 6) d ^ 8 = ");
    res = exponenciar(d,8,exp,length);
    imprimir(res,length);
    liberarResultado(res);

    printf("\n\nPrueba 7) 10277733 ^ 8 = ");
    d[0]=1; d[1]=0; d[2]=2; d[3]=7; d[4]=7; d[5]=7; d[6]=3; d[7]=3;
    res = exponenciar(d,8,exp,length);
    imprimir(res,length);
    liberarResultado(res);

    printf("\n\nPrueba 8) e ^ 8 = ");
    res = exponenciar(e,16,exp,length);
    imprimir(res,length);
    liberarResultado(res);

    printf("\n\nPrueba 9) f ^ 8 = ");
    res = exponenciar(f,32,exp,length);
    imprimir(res,length);
    liberarResultado(res);

    printf("\n\nPrueba 10) g ^ 8 = ");
    res = exponenciar(g,64,exp,length);
    imprimir(res,length);
    liberarResultado(res);

    printf("\n\nPrueba 11) h ^ 8 = ");
    res = exponenciar(h,128,exp,length);
    imprimir(res,length);
    liberarResultado(res);

    printf("\n\nPrueba 12) i ^ 8 = ");
    res = exponenciar(i,256,exp,length);
    imprimir(res,length);
    liberarResultado(res);

    printf("\n\nPrueba 13) j ^ 8 = ");
    res = exponenciar(j,512,exp,length);
    imprimir(res,length);
    liberarResultado(res);

    printf("\n\nPrueba 14) k ^ 8 = ");
    res = exponenciar(k,1024,exp,length);
    imprimir(res,length);
    liberarResultado(res);
    delete [] k;

    printf("\n\nPrueba 15) e1 ^ 8 = ");
    res = exponenciar(e1,16,exp,length);
    imprimir(res,length);
    liberarResultado(res);

    printf("\n\nPrueba 16) f1 ^ 8 = ");
    res = exponenciar(f1,32,exp,length);
    imprimir(res,length);
    liberarResultado(res);



    printf("\n\nExponente = 16:\n\n");
    exp = 16;

    printf("\n\nPrueba 1) 0 ^ 16 = ");
    a[0]=0;
    res = exponenciar(a,1,exp,length);
    imprimir(res,length);
    liberarResultado(res);

    printf("\n\nPrueba 2) 1 ^ 16 = ");
    a[0]=1;
    res = exponenciar(a,1,exp,length);
    imprimir(res,length);
    liberarResultado(res);

    printf("\n\nPrueba 3) 8 ^ 16 = ");
    a[0]=8;
    res = exponenciar(a,1,exp,length);
    imprimir(res,length);
    liberarResultado(res);
    delete [] a;

    printf("\n\nPrueba 4) 45 ^ 16 = ");
    b[0]=4; b[1]=5;
    res = exponenciar(b,2,exp,length);
    imprimir(res,length);
    liberarResultado(res);
    delete [] b;

    printf("\n\nPrueba 5) 7685 ^ 16 = ");
    c[0]=7; c[1]=6; c[2]=8; c[3]=5;
    res = exponenciar(c,4,exp,length);
    imprimir(res,length);
    liberarResultado(res);
    delete [] c;

    printf("\n\nPrueba 6) d ^ 16 = ");
    res = exponenciar(d,8,exp,length);
    imprimir(res,length);
    liberarResultado(res);

    printf("\n\nPrueba 7) 10293758 ^ 16 = ");
    d[0]=1; d[1]=0; d[2]=2; d[3]=9; d[4]=3; d[5]=7; d[6]=5; d[7]=8;
    res = exponenciar(d,8,exp,length);
    imprimir(res,length);
    liberarResultado(res);
    delete [] d;

    printf("\n\nPrueba 8) e ^ 16 = ");
    res = exponenciar(e,16,exp,length);
    imprimir(res,length);
    liberarResultado(res);
    delete [] e;

    printf("\n\nPrueba 9) f ^ 16 = ");
    res = exponenciar(f,32,exp,length);
    imprimir(res,length);
    liberarResultado(res);
    delete [] f;

    printf("\n\nPrueba 10) g ^ 16 = ");
    res = exponenciar(g,64,exp,length);
    imprimir(res,length);
    liberarResultado(res);
    delete [] g;

    printf("\n\nPrueba 11) h ^ 16 = ");
    res = exponenciar(h,128,exp,length);
    imprimir(res,length);
    liberarResultado(res);
    delete [] h;

    printf("\n\nPrueba 12) i ^ 16 = ");
    res = exponenciar(i,256,exp,length);
    imprimir(res,length);
    liberarResultado(res);
    delete [] i;

    printf("\n\nPrueba 13) j ^ 16 = ");
    res = exponenciar(j,512,exp,length);
    imprimir(res,length);
    liberarResultado(res);
    delete [] j;

    printf("\n\nPrueba 14) e1 ^ 16 = ");
    res = exponenciar(e1,16,exp,length);
    imprimir(res,length);
    liberarResultado(res);
    delete [] e1;

    printf("\n\nPrueba 15) f1 ^ 16 = ");
    res = exponenciar(f1,32,exp,length);
    imprimir(res,length);
    liberarResultado(res);
    delete [] f1;
    printf("\n");
    printf("***********************************************************************\n");
    printf("***********************************************************************\n");
    printf("                                  FIN!                                 \n");
    printf("***********************************************************************\n");
    printf("***********************************************************************\n");


    return 0;
}












