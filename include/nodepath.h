#pragma once
#include <memory>

class NodePath {
public:

	int _node;
	int _prevNode;

	std::shared_ptr<NodePath> _next;
	std::shared_ptr<NodePath> _prev;

private:

};