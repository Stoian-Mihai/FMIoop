#ifndef MANUALVECTOR_HPP
#define MANUALVECTOR_HPP
#pragma once

#include "Node.hpp"
class manualVector
{
	int *v;
	int count = 0;
public:
	manualVector();
	manualVector(const manualVector &);
	~manualVector();
	int *begin();
	int *end();
	void pushBack(int x);
	void operator=(manualVector &);
	int &operator[] (int);
	bool empty();
	void print();
	int getSize();
};

class manualVectorNode
{
public:
	int count = 0;
	node *v;

	manualVectorNode();
	manualVectorNode(const manualVectorNode &);
	~manualVectorNode();
	node *begin();
	node *end();
	void pushBack(node x);
	void print();
	bool empty();
	void operator=(manualVectorNode &);
};
#endif