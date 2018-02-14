#include<iostream>
#include "graph.h"
#include "parser.h";
int main() {
	//Load the Graph
	Graph g = Parser::Load("D:/Projects/UWS/AI/part_a/data/random64_4_1517441833.dot", true);

	//Assign Start Node and End node
	//Astar(graph, start, end);
	//Output Path
	//Astar.output();
	system("pause");
	return 0;
}