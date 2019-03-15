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
	friend std::istream &operator>>(std::istream &input, graph &G);
	friend std::ostream &operator<<(std::ostream &output, const graph G);
	graph &operator=(graph& C);
	friend bool operator==(graph &C, graph &G);
	friend bool operator!=(graph &C, graph &G);
	friend bool operator<(graph &C, graph &G);
	friend bool operator>(graph &C, graph &G);

	int getNodes();
	int getVertices();
	manualVector* getConnectedComponents();
	bool isConnected();
	void dijkstraForNode(int startingNode);
	std::vector< std::vector<int> > getMinimumCostMatrix();
	int getNumberOfConnectedComponents();
};

#endif