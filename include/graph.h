/*

Name: John Honkanen, Lars Palm

Student ID: B00291253, B00294272

We declare that the following code was produced by John Honkanen (B00291253), Lars Palm (B00294272) as a group assignment for the Computer Game AI module and that this is our own work.

We are aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

This file was created by John Honkanen (B00291253) and Lars Palm (B00294272).
*/


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
	Node() {};
	Node(int in_x, int in_y) : x(in_x), y(in_y) {};
	void AddConnections(Connections connect) { connections.push_back(connect); };
	std::vector<Connections> GetConnections() { return connections; };
	int GetID() { return id; };
	void SetID(int in_id) { id = in_id; };
	void GetPosition(int &out_x, int &out_y) { out_x = x; out_y = y; };
	bool operator<(const Node& n2) const {
		if (x < n2.x) {
			return true;
		}
		else if (x > n2.x) {
			return false;
		} else {
			if (y < n2.y) {
				return true;
			}
		} 
		return false;
	};
	int id;

private:
	std::vector<Connections> connections;
	int x, y;
	
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

