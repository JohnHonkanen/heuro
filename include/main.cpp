#include<iostream>
#include "graph.h"
#include "parser.h";
#include "astar.h"
#include "nodepath.h"
#include <map>
#include <iostream>

int main() {
	//Load the Graph
	//Graph g = Parser::Load("D:/Projects/UWS/AI/part_a/data/random64_4_1517441833.dot", true);
	Graph g = Parser::Load("C:/Users/Clover/Desktop/UWS/AI/heuro/data/random64_4_1517441833.dot", true);
	//Assign Start Node and End node
	//Astar(graph, start, end);
	Astar astar(&g, 0, 63);

	std::map<int, int> came_from;
	std::map<int, double> cost_so_far;

	astar.Find(came_from, cost_so_far);

	int current = 63;
	int goal = 0;
	
	while (current != goal) {
		std::cout << "From: " << current << " to " << came_from[current] << std::endl;
		current = came_from[current];
	}

	system("pause");
	return 0;
}