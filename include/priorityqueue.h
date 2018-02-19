/*

Name: John Honkanen, Lars Palm

Student ID: B00291253, B00294272

We declare that the following code was produced by John Honkanen (B00291253), Lars Palm (B00294272) as a group assignment for the Computer Game AI module and that this is our own work.

We are aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

This file was created by John Honkanen (B00291253) and Lars Palm (B00294272).
*/

#pragma once

#include <functional>
#include <queue>

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
