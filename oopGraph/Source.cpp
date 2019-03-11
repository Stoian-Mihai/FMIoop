#include <iostream>
#include <fstream>
#include "Graph.hpp"


int main()
{
	
	//node x(1, 5);
	//std::cout << x.getKey();
	graph G;
	freopen("GraphInput.txt", "r", stdin);
	std::cin >> G;
	std::cout << G;
	//std::cout << G.isConnected();
	std::vector<std::vector<int> > toPrint;
	toPrint = G.getMinimumCostMatrix();
	for (int i = 1; i <= G.getNodes(); i++)
	{
		for (int j = 1; j <= G.getNodes(); j++)
			std::cout << toPrint[i][j]<<" ";
		std::cout << "\n";
	}
	system("pause");
	return 0;
}