#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	unsigned int l1,l2,hip;
	cout << "Combinaciones posibles:\n"; 
	for (l1 = 1; l1 <= 50; l1++)
		for (l2 = 1; l2 <= 50; l2++)
			for (hip = 1; hip <= 50; hip++)
			{
				if ((pow((double)l1,2) + pow((double)l2,2) == pow((double)hip,2))) 
					cout << "Lado1 = " << l1 << " Lado2 = " << l2 << " Hipotenusa = " << hip << endl;
			}
	system("Pause");
	return 0;
}
