#include "TreeNode.h"
#include <cassert>

TreeNode::TreeNode(int _value)
{
	value = _value;
	right = nullptr;
	left = nullptr;
}

TreeNode::TreeNode()
{
	value = 0;
	right = nullptr;
	left = nullptr;
}

TreeNode::~TreeNode()
{
	delete left;
	delete right;
}

int TreeNode::getValue() const
{
	return this->value;
}

bool TreeNode::containsRight() const
{
	return this->right != nullptr;
}

bool TreeNode::containsLeft() const
{
	return this->left != nullptr;
}

TreeNode* TreeNode::getRight() const
{
	return this->right;
}

TreeNode* TreeNode::getLeft() const
{
	return this->left;
}

void TreeNode::setLeft(int value)
{
	assert(!(getLeft() != nullptr) && "Can't change non-null node");
	this->left = new TreeNode(value);
}

void TreeNode::setRight(int value)
{
	assert(!(getRight() != nullptr) && "Can't change non-null node");
	this->right = new TreeNode(value);
}