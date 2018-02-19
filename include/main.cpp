/*

Name: John Honkanen, Lars Palm

Student ID: B00291253, B00294272

We declare that the following code was produced by John Honkanen (B00291253), Lars Palm (B00294272) as a group assignment for the Computer Game AI module and that this is our own work.

We are aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

This file was created by John Honkanen (B00291253) and Lars Palm (B00294272).
*/

#include<iostream>
#include "graph.h"
#include "parser.h";
#include "astar.h"
#include "djikstra.h"
#include "nodepath.h"
#include <map>
#include <iostream>
#include <ctime>
#include <string>

int main() {
	//Load the Graph

	std::string path;
	bool success = false;
	Graph g;

	while (!success) {
		std::cout << "Please enter your path to '.dot' file: " << std::endl;
		std::cout << "EXAMPLE: E:/path/to/folder/yourdotfile.dot" << std::endl;
		std::cin >> path;
		g = Parser::Load(path, false, success);
		std::cout << std::endl;
	}

	int startPoint = -1;
	int endPoint = -1;

	while (startPoint < 0 || startPoint > 63) {
		std::cout << "Please enter: START POINT (MIN 0 : MAX 63)" << std::endl;
		std::cin >> startPoint;
		std::cout << std::endl;
	}
	
	while (endPoint < 0 || endPoint > 63) {
		std::cout << "Please enter: END POINT (MAX 63)" << std::endl;;
		std::cin >> endPoint;
		std::cout << std::endl;
	}

	Astar astar(&g, startPoint, endPoint);
	Djikstra djikstra(&g, startPoint, endPoint);

	std::map<int, int> came_from;
	std::map<int, double> cost_so_far;

	std::map<int, int> came_from_djikstra;
	std::map<int, double> cost_so_far_djikstra;

	int current = endPoint;
	int goal = startPoint;
	
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

	current = endPoint;
	while (current != goal) {
		std::cout << "From: " << current << " to " << came_from_djikstra[current] << std::endl;
		current = came_from_djikstra[current];
	}

	system("pause");
	return 0;
}