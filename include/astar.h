/*

Name: John Honkanen, Lars Palm

Student ID: B00291253, B00294272

We declare that the following code was produced by John Honkanen (B00291253), Lars Palm (B00294272) as a group assignment for the Computer Game AI module and that this is our own work.

We are aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

This file was created by John Honkanen (B00291253) and Lars Palm (B00294272).
*/

#pragma once

#include <vector>
#include "nodepath.h"
#include <map>
#include "graph.h"
#include "priorityqueue.h"

class Astar {
public:

	Astar(class Graph* in_graph, int in_start, int in_end);
	~Astar();
	
	void Find(std::map<int, int> &came_from, std::map<int, double> &cost_so_far);
	
	int Heuristics(int in_node, int in_end);


private:
	
	class Graph* _graph;

	int _start;
	int _end = -1;
};