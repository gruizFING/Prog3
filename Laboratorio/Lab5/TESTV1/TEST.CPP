#include <iostream>
#include "carrera.h"

using namespace std;

int main()
{
    printf("CASO 1: L=1, S=1\n");
    int L = 1;
    int S = 1;
    Par* sol1 = new Par[L];
    int* t1 = new int[S];
    int* c1 = new int[S];


    printf("\nCASO 1.1: basico\n");
    int C = 5;
    int B = 5;
    t1[0] = 3;
    c1[0] = 3;
    int resultado = minimizar_tiempo_carrera(L,C,B,S,t1,c1,sol1);
    if (resultado >= 0)
    {
        printf("La solucion optima toma %d segundos:\n", resultado);
        for (int i=0; i<L; i++)
        {
            printf("La vuelta %d se hizo a velocidad %d", (i+1), (sol1[i].velocidad+1));
            if (sol1[i].boxes) printf(", hizo stop");
            printf("\n");
        }
    }
    else
        printf("Es imposible completar la carrera\n");



    printf("\nCASO 1.2: imposible\n");
    C = 5;
    B = 5;
    t1[0] = 3;
    c1[0] = 6;
    resultado = minimizar_tiempo_carrera(L,C,B,S,t1,c1,sol1);
    if (resultado >= 0)
    {
        printf("La solucion optima toma %d segundos:\n", resultado);
        for (int i=0; i<L; i++)
        {
            printf("La vuelta %d se hizo a velocidad %d", (i+1), (sol1[i].velocidad+1));
            if (sol1[i].boxes) printf(", hizo stop");
            printf("\n");
        }
    }
    else
        printf("Es imposible completar la carrera\n");


    printf("\n\nCASO 2: L=1, S=2\n");
    L = 1;
    S = 2;
    Par* sol2 = new Par[L];
    int* t2 = new int[S];
    int* c2 = new int[S];


    printf("\nCASO 2.1: basico\n");
    C = 5;
    B = 5;
    t2[0] = 3;
    c2[0] = 3;
    t2[1] = 2;
    c2[1] = 4;

    resultado = minimizar_tiempo_carrera(L,C,B,S,t2,c2,sol2);
    if (resultado >= 0)
    {
        printf("La solucion optima toma %d segundos:\n", resultado);
        for (int i=0; i<L; i++)
        {
            printf("La vuelta %d se hizo a velocidad %d", (i+1), (sol2[i].velocidad+1));
            if (sol2[i].boxes) printf(", hizo stop");
            printf("\n");
        }
    }
    else
        printf("Es imposible completar la carrera\n");



    printf("\nCASO 2.2: imposible\n");
    C = 5;
    B = 5;
    t2[0] = 3;
    c2[0] = 7;
    t2[1] = 2;
    c2[1] = 6;
    resultado = minimizar_tiempo_carrera(L,C,B,S,t2,c2,sol2);
    if (resultado >= 0)
    {
        printf("La solucion optima toma %d segundos:\n", resultado);
        for (int i=0; i<L; i++)
        {
            printf("La vuelta %d se hizo a velocidad %d", (i+1), (sol2[i].velocidad+1));
            if (sol2[i].boxes) printf(", hizo stop");
            printf("\n");
        }
    }
    else
        printf("Es imposible completar la carrera\n");


    printf("\nCASO 2.3: solo 1 posible velocidad\n");
    C = 5;
    B = 5;
    t2[0] = 3;
    c2[0] = 4;
    t2[1] = 2;
    c2[1] = 6;
    resultado = minimizar_tiempo_carrera(L,C,B,S,t2,c2,sol2);
    if (resultado >= 0)
    {
        printf("La solucion optima toma %d segundos:\n", resultado);
        for (int i=0; i<L; i++)
        {
            printf("La vuelta %d se hizo a velocidad %d", (i+1), (sol2[i].velocidad+1));
            if (sol2[i].boxes) printf(", hizo stop");
            printf("\n");
        }
    }
    else
        printf("Es imposible completar la carrera\n");


    printf("\nCASO 3: L=2, S=2\n");
    L = 2;
    S = 2;
    Par* sol3 = new Par[L];
    int* t3 = new int[S];
    int* c3 = new int[S];

    printf("\nCASO 3.1: ir lento y no parar\n");
    C = 5;
    B = 5;
    t3[0] = 2;
    c3[0] = 2;
    t3[1] = 1;
    c3[1] = 3;
    resultado = minimizar_tiempo_carrera(L,C,B,S,t3,c3,sol3);
    if (resultado >= 0)
    {
        printf("La solucion optima toma %d segundos:\n", resultado);
        for (int i=0; i<L; i++)
        {
            printf("La vuelta %d se hizo a velocidad %d", (i+1), (sol3[i].velocidad+1));
            if (sol3[i].boxes) printf(", hizo stop");
            printf("\n");
        }
    }
    else
        printf("Es imposible completar la carrera\n");

    printf("\nCASOS DE LA LETRA\n");
    printf("\nCASO 1\n");

    L = 7;
    S = 10;
    C = 37;
    B = 10;
    Par* soll1 = new Par[L];
    int* tl1 = new int[S];
    int* cl1 = new int[S];
    tl1[0] = 120;
    tl1[1] = 70;
    tl1[2] = 34;
    tl1[3] = 27;
    tl1[4] = 25;
    tl1[5] = 20;
    tl1[6] = 19;
    tl1[7] = 17;
    tl1[8] = 15;
    tl1[9] = 10;
    cl1[0] = 1;
    cl1[1] = 2;
    cl1[2] = 3;
    cl1[3] = 4;
    cl1[4] = 5;
    cl1[5] = 6;
    cl1[6] = 7;
    cl1[7] = 9;
    cl1[8] = 14;
    cl1[9] = 38;
    resultado = minimizar_tiempo_carrera(L,C,B,S,tl1,cl1,soll1);
    if (resultado >= 0)
    {
        printf("La solucion optima toma %d segundos:\n", resultado);
        for (int i=0; i<L; i++)
        {
            printf("La vuelta %d se hizo a velocidad %d", (i+1), (soll1[i].velocidad+1));
            if (soll1[i].boxes) printf(", hizo stop");
            printf("\n");
        }
    }
    else
        printf("Es imposible completar la carrera\n");

    printf("\nCASO 2\n");

    L = 10;
    S = 10;
    C = 10;
    B = 5;
    Par* soll2 = new Par[L];
    int* tl2 = new int[S];
    int* cl2 = new int[S];
    tl2[0] = 40;
    tl2[1] = 35;
    tl2[2] = 27;
    tl2[3] = 24;
    tl2[4] = 20;
    tl2[5] = 14;
    tl2[6] = 13;
    tl2[7] = 12;
    tl2[8] = 11;
    tl2[9] = 10;
    cl2[0] = 15;
    cl2[1] = 16;
    cl2[2] = 17;
    cl2[3] = 18;
    cl2[4] = 19;
    cl2[5] = 20;
    cl2[6] = 21;
    cl2[7] = 23;
    cl2[8] = 25;
    cl2[9] = 27;
    resultado = minimizar_tiempo_carrera(L,C,B,S,tl2,cl2,soll2);
    if (resultado >= 0)
    {
        printf("La solucion optima toma %d segundos:\n", resultado);
        for (int i=0; i<L; i++)
        {
            printf("La vuelta %d se hizo a velocidad %d", (i+1), (soll2[i].velocidad+1));
            if (soll2[i].boxes) printf(", hizo stop");
            printf("\n");
        }
    }
    else
        printf("Es imposible completar la carrera");
    return 1;


    return 1;
}
