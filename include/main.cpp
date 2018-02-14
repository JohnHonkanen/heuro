#include<iostream>
#include "graph.h"
#include "parser.h";
int main() {
	//Load the Graph
	Graph g = Parser::Load("path/to/file", true);

	//Assign Start Node and End node
	//Astar(graph, start, end);
	//Output Path
	//Astar.output();
	system("pause");
	return 0;
}