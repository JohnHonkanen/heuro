#pragma once
#include <string>
class Graph;
class Parser
{
public:
	static Graph Load(std::string path, bool debug);
};