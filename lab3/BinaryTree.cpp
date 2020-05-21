#include "BinaryTree.h"
#include <cassert>
#include "TreeNode.h"

BinaryTree::BinaryTree()
{
	this->root = nullptr;
}

BinaryTree::BinaryTree(int value)
{
	this->root = new TreeNode(value);
}

BinaryTree::~BinaryTree()
{
	delete root;
}



void BinaryTree::Insert(int value)
{
	Insert(value, this->root);
}

TreeNode* BinaryTree::Search(int value) const
{
	return Search(value, this->root);
}


void BinaryTree::Insert(int value, TreeNode* node)
{
	if (node == nullptr) {
		this->root = new TreeNode(value);
		return;
	}
	auto step = node;
	while (true) {
		if (value >= step->getValue())
			if (step->containsRight())
				step = step->getRight();
			else {
				step->setRight(value);
				break;
			}

		else
			if (step->containsLeft())
				step = step->getLeft();
			else {
				step->setLeft(value);
				break;
			}
	}
}

TreeNode* BinaryTree::Search(int value,  TreeNode* node) const
{
	auto step = node;
	while (true) {
		auto nodeValue = step->getValue();
		if (value == step->getValue()) { return step; }
		else {
			if (value >= nodeValue) {
				if (step->containsRight())
					step = step->getRight();
			}
			else
				if (step->containsLeft())
					step = step->getLeft();
				else break;
		}
	}
	assert("There is no element you are looking for");
}




