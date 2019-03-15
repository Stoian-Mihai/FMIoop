#ifndef NODE_HPP
#define NODE_HPP
#include <iostream>

class node
{
	int m_cost;
	int m_key;
public:
	node(int key = 0, int cost = 0);
	int getKey();
	int getCost();
	friend std::ostream &operator<<(std::ostream &output, const node N);
	friend bool operator==(node &N, node &M);
	friend bool operator!=(node &N, node &M);
	friend bool operator<(node &N, node &M);
	friend bool operator>(node &N, node &M);
};
#endif