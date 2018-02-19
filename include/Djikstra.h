#pragma once

#include <vector>
#include "nodepath.h"
#include <map>
#include "priorityqueue.h"
#include "graph.h"

class Djikstra {
public:

	Djikstra(class Graph* in_graph, int in_start, int in_end);
	~Djikstra();

	void Find(std::map<int, int> &came_from, std::map<int, double> &cost_so_far);

	int Heuristics(int in_node, int in_end);


private:

	class Graph* _graph;

	int _start;
	int _end = -1;
};