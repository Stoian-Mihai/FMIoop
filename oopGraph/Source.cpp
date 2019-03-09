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
	std::vector<int> toPrint;
	toPrint = G.dijkstraForNode(1);
	for (auto i : toPrint)
		std::cout << i << " ";
	system("pause");
	return 0;
}