#ifndef GRAPH_HPP
#define GRAPH_HPP

#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include "manualVector.hpp"
#include "manualQueue.hpp"
#include "Node.hpp"
class graph
{
	//std::map<int, std::vector<node> > m_adjList;
	manualVectorNode * m_adjList;
	int m_nodes;
	int m_vertices;
public:
	graph();
	~graph();
	graph(const graph &);
	friend std::istream &operator>>(std::istream &input, graph &G);
	friend std::ostream &operator<<(std::ostream &output, const graph G);
	void operator=(const graph &);
	friend bool operator==(graph &C, graph &G);
	friend bool operator!=(graph &C, graph &G);
	friend bool operator<(graph &C, graph &G);
	friend bool operator>(graph &C, graph &G);
	friend graph operator*(graph &C, graph &G);
	int getNodes();
	int getVertices();
	manualVector* getConnectedComponents();
	bool isConnected();
	manualVector dijkstraForNode(int startingNode);
	int** getMinimumCostMatrix();
	int getNumberOfConnectedComponents();
	manualVector minimumSpanningTree();
	manualVector pathBetween(int nodeA, int nodeB);
};

#endif