#include<iostream>
#include "graph.h"
#include "parser.h";
#include "astar.h"
#include "nodepath.h"

int main() {
	//Load the Graph
	//Graph g = Parser::Load("D:/Projects/UWS/AI/part_a/data/random64_4_1517441833.dot", true);
	Graph g = Parser::Load("C:/Users/Clover/Desktop/UWS/AI/heuro/data/random64_4_1517441833.dot", true);
	//Assign Start Node and End node
	//Astar(graph, start, end);
	Astar astar(&g, 0, 63);
	std::vector<NodePath> path = astar.FindPath();
	for (int i = 0; i < path.size(); i++) {
		//cout << path[i]._node << endl;
	}

	//Output Path
	//Astar.output();
	system("pause");
	return 0;
}