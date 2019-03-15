#include "manualVector.hpp"
manualVector::manualVector()
{
	this->v = new int[100];
}
manualVector::manualVector(const manualVector &toCopyVect)
{
	this->count = 0;
	delete[] this->v;
	this->v = new int[100];
	for (int i = 0; i < toCopyVect.count; i++)
		this->pushBack(toCopyVect.v[i]);

}
manualVector::~manualVector()
{
	delete[] this->v;
}
void manualVector::pushBack(int x)
{
	this->v[count++] = x;
}
int *manualVector::begin()
{
	return this->v;
}
int *manualVector::end()
{
	return (this->v + count );
}
bool manualVector::empty()
{
	if (this->count == 0) return 1;
	return 0;
}
void manualVector::operator=(manualVector &toCopyVect)
{
	this->count = 0;
	delete[] this->v;
	this->v = new int[100];
	for (int i = 0; i < toCopyVect.count; i++)
		this->pushBack(toCopyVect.v[i]);

}
int &manualVector::operator[](int index)
{
	return this->v[index];
}

//For node vector
manualVectorNode::manualVectorNode()
{
	this->v = new node[100];
}
manualVectorNode::manualVectorNode(const manualVectorNode &toCopyVect)
{
	this->count = 0;
		delete[] this->v;
	this->v = new node[100];
	for (int i = 0; i < toCopyVect.count; i++)
		this->pushBack(toCopyVect.v[i]);
	
}
manualVectorNode::~manualVectorNode()
{
	delete[] v;
	std::cout << "desctr vector\n";
}
void manualVectorNode::pushBack(node x)
{
	this->v[count++] = x;
}
node *manualVectorNode::begin()
{
	return this->v;
}
node *manualVectorNode::end()
{
	return (this->v + count);
}
bool manualVectorNode::empty()
{
	if (this->count == 0) return 1;
	return 0;
}
void manualVectorNode::operator=(manualVectorNode &toCopyVect)
{
	this->count = 0;
	delete[] this->v;
	this->v = new node[100];
	for (int i = 0; i < toCopyVect.count; i++)
		this->pushBack(toCopyVect.v[i]);

}
void manualVectorNode::print()
{
	for (int i = 0; i < this->count; i++)
	{
		std::cout << this->v[i] << " ";
	}
	std::cout << "\n";
}