#pragma once
#include <map>
#include <vector>
#include <iostream>
class node
{
	int m_cost;
	int m_key;
public:
	node(int key, int cost);
	int getKey();
	int getCost();
	friend std::ostream &operator<<(std::ostream &output, const node N);
	friend bool operator==(node &N, node &M);
	friend bool operator!=(node &N, node &M);
};
class graph
{
	std::map<int, std::vector<node> > m_adjList;
	int m_nodes;
	int m_vertices;
public:
	friend std::istream &operator>>(std::istream &input, graph &G);
	friend std::ostream &operator<<(std::ostream &output, const graph G);
	friend bool operator==(graph &C, graph &G);
	friend bool operator!=(graph &C, graph &G);

	int getNodes();
	int getVertices();
	std::vector< std::vector<int> > getConnectedComponents();
	bool isConnected();
	std::vector<int> dijkstraForNode(int startingNode);
};

