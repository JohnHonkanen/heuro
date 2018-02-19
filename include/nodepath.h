/*

Name: John Honkanen, Lars Palm

Student ID: B00291253, B00294272

We declare that the following code was produced by John Honkanen (B00291253), Lars Palm (B00294272) as a group assignment for the Computer Game AI module and that this is our own work.

We are aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

This file was created by John Honkanen (B00291253) and Lars Palm (B00294272).
*/


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