#pragma once
#include "Graph.hpp"
#include "Node.hpp"
class manualQueue
{
	int *v;
	int count = 0;
	int first = 0;
public:
	manualQueue();
	~manualQueue();
	int *begin();
	int *end();
	void push(int x);
	int front();
	void pop();
	bool empty();
};

class manualQueueNode
{
protected:
	node *v;
	int count = 0;
	int first = 0;
public:
	manualQueueNode();
	~manualQueueNode();
	node *begin();
	node *end();
	void push(node x);
	node front();
	void pop();
	bool empty();
	void print();
};

class manualpriorityQueueNode : public manualQueueNode
{
public:
	node top();
	void pop();
};