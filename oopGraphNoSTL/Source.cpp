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
void dijkstraTest(graph &G)
{
	manualVector minCost = G.dijkstraForNode(1);
	minCost.print();
}
void minMatrixTest(graph &G)
{
	int** matrix = G.getMinimumCostMatrix();
	int n = G.getNodes();
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			std::cout << matrix[i][j] << " ";
		std::cout << "\n";
	}

	
}
int main()
{
	graph G;
	freopen("GraphInput.txt", "r", stdin);
	std::cin >> G;
	system("pause");
	return 0;
}