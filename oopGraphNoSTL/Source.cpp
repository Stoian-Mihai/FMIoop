#include <iostream>
#include "Graph.hpp"
#include "manualQueue.hpp"
void connectedComponentsTest(graph &G)
{
	manualVector *conComponents = G.getConnectedComponents();
	for (int i = 1; i <= G.getNumberOfConnectedComponents(); i++)
	{
		for (auto j : conComponents[i])
			std::cout << j << " ";
		std::cout << "\n";
	}
	
}
int main()
{
	graph G;
	freopen("GraphInput.txt", "r", stdin);
	std::cin >> G;
	std::cout << G;
	connectedComponentsTest(G);
	
	int a;
	a = 5;
	system("pause");
	return 0;
}