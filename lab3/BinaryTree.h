#pragma once
#include "TreeNode.h"
class BinaryTree
{
	

public:
	BinaryTree();
	BinaryTree(int value);
	~BinaryTree();
	void Insert(int value);
	TreeNode* Search(int value) const;
	
private:
	TreeNode* root;
	void Insert(int value, TreeNode*node);
	TreeNode* Search(int value, TreeNode* node) const;
};

