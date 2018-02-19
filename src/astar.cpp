#include "../include/astar.h"
#include "../include/graph.h"

Astar::Astar(Graph * in_graph, int in_start, int in_end)
{
	_graph = in_graph;
	_start = in_start;
	_end = in_end;

}

Astar::~Astar()
{
}

std::vector<NodePath> Astar::FindPath()
{
	// Finds path <---- :: f(n) = g(n) + h(n)
	std::vector<NodePath> out_path;

	// If destination is start
	if (_start == _end) {
		return out_path;
	}
	
	// calculate lowest cost path

	// Get start node
	Node currentNode = _graph->GetNode(_start);
	Node destinationNode = _graph->GetNode(_end);
	
	int end_x, end_y;
	destinationNode.GetPosition(end_x, end_y);

	// Record our (start) path we begin with
	NodePath currentPath;
	currentPath._node = _start;
	currentPath._prevNode = -1;
	out_path.push_back(currentPath);

	// While end node "destination" is not reached
	while (currentNode.GetID() != _end) {
		std::vector<Node::Connections> connections = currentNode.GetConnections();

		int lowestPathCost = -1;
		int nodeToMove = -1;
		for (int i = 0; i < connections.size(); i++) {
			
			// f(n)
			int pathCost = 0;

			// g(n)
			int costToTraverse = connections[i].label; // label = weights
			int manhattanDistance = 0;
			int px, py;
			Node potentialNode = _graph->GetNode(connections[i].node); // get the node ID of our connection.
			potentialNode.GetPosition(px, py);

			// h(n)
			manhattanDistance = (end_x - px) + (end_y - py);

			// f(n) = g(n) + h(n)
			pathCost = costToTraverse + manhattanDistance;

			if (lowestPathCost == -1 || pathCost < lowestPathCost) {
				lowestPathCost = pathCost;
				nodeToMove = potentialNode.GetID();
			}
		}

		// Record our path
		currentPath._node = nodeToMove;
		currentPath._prevNode = currentNode.GetID();
		out_path.push_back(currentPath);

		printf("%i \n", nodeToMove);
		// Move to node
		currentNode = _graph->GetNode(nodeToMove);

	}

	return out_path;
}
