#include "Node.hpp"
//node class methods

//init method
node::node(int key, int cost)
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

bool operator<(node & N, node & M)
{
	if (N.m_cost < M.m_cost) return 1;
	return 0;
}

bool operator>(node & N, node & M)
{
	if (N.m_cost > M.m_cost) return 1;
	return 0;
}
