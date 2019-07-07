
#include<iostream>

using namespace std;

int main2(){
int a, b;
cout << "\nPor favor, ingrese un numero: ";
cin >> a;
cout << "\nIngrese otro numero: ";
cin >> b;
if (a == b) 
cout << "\nSon iguales";
else cout << "Son distintos";
return 0;
}

void darValor (int val, int* &ptr)
{
int* aux = new int;
*aux = val;
ptr = aux;
}
int main ()
{
int* ptr;
darValor (3, ptr);
cout << *ptr;
return 0;
}


