#include "..\include\parser.h"
#include "..\include\graph.h"
#include <sstream>
#include <fstream>
#include <string>
Graph Parser::Load(std::string path, bool debug)
{
	Graph graph = Graph();

	if (debug)
	{
		printf("Debug Mode enabled \n");
	}
	std::ifstream infile(path);
	std::string line;

	//Check if we found file
	if (!infile)
	{
		printf("No file found: %s \n", path.c_str());
		return graph;
	}

	bool preinformation = false;
	//Read line by line
	while (!preinformation)
	{
		if (std::getline(infile, line))
		{

			if (line.find("node") != std::string::npos)
			{

				preinformation = true;
			}
		}
		else {
			preinformation = true;
		}
		
	}

	bool nodeinformation = false;

	//Parse Node information
	while (!nodeinformation)
	{
		if (std::getline(infile, line))
		{
			if (line.find("--") != std::string::npos)
			{
				//Get the Node Connection
				std::size_t first = line.find_first_of('-');
				std::size_t last = line.find_first_of('[');

				std::string node1 = line.substr(0, first);
				std::string node2 = line.substr(first + 2, last - (first + 2));

				//Get the Label
				std::size_t position = line.find("label");
				std::string label = line.substr(position);

				first = label.find_first_of('"');
				last = label.find_last_of('"');

				label = label.substr(first + 1, last - (first + 1));

				graph.AddConnection(std::stoi(node1), { std::stoi(label), std::stoi(node2) });
				graph.AddConnection(std::stoi(node2), { std::stoi(label), std::stoi(node1) });
			}
			else if(line.find("pos") != std::string::npos)
			{
				//Deconstructe String
				std::size_t position = line.find("pos");
				std::string posInfo = line.substr(position);
				std::size_t first = posInfo.find_first_of('"');
				std::size_t last = posInfo.find_last_of('"');

				posInfo = posInfo.substr(first+1, last - (first +1));

				std::vector<std::string> nodePosInfo;
				std::stringstream ss(posInfo);

				//Push our string position
				std::string token;
				while (std::getline(ss, token, ','))
				{
					nodePosInfo.push_back(token);
				}

				//Create our node
				Node n = Node(std::stoi(nodePosInfo[0]), std::stoi(nodePosInfo[1]));
				graph.AddNodes(n);
			}
		}
		else {
			nodeinformation = true;
		}
	}

	return graph;
}
