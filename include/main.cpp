#include<iostream>
#include "graph.h"
#include "parser.h";
#include "astar.h"
#include "djikstra.h"
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
	Djikstra djikstra(&g, 0, 63);

	std::map<int, int> came_from;
	std::map<int, double> cost_so_far;

	std::map<int, int> came_from_djikstra;
	std::map<int, double> cost_so_far_djikstra;

	
	

	int current = 63;
	int goal = 0;
	
	std::cout << "==== A* ====" << std::endl << std::endl;
	astar.Find(came_from, cost_so_far);
	while (current != goal) {
		std::cout << "From: " << current << " to " << came_from[current] << std::endl;
		current = came_from[current];
	}

	std::cout << "==== Djikstra ====" << std::endl << std::endl;
	djikstra.Find(came_from_djikstra, cost_so_far_djikstra);
	current = 63;
	while (current != goal) {
		std::cout << "From: " << current << " to " << came_from_djikstra[current] << std::endl;
		current = came_from_djikstra[current];
	}

	system("pause");
	return 0;
}