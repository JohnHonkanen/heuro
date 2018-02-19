#pragma once

#include <vector>
#include "nodepath.h"


class Astar {
public:

	Astar(class Graph* in_graph, int in_start, int in_end);
	~Astar();
	
	void findPath();

private:
	std::vector<NodePath> _path;
	class Graph* _graph;

	int _start, _end;
};