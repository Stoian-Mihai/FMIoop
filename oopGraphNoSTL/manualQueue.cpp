#include "manualQueue.hpp"

manualQueue::manualQueue()
{
	this->v = new int[100];
}
manualQueue::~manualQueue()
{
	delete[] this->v;
}
void manualQueue::push(int x)
{
	this->v[count++] = x;
}
int *manualQueue::begin()
{
	return (this->v + this->first);
}
int *manualQueue::end()
{
	return (this->v + count);
}
void manualQueue::pop()
{
	this->first++;
}
int manualQueue::front()
{
	return this->v[first];
}
bool manualQueue::empty()
{
	if (this->first == this->count) return 1;
	return 0;
}
// For node queue
manualQueueNode::manualQueueNode()
{
	this->v = new node[100];
}
manualQueueNode::~manualQueueNode()
{
	delete[] this->v;
}
void manualQueueNode::push(node x)
{
	this->v[count++] = x;
}
node *manualQueueNode::begin()
{
	return (this->v + this->first);
}
node *manualQueueNode::end()
{
	return (this->v + count);
}
void manualQueueNode::pop()
{
	this->first++;
}
node manualQueueNode::front()
{
	return this->v[first];
}
bool manualQueueNode::empty()
{
	return 1;
}

// for priority queue
node manualpriorityQueueNode::top()
{
	node maxNode(INT_MAX,INT_MAX);
	for (int i = this->first; i < this->first + this->count; i++)
	{
		if (this->v[i] < maxNode) maxNode = this->v[i];
	}
	return maxNode;
}
