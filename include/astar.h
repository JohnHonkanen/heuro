#pragma once

#include <vector>
#include "nodepath.h"


class Astar {
public:

	Astar(class Graph* in_graph, int in_start, int in_end);
	~Astar();
	
	std::vector<NodePath> FindPath();

private:
	
	class Graph* _graph;

	int _start, _end;
};