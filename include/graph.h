#pragma once
#include <vector>
#include <string>
class Node
{
public:
	struct Connections
	{
		int label;
		int node;
	};

	void AddConnections(Connections connect) { connections.push_back(connect); };
private:
	std::vector<Connections> connections;
	int x, y;
};

class Graph
{
public:
	void AddNodes(Node node) { nodes.push_back(node); };
private:
	std::string name;
	std::vector<Node> nodes;
};

