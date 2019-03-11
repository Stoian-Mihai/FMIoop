#include "Graph.hpp"
#include <queue>
#include <map>
//node class methods

//init method
node::node(int key = 0, int cost = 0)
{
	m_cost = cost;
	m_key = key;
}
//getters
int  node::getKey()
{
	return m_key;
}
int  node::getCost()
{
	return m_cost;
}
//Operator overload
std::ostream &operator<<(std::ostream &output, const node N)
{
	output << "cost = " << N.m_cost << " ";
	output << "node = " << N.m_key << " ";
	return output;
}
bool operator==(node &N, node&M)
{
	if (N.m_cost == M.m_cost && N.m_key == N.m_key) return 1;
	return 0;
}
bool operator!=(node &N, node&M)
{
	if (N == M) return 0;
	return 1;
}
//graph class methods

//Operator overload
std::istream &operator>>(std::istream &input, graph &G)
{
	int a, b, c, i;
	input >> G.m_nodes >> G.m_vertices;
	for (i = 1; i <= G.m_vertices; i++)
	{
		input >> a >> c >> b;
		G.m_adjList[a].push_back(node(b, c));
		G.m_adjList[b].push_back(node(a, c));
	}
	return input;
}
std::ostream &operator<<(std::ostream &output, graph G)
{
	int i;
	output << "Nodes: " << G.m_nodes <<" ";
	output << "Vertices: " << G.m_vertices <<" ";
	output << "\n";
	for (i = 1; i <= G.m_nodes; i++)
	{
		if (!G.m_adjList[i].empty())
		{
			for (size_t j=0; j < G.m_adjList[i].size(); j++)
			{
				output << "Node= " << i << " ";
				output << G.m_adjList[i][j];
				output << "\n";
				
			}
		}
	}

	return output;
}
bool operator==(graph &C, graph &G)
{
	if (C.m_nodes != G.m_nodes) return 0;
	if (C.m_vertices!= C.m_vertices) return 0;

	//Iterating through all the nodes
	for (int i = 1; i <= G.m_vertices; i++)
	{
		//Accessing the map for the node i
		//Now the m_adjList[i] is a vector and can be compared
		auto jt = G.m_adjList[i].begin();
		for (auto it = G.m_adjList[i].begin(); it != G.m_adjList[i].end(); it++)
		{
			if (it != jt) return 0;

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
//getters
int graph::getNodes()
{
	return m_nodes;
}
int graph::getVertices()
{
	return m_vertices;
}

std::vector<std::vector<int> > graph::getConnectedComponents()
{
	std::vector<std::vector<int> > conComponents;
	std::map<int,bool> visited;
	int i;

	for (i = 1; i <= this->m_nodes; i++)
	{
		std::queue <int> q;
		if (!visited[i])
		{
			q.push(i);
			std::vector<int> conComp;
			
			while (!q.empty())
			{
				int curentNode = q.front();
				q.pop();
				if (visited[curentNode]) continue;
				visited[curentNode] = 1;
				conComp.push_back(curentNode);
				for (auto &nextNode : this->m_adjList[curentNode])
				{
					q.push(nextNode.getKey());
				}
			}
			conComponents.push_back(conComp);
		}
	}

	return conComponents;
}
bool graph::isConnected()
{
	std::vector<std::vector<int> > connectedComponents;
	connectedComponents = this->getConnectedComponents();
	if (connectedComponents.size() == 1) return 1;
	return 0;
}
std::vector<int> graph::dijkstraForNode(int startingNode)
{
	//apply the disjktra algorithm from a startingNode to get the minimum
	//cost to all the nodes in the graph
	//initializing the vector with a big value
	std::vector<int> minimumCostVect;
	for (int i = 0; i <= this->m_nodes; i++)
		minimumCostVect.push_back(INT_MAX);
	minimumCostVect[startingNode] = 0;
	//putting the startingNode in a priority queue
	std::priority_queue <int> pQueue;
	pQueue.push(startingNode);

	while (!pQueue.empty())
	{
		int curentNode = pQueue.top();
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
std::vector< std::vector<int> > graph::getMinimumCostMatrix()
{
	//Using Dijkstra algorithm function I generate a minimum cost array for every node, 
	//then I will create a matrix.
	std::vector< std::vector<int> > minMatrix;
	std::vector<int> padding;
	//Because I will start the counting from 1 I must add some padding 
	minMatrix.push_back(padding);
	for (int i = 1; i <= this->m_nodes; i++)
	{
		std::vector<int> minArray;
		minArray = this->dijkstraForNode(i);
		minMatrix.push_back(minArray);
	}
	return minMatrix;
}