#include <iostream>
#include "gomokuModel.h"
int main()
{
	gomoku G;
	int option;
	std::cin >> option;
	while(1)
	switch (option)
	{
	case 1:
		{
			int j, i;
			std::cin >> i >> j;
			G.makeMove(1, i, j);
			std::cin >> option;
			break;
		}
	case 2:
		{
			G.printGrid();
			std::cin >> option;
			break;
		}
	case 3:
		{
			std::cout << "\n" << G.checkForWin() << "\n";
			std::cin >> option;
			break;
		}
	
	}
	system("pause");
	return 0;
}