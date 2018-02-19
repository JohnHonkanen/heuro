#include "astar.h"
#include "graph.h"

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
	
	while (currentNode != destinationNode) {

	}
	return out_path;
}
