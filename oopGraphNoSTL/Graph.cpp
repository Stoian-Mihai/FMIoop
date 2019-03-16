#include "Graph.hpp"
#include <queue>
#include <map>

graph::graph()
{
	this->m_adjList = new manualVectorNode[100];
}
graph::~graph()
{
	delete[] m_adjList;
}
graph::graph(const graph &other)
{
	delete[] m_adjList;
	this->m_adjList = new manualVectorNode[100];
	this->m_vertices = other.m_vertices;
	this->m_nodes = other.m_nodes;
	for(int i=1;i<=m_nodes;i++)
	{
		this->m_adjList[i] = other.m_adjList[i];
	}
}

void graph::operator=(const graph &other)
{
	delete[] m_adjList;
	this->m_adjList = new manualVectorNode[100];
	this->m_vertices = other.m_vertices;
	this->m_nodes = other.m_nodes;
	for (int i = 1; i <= m_nodes; i++)
	{
		this->m_adjList[i] = other.m_adjList[i];
	}
}

// Input / Output
std::istream &operator>>(std::istream &input, graph &G)
{
	int a, b, c, i;
	input >> G.m_nodes >> G.m_vertices;
	for (i = 1; i <= G.m_vertices; i++)
	{
		input >> a >> c >> b;
		G.m_adjList[a].pushBack(node(b, c));
		G.m_adjList[b].pushBack(node(a, c));
	}
	return input;
}
std::ostream &operator<<(std::ostream &output, graph G)
{
	int i;
	output << "Nodes: " << G.m_nodes << " ";
	output << "Vertices: " << G.m_vertices << " ";
	output << "\n";
	for (i = 1; i <= G.m_nodes; i++)
	{
		if (!G.m_adjList[i].empty())
		{
			for (auto j : G.m_adjList[i])
			{
				output << "Node= " << i << " ";
				output << j;
				output << "\n";
			}
		}
	}

	return output;
}
//Operator overload
bool operator==(graph &C, graph &G)
{
	if (C.m_nodes != G.m_nodes) return 0;
	if (C.m_vertices!= C.m_vertices) return 0;

	//Iterating through all the nodes
	for (int i = 1; i <= G.m_vertices; i++)
	{
		//Accessing the map for the node i
		//Now the m_adjList[i] is a vector and can be compared
		//auto jt = C.m_adjList[i].begin();
		node*jt = C.m_adjList[i].begin();
		for (auto it : G.m_adjList[i])
		{
			if (it != *jt) return 0;

			jt++;
		}

			

	}
	return 1;
}
bool operator!=(graph &C, graph &G)
{
	if (C == G) return 0;
	return 1;
}
bool operator<(graph &C, graph &G)
{
	if (C.m_nodes < G.m_nodes) return 1;
	if (C.m_nodes > G.m_nodes) return -1;
	return 0;
}
bool operator>(graph &C, graph &G)
{
	if (C.m_nodes > G.m_nodes) return 1;
	if (C.m_nodes < G.m_nodes) return -1;
	return 0;
}

graph operator*(graph& C, graph& G)
{
	graph R;
	R.m_nodes = C.m_nodes;
	R.m_vertices = C.m_vertices;

	for(int i=1;i<=C.m_nodes;i++)
	{
		node *Git = G.m_adjList[i].begin();
		for(auto Cit : C.m_adjList[i])
		{
			if(Cit.getKey() == Git->getKey())
			{
				if(Cit.getCost() < Git->getCost())
				{
					R.m_adjList[i].pushBack(Cit);
				}
				else
				{
					R.m_adjList[i].pushBack(*Git);
				}
			}
		}
	}
	return R;
}

//getters
int graph::getNodes()
{
	return m_nodes;
}
int graph::getVertices()
{
	return m_vertices;
}

manualVector*  graph::getConnectedComponents()
{
	manualVector *conComponents;
	conComponents = new manualVector[100];
	int k = 0;
	int visited[100];
	for (int i = 1; i < 100; i++)
		visited[i] = 0;
	int i;

	for (i = 1; i <= this->m_nodes; i++)
	{
		manualQueue q;
		if (!visited[i])
		{
			q.push(i);
			k++;

			while (!q.empty())
			{
				int curentNode = q.front();
				q.pop();
				if (visited[curentNode]) continue;
				visited[curentNode] = 1;
				conComponents[k].pushBack(curentNode);
				for (auto &nextNode : this->m_adjList[curentNode])
				{
					q.push(nextNode.getKey());
				}
			}
		}
	}
	return conComponents;

}
int graph::getNumberOfConnectedComponents()
{
	int k = 0;
	int visited[100];
	for (int i = 1; i < 100; i++)
		visited[i] = 0;
	int i;

	for (i = 1; i <= this->m_nodes; i++)
	{
		std::queue <int> q;
		if (!visited[i])
		{
			q.push(i);
			k++;

			while (!q.empty())
			{
				int curentNode = q.front();
				q.pop();
				if (visited[curentNode]) continue;
				visited[curentNode] = 1;
				for (auto &nextNode : this->m_adjList[curentNode])
				{
					q.push(nextNode.getKey());
				}
			}
		}
	}
	return k;
}

