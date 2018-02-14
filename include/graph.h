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
	Node(int in_x, int in_y) : x(in_x), y(in_y) {};
	void AddConnections(Connections connect) { connections.push_back(connect); };

private:
	std::vector<Connections> connections;
	int x, y;
};

class Graph
{
public:
	void AddNodes(Node node) { nodes.push_back(node); };
	void AddConnection(int node, Node::Connections connection) { nodes[node].AddConnections(connection); };
	Node GetNode(int node) { return nodes[node]; };
private:
	std::string name;
	std::vector<Node> nodes;
};

