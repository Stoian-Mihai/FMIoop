#include "orase.h"
#include <iostream>
#include <fstream>
// nume prefect - nr blocuri - cod - denumire - nr loc


int main()
{
	freopen("testData.txt", "r", stdin);
	
	//Judet J = read();
	Judet J;
	std::cin >> J;
	std::cout << J;
	system("pause");
	return 0;
}