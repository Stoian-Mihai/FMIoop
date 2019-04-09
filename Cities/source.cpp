#include "orase.h"
#include <iostream>

int main()
{
	char l[100] = "Domnesti";
	char o[100] = "Brasov";
	char c[100] = "Bucuresti";
	char p[100] = "Xu";
	Localitate L(1,l,100);
	Oras O(1, o, 100, 1000);
	Capitala C(1, c, 100000, 1000, p);

	L.display();
	O.display();
	C.display();
	Localitate P;
	
	system("pause");
	return 0;
}