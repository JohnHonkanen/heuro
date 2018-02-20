#include "../include/djikstra.h"
#include "../include/graph.h"
#include <map>
#include <queue>

Djikstra::Djikstra(Graph * in_graph, int in_start, int in_end)
{
	_graph = in_graph;
	_start = in_start;
	_end = in_end;

}

Djikstra::~Djikstra()
{
}

void Djikstra::Find(std::map<int, int>& came_from, std::map<int, double>& cost_so_far)
{
	Node start_node = _graph->GetNode(_start);

	PriorityQueue<int, double> frontier;
	frontier.put(_start, 0);

	came_from[_start] = _start;
	cost_so_far[_start] = 0;

	while (!frontier.empty()) {
		Node current = _graph->GetNode(frontier.get());
		int end = _end;
		int current_id = current.GetID();
		/*if (current_id == end) {
			break;
		}*/
		for (Node::Connections c : current.GetConnections()) {
			Node next = _graph->GetNode(c.node);
			double new_cost = cost_so_far[current_id] + c.label; // g(n)

			if (cost_so_far.find(next.GetID()) == cost_so_far.end() || new_cost < cost_so_far[next.GetID()]) {
				cost_so_far[next.GetID()] = new_cost;
				double priority = new_cost; 
				frontier.put(next.GetID(), priority);
				came_from[next.GetID()] = current.GetID();
			}
		}
	}
}

int Djikstra::Heuristics(int in_node, int in_end)
{
	int px, py, end_x, end_y;

	_graph->GetNode(in_node).GetPosition(px, py);
	_graph->GetNode(in_end).GetPosition(end_x, end_y);

	return abs(end_x - px) + abs(end_y - py);
}
