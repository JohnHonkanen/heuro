#include<iostream>
#include "graph.h"
#include "parser.h";
#include "astar.h"
#include "djikstra.h"
#include "nodepath.h"
#include <map>
#include <iostream>
#include <ctime>

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

	std::clock_t begin = std::clock();
	astar.Find(came_from, cost_so_far);
	std::clock_t end = std::clock();
	double elapsed_secs = double(end - begin) / 1000;
	std::cout << "Time taken to complete(A*): " << elapsed_secs << std::endl;

	while (current != goal) {
		std::cout << "From: " << current << " to " << came_from[current] << std::endl;
		current = came_from[current];
	}

	std::cout << "==== Djikstra ====" << std::endl << std::endl;

	begin = std::clock();
	djikstra.Find(came_from_djikstra, cost_so_far_djikstra);
	end = std::clock();
	elapsed_secs = double(end - begin) / 1000;;
	std::cout << "Time taken to complete(Djikstra): " << elapsed_secs << std::endl;

	current = 63;
	while (current != goal) {
		std::cout << "From: " << current << " to " << came_from_djikstra[current] << std::endl;
		current = came_from_djikstra[current];
	}

	system("pause");
	return 0;
}