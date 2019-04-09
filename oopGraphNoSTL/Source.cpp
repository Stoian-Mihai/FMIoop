#include <iostream>
#include "Graph.hpp"
#include "manualQueue.hpp"
void connectedComponentsTest(graph &G)
{
    std::cout<<"number of con comp = "<<G.getNumberOfConnectedComponents() <<"\n";
    std::cout<<"connected components: \n";
	manualVector *conComponents = G.getConnectedComponents();
	for (int i = 1; i <= G.getNumberOfConnectedComponents(); i++)
	{
		for (auto j : conComponents[i])
			std::cout << j << " ";
		std::cout << "\n";
	}
    std::cout<<"\n";
}
void dijkstraTest(graph &G)
{
    std::cout<<" dijkstra : \n";
	manualVector minCost = G.dijkstraForNode(1);
	minCost.print();
    std::cout<<"\n";
}
void minMatrixTest(graph &G)
{
    std::cout<<" min matrix: \n";
	int** matrix = G.getMinimumCostMatrix();
	int n = G.getNodes();
	for (int i = 1; i <= n; i++)
	{
		for (int j = 2; j <= n + 1; j++)
			std::cout << matrix[i][j] << " ";
		std::cout << "\n";
	}
    std::cout<<"\n";
	
}
void pathTest(graph &G)
{
    std::cout<<"path test: \n";
    manualVector v = G.pathBetween(1, 4);
    v.print();
    std::cout<<"\n";
}
void minimumSpanningTreeTest(graph &G)
{
    std::cout<<"minimum spanning tree: \n";
    manualVector v = G.minimumSpanningTree();
    v.print();
    std::cout<<"\n";
}

int main()
{
	graph G;
	freopen("GraphInput.txt", "r", stdin);
	std::cin >> G;
    std::cout << G;
    dijkstraTest(G);
    minMatrixTest(G);
    connectedComponentsTest(G);
    pathTest(G);
    minimumSpanningTreeTest(G);
    
    
	return 0;
}
