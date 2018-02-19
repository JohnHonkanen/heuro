#pragma once

#include <vector>
#include "nodepath.h"

// struct "PriorityQueue" implementation taken from: https://www.redblobgames.com/pathfinding/a-star/implementation.html
template<typename T, typename priority_t>
struct PriorityQueue {
	typedef std::pair<priority_t, T> PQElement;
	std::priority_queue<PQElement, std::vector<PQElement>,
		std::greater<PQElement>> elements;

	inline bool empty() const {
		return elements.empty();
	}

	inline void put(T item, priority_t priority) {
		elements.emplace(priority, item);
	}

	T get() {
		T best_item = elements.top().second;
		elements.pop();
		return best_item;
	}
};

class Astar {
public:

	Astar(class Graph* in_graph, int in_start, int in_end);
	~Astar();
	
	std::vector<NodePath> FindPath();
	NodePath* Find();

	int Heuristics(int in_node, int in_end);


private:
	
	class Graph* _graph;

	int _start, _end;
};