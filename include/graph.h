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
	std::vector<Connections> GetConnections() { return connections; };
	int GetID() { return id; };
	void SetID(int in_id) { id = in_id; };
	void GetPosition(int &out_x, int &out_y) { out_x = x; out_y = y; };
private:
	std::vector<Connections> connections;
	int x, y;
	int id;
};

class Graph
{
public:
	void AddNodes(Node node) {
		node.SetID(counter);
		nodes.push_back(node);
		counter++;
	};
	void AddConnection(int node, Node::Connections connection) { nodes[node].AddConnections(connection); };
	Node GetNode(int node) { return nodes[node]; };
private:
	int counter = 0;
	std::string name;
	std::vector<Node> nodes;
};