manualVector graph::minimumSpanningTree()
{
	// picking starting vertex
	int startingNode = 1;
	manualpriorityQueueNode Q;
	manualVector minSpanningTree;
	int *visited = new int[100];
	for (int i = 0; i < 100; i++)
		visited[i] = 0;
	Q.push(node(1, 0));

	while(!Q.empty())
	{
		// picking the minimum cost node
		int curentNode = Q.top().getKey();
		Q.pop();
		//Q.print();
		if (visited[curentNode] == 1) continue;
		visited[curentNode] = 1;
		minSpanningTree.pushBack(curentNode);
		for (auto nextNode :this->m_adjList[curentNode])
		{
			Q.push(nextNode);
		}
		
	}
	delete[] visited;
	return minSpanningTree;
	

}

manualVector graph::pathBetween(int nodeA, int nodeB)
{
	// Using disjktra algorithm and a path vector
	manualVector pathVector;
	for(int i=0;i<= this->m_nodes;i++)
	{
		pathVector.pushBack(-1);
	}
	int startingNode = nodeA;
	pathVector[startingNode] = 0;
	manualVector minimumCostVect;
	for (int i = 0; i <= this->m_nodes; i++)
		minimumCostVect.pushBack(INT_MAX);
	minimumCostVect[startingNode] = 0;

	manualpriorityQueueNode pQueue;
	pQueue.push(node(startingNode, 0));
	while (!pQueue.empty())
	{
		int curentNode = pQueue.top().getKey();
		pQueue.pop();
		for (auto nextNode : this->m_adjList[curentNode])
		{
			if (nextNode.getCost() + minimumCostVect[curentNode] < minimumCostVect[nextNode.getKey()])
			{
				minimumCostVect[nextNode.getKey()] = nextNode.getCost() + minimumCostVect[curentNode];
				pQueue.push(nextNode.getKey());
				pathVector[nextNode.getKey()] = curentNode;
			}
		}
	}
	int pathNode = 3;
	manualVector minimumPath;
	while(pathNode != 0)
	{
		minimumPath.pushBack(pathNode);
		pathNode = pathVector[pathNode];
	}
	return minimumPath;
}

manualVector graph::dijkstraForNode(int startingNode)
{
	//apply the disjktra algorithm from a startingNode to get the minimum
	//cost to all the nodes in the graph
	//initializing the vector with a big value
	//std::vector<int> minimumCostVect;
	manualVector minimumCostVect;
	for (int i = 0; i <= this->m_nodes; i++)
		minimumCostVect.pushBack(INT_MAX);
	minimumCostVect[startingNode] = 0;
	//putting the startingNode in a priority queue
	//std::priority_queue <int> pQueue;
	manualpriorityQueueNode pQueue;
	pQueue.push(node(startingNode, 0));
	while (!pQueue.empty())
	{
		int curentNode = pQueue.top().getKey();
		pQueue.pop();
		//looping through curentNode adjList
		for (auto nextNode : this->m_adjList[curentNode])
		{
			//if we found a cheaper way to get to next node we add that node to priority queue
			if (nextNode.getCost() + minimumCostVect[curentNode] < minimumCostVect[nextNode.getKey()])
			{
				minimumCostVect[nextNode.getKey()] = nextNode.getCost() + minimumCostVect[curentNode];
				pQueue.push(nextNode.getKey());
			}
		}
	}
	//replacing INT_MAX value with -1 for better readability when printed
	for (int i = 0; i <= this->m_nodes; i++)
		if (minimumCostVect[i] == INT_MAX) minimumCostVect[i] = -1;

	return minimumCostVect;
}
int** graph::getMinimumCostMatrix()
{
	//Using Dijkstra algorithm function I generate a minimum cost array for every node, 
	//then I will create a matrix.
	int** minMatrix = new int*[100];
	for (int i = 0; i < 100; i++)
		minMatrix[i] = new int[100];

	for (int i = 1; i <= this->m_nodes; i++)
	{
		
		manualVector minArray = this->dijkstraForNode(i);
		minArray.print();
		minMatrix[i][0] = minArray.getSize();
		int k = 0;
		for(auto j  : minArray)
		{
			minMatrix[i][++k] = j;
		}
	}
	return minMatrix;
}
